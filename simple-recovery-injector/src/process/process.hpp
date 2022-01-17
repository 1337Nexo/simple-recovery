#include "common.hpp"

#include "util/util.hpp"

namespace process
{
	inline std::uint32_t pid{};
	inline std::string name{ "GTA5.exe" };

	typedef DWORD(WINAPI* pRtlCreateUserThread)(IN HANDLE ProcessHandle, IN PSECURITY_DESCRIPTOR SecurityDescriptor, IN BOOL CreateSuspended, IN ULONG StackZeroBits, IN OUT PULONG StackReserved, IN OUT PULONG StackCommit, IN LPVOID StartAddress, IN LPVOID StartParameter, OUT HANDLE ThreadHandle, OUT LPVOID ClientID);

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

	static bool create_remote_thread(std::string file_name, std::uint32_t pid)
	{
		if (!util::does_file_exist(std::filesystem::absolute(file_name).string()))
		{
			spdlog::error("{} file doesn't exist.", file_name);
			return false;
		}

		HANDLE m_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (m_handle == NULL)
		{
			spdlog::error("Failed to OpenProcess().");
			return false;
		}

		LPVOID m_virtual_alloc = VirtualAllocEx(m_handle, NULL, static_cast<long>(std::filesystem::absolute(file_name).string().length() + 1), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (m_virtual_alloc == NULL)
		{
			spdlog::error("Failed to VirtualAllocEx().");
			return false;
		}

		int m_write_process_memory = WriteProcessMemory(m_handle, m_virtual_alloc, std::filesystem::absolute(file_name).string().c_str(), static_cast<long>(std::filesystem::absolute(file_name).string().length() + 1), NULL);
		if (m_write_process_memory == ERROR_INVALID_HANDLE) {

			spdlog::error("Failed to WriteProcessMemory().");
			return false;
		}

		HANDLE m_create_remote_thread = CreateRemoteThread(m_handle, NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(LoadLibraryA("kernel32"), "LoadLibraryA")), m_virtual_alloc, NULL, NULL);
		if (m_create_remote_thread == NULL)
		{
			spdlog::error("Failed to CreateRemoteThread().");
			return false;
		}

		if (m_handle != NULL && m_virtual_alloc != NULL && m_write_process_memory != ERROR_INVALID_HANDLE && m_create_remote_thread != NULL)
			return true;

		return false;
	}
}