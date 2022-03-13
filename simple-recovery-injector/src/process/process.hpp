#include "common.hpp"

namespace process
{
	inline std::uint32_t pid{};
	inline std::string name{ "GTA5.exe" };

	static bool is_process_running()
	{
		auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (snapshot == INVALID_HANDLE_VALUE)
			return false;

		auto entry = PROCESSENTRY32{ sizeof(PROCESSENTRY32) };

		if (Process32First(snapshot, &entry))
		{
			do
			{
				if (!_stricmp(entry.szExeFile, name.c_str()))
				{
					CloseHandle(snapshot);
					return true;
				}
			} while (Process32Next(snapshot, &entry));
		}

		CloseHandle(snapshot);
		return false;
	}

	static std::uint32_t get_process_id_by_name()
	{
		auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (snapshot == INVALID_HANDLE_VALUE)
			return false;

		auto entry = PROCESSENTRY32{ sizeof(PROCESSENTRY32) };

		if (Process32First(snapshot, &entry))
		{
			do
			{
				if (!_stricmp(entry.szExeFile, name.c_str()))
				{
					CloseHandle(snapshot);
					return entry.th32ProcessID;
				}
			} while (Process32Next(snapshot, &entry));
		}

		CloseHandle(snapshot);
		return 0;
	}

	static bool create_remote_thread(std::string file_name)
	{
		HANDLE m_handle{ NULL };
		HANDLE m_create_remote_thread{ NULL };
		LPVOID m_virtual_alloc{ NULL };

		auto cleanup = [m_handle, m_create_remote_thread, m_virtual_alloc]() -> void
		{
			VirtualFreeEx(m_handle, m_virtual_alloc, NULL, MEM_RELEASE);
			CloseHandle(m_handle);
			CloseHandle(m_create_remote_thread);
		};

		if (!std::filesystem::exists(file_name))
		{
			spdlog::error("{} file doesn't exist.", file_name);
			return false;
		}

		if (pid == NULL)
		{
			spdlog::error("{} is not open.", name);
			return false;
		}

		m_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (m_handle == NULL)
		{
			spdlog::error("Failed to OpenProcess(). 0x{:X}", GetLastError());
			cleanup();
			return false;
		}

		m_virtual_alloc = VirtualAllocEx(m_handle, NULL, static_cast<long>(std::filesystem::absolute(file_name).string().size() * 2), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (m_virtual_alloc == NULL)
		{
			spdlog::error("Failed to VirtualAllocEx(). 0x{:X}", GetLastError());
			cleanup();
			return false;
		}

		auto m_write_process_memory = WriteProcessMemory(m_handle, m_virtual_alloc, std::filesystem::absolute(file_name).string().c_str(), static_cast<long>(std::filesystem::absolute(file_name).string().length() + 1), NULL);
		if (m_write_process_memory == NULL)
		{
			spdlog::error("Failed to WriteProcessMemory(). 0x{:X}", GetLastError());
			cleanup();
			return false;
		}

		auto m_loadlibrary_address = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandleA("kernel32.dll"), ("LoadLibraryA")));
		if (m_loadlibrary_address == NULL)
		{
			spdlog::error("Failed to GetProcAddress(). 0x{:X}", GetLastError());
			cleanup();
			return false;
		}

		spdlog::info("[m_loadlibrary_address]: 0x{:X}", reinterpret_cast<DWORD64>(m_loadlibrary_address));

		m_create_remote_thread = CreateRemoteThread(m_handle, NULL, NULL, m_loadlibrary_address, m_virtual_alloc, NULL, NULL);
		if (m_create_remote_thread == NULL)
		{
			spdlog::error("Failed to CreateRemoteThread(). 0x{:X}", GetLastError());
			cleanup();
			return false;
		}

		cleanup();

		return true;
	}
}
