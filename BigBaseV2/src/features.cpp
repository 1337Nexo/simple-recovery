#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include <local_player.hpp>

namespace big
{
	void features::run_tick()
	{
		static std::chrono::high_resolution_clock::time_point previous_call_time = {};
		auto milliseconds_delta = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::high_resolution_clock::now( ) - previous_call_time );
		if ( milliseconds_delta > 60s )
		{
			STATS::STAT_GET_INT( RAGE_JOAAT( "MPPLY_LAST_MP_CHAR" ), &g_local_player.character_index, TRUE );
			previous_call_time = std::chrono::high_resolution_clock::now( );
		}
	}

	void features::script_func()
	{
		while (true)
		{
			TRY_CLAUSE
			{
				run_tick();
			}
			EXCEPT_CLAUSE
			script::get_current()->yield();
		}
	}
}
