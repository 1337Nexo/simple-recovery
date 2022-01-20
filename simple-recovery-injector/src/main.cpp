#include "common.hpp"
#include "process/process.hpp"

int main()
{
	spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");

	spdlog::info("simple-recovery");

	spdlog::info("press ENTER to continue\n");

	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			spdlog::info("Waiting for {}...", process::name);
			while (!process::is_process_running())
				std::this_thread::sleep_for(100ms);

			process::pid = process::get_process_id_by_name();
			spdlog::info("{0} found... | 0x{1:X} | {1}", process::name, process::pid);

			/*
			if (debugger_bypass)
			{
				spdlog::info("Bypassing anti-debugger.");
				if (process::create_remote_thread("HookLibraryx64.dll", process::pid))
					spdlog::info("Bypassed anti-debugger.");
				else
					spdlog::error("Could not bypass anti-debugger.");
			}
			*/

			if (process::create_remote_thread("simple-recovery.dll"))
				spdlog::info("DLL Injection done.\n");
			else
				spdlog::error("Could not inject the DLL.\n");

			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			spdlog::info("Closing in 10 seconds.");

			std::this_thread::sleep_for(std::chrono::milliseconds(10000));

			return 0;
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	return 0;
}