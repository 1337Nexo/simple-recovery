#include "common.hpp"
//#include "natives.hpp"
#include "script.hpp"
#include "local_player.hpp"
#include "gta/enums.hpp"
#include "script_global.hpp"

using namespace big;

namespace helper
{
	// example: set_packed_bool(31736, 1)
	//
	//HUD::CLEAR_HELP(true);
	//func_799("BURIED_OUTHEL2", -1);
	//HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("BURIED_OUTTIC");
	//HUD::END_TEXT_COMMAND_THEFEED_POST_UNLOCK_TU("CLOTHES_UNLOCK", 7, "BURIED_OUTHEL", 1);
	//func_19945(31736, 1, -1, 1);

	//获取Packed Bool Mask
	//Get Packed Bool Mask
	static int get_packed_bool_mask(int index)
	{
		int iParam0 = index; // index
		int iVar0 = 0;

		if (iParam0 >= 0 && iParam0 < 192)
		{
			iVar0 = ((iParam0 - 0) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 0)) * 64);
		}
		else if (iParam0 >= 192 && iParam0 < 384)
		{
			iVar0 = ((iParam0 - 192) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 192)) * 64);
		}
		else if (iParam0 >= 513 && iParam0 < 705)
		{
			iVar0 = ((iParam0 - 513) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 513)) * 64);
		}
		else if (iParam0 >= 705 && iParam0 < 1281)
		{
			iVar0 = ((iParam0 - 705) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 705)) * 64);
		}
		else if (iParam0 >= 2919 && iParam0 < 3111)
		{
			iVar0 = ((iParam0 - 2919) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 2919)) * 64);
		}
		else if (iParam0 >= 3111 && iParam0 < 3879)
		{
			iVar0 = ((iParam0 - 3111) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 3111)) * 64);
		}
		else if (iParam0 >= 4335 && iParam0 < 4399)
		{
			iVar0 = ((iParam0 - 4335) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 4335)) * 64);
		}
		else if (iParam0 >= 4207 && iParam0 < 4335)
		{
			iVar0 = ((iParam0 - 4207) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 4207)) * 64);
		}
		else if (iParam0 >= 6029 && iParam0 < 6413)
		{
			iVar0 = ((iParam0 - 6029) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 6029)) * 64);
		}
		else if (iParam0 >= 7385 && iParam0 < 7641)
		{
			iVar0 = ((iParam0 - 7385) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 7385)) * 64);
		}
		else if (iParam0 >= 7321 && iParam0 < 7385)
		{
			iVar0 = ((iParam0 - 7321) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 7321)) * 64);
		}
		else if (iParam0 >= 9361 && iParam0 < 9553)
		{
			iVar0 = ((iParam0 - 9361) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 9361)) * 64);
		}
		else if (iParam0 >= 15369 && iParam0 < 15561)
		{
			iVar0 = ((iParam0 - 15369) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 15369)) * 64);
		}
		else if (iParam0 >= 15562 && iParam0 < 15946)
		{
			iVar0 = ((iParam0 - 15562) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 15562)) * 64);
		}
		else if (iParam0 >= 15946 && iParam0 < 16010)
		{
			iVar0 = ((iParam0 - 15946) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 15946)) * 64);
		}
		else if (iParam0 >= 18098 && iParam0 < 18162)
		{
			iVar0 = ((iParam0 - 18098) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 18098)) * 64);
		}
		else if (iParam0 >= 22066 && iParam0 < 22194)
		{
			iVar0 = ((iParam0 - 22066) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 22066)) * 64);
		}
		else if (iParam0 >= 24962 && iParam0 < 25538)
		{
			iVar0 = ((iParam0 - 24962) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 24962)) * 64);
		}
		else if (iParam0 >= 26810 && iParam0 < 27258)
		{
			iVar0 = ((iParam0 - 26810) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 26810)) * 64);
		}
		else if (iParam0 >= 28098 && iParam0 < 28354)
		{
			iVar0 = ((iParam0 - 28098) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 28098)) * 64);
		}
		else if (iParam0 >= 28355 && iParam0 < 28483)
		{
			iVar0 = ((iParam0 - 28355) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 28355)) * 64);
		}
		else if (iParam0 >= 30227 && iParam0 < 30355)
		{
			iVar0 = ((iParam0 - 30227) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 30227)) * 64);
		}
		else if (iParam0 >= 30355 && iParam0 < 30483)
		{
			iVar0 = ((iParam0 - 30355) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 30355)) * 64);
		}
		else if (iParam0 >= 30515 && iParam0 < 30707)
		{
			iVar0 = ((iParam0 - 30515) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 30515)) * 64);
		}
		else if (iParam0 >= 31707 && iParam0 < 32283)
		{
			iVar0 = ((iParam0 - 31707) - STATS::_STAT_GET_PACKED_BOOL_MASK((iParam0 - 31707)) * 64);
		}
		return iVar0;
	}

	//获取Packed Bool Hash
	//Get Packed Bool Hash
	static int get_packed_bool_hash(int index)
	{
		int iParam0 = index; // index
		int iParam1 = -1;// character
		int iVar0 = 0;

		if (iParam1 == -1)
		{
			iParam1 = g_local_player.character_index;
		}
		if (iParam0 >= 0 && iParam0 < 192)
		{
			iVar0 = STATS::GET_PACKED_BOOL_STAT_KEY((iParam0 - 0), false, true, iParam1);
		}
		else if (iParam0 >= 192 && iParam0 < 384)
		{
			iVar0 = STATS::GET_PACKED_BOOL_STAT_KEY((iParam0 - 192), true, true, iParam1);
		}
		else if (iParam0 >= 513 && iParam0 < 705)
		{
			iVar0 = STATS::GET_PACKED_BOOL_STAT_KEY((iParam0 - 513), false, false, 0);
		}
		else if (iParam0 >= 705 && iParam0 < 1281)
		{
			iVar0 = STATS::GET_PACKED_BOOL_STAT_KEY((iParam0 - 705), true, false, 0);
		}
		else if (iParam0 >= 2919 && iParam0 < 3111)
		{
			iVar0 = STATS::GET_PACKED_TU_BOOL_STAT_KEY((iParam0 - 2919), false, false, 0);
		}
		else if (iParam0 >= 3111 && iParam0 < 3879)
		{
			iVar0 = STATS::GET_PACKED_TU_BOOL_STAT_KEY((iParam0 - 3111), false, true, iParam1);
		}
		else if (iParam0 >= 4335 && iParam0 < 4399)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 4335), false, false, 0, "_NGPSTAT_BOOL");
		}
		else if (iParam0 >= 4207 && iParam0 < 4335)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 4207), false, true, iParam1, "_NGPSTAT_BOOL");
		}
		else if (iParam0 >= 6029 && iParam0 < 6413)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 6029), false, true, iParam1, "_NGTATPSTAT_BOOL");
		}
		else if (iParam0 >= 7321 && iParam0 < 7385)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 7321), false, false, 0, "_NGDLCPSTAT_BOOL");
		}
		else if (iParam0 >= 7385 && iParam0 < 7641)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 7385), false, true, iParam1, "_NGDLCPSTAT_BOOL");
		}
		else if (iParam0 >= 9361 && iParam0 < 9553)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 9361), false, true, iParam1, "_DLCBIKEPSTAT_BOOL");
		}
		else if (iParam0 >= 15369 && iParam0 < 15561)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 15369), false, true, iParam1, "_DLCGUNPSTAT_BOOL");
		}
		else if (iParam0 >= 15562 && iParam0 < 15946)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 15562), false, true, iParam1, "_GUNTATPSTAT_BOOL");
		}
		else if (iParam0 >= 15946 && iParam0 < 16010)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 15946), false, true, iParam1, "_DLCSMUGCHARPSTAT_BOOL");
		}
		else if (iParam0 >= 18098 && iParam0 < 18162)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 18098), false, true, iParam1, "_GANGOPSPSTAT_BOOL");
		}
		else if (iParam0 >= 22066 && iParam0 < 22194)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 22066), false, true, iParam1, "_BUSINESSBATPSTAT_BOOL");
		}
		else if (iParam0 >= 24962 && iParam0 < 25538)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 24962), false, true, iParam1, "_ARENAWARSPSTAT_BOOL");
		}
		else if (iParam0 >= 26810 && iParam0 < 27258)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 26810), false, true, iParam1, "_CASINOPSTAT_BOOL");
		}
		else if (iParam0 >= 28098 && iParam0 < 28354)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 28098), false, true, iParam1, "_CASINOHSTPSTAT_BOOL");
		}
		else if (iParam0 >= 28355 && iParam0 < 28483)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 28355), false, true, iParam1, "_HEIST3TATTOOSTAT_BOOL");
		}
		else if (iParam0 >= 30227 && iParam0 < 30355)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 30227), false, true, iParam1, "_SU20PSTAT_BOOL");
		}
		else if (iParam0 >= 30355 && iParam0 < 30483)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 30355), false, true, iParam1, "_SU20TATTOOSTAT_BOOL");
		}
		else if (iParam0 >= 30515 && iParam0 < 30707)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 30515), false, true, iParam1, "_HISLANDPSTAT_BOOL");
		}
		else if (iParam0 >= 31707 && iParam0 < 32283)
		{
			iVar0 = STATS::_GET_NGSTAT_BOOL_HASH((iParam0 - 31707), false, true, iParam1, "_TUNERPSTAT_BOOL");
		}
		return iVar0;
	}

	// 设置Packed Bool
	// Set Packed Bool
	static bool set_packed_bool(int index, bool value)
	{
		int iParam0 = index; // index
		bool bParam1 = value; // value
		bool bVar0 = false;

		int iVar1 = get_packed_bool_hash(iParam0);
		int iVar2 = get_packed_bool_mask(iParam0);
		STATS::STAT_SET_BOOL_MASKED(iVar1, bParam1, iVar2, true);
		return bVar0;
	}

	//获取Packed Bool
	//Get Packed Bool
	static bool get_packed_bool(int index)
	{
		int iParam0 = index; // index
		bool bVar0 = false;

		int iVar1 = get_packed_bool_hash(iParam0);
		int iVar2 = get_packed_bool_mask(iParam0);
		if (0 != iVar1)
		{
			bVar0 = STATS::STAT_GET_BOOL_MASKED(iVar1, iVar2, true);
			LOG_INFO(fmt::format(u8"获取Packed Bool值: Value: {} | index:{}", bVar0, iParam0));
		}
		return bVar0;
	}

	//批量设置Packed Bool
	static void set_mass_packed_bool(BOOL value, int min_i, int max_i)
	{
		for (auto index = min_i; index <= max_i; index++)
		{
			set_packed_bool(index, value);
		}
	}

	//批量获取Packed Bool
	static void get_mass_packed_bool(int min_i, int max_i)
	{
		for (auto index = min_i; index <= max_i; index++)
		{
			get_packed_bool(index);
		}
	}

	//获取Packed Int Mask
	//Get Packed Int Mask	
	static int get_packed_int_mask(int index)
	{
		int iParam0 = index; // index
		int iVar0 = 0;

		if (iParam0 >= 384 && iParam0 < 457)
		{
			iVar0 = ((iParam0 - 384) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 384)) * 8) * 8;
		}
		else if (iParam0 >= 457 && iParam0 < 513)
		{
			iVar0 = ((iParam0 - 457) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 457)) * 8) * 8;
		}
		else if (iParam0 >= 1281 && iParam0 < 1305)
		{
			iVar0 = ((iParam0 - 1281) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 1281)) * 8) * 8;
		}
		else if (iParam0 >= 1305 && iParam0 < 1361)
		{
			iVar0 = ((iParam0 - 1305) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 1305)) * 8) * 8;
		}
		else if (iParam0 >= 1361 && iParam0 < 1393)
		{
			iVar0 = ((iParam0 - 1361) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 1361)) * 8) * 8;
		}
		else if (iParam0 >= 1393 && iParam0 < 2919)
		{
			iVar0 = ((iParam0 - 1393) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 1393)) * 8) * 8;
		}
		else if (iParam0 >= 4143 && iParam0 < 4207)
		{
			iVar0 = ((iParam0 - 4143) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 4143)) * 8) * 8;
		}
		else if (iParam0 >= 3879 && iParam0 < 4143)
		{
			iVar0 = ((iParam0 - 3879) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 3879)) * 8) * 8;
		}
		else if (iParam0 >= 4399 && iParam0 < 6028)
		{
			iVar0 = ((iParam0 - 4399) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 4399)) * 8) * 8;
		}
		else if (iParam0 >= 6413 && iParam0 < 7262)
		{
			iVar0 = ((iParam0 - 6413) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 6413)) * 8) * 8;
		}
		else if (iParam0 >= 7262 && iParam0 < 7313)
		{
			iVar0 = ((iParam0 - 7262) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 7262)) * 8) * 8;
		}
		else if (iParam0 >= 7681 && iParam0 < 9361)
		{
			iVar0 = ((iParam0 - 7681) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 7681)) * 8) * 8;
		}
		else if (iParam0 >= 9553 && iParam0 < 15265)
		{
			iVar0 = ((iParam0 - 9553) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 9553)) * 8) * 8;
		}
		else if (iParam0 >= 15265 && iParam0 < 15369)
		{
			iVar0 = ((iParam0 - 15265) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 15265)) * 8) * 8;
		}
		else if (iParam0 >= 7313 && iParam0 < 7321)
		{
			iVar0 = ((iParam0 - 7313) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 7313)) * 8) * 8;
		}
		else if (iParam0 >= 7641 && iParam0 < 7681)
		{
			iVar0 = ((iParam0 - 7641) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 7641)) * 8) * 8;
		}
		else if (iParam0 >= 16010 && iParam0 < 18098)
		{
			iVar0 = ((iParam0 - 16010) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 16010)) * 8) * 8;
		}
		else if (iParam0 >= 18162 && iParam0 < 19018)
		{
			iVar0 = ((iParam0 - 18162) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 18162)) * 8) * 8;
		}
		else if (iParam0 >= 19018 && iParam0 < 22066)
		{
			iVar0 = ((iParam0 - 19018) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 19018)) * 8) * 8;
		}
		else if (iParam0 >= 22194 && iParam0 < 24962)
		{
			iVar0 = ((iParam0 - 22194) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 22194)) * 8) * 8;
		}
		else if (iParam0 >= 25538 && iParam0 < 26810)
		{
			iVar0 = ((iParam0 - 25538) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 25538)) * 8) * 8;
		}
		else if (iParam0 >= 27258 && iParam0 < 28098)
		{
			iVar0 = ((iParam0 - 27258) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 27258)) * 8) * 8;
		}
		else if (iParam0 >= 28483 && iParam0 < 30227)
		{
			iVar0 = ((iParam0 - 28483) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 28483)) * 8) * 8;
		}
		else if (iParam0 >= 30483 && iParam0 < 30515)
		{
			iVar0 = ((iParam0 - 30483) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 30483)) * 8) * 8;
		}
		else if (iParam0 >= 30707 && iParam0 < 31707)
		{
			iVar0 = ((iParam0 - 30707) - STATS::_STAT_GET_PACKED_INT_MASK((iParam0 - 30707)) * 8) * 8;
		}
		return iVar0;
	}

	//获取Packed Int Hash
	//Get Packed Int Hash
	static int get_packed_int_hash(int index)
	{
		int iParam0 = index; // index
		int iParam1 = -1; // character_index
		int iVar0 = 0;

		if (iParam1 == -1)
		{
			iParam1 = g_local_player.character_index;
		}
		if (iParam0 >= 384 && iParam0 < 457)
		{
			iVar0 = STATS::GET_PACKED_INT_STAT_KEY((iParam0 - 384), false, true, iParam1);
		}
		else if (iParam0 >= 457 && iParam0 < 513)
		{
			iVar0 = STATS::GET_PACKED_INT_STAT_KEY((iParam0 - 457), true, true, iParam1);
		}
		else if (iParam0 >= 1281 && iParam0 < 1305)
		{
			iVar0 = STATS::GET_PACKED_INT_STAT_KEY((iParam0 - 1281), false, false, 0);
		}
		else if (iParam0 >= 1305 && iParam0 < 1361)
		{
			iVar0 = STATS::GET_PACKED_INT_STAT_KEY((iParam0 - 1305), true, false, 0);
		}
		else if (iParam0 >= 1361 && iParam0 < 1393)
		{
			iVar0 = STATS::GET_PACKED_TU_INT_STAT_KEY((iParam0 - 1361), false, false, 0);
		}
		else if (iParam0 >= 1393 && iParam0 < 2919)
		{
			iVar0 = STATS::GET_PACKED_TU_INT_STAT_KEY((iParam0 - 1393), false, true, iParam1);
		}
		else if (iParam0 >= 4143 && iParam0 < 4207)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 4143), false, false, 0, "_NGPSTAT_INT");
		}
		else if (iParam0 >= 3879 && iParam0 < 4143)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 3879), false, true, iParam1, "_NGPSTAT_INT");
		}
		else if (iParam0 >= 4399 && iParam0 < 6028)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 4399), false, true, iParam1, "_LRPSTAT_INT");
		}
		else if (iParam0 >= 6413 && iParam0 < 7262)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 6413), false, true, iParam1, "_APAPSTAT_INT");
		}
		else if (iParam0 >= 7262 && iParam0 < 7313)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 7262), false, true, iParam1, "_LR2PSTAT_INT");
		}
		else if (iParam0 >= 7681 && iParam0 < 9361)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 7681), false, true, iParam1, "_BIKEPSTAT_INT");
		}
		else if (iParam0 >= 9553 && iParam0 < 15265)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 9553), false, true, iParam1, "_IMPEXPPSTAT_INT");
		}
		else if (iParam0 >= 15265 && iParam0 < 15369)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 15265), false, true, iParam1, "_GUNRPSTAT_INT");
		}
		else if (iParam0 >= 7313 && iParam0 < 7321)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 7313), false, false, 0, "_NGDLCPSTAT_INT");
		}
		else if (iParam0 >= 7641 && iParam0 < 7681)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 7641), false, true, iParam1, "_NGDLCPSTAT_INT");
		}
		else if (iParam0 >= 16010 && iParam0 < 18098)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 16010), false, true, iParam1, "_DLCSMUGCHARPSTAT_INT");
		}
		else if (iParam0 >= 18162 && iParam0 < 19018)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 18162), false, true, iParam1, "_GANGOPSPSTAT_INT");
		}
		else if (iParam0 >= 19018 && iParam0 < 22066)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 19018), false, true, iParam1, "_BUSINESSBATPSTAT_INT");
		}
		else if (iParam0 >= 22194 && iParam0 < 24962)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 22194), false, true, iParam1, "_ARENAWARSPSTAT_INT");
		}
		else if (iParam0 >= 25538 && iParam0 < 26810)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 25538), false, true, iParam1, "_CASINOPSTAT_INT");
		}
		else if (iParam0 >= 27258 && iParam0 < 28098)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 27258), false, true, iParam1, "_CASINOHSTPSTAT_INT");
		}
		else if (iParam0 >= 28483 && iParam0 < 30227)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 28483), false, true, iParam1, "_SU20PSTAT_INT");
		}
		else if (iParam0 >= 30483 && iParam0 < 30515)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 30483), false, true, iParam1, "_HISLANDPSTAT_INT");
		}
		else if (iParam0 >= 30707 && iParam0 < 31707)
		{
			iVar0 = STATS::_GET_NGSTAT_INT_HASH((iParam0 - 30707), false, true, iParam1, "_TUNERPSTAT_INT");
		}
		return iVar0;
	}

	//设置Packed Int
	//Set Packed Int
	static bool set_packed_int(int index, int value)
	{
		int iParam0 = index; // index
		int iParam1 = value; // value

		int iVar0 = 0;
		int iVar1 = 0;
		bool bVar2;

		if (iParam1 < 0)
		{
			iParam1 = 255;
		}
		iVar0 = get_packed_int_hash(iParam0);
		iVar1 = get_packed_int_mask(iParam0);
		bVar2 = STATS::STAT_SET_MASKED_INT(iVar0, iParam1, iVar1, 8, true);
		//LOG_INFO(u8"设置Packed Int值: Value {} | index{}", iParam1, iParam0);
		return bVar2;
	}

	//获取Packed Int
	//Get Packed Int
	static void get_packed_int(int index, int* value)
	{
		int iParam0 = index;
		int& iVar0 = *value;

		iVar0 = 0;
		int iVar1 = get_packed_int_hash(iParam0);
		int iVar2 = get_packed_int_mask(iParam0);
		if (0 != iVar1)
		{
			if (!STATS::STAT_GET_MASKED_INT(iVar1, &iVar0, iVar2, 8, true))
			{
				iVar0 = 0;
			}
		}
		LOG_INFO(u8"获取Packed Int值： Value: {} | index:{}", iVar0, iParam0);
		//return iVar0;
	}

	//批量获取Packed Int
	static void get_mass_packed_int(int min_i, int max_i)
	{
		int value;
		for (auto index = min_i; index <= max_i; index++)
		{
			get_packed_int(index, &value);
		}

	}


	//指定位为1
	//Set Bit
	static void Set_Stat_Bit(const std::string& String_value, int bit)
	{
		int value = 0;
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		const auto stat = rage::joaat(String_value_Complete.c_str());
		STATS::STAT_GET_INT(stat, &value, true);
		//MISC::SET_BIT(&value, bit);
		value |= (1 << bit);
		g_fiber_pool->queue_job([stat, value]
			{
				STATS::STAT_SET_INT(stat, value, true);
			});
	}

	//指定位为0
	//Clear Bit
	static void Clear_Stat_Bit(const std::string& String_value, int bit)
	{
		int value = 0;
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		const auto stat = rage::joaat(String_value_Complete.c_str());
		STATS::STAT_GET_INT(stat, &value, true);
		//MISC::CLEAR_BIT(&value, bit);
		value &= ~(1 << bit);
		g_fiber_pool->queue_job([stat, value]
			{
				STATS::STAT_SET_INT(stat, value, true);
			});
	}

	static void STAT_GET_INT(const std::string& String_value, int* value)
	{
		int& outValue = *value;
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_GET_INT(rage::joaat(String_value_Complete.c_str()), &outValue, true);
	}

	static void STAT_SET_INT(const std::string& String_value, int value)
	{
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_SET_INT(rage::joaat(String_value_Complete.c_str()), value, true);
	}

	static void STAT_SET_BOOL(const std::string& String_value, bool value)
	{
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_SET_BOOL(rage::joaat(String_value_Complete.c_str()), value, true);
	}

	static void STAT_SET_FLOAT(const std::string& String_value, float value)
	{
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_SET_FLOAT(rage::joaat(String_value_Complete.c_str()), value, true);
	}

	static int get_rp_value(int64_t value)
	{
		return *script_global(293361).at(value + 1).as<int64_t*>();
	}

	static void bool_unlocks()
	{
		STAT_SET_BOOL("MPPLY_MELEECHLENGECOMPLETED", true);
		STAT_SET_BOOL("MPPLY_HEADSHOTCHLENGECOMPLETED", true);
		STAT_SET_BOOL("MPPLY_AWD_COMPLET_HEIST_MEM", true);
		STAT_SET_BOOL("MPPLY_AWD_COMPLET_HEIST_1STPER", true);
		STAT_SET_BOOL("MPPLY_AWD_FLEECA_FIN", true);
		STAT_SET_BOOL("MPPLY_AWD_HST_ORDER", true);
		STAT_SET_BOOL("MPPLY_AWD_HST_SAME_TEAM", true);
		STAT_SET_BOOL("MPPLY_AWD_HST_ULT_CHAL", true);
		STAT_SET_BOOL("MPPLY_AWD_HUMANE_FIN", true);
		STAT_SET_BOOL("MPPLY_AWD_PACIFIC_FIN", true);
		STAT_SET_BOOL("MPPLY_AWD_PRISON_FIN", true);
		STAT_SET_BOOL("MPPLY_AWD_SERIESA_FIN", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_IAA", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_SUBMARINE", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_MISSILE", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_SUPPORT", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_LOYALTY2", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_LOYALTY3", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_CRIMMASMD2", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_CRIMMASMD3", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_ALLINORDER", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_LOYALTY", true);
		STAT_SET_BOOL("MPPLY_AWD_GANGOPS_CRIMMASMD", true);
		STAT_SET_BOOL("MPX_AWD_INTELGATHER", true);
		STAT_SET_BOOL("MPX_AWD_COMPOUNDINFILT", true);
		STAT_SET_BOOL("MPX_AWD_LOOT_FINDER", true);
		STAT_SET_BOOL("MPX_AWD_MAX_DISRUPT", true);
		STAT_SET_BOOL("MPX_AWD_THE_ISLAND_HEIST", true);
		STAT_SET_BOOL("MPX_AWD_GOING_ALONE", true);
		STAT_SET_BOOL("MPX_AWD_TEAM_WORK", true);
		STAT_SET_BOOL("MPX_AWD_MIXING_UP", true);
		STAT_SET_BOOL("MPX_AWD_PRO_THIEF", true);
		STAT_SET_BOOL("MPX_AWD_CAT_BURGLAR", true);
		STAT_SET_BOOL("MPX_AWD_ONE_OF_THEM", true);
		STAT_SET_BOOL("MPX_AWD_GOLDEN_GUN", true);
		STAT_SET_BOOL("MPX_AWD_ELITE_THIEF", true);
		STAT_SET_BOOL("MPX_AWD_PROFESSIONAL", true);
		STAT_SET_BOOL("MPX_AWD_HELPING_OUT", true);
		STAT_SET_BOOL("MPX_AWD_COURIER", true);
		STAT_SET_BOOL("MPX_AWD_PARTY_VIBES", true);
		STAT_SET_BOOL("MPX_AWD_HELPING_HAND", true);
		STAT_SET_BOOL("MPX_AWD_ELEVENELEVEN", true);
		STAT_SET_BOOL("MPX_VCM_FLOW_CS_RSC_SEEN", true);
		STAT_SET_BOOL("MPX_VCM_FLOW_CS_BWL_SEEN", true);
		STAT_SET_BOOL("MPX_VCM_FLOW_CS_MTG_SEEN", true);
		STAT_SET_BOOL("MPX_VCM_FLOW_CS_OIL_SEEN", true);
		STAT_SET_BOOL("MPX_VCM_FLOW_CS_DEF_SEEN", true);
		STAT_SET_BOOL("MPX_VCM_FLOW_CS_FIN_SEEN", true);
		STAT_SET_BOOL("MPX_CAS_VEHICLE_REWARD", false);
		STAT_SET_BOOL("MPX_CL_RACE_MODDED_CAR", true);
		STAT_SET_BOOL("MPX_CL_DRIVE_RALLY", true);
		STAT_SET_BOOL("MPX_CL_PLAY_GTA_RACE", true);
		STAT_SET_BOOL("MPX_CL_PLAY_BOAT_RACE", true);
		STAT_SET_BOOL("MPX_CL_PLAY_FOOT_RACE", true);
		STAT_SET_BOOL("MPX_CL_PLAY_TEAM_DM", true);
		STAT_SET_BOOL("MPX_CL_PLAY_VEHICLE_DM", true);
		STAT_SET_BOOL("MPX_CL_PLAY_MISSION_CONTACT", true);
		STAT_SET_BOOL("MPX_CL_PLAY_A_PLAYLIST", true);
		STAT_SET_BOOL("MPX_CL_PLAY_POINT_TO_POINT", true);
		STAT_SET_BOOL("MPX_CL_PLAY_ONE_ON_ONE_DM", true);
		STAT_SET_BOOL("MPX_CL_PLAY_ONE_ON_ONE_RACE", true);
		STAT_SET_BOOL("MPX_CL_SURV_A_BOUNTY", true);
		STAT_SET_BOOL("MPX_CL_SET_WANTED_LVL_ON_PLAY", true);
		STAT_SET_BOOL("MPX_CL_GANG_BACKUP_GANGS", true);
		STAT_SET_BOOL("MPX_CL_GANG_BACKUP_LOST", true);
		STAT_SET_BOOL("MPX_CL_GANG_BACKUP_VAGOS", true);
		STAT_SET_BOOL("MPX_CL_CALL_MERCENARIES", true);
		STAT_SET_BOOL("MPX_CL_PHONE_MECH_DROP_CAR", true);
		STAT_SET_BOOL("MPX_CL_GONE_OFF_RADAR", true);
		STAT_SET_BOOL("MPX_CL_FILL_TITAN", true);
		STAT_SET_BOOL("MPX_CL_MOD_CAR_USING_APP", true);
		STAT_SET_BOOL("MPX_CL_BUY_APPARTMENT", true);
		STAT_SET_BOOL("MPX_CL_BUY_INSURANCE", true);
		STAT_SET_BOOL("MPX_CL_BUY_GARAGE", true);
		STAT_SET_BOOL("MPX_CL_ENTER_FRIENDS_HOUSE", true);
		STAT_SET_BOOL("MPX_CL_CALL_STRIPPER_HOUSE", true);
		STAT_SET_BOOL("MPX_CL_CALL_FRIEND", true);
		STAT_SET_BOOL("MPX_CL_SEND_FRIEND_REQUEST", true);
		STAT_SET_BOOL("MPX_CL_W_WANTED_PLAYER_TV", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_0", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_1", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_2", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_3", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_4", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_5", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_6", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_7", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_8", true);
		STAT_SET_BOOL("MPX_PILOT_ASPASSEDLESSON_9", true);
		STAT_SET_BOOL("MPX_AWD_FIRST_TIME1", true);
		STAT_SET_BOOL("MPX_AWD_FIRST_TIME2", true);
		STAT_SET_BOOL("MPX_AWD_FIRST_TIME3", true);
		STAT_SET_BOOL("MPX_AWD_FIRST_TIME4", true);
		STAT_SET_BOOL("MPX_AWD_FIRST_TIME5", true);
		STAT_SET_BOOL("MPX_AWD_FIRST_TIME6", true);
		STAT_SET_BOOL("MPX_AWD_ALL_IN_ORDER", true);
		STAT_SET_BOOL("MPX_AWD_SUPPORTING_ROLE", true);
		STAT_SET_BOOL("MPX_AWD_ACTIVATE_2_PERSON_KEY", true);
		STAT_SET_BOOL("MPX_AWD_ALL_ROLES_HEIST", true);
		STAT_SET_BOOL("MPX_AWD_LEADER", true);
		STAT_SET_BOOL("MPX_AWD_SURVIVALIST", true);
		STAT_SET_BOOL("MPX_AWD_SCOPEOUT", true);
		STAT_SET_BOOL("MPX_AWD_CREWEDUP", true);
		STAT_SET_BOOL("MPX_AWD_MOVINGON", true);
		STAT_SET_BOOL("MPX_AWD_PROMOCAMP", true);
		STAT_SET_BOOL("MPX_AWD_GUNMAN", true);
		STAT_SET_BOOL("MPX_AWD_SMASHNGRAB", true);
		STAT_SET_BOOL("MPX_AWD_INPLAINSI", true);
		STAT_SET_BOOL("MPX_AWD_UNDETECTED", true);
		STAT_SET_BOOL("MPX_AWD_ALLROUND", true);
		STAT_SET_BOOL("MPX_AWD_ELITETHEIF", true);
		STAT_SET_BOOL("MPX_AWD_PRO", true);
		STAT_SET_BOOL("MPX_AWD_SUPPORTACT", true);
		STAT_SET_BOOL("MPX_AWD_SHAFTED", true);
		STAT_SET_BOOL("MPX_AWD_COLLECTOR", true);
		STAT_SET_BOOL("MPX_AWD_DEADEYE", true);
		STAT_SET_BOOL("MPX_AWD_PISTOLSATDAWN", true);
		STAT_SET_BOOL("MPX_AWD_TRAFFICAVOI", true);
		STAT_SET_BOOL("MPX_AWD_CANTCATCHBRA", true);
		STAT_SET_BOOL("MPX_AWD_WIZHARD", true);
		STAT_SET_BOOL("MPX_AWD_APEESCAPE", true);
		STAT_SET_BOOL("MPX_AWD_MONKEYKIND", true);
		STAT_SET_BOOL("MPX_AWD_AQUAAPE", true);
		STAT_SET_BOOL("MPX_AWD_KEEPFAITH", true);
		STAT_SET_BOOL("MPX_AWD_TRUELOVE", true);
		STAT_SET_BOOL("MPX_AWD_NEMESIS", true);
		STAT_SET_BOOL("MPX_AWD_FRIENDZONED", true);
		STAT_SET_BOOL("MPX_AWD_BUY_EVERY_GUN", true);
		STAT_SET_BOOL("MPX_AWD_DAILYOBJMONTHBONUS", true);
		STAT_SET_BOOL("MPX_AWD_DAILYOBJWEEKBONUS", true);
		STAT_SET_BOOL("MPX_AWD_DRIVELESTERCAR5MINS", true);
		STAT_SET_BOOL("MPX_AWD_FINISH_HEIST_NO_DAMAGE", true);
		STAT_SET_BOOL("MPX_AWD_FM25DIFFERENTDM", true);
		STAT_SET_BOOL("MPX_AWD_FM25DIFFERENTRACES", true);
		STAT_SET_BOOL("MPX_AWD_FM25DIFITEMSCLOTHES", true);
		STAT_SET_BOOL("MPX_AWD_FMFURTHESTWHEELIE", true);
		STAT_SET_BOOL("MPX_AWD_FM6DARTCHKOUT", true);
		STAT_SET_BOOL("MPX_AWD_FM_GOLF_HOLE_IN_1", true);
		STAT_SET_BOOL("MPX_AWD_FM_SHOOTRANG_GRAN_WON", true);
		STAT_SET_BOOL("MPX_AWD_FM_TENNIS_5_SET_WINS", true);
		STAT_SET_BOOL("MPX_AWD_FMATTGANGHQ", true);
		STAT_SET_BOOL("MPX_AWD_FMFULLYMODDEDCAR", true);
		STAT_SET_BOOL("MPX_AWD_FMKILL3ANDWINGTARACE", true);
		STAT_SET_BOOL("MPX_AWD_FMKILLSTREAKSDM", true);
		STAT_SET_BOOL("MPX_AWD_FMMOSTKILLSGANGHIDE", true);
		STAT_SET_BOOL("MPX_AWD_FMMOSTKILLSSURVIVE", true);
		STAT_SET_BOOL("MPX_AWD_FMPICKUPDLCCRATE1ST", true);
		STAT_SET_BOOL("MPX_AWD_FMRACEWORLDRECHOLDER", true);
		STAT_SET_BOOL("MPX_AWD_FMTATTOOALLBODYPARTS", true);
		STAT_SET_BOOL("MPX_AWD_FMWINALLRACEMODES", true);
		STAT_SET_BOOL("MPX_AWD_FMWINCUSTOMRACE", true);
		STAT_SET_BOOL("MPX_AWD_FMWINEVERYGAMEMODE", true);
		STAT_SET_BOOL("MPX_AWD_SPLIT_HEIST_TAKE_EVENLY", true);
		STAT_SET_BOOL("MPX_AWD_STORE_20_CAR_IN_GARAGES", true);
		STAT_SET_BOOL("MPX_SR_TIER_1_REWARD", true);
		STAT_SET_BOOL("MPX_SR_TIER_3_REWARD", true);
		STAT_SET_BOOL("MPX_SR_INCREASE_THROW_CAP", true);
		STAT_SET_BOOL("MPX_AWD_CLUB_COORD", true);
		STAT_SET_BOOL("MPX_AWD_CLUB_HOTSPOT", true);
		STAT_SET_BOOL("MPX_AWD_CLUB_CLUBBER", true);
		STAT_SET_BOOL("MPX_AWD_BEGINNER", true);
		STAT_SET_BOOL("MPX_AWD_FIELD_FILLER", true);
		STAT_SET_BOOL("MPX_AWD_ARMCHAIR_RACER", true);
		STAT_SET_BOOL("MPX_AWD_LEARNER", true);
		STAT_SET_BOOL("MPX_AWD_SUNDAY_DRIVER", true);
		STAT_SET_BOOL("MPX_AWD_THE_ROOKIE", true);
		STAT_SET_BOOL("MPX_AWD_BUMP_AND_RUN", true);
		STAT_SET_BOOL("MPX_AWD_GEAR_HEAD", true);
		STAT_SET_BOOL("MPX_AWD_DOOR_SLAMMER", true);
		STAT_SET_BOOL("MPX_AWD_HOT_LAP", true);
		STAT_SET_BOOL("MPX_AWD_ARENA_AMATEUR", true);
		STAT_SET_BOOL("MPX_AWD_PAINT_TRADER", true);
		STAT_SET_BOOL("MPX_AWD_SHUNTER", true);
		STAT_SET_BOOL("MPX_AWD_JOCK", true);
		STAT_SET_BOOL("MPX_AWD_WARRIOR", true);
		STAT_SET_BOOL("MPX_AWD_T_BONE", true);
		STAT_SET_BOOL("MPX_AWD_MAYHEM", true);
		STAT_SET_BOOL("MPX_AWD_WRECKER", true);
		STAT_SET_BOOL("MPX_AWD_CRASH_COURSE", true);
		STAT_SET_BOOL("MPX_AWD_ARENA_LEGEND", true);
		STAT_SET_BOOL("MPX_AWD_PEGASUS", true);
		STAT_SET_BOOL("MPX_AWD_CONTACT_SPORT", true);
		STAT_SET_BOOL("MPX_AWD_UNSTOPPABLE", true);
		STAT_SET_BOOL("MPX_LOW_FLOW_CS_DRV_SEEN", true);
		STAT_SET_BOOL("MPX_LOW_FLOW_CS_TRA_SEEN", true);
		STAT_SET_BOOL("MPX_LOW_FLOW_CS_FUN_SEEN", true);
		STAT_SET_BOOL("MPX_LOW_FLOW_CS_PHO_SEEN", true);
		STAT_SET_BOOL("MPX_LOW_FLOW_CS_FIN_SEEN", true);
		STAT_SET_BOOL("MPX_LOW_BEN_INTRO_CS_SEEN", true);
		STAT_SET_BOOL("MPX_AWD_SCOPEOUT", true);
		STAT_SET_BOOL("MPX_AWD_CREWEDUP", true);
		STAT_SET_BOOL("MPX_AWD_MOVINGON", true);
		STAT_SET_BOOL("MPX_AWD_PROMOCAMP", true);
		STAT_SET_BOOL("MPX_AWD_GUNMAN", true);
		STAT_SET_BOOL("MPX_AWD_SMASHNGRAB", true);
		STAT_SET_BOOL("MPX_AWD_INPLAINSI", true);
		STAT_SET_BOOL("MPX_AWD_UNDETECTED", true);
		STAT_SET_BOOL("MPX_AWD_ALLROUND", true);
		STAT_SET_BOOL("MPX_AWD_ELITETHEIF", true);
		STAT_SET_BOOL("MPX_AWD_PRO", true);
		STAT_SET_BOOL("MPX_AWD_SUPPORTACT", true);
		STAT_SET_BOOL("MPX_AWD_SHAFTED", true);
		STAT_SET_BOOL("MPX_AWD_COLLECTOR", true);
		STAT_SET_BOOL("MPX_AWD_DEADEYE", true);
		STAT_SET_BOOL("MPX_AWD_PISTOLSATDAWN", true);
		STAT_SET_BOOL("MPX_AWD_TRAFFICAVOI", true);
		STAT_SET_BOOL("MPX_AWD_CANTCATCHBRA", true);
		STAT_SET_BOOL("MPX_AWD_WIZHARD", true);
		STAT_SET_BOOL("MPX_AWD_APEESCAPE", true);
		STAT_SET_BOOL("MPX_AWD_MONKEYKIND", true);
		STAT_SET_BOOL("MPX_AWD_AQUAAPE", true);
		STAT_SET_BOOL("MPX_AWD_KEEPFAITH", true);
		STAT_SET_BOOL("MPX_AWD_TRUELOVE", true);
		STAT_SET_BOOL("MPX_AWD_NEMESIS", true);
		STAT_SET_BOOL("MPX_AWD_FRIENDZONED", true);
		STAT_SET_BOOL("MPX_AWD_INTELGATHER", true);
		STAT_SET_BOOL("MPX_AWD_COMPOUNDINFILT", true);
		STAT_SET_BOOL("MPX_AWD_LOOT_FINDER", true);
		STAT_SET_BOOL("MPX_AWD_MAX_DISRUPT", true);
		STAT_SET_BOOL("MPX_AWD_THE_ISLAND_HEIST", true);
		STAT_SET_BOOL("MPX_AWD_GOING_ALONE", true);
		STAT_SET_BOOL("MPX_AWD_TEAM_WORK", true);
		STAT_SET_BOOL("MPX_AWD_MIXING_UP", true);
		STAT_SET_BOOL("MPX_AWD_PRO_THIEF", true);
		STAT_SET_BOOL("MPX_AWD_CAT_BURGLAR", true);
		STAT_SET_BOOL("MPX_AWD_ONE_OF_THEM", true);
		STAT_SET_BOOL("MPX_AWD_GOLDEN_GUN", true);
		STAT_SET_BOOL("MPX_AWD_ELITE_THIEF", true);
		STAT_SET_BOOL("MPX_AWD_PROFESSIONAL", true);
		STAT_SET_BOOL("MPX_AWD_HELPING_OUT", true);
		STAT_SET_BOOL("MPX_AWD_COURIER", true);
		STAT_SET_BOOL("MPX_AWD_PARTY_VIBES", true);
		STAT_SET_BOOL("MPX_AWD_HELPING_HAND", true);
		STAT_SET_BOOL("MPX_AWD_ELEVENELEVEN", true);
		STAT_SET_BOOL("MPX_COMPLETE_H4_F_USING_VETIR", true);
		STAT_SET_BOOL("MPX_COMPLETE_H4_F_USING_LONGFIN", true);
		STAT_SET_BOOL("MPX_COMPLETE_H4_F_USING_ANNIH", true);
		STAT_SET_BOOL("MPX_COMPLETE_H4_F_USING_ALKONOS", true);
		STAT_SET_BOOL("MPX_COMPLETE_H4_F_USING_PATROLB", true);
		STAT_SET_BOOL("MPX_HELP_FURIA", true);
		STAT_SET_BOOL("MPX_HELP_MINITANK", true);
		STAT_SET_BOOL("MPX_HELP_YOSEMITE2", true);
		STAT_SET_BOOL("MPX_HELP_ZHABA", true);
		STAT_SET_BOOL("MPX_HELP_IMORGEN", true);
		STAT_SET_BOOL("MPX_HELP_SULTAN2", true);
		STAT_SET_BOOL("MPX_HELP_VAGRANT", true);
		STAT_SET_BOOL("MPX_HELP_VSTR", true);
		STAT_SET_BOOL("MPX_HELP_STRYDER", true);
		STAT_SET_BOOL("MPX_HELP_SUGOI", true);
		STAT_SET_BOOL("MPX_HELP_KANJO", true);
		STAT_SET_BOOL("MPX_HELP_FORMULA", true);
		STAT_SET_BOOL("MPX_HELP_FORMULA2", true);
		STAT_SET_BOOL("MPX_HELP_JB7002", true);
		STAT_SET_BOOL("MPX_AWD_STRAIGHT_TO_VIDEO", true);
		STAT_SET_BOOL("MPX_AWD_MONKEY_C_MONKEY_DO", true);
		STAT_SET_BOOL("MPX_AWD_TRAINED_TO_KILL", true);
		STAT_SET_BOOL("MPX_AWD_DIRECTOR", true);
	}

	static void int_unlocks()
	{
		STAT_SET_INT("MPPLY_XMASLIVERIES0", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES1", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES2", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES3", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES4", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES5", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES6", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES7", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES8", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES9", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES10", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES11", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES12", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES13", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES14", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES15", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES16", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES17", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES18", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES19", -1);
		STAT_SET_INT("MPPLY_XMASLIVERIES20", -1);
		STAT_SET_INT("MPPLY_HEIST_ACH_TRACKER", -1);
		STAT_SET_INT("MPPLY_TOTAL_RACES_WON", 50);
		STAT_SET_INT("MPPLY_TOTAL_RACES_LOST", 25);
		STAT_SET_INT("MPPLY_RACES_WON", 50);
		STAT_SET_INT("MPPLY_RACES_LOST", 25);
		STAT_SET_INT("MPX_RACES_WON", 50);
		STAT_SET_INT("MPX_RACES_LOST", 25);
		STAT_SET_INT("MPX_SR_HIGHSCORE_1", 910);
		STAT_SET_INT("MPX_SR_HIGHSCORE_2", 2500);
		STAT_SET_INT("MPX_SR_HIGHSCORE_3", 3440);
		STAT_SET_INT("MPX_SR_HIGHSCORE_4", 3340);
		STAT_SET_INT("MPX_SR_HIGHSCORE_5", 4150);
		STAT_SET_INT("MPX_SR_HIGHSCORE_6", 560);
		STAT_SET_INT("MPX_SR_TARGETS_HIT", 270);
		STAT_SET_INT("MPX_SR_WEAPON_BIT_SET", -1);
		STAT_SET_INT("MPX_YACHT_MISSION_PROG", 0);
		STAT_SET_INT("MPX_YACHT_MISSION_FLOW", 21845);
		STAT_SET_INT("MPX_CASINO_DECORATION_GIFT_1", -1);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_STAM", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_STRN", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_LUNG", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_DRIV", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_FLY", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_SHO", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_STL", 100);
		STAT_SET_INT("MPX_SCRIPT_INCREASE_MECH", 100);
		STAT_SET_INT("MPX_MOLOTOV_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_CMBTPISTOL_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_PISTOL50_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_APPISTOL_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_MICROSMG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_SMG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_ASLTSMG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_ASLTRIFLE_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_CRBNRIFLE_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_ADVRIFLE_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_MG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_CMBTMG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_ASLTMG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_PUMP_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_SAWNOFF_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_BULLPUP_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_ASLTSHTGN_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_SNIPERRFL_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_HVYSNIPER_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_GRNLAUNCH_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_RPG_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_MINIGUNS_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_GRENADE_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_SMKGRENADE_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_STKYBMB_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_MOLOTOV_ENEMY_KILLS", 600);
		STAT_SET_INT("MPX_AWD_WIN_LAST_TEAM_STANDINGS", 50);
		STAT_SET_INT("MPX_AWD_NIGHTVISION_KILLS", 100);
		STAT_SET_INT("MPX_AWD_FINISH_HEIST_SETUP_JOB", 50);
		STAT_SET_INT("MPX_AWD_FINISH_HEISTS", 50);
		STAT_SET_INT("MPX_AWD_KILL_CARRIER_CAPTURE", 100);
		STAT_SET_INT("MPX_AWD_DROPOFF_CAP_PACKAGES", 100);
		STAT_SET_INT("MPX_AWD_WIN_CAPTURES", 50);
		STAT_SET_INT("MPX_NUMBER_SLIPSTREAMS_IN_RACE", 100);
		STAT_SET_INT("MPX_AWD_FM_RACES_FASTEST_LAP", 50);
		STAT_SET_INT("MPX_USJS_COMPLETED", 50);
		STAT_SET_INT("MPX_NUMBER_TURBO_STARTS_IN_RACE", 50);
		STAT_SET_INT("MPX_AWD_FMWINAIRRACE", 1);
		STAT_SET_INT("MPX_AWD_FMWINSEARACE", 1);
		STAT_SET_INT("MPX_AWD_FMRALLYWONNAV", 1);
		STAT_SET_INT("MPX_AWD_FMRALLYWONDRIVE", 1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_7_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_6_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_5_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_4_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_3_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_2_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_1_UNLCK", -1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_9", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_8", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_7", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_6", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_5", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_4", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_3", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_2", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_1", 1);
		STAT_SET_INT("MPX_PILOT_SCHOOL_MEDAL_0", 1);
		STAT_SET_INT("MPX_CHAR_ARMOUR_5_COUNT", 10);
		STAT_SET_INT("MPX_CHAR_ARMOUR_4_COUNT", 10);
		STAT_SET_INT("MPX_CHAR_ARMOUR_3_COUNT", 10);
		STAT_SET_INT("MPX_CHAR_ARMOUR_2_COUNT", 10);
		STAT_SET_INT("MPX_CHAR_ARMOUR_1_COUNT", 10);
		STAT_SET_INT("MPX_CIGARETTES_BOUGHT", 20);
		STAT_SET_INT("MPX_NUMBER_OF_BOURGE_BOUGHT", 10);
		STAT_SET_INT("MPX_NUMBER_OF_ORANGE_BOUGHT", 10);
		STAT_SET_INT("MPX_NO_BOUGHT_EPIC_SNACKS", 5);
		STAT_SET_INT("MPX_NO_BOUGHT_HEALTH_SNACKS", 15);
		STAT_SET_INT("MPX_NO_BOUGHT_YUM_SNACKS", 30);
		STAT_SET_INT("MPX_AWD_CLUB_DRUNK", 100);
		STAT_SET_INT("MPX_AWD_DANCE_TO_BLKMAD", 100);
		STAT_SET_INT("MPX_AWD_DANCE_TO_DIXON", 100);
		STAT_SET_INT("MPX_AWD_DANCE_TO_TALEOFUS", 100);
		STAT_SET_INT("MPX_AWD_DANCE_TO_SOLOMUN", 100);
		STAT_SET_INT("MPX_AWD_ONLY_PLAYER_ALIVE_LTS", 50);
		STAT_SET_INT("MPX_AWD_WIN_LAST_TEAM_STANDINGS", 50);
		STAT_SET_INT("MPX_AWD_NIGHTVISION_KILLS", 100);
		STAT_SET_INT("MPX_AWD_FINISH_HEIST_SETUP_JOB", 50);
		STAT_SET_INT("MPX_AWD_FINISH_HEISTS", 50);
		STAT_SET_INT("MPX_AWD_KILL_CARRIER_CAPTURE", 100);
		STAT_SET_INT("MPX_AWD_DROPOFF_CAP_PACKAGES", 100);
		STAT_SET_INT("MPX_AWD_WIN_CAPTURES", 50);
		STAT_SET_INT("MPX_NUMBER_SLIPSTREAMS_IN_RACE", 100);
		STAT_SET_INT("MPX_AWD_FM_RACES_FASTEST_LAP", 50);
		STAT_SET_INT("MPX_USJS_COMPLETED", 50);
		STAT_SET_INT("MPX_NUMBER_TURBO_STARTS_IN_RACE", 50);
		STAT_SET_INT("MPX_AWD_FMWINAIRRACE", 1);
		STAT_SET_INT("MPX_AWD_FMWINSEARACE", 1);
		STAT_SET_INT("MPX_AWD_FMRALLYWONNAV", 1);
		STAT_SET_INT("MPX_AWD_FMRALLYWONDRIVE", 1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_7_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_6_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_5_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_4_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_3_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_2_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_1_UNLCK", -1);
		STAT_SET_INT("MPX_USJS_FOUND", 50);
		STAT_SET_INT("MPX_USJS_COMPLETED", 50);
		STAT_SET_INT("MPX_AWD_CONTROL_CROWDS", 25);
		STAT_SET_INT("MPX_AWD_TRADE_IN_YOUR_PROPERTY", 25);
		STAT_SET_INT("MPX_AWD_MENTALSTATE_TO_NORMAL", 25);
		STAT_SET_INT("MPX_AWD_FM_SHOOTRANG_CT_WON", 100);
		STAT_SET_INT("MPX_AWD_FM_SHOOTRANG_RT_WON", 100);
		STAT_SET_INT("MPX_AWD_FM_SHOOTRANG_TG_WON", 100);
		STAT_SET_INT("MPX_AWD_FM_GOLF_WON", 100);
		STAT_SET_INT("MPX_AWD_FM_GOLF_BIRDIES", 100);
		STAT_SET_INT("MPX_AWD_FM_TENNIS_ACE", 100);
		STAT_SET_INT("MPX_AWD_FM_TENNIS_WON", 100);
		STAT_SET_INT("MPX_AWD_FM_DM_STOLENKILL", 100);
		STAT_SET_INT("MPX_AWD_FM_DM_3KILLSAMEGUY", 100);
		STAT_SET_INT("MPX_AWD_FM_DM_TOTALKILLS", 100);
		STAT_SET_INT("MPX_AWD_FM_DM_KILLSTREAK", 100);
		STAT_SET_INT("MPX_AWD_FM_TDM_MVP", 100);
		STAT_SET_INT("MPX_AWD_FM_TDM_WINS", 100);
		STAT_SET_INT("MPX_AWD_FM_DM_WINS", 100);
		STAT_SET_INT("MPX_AWD_FM_RACE_LAST_FIRST", 100);
		STAT_SET_INT("MPX_AWD_FM_RACES_FASTEST_LAP", 100);
		STAT_SET_INT("MPX_AWD_FM_GTA_RACES_WON", 100);
		STAT_SET_INT("MPX_AWD_PREPARATION", 40);
		STAT_SET_INT("MPX_AWD_ASLEEPONJOB", 20);
		STAT_SET_INT("MPX_AWD_DAICASHCRAB", 100000);
		STAT_SET_INT("MPX_AWD_BIGBRO", 40);
		STAT_SET_INT("MPX_AWD_SHARPSHOOTER", 40);
		STAT_SET_INT("MPX_AWD_RACECHAMP", 40);
		STAT_SET_INT("MPX_AWD_BATSWORD", 1000000);
		STAT_SET_INT("MPX_AWD_COINPURSE", 950000);
		STAT_SET_INT("MPX_AWD_ASTROCHIMP", 3000000);
		STAT_SET_INT("MPX_AWD_MASTERFUL", 40000);
		STAT_SET_INT("MPX_AWD_COINPURSE", 950000);
		STAT_SET_INT("MPX_CH_ARC_CAB_CLAW_TROPHY", -1);
		STAT_SET_INT("MPX_CH_ARC_CAB_LOVE_TROPHY", -1);
		STAT_SET_INT("MPX_H3_COMPLETEDPOSIX", 0);
		STAT_SET_INT("MPX_CAS_HEIST_FLOW", -1);
		STAT_SET_INT("MPX_H3OPT_ACCESSPOINTS", -1);
		STAT_SET_INT("MPX_H3OPT_POI", -1);
		STAT_SET_INT("MPX_AWD_LOSTANDFOUND", 500000);
		STAT_SET_INT("MPX_AWD_SUNSET", 1800000);
		STAT_SET_INT("MPX_AWD_TREASURE_HUNTER", 1000000);
		STAT_SET_INT("MPX_AWD_WRECK_DIVING", 1000000);
		STAT_SET_INT("MPX_AWD_KEINEMUSIK", 1800000);
		STAT_SET_INT("MPX_AWD_PALMS_TRAX", 1800000);
		STAT_SET_INT("MPX_AWD_MOODYMANN", 1800000);
		STAT_SET_INT("MPX_AWD_FILL_YOUR_BAGS", 10000000);
		STAT_SET_INT("MPX_AWD_WELL_PREPARED", 50);
		STAT_SET_INT("MPX_H4_PLAYTHROUGH_STATUS", 3);
		STAT_SET_INT("MPX_H4_H4_DJ_MISSIONS", -1);
		STAT_SET_INT("MPX_H4_H4_DJ_MISSIONS_CD", -1);
		STAT_SET_INT("MPX_AWD_ODD_JOBS", 52);
		STAT_SET_INT("MPX_VCM_FLOW_PROGRESS", 1839072);
		STAT_SET_INT("MPX_VCM_STORY_PROGRESS", 0);
		STAT_SET_INT("MPX_GANGOPS_HEIST_STATUS", 9999);
		STAT_SET_INT("MPX_LOWRIDER_FLOW_COMPLETE", 3);
		STAT_SET_INT("MPX_LOW_FLOW_CURRENT_PROG", 9);
		STAT_SET_INT("MPX_LOW_FLOW_CURRENT_CALL", 9);
		// mod sobeit?
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_1_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_2_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_3_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_4_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_5_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_6_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CARMOD_7_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_VEHICLE_1_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_VEHICLE_2_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_ADDON_1_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_ADDON_2_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_ADDON_3_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_ADDON_4_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_ADDON_5_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_UNLOCKED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_WEAP_UNLOCKED2", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_10_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_11_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_12_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_1_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_2_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_3_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_4_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_5_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_6_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_7_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_8_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_9_FM_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE10", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE11", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE12", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE2", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE3", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE4", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE5", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE6", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE7", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE8", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_KIT_FM_PURCHASE9", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_0", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_1", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_2", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_3", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_4", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_5", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_6", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_7", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_8", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_9", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_10", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_11", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_12", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_13", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_14", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_15", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_16", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_17", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_18", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_19", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_20", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_21", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_22", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_23", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_24", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_25", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_26", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_27", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_28", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_29", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_30", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_31", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_32", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_33", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_34", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_35", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_36", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_37", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_38", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_39", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_40", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_41", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_42", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_43", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_44", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_45", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_46", 0xFFFFFFFF);
		STAT_SET_INT("MPX_TATTOO_FM_UNLOCKS_47", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_1_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_2_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_3_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_4_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_5_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_6_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_7_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_8_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_9_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_10_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_11_UNLCK", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_1_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_2_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_3_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_4_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_5_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_6_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_7_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_8_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_9_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_10_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_CHAR_FM_CLOTHES_11_OWNED", 0xFFFFFFFF);
		STAT_SET_INT("MPX_SCGW_NUM_WINS_GANG_0", 50);
		STAT_SET_INT("MPX_SCGW_NUM_WINS_GANG_1", 50);
		STAT_SET_INT("MPX_SCGW_NUM_WINS_GANG_2", 50);
		STAT_SET_INT("MPX_SCGW_NUM_WINS_GANG_3", 50);
		STAT_SET_INT("MPX_AWD_FACES_OF_DEATH", 50);
		STAT_SET_INT("MPX_CHAR_FM_HEALTH_1_UNLCK", -1);
		STAT_SET_INT("MPX_CHAR_FM_HEALTH_2_UNLCK", -1);
		STAT_SET_INT("MPX_CRDEADLINE", 5);
	}


	static void magic()
	{
		QUEUE_JOB_BEGIN_CLAUSE()
		{
			helper::bool_unlocks();
			helper::int_unlocks();
			helper::set_packed_int(22058, 20);
		} QUEUE_JOB_END_CLAUSE

			QUEUE_JOB_BEGIN_CLAUSE()
		{
			helper::set_mass_packed_bool(1, 0, 192);
			helper::set_mass_packed_bool(1, 513, 705);
			helper::set_mass_packed_bool(1, 2919, 3111);
			helper::set_mass_packed_bool(1, 3111, 3879);
			helper::set_mass_packed_bool(1, 4207, 4399);
			helper::set_mass_packed_bool(1, 6029, 6413);
			helper::set_mass_packed_bool(1, 7385, 7641);
			helper::set_mass_packed_bool(1, 9361, 9553);
			helper::set_mass_packed_bool(1, 15369, 15561);
			helper::set_mass_packed_bool(1, 15562, 15946);
			helper::set_mass_packed_bool(1, 15946, 16010);
			helper::set_mass_packed_bool(1, 18098, 18162);
			helper::set_mass_packed_bool(1, 22066, 22194);
			helper::set_mass_packed_bool(1, 24962, 25538);
			helper::set_mass_packed_bool(1, 26810, 27258);
			helper::set_mass_packed_bool(1, 28098, 28354);
			helper::set_mass_packed_bool(1, 28355, 28483);
			helper::set_mass_packed_bool(1, 30227, 30355);
			helper::set_mass_packed_bool(1, 30355, 30483);
			helper::set_mass_packed_bool(1, 30515, 30707);
			helper::set_mass_packed_bool(1, 31707, 32283);
		} QUEUE_JOB_END_CLAUSE

			QUEUE_JOB_BEGIN_CLAUSE()
		{
			helper::set_packed_bool(7387, 0);
			helper::set_packed_bool(7388, 0);
			helper::set_packed_bool(7389, 0);
			helper::set_packed_bool(7390, 0);
			helper::set_packed_bool(7391, 0);
			helper::set_packed_bool(7392, 0);
			helper::set_packed_bool(7393, 0);
			helper::set_packed_bool(7394, 0);
			helper::set_packed_bool(7395, 0);
			helper::set_packed_bool(7396, 0);
			helper::set_packed_bool(7397, 0);
			helper::set_packed_bool(7398, 0);
			helper::set_packed_bool(7399, 0);
			helper::set_packed_bool(7400, 0);
			helper::set_packed_bool(7401, 0);
			helper::set_packed_bool(7402, 0);
			helper::set_packed_bool(7403, 0);
			helper::set_packed_bool(7404, 0);
			helper::set_packed_bool(7405, 0);
			helper::set_packed_bool(7406, 0);
			helper::set_packed_bool(7407, 0);
			helper::set_packed_bool(7408, 0);
			helper::set_packed_bool(7409, 0);
			helper::set_packed_bool(7410, 0);
			helper::set_packed_bool(7411, 0);
			helper::set_packed_bool(7412, 0);
			helper::set_packed_bool(7413, 0);
			helper::set_packed_bool(7414, 0);
			helper::set_packed_bool(7415, 0);
			helper::set_packed_bool(7416, 0);
			helper::set_packed_bool(7417, 0);
			helper::set_packed_bool(7418, 0);
			helper::set_packed_bool(7419, 0);
			helper::set_packed_bool(7420, 0);
			helper::set_packed_bool(7421, 0);
			helper::set_packed_bool(7422, 0);
			helper::set_packed_bool(7423, 0);
			helper::set_packed_bool(7424, 0);
			helper::set_packed_bool(7425, 0);
			helper::set_packed_bool(7426, 0);
			helper::set_packed_bool(7427, 0);
			helper::set_packed_bool(7428, 0);
			helper::set_packed_bool(7429, 0);
			helper::set_packed_bool(7430, 0);
			helper::set_packed_bool(7431, 0);
			helper::set_packed_bool(7432, 0);
			helper::set_packed_bool(7433, 0);
			helper::set_packed_bool(7434, 0);
			helper::set_packed_bool(7435, 0);
			helper::set_packed_bool(7436, 0);
			helper::set_packed_bool(7437, 0);
			helper::set_packed_bool(7438, 0);
			helper::set_packed_bool(7439, 0);
			helper::set_packed_bool(7440, 0);
			helper::set_packed_bool(7441, 0);
			helper::set_packed_bool(7442, 0);
			helper::set_packed_bool(7443, 0);
			helper::set_packed_bool(7444, 0);
			helper::set_packed_bool(7445, 0);
			helper::set_packed_bool(7446, 0);
			helper::set_packed_bool(7447, 0);
			helper::set_packed_bool(7448, 0);
			helper::set_packed_bool(7449, 0);
			helper::set_packed_bool(7466, 0);
			helper::set_packed_bool(7621, 0);
			helper::set_packed_bool(7622, 0);
			helper::set_packed_bool(7623, 0);
			helper::set_packed_bool(7624, 0);
			helper::set_packed_bool(7625, 0);
			helper::set_packed_bool(7626, 0);
			helper::set_packed_bool(7627, 0);
			helper::set_packed_bool(15441, 0);
			helper::set_packed_bool(15442, 0);
			helper::set_packed_bool(15443, 0);
			helper::set_packed_bool(15444, 0);
			helper::set_packed_bool(15445, 0);
			helper::set_packed_bool(15446, 0);
			helper::set_packed_bool(18100, 0);
			helper::set_packed_bool(18101, 0);
			helper::set_packed_bool(18102, 0);
			helper::set_packed_bool(18103, 0);
			helper::set_packed_bool(18104, 0);
			helper::set_packed_bool(18105, 0);
			helper::set_packed_bool(15995, 0);
			helper::set_packed_bool(15548, 0);
			helper::set_packed_bool(25241, 0);
			helper::set_packed_bool(25242, 0);
			helper::set_packed_bool(25243, 0);
			helper::set_packed_bool(25518, 0);
			helper::set_packed_bool(25519, 0);
			helper::set_packed_bool(30321, 0);
			helper::set_packed_bool(30322, 0);
			helper::set_packed_bool(30323, 0);
			helper::set_packed_bool(7386, 0);
		} QUEUE_JOB_END_CLAUSE
	}
}