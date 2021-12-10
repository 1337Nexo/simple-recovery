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


	//Set Bit
	static void Set_Stat_Bit(const std::string String_value, int bit)
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

	//Clear Bit
	static void Clear_Stat_Bit(const std::string String_value, int bit)
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

	static void STAT_GET_INT(const std::string String_value, int* value)
	{
		int& outValue = *value;
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_GET_INT(rage::joaat(String_value_Complete.c_str()), &outValue, true);
	}

	static void STAT_SET_INT(const std::string String_value, int value)
	{
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_SET_INT(rage::joaat(String_value_Complete.c_str()), value, true);
	}

	static void STAT_SET_BOOL(const std::string String_value, bool value)
	{
		std::string character_index = "MP" + std::to_string(g_local_player.character_index);
		std::string String_value_Complete = std::regex_replace(String_value, std::regex(R"(\MPX)"), character_index);
		STATS::STAT_SET_BOOL(rage::joaat(String_value_Complete.c_str()), value, true);
	}

	static void STAT_SET_FLOAT(const std::string String_value, float value)
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

	static void Other()
	{
		QUEUE_JOB_BEGIN_CLAUSE()
		{
			*script_global(262145 + 27380).as<int64_t*>() = 1;//Lucky 7s -- (197291252)
			*script_global(262145 + 27387).as<int64_t*>() = 1;//Royals-- (-437644925)

			//Valentine Unlocks 1.57:
			*script_global(262145 + 6770).as<int64_t*>() = 1; // "TURN_ON_VALENTINES_EVENT"
			*script_global(262145 + 11733).as<int64_t*>() = 1;// "TURN_ON_VALENTINE_WEAPON"
			*script_global(262145 + 11734).as<int64_t*>() = 1;//"TURN_ON_VALENTINE_VEHICLE"
			*script_global(262145 + 11735).as<int64_t*>() = 1; // "TURN_ON_VALENTINE_MASKS"
			*script_global(262145 + 11736).as<int64_t*>() = 1; //"TURN_ON_VALENTINE_HAIR"
			*script_global(262145 + 11737).as<int64_t*>() = 1; // "TURN_ON_VALENTINE_CLOTHING"
			*script_global(262145 + 13099).as<int64_t*>() = 1; // "TURN_ON_VALENTINE_2016_CLOTHING"
			*script_global(262145 + 13100).as<int64_t*>() = 1; //"TURN_ON_VALENTINE_2016_VEHICLE"
			//Independance Day Unlocks 1.57:
			*script_global(262145 + 7965).as<int64_t*>() = 1; //"toggle_activate_independence_pack"
			*script_global(262145 + 7970).as<int64_t*>() = 1; //"INDEPENDENCE_DAY_FIREWORKS_TYPE_1"
			*script_global(262145 + 7971).as<int64_t*>() = 1; //"INDEPENDENCE_DAY_FIREWORKS_TYPE_2"
			*script_global(262145 + 7972).as<int64_t*>() = 1; //"INDEPENDENCE_DAY_FIREWORKS_TYPE_3"
			*script_global(262145 + 7973).as<int64_t*>() = 1; //"INDEPENDENCE_DAY_FIREWORKS_TYPE_4"
			*script_global(262145 + 7974).as<int64_t*>() = 1; //"independence_day_deactivate_fireworks_launcher"
			*script_global(262145 + 7975).as<int64_t*>() = 1; //"independence_day_deactivate_placed_fireworks"
			*script_global(262145 + 7978).as<int64_t*>() = 1; //"DISABLEFIREWORKS"
			*script_global(262145 + 7979).as<int64_t*>() = 1; //"Toggle_activate_Western_sovereign"
			*script_global(262145 + 7980).as<int64_t*>() = 1; //"Toggle_activate_Monster_truck"
			*script_global(262145 + 7981).as<int64_t*>() = 1; //"CLOTHING_INDEPENDENCEDAY_GROUP"
			*script_global(262145 + 7982).as<int64_t*>() = 1; //"HAIR_MAKEUP_INDEPENDENCEDAY_GROUP"
			*script_global(262145 + 7983).as<int64_t*>() = 1; //"MASKS_INDEPENDENCEDAY_MASKS_GROUP"
			*script_global(262145 + 7984).as<int64_t*>() = 1; //"vehicle_independenceday_monster"
			*script_global(262145 + 7985).as<int64_t*>() = 1; //"vehicle_independenceday_sovereign"
			*script_global(262145 + 7986).as<int64_t*>() = 1; //"vehiclekit_independenceday_patriot_tire_smoke"
			*script_global(262145 + 7987).as<int64_t*>() = 1; //"vehiclekit_independenceday_horn_1"
			*script_global(262145 + 7988).as<int64_t*>() = 1; //"vehiclekit_independenceday_horn_2"
			*script_global(262145 + 7989).as<int64_t*>() = 1; //"vehiclekit_independenceday_horn_3"
			*script_global(262145 + 7990).as<int64_t*>() = 1; //"vehiclekit_independenceday_horn_4"
			*script_global(262145 + 7991).as<int64_t*>() = 1; //"weapons_independenceday_musket"
			*script_global(262145 + 7992).as<int64_t*>() = 1; //"weapons_independenceday_musket_ammo"
			*script_global(262145 + 7993).as<int64_t*>() = 1; //"weapons_independenceday_fireworklauncher"
			*script_global(262145 + 7994).as<int64_t*>() = 1; //"weapons_independenceday_fireworklauncher_ammo"
			*script_global(262145 + 7995).as<int64_t*>() = 1; //"weapons_independenceday_patriot_parachute_smoke"

			*script_global(262145 + 8003).as<int64_t*>() = 1; //"Pisswasser" Beer Hat"
			*script_global(262145 + 8004).as<int64_t*>() = 1; //"Benedict" Beer Hat
			*script_global(262145 + 8005).as<int64_t*>() = 1; //"J Lager" Beer Hat
			*script_global(262145 + 8006).as<int64_t*>() = 1; //"Patriot" Beer Hat
			*script_global(262145 + 8007).as<int64_t*>() = 1; //"Blarneys" Beer Hat
			*script_global(262145 + 8008).as<int64_t*>() = 1; //"Supa Wet" Beer Hat
			*script_global(262145 + 8009).as<int64_t*>() = 1; //"Statue of Happiness T-shirt"
			//------------------------------------------------------------------
			*script_global(262145 + 12266).as<int64_t*>() = 1; //"HALLOWEEN_2015_BRUNETTE_CORPSE_BRIDE_BOBBLEHEAD"
			*script_global(262145 + 12267).as<int64_t*>() = 1; //"HALLOWEEN_2015_WHITE_CORPSE_BRIDE_BOBBLEHEAD"
			*script_global(262145 + 12268).as<int64_t*>() = 1; //"HALLOWEEN_2015_PINK_CORPSE_BRIDE_BOBBLEHEAD"
			*script_global(262145 + 12269).as<int64_t*>() = 1; //"HALLOWEEN_2015_WHITE_MASK_SLASHER_BOBBLEHEAD"
			*script_global(262145 + 12270).as<int64_t*>() = 1; //"HALLOWEEN_2015_RED_MASK_SLASHER_BOBBLEHEAD"
			*script_global(262145 + 12271).as<int64_t*>() = 1; //"HALLOWEEN_2015_YELLOW_MASK_SLASHER_BOBBLEHEAD"
			*script_global(262145 + 12272).as<int64_t*>() = 1; //"HALLOWEEN_2015_BLUE_ZOMBIE_BOBBLEHEAD"
			*script_global(262145 + 12273).as<int64_t*>() = 1; //"HALLOWEEN_2015_GREEN_ZOMBIE_BOBBLEHEAD"
			*script_global(262145 + 12274).as<int64_t*>() = 1; //"HALLOWEEN_2015_PALE_ZOMBIE_BOBBLEHEAD"
			*script_global(262145 + 12275).as<int64_t*>() = 1; //"HALLOWEEN_2015_POSSESSED_URCHIN_BOBBLEHEAD"
			*script_global(262145 + 12276).as<int64_t*>() = 1; //"HALLOWEEN_2015_DEMONIC_URCHIN_BOBBLEHEAD"
			*script_global(262145 + 12277).as<int64_t*>() = 1; //"HALLOWEEN_2015_GRUESOME_URCHIN_BOBBLEHEAD"
			*script_global(262145 + 12278).as<int64_t*>() = 1; //"HALLOWEEN_2015_TUXEDO_FRANK_BOBBLEHEAD"
			*script_global(262145 + 12279).as<int64_t*>() = 1; //"HALLOWEEN_2015_PURPLE_SUIT_FRANK_BOBBLEHEAD"
			*script_global(262145 + 12280).as<int64_t*>() = 1; //"HALLOWEEN_2015_STRIPED_SUIT_FRANK_BOBBLEHEAD"
			*script_global(262145 + 12281).as<int64_t*>() = 1; //"HALLOWEEN_2015_BLACK_MUMMY_BOBBLEHEAD"
			*script_global(262145 + 12282).as<int64_t*>() = 1; //"HALLOWEEN_2015_WHITE_MUMMY_BOBBLEHEAD"
			*script_global(262145 + 12283).as<int64_t*>() = 1; //"HALLOWEEN_2015_BROWN_MUMMY_BOBBLEHEAD"
			*script_global(262145 + 12284).as<int64_t*>() = 1; //"HALLOWEEN_2015_PALE_WEREWOLF_BOBBLEHEAD"
			*script_global(262145 + 12285).as<int64_t*>() = 1; //"HALLOWEEN_2015_DARK_WEREWOLF_BOBBLEHEAD"
			*script_global(262145 + 12286).as<int64_t*>() = 1; //"HALLOWEEN_2015_GREY_WEREWOLF_BOBBLEHEAD"
			*script_global(262145 + 12287).as<int64_t*>() = 1; //"HALLOWEEN_2015_FLESHY_VAMPIRE_BOBBLEHEAD"
			//Halloween Unlocks 1.57:
			*script_global(262145 + 11699).as<int64_t*>() = 1; // "turn_on_halloween_event"
			*script_global(262145 + 11739).as<int64_t*>() = 1; // "enable_heist_masks_halloween"
			*script_global(262145 + 11744).as<int64_t*>() = 1; // "turn_on_halloween_vehicles"
			*script_global(262145 + 11745).as<int64_t*>() = 1; // "turn_on_halloween_masks"
			*script_global(262145 + 11746).as<int64_t*>() = 1; // "turn_on_halloween_facepaint"
			*script_global(262145 + 11748).as<int64_t*>() = 1; // "turn_on_halloween_bobbleheads"
			*script_global(262145 + 11754).as<int64_t*>() = 1; // "turn_on_halloween_clothing"
			*script_global(262145 + 11755).as<int64_t*>() = 1; // "turn_on_halloween_weapons"
			*script_global(262145 + 11756).as<int64_t*>() = 1; // "turn_on_halloween_horns"
			*script_global(262145 + 11762).as<int64_t*>() = 1; // "TURN_ON_HALLOWEEN_ANIMS"
			*script_global(262145 + 12405).as<int64_t*>() = 1; // "TURN_ON_HALLOWEEN_SOUNDS"
			*script_global(262145 + 17200).as<int64_t*>() = 1; // "enable_biker_sanctus"
			//X - Mas 201x - 2020 Unlocks 1.57:
			*script_global(262145 + 4724).as<int64_t*>() = 1;// Turn On Snow
			*script_global(262145 + 4735).as<int64_t*>() = 1;// Toggle xmas content
			*script_global(262145 + 8891).as<int64_t*>() = 1;// exclusive stocking mask, firework launcher, etc.
			/*----------------------------------------------------------------------*/
			*script_global(262145 + 9098).as<int64_t*>() = 1;//  "disable_snowballs"
			*script_global(262145 + 9099).as<int64_t*>() = 1;//  "DISABLE_CHRISTMAS_TREE_PERISHING_SQUARE_SNOW"
			*script_global(262145 + 9100).as<int64_t*>() = 1;//  "DISABLE_CHRISTMAS_TREE_PERISHING_SQUARE"
			*script_global(262145 + 9101).as<int64_t*>() = 1;//  "DISABLE_CHRISTMAS_TREE_APARTMENT"
			*script_global(262145 + 9102).as<int64_t*>() = 1;//  "disable_christmas_clothing"
			*script_global(262145 + 9103).as<int64_t*>() = 1;//  "disable_christmas_masks"
			*script_global(262145 + 9104).as<int64_t*>() = 1;//  "disable_christmas_vehicles"
			*script_global(262145 + 9106).as<int64_t*>() = 1;//  "max_number_of_snowballs
			*script_global(262145 + 9107).as<int64_t*>() = 1;//  "pick_up_number_of_snowballs"
			//----------------------------------------------------------------------
			*script_global(262145 + 9108).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_DINKA_JESTER_RACECAR 
			*script_global(262145 + 9109).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_DEWBAUCHEE_MASSACRO_RACECAR
			*script_global(262145 + 9110).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_RAT_TRUCK
			*script_global(262145 + 9111).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_SLAMVAN
			*script_global(262145 + 9112).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_BRAVADO_SPRUNK_BUFFALO
			*script_global(262145 + 9113).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_VAPID_PISSWASSER_DOMINATOR
			*script_global(262145 + 9114).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_BRAVADO_REDWOOD_GAUNTLET
			*script_global(262145 + 9115).as<int64_t*>() = 1;//  "VEHICLE_XMAS14_DECLASSE_BURGER_SHOT_STALLION
		//----------------------------------------------------------------------
			*script_global(262145 + 9116).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_HOMING_LAUNCHER
			*script_global(262145 + 9117).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_HOMING_LAUNCHER_AMMO
			*script_global(262145 + 9118).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_PROXIMITY_MINE
			*script_global(262145 + 9119).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_BLACK_COMBAT_CHUTE_BAG
			*script_global(262145 + 9120).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_GRAY_COMBAT_CHUTE_BAG
			*script_global(262145 + 9121).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_CHARCOAL_COMBAT_CHUTE_BAG
			*script_global(262145 + 9122).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_TAN_COMBAT_CHUTE_BAG
			*script_global(262145 + 9123).as<int64_t*>() = 1;//  "WEAPONS_XMAS14_FOREST_COMBAT_CHUTE_BAG
			//----------------------------------------------------------------------
			*script_global(262145 + 9124).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SKULL_RIDER
			*script_global(262145 + 9125).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SPIDER_OUTLINE
			*script_global(262145 + 9126).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SPIDER_COLOR
			*script_global(262145 + 9127).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SNAKE_OUTLINE 
			*script_global(262145 + 9128).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SNAKE_SHADED
			*script_global(262145 + 9129).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_CARP_OUTLINE
			*script_global(262145 + 9130).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_CARP_SHADED
			*script_global(262145 + 9131).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_LOS_MUERTOS
			*script_global(262145 + 9132).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_DEATH_BEFORE_DISHONOR
			*script_global(262145 + 9133).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_TIME_TO_DIE
			*script_global(262145 + 9134).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_ELECTRIC_SNAKE
			*script_global(262145 + 9135).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_ROARING_TIGER
			*script_global(262145 + 9136).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_8_BALL_SKULL
			*script_global(262145 + 9137).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_LIZARD
			*script_global(262145 + 9138).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_FLORAL_DAGGER
			*script_global(262145 + 9139).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_JAPANESE_WARRIOR
			*script_global(262145 + 9140).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_LOOSE_LIPS_OUTLINE
			*script_global(262145 + 9141).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_LOOSE_LIPS_COLOR
			*script_global(262145 + 9142).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_ROYAL_DAGGER_OUTLINE
			*script_global(262145 + 9143).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_ROYAL_DAGGER_COLOR
			*script_global(262145 + 9144).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_TIMES_UP_OUTLINE
			*script_global(262145 + 9145).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_TIMES_UP_COLOR
			*script_global(262145 + 9146).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_YOURE_NEXT_OUTLINE
			*script_global(262145 + 9147).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_YOURE_NEXT_COLOR
			*script_global(262145 + 9148).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SNAKE_HEAD_OUTLINE
			*script_global(262145 + 9149).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_SNAKE_HEAD_COLOR
			*script_global(262145 + 9150).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_FUCK_LUCK_OUTLINE
			*script_global(262145 + 9151).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_FUCK_LUCK_COLOR
			*script_global(262145 + 9152).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_EXECUTIONER
			*script_global(262145 + 9153).as<int64_t*>() = 1;//  "TATTOOS_XMAS14_BEAUTIFUL_DEATH
			//Bodysuits:
			*script_global(262145 + 23087).as<int64_t*>() = 1;// Bodysuit Green
			*script_global(262145 + 23088).as<int64_t*>() = 1;// Bodysuit Orange
			*script_global(262145 + 23089).as<int64_t*>() = 1;// Bodysuit Blue
			*script_global(262145 + 23090).as<int64_t*>() = 1;// Bodysuit Pink
			*script_global(262145 + 23091).as<int64_t*>() = 1;// Bodysuit Yellow
			//Free items :
			*script_global(262145 + 25333).as<int64_t*>() = 1;// Free Vapid Clique with Merry Cliquemas
			*script_global(262145 + 25334).as<int64_t*>() = 1;// Free Nagasaki Buzzard Attack Chopper
			*script_global(262145 + 25335).as<int64_t*>() = 1;// Free HVY Insurgent Pick - Up
			//Other gifts, items:
			*script_global(262145 + 9154).as<int64_t*>() = 1;// christmas_eve_gift: firework launcher + 5 fireworks
			*script_global(262145 + 9155).as<int64_t*>() = 1;// new_years_eve_gift: firework launcher + 5 fireworks
			*script_global(262145 + 9156).as<int64_t*>() = 1;// new_years_day_gift: firework launcher + 5 fireworks
			*script_global(262145 + 12413).as<int64_t*>() = 1;//  "XMAS2015_VEHICLE"
			*script_global(262145 + 23092).as<int64_t*>() = 1;// full armor(holiday)
			*script_global(262145 + 23093).as<int64_t*>() = 1;// full sticky bombs(holiday)
			*script_global(262145 + 23094).as<int64_t*>() = 1;// full snacks(holiday)
			*script_global(262145 + 23095).as<int64_t*>() = 1;// full ammo(holiday)
			*script_global(262145 + 23883).as<int64_t*>() = 1;// idk what is this (-1029230616)
			//Christmas clothing :
			*script_global(262145 + 12414).as<int64_t*>() = 1;// Festive masks(2015)
			*script_global(262145 + 12416).as<int64_t*>() = 1;// Festive Pajamas(2015)
			*script_global(262145 + 18963).as<int64_t*>() = 1;//  "christmas2016_clothing"
			*script_global(262145 + 22736).as<int64_t*>() = 1;//  "christmas2017_clothing"
			//2015:
			*script_global(262145 + 12519).as<int64_t*>() = 1;//  2015_christmas_eve_gift: fireworks launcher, fireworks
			*script_global(262145 + 12520).as<int64_t*>() = 1;//  2015_new_years_eve_gift: fireworks launcher, fireworks
			*script_global(262145 + 12521).as<int64_t*>() = 1;//  2015_new_years_day_gift: fireworks launcher, fireworks
			*script_global(262145 + 12522).as<int64_t*>() = 1;//  2015_christmas_day_gift: abominable snowman mask, set of pajamas, naughty cap, etc
			//2016 :
			*script_global(262145 + 18822).as<int64_t*>() = 1;//  2016_christmas_eve_gift
			*script_global(262145 + 18823).as<int64_t*>() = 1;//  2016_new_years_eve_gift
			*script_global(262145 + 18824).as<int64_t*>() = 1;//  2016_new_years_day_gift
			*script_global(262145 + 18825).as<int64_t*>() = 1;//  2016_christmas_day_gift
			//2017
			*script_global(262145 + 23113).as<int64_t*>() = 1;//  2017 christmas eve gift : odious krampus mask, black ammu - nation hoodie, etc.
			*script_global(262145 + 23114).as<int64_t*>() = 1;//  2017_new_years_eve_gift: hideous krampus mask, vivisection t - shirt, etc.
			*script_global(262145 + 23115).as<int64_t*>() = 1;//  2017_new_years_day_gift: fearsome krampus mask, fake dix white t - shirt, etc.
			*script_global(262145 + 23116).as<int64_t*>() = 1;//  2017_christmas_day_gift: heinous krampus mask, one free albany hermes, etc.
		//2018
			*script_global(262145 + 25337).as<int64_t*>() = 1;//  2018_christmas_eve_gift: black & white bones festive sweater, firework launcher, etc.
			*script_global(262145 + 25338).as<int64_t*>() = 1;//  2018_new_years_eve_gift: black & red bones festive sweater, one free hvy insurgent pick - up, etc.
			*script_global(262145 + 25339).as<int64_t*>() = 1;//  2018_new_years_day_gift: red bones festive sweater, firework launcher, etc.
			*script_global(262145 + 25340).as<int64_t*>() = 1;//  2018_christmas_day_gift: slasher festive sweater, one free vapid clique, up - n - atomizer, etc.
			//2019 :				
			*script_global(262145 + 28188).as<int64_t*>() = 1;//  2019_christmas_eve_gift: green reindeer lights bodysuit, firework launcher, etc.
			*script_global(262145 + 28189).as<int64_t*>() = 1;//  2019_new_years_eve_gift: yellow reindeer lights bodysuit, firework launcher, etc.
			*script_global(262145 + 28190).as<int64_t*>() = 1;//  2019_new_years_day_gift: neon festive lights bodysuit, firework launcher, etc.
			*script_global(262145 + 28191).as<int64_t*>() = 1;//  2019_christmas_day_gift: minigun sweater, festive lights bodysuit, firework launcher, etc.
			//2020 :
			*script_global(262145 + 30381).as<int64_t*>() = 1;//  2020_christmas_eve_gift: vibrant stitch emissive mask, firework launcher, etc.
			//Unlock Caps:
			*script_global(262145 + 20815).as<int64_t*>() = 1;// BLACK_AMMUNATION_CAP
			*script_global(262145 + 20818).as<int64_t*>() = 1;// BLACK_COIL_CAP
			*script_global(262145 + 20824).as<int64_t*>() = 1;// BLACK_VOM_FEUER_CAP
			*script_global(262145 + 20827).as<int64_t*>() = 1;// RED_HAWK_AND_LITTLE_CAP
			*script_global(262145 + 20828).as<int64_t*>() = 1;// WARSTOCK_CAP
			*script_global(262145 + 20835).as<int64_t*>() = 1;// WHITE_SHREWSBURY_CAP
			*script_global(262145 + 20838).as<int64_t*>() = 1;// WHITE_VOM_FEUER_CAP
			*script_global(262145 + 20840).as<int64_t*>() = 1;// WINE_COIL_CAP
			//Unlock Hats :
			*script_global(262145 + 12294).as<int64_t*>() = 1;//  "Magnetics Script Hat"
			*script_global(262145 + 12295).as<int64_t*>() = 1;//  "Magnetics Block Hat"
			*script_global(262145 + 12296).as<int64_t*>() = 1;//  "Los Santos Hat"
			*script_global(262145 + 12297).as<int64_t*>() = 1;//  "Boars Hat"
			*script_global(262145 + 12298).as<int64_t*>() = 1;//  "Benny's Hat"
			*script_global(262145 + 12299).as<int64_t*>() = 1;//  "Westside Hat"
			*script_global(262145 + 12300).as<int64_t*>() = 1;//  "Eastside Hat"
			*script_global(262145 + 12301).as<int64_t*>() = 1;//  "Strawberry Hat"
			*script_global(262145 + 12302).as<int64_t*>() = 1;//  "S.A. Hat"
			*script_global(262145 + 12303).as<int64_t*>() = 1;//  "Davis Hat"
			//Brands Shirts :
			*script_global(262145 + 14885).as<int64_t*>() = 1;//  "Accountant Shirt"
			*script_global(262145 + 14886).as<int64_t*>() = 1;//  "Bahamamamas Shirt"
			*script_global(262145 + 14887).as<int64_t*>() = 1;//  "Drone Shirt"
			*script_global(262145 + 14889).as<int64_t*>() = 1;//  "Golf Shirt"
			*script_global(262145 + 14890).as<int64_t*>() = 1;//  "Maisonette Shirt"
			*script_global(262145 + 14891).as<int64_t*>() = 1;//  "Manopause Shirt"
			*script_global(262145 + 14893).as<int64_t*>() = 1;//  "Pacific Bluffs Shirt"
			*script_global(262145 + 14894).as<int64_t*>() = 1;//  "Prolaps Shirt"
			*script_global(262145 + 14895).as<int64_t*>() = 1;//  "Tennis Shirt"
			*script_global(262145 + 14896).as<int64_t*>() = 1;//  "Toe Shirt"
			*script_global(262145 + 14897).as<int64_t*>() = 1;//  "Vanilla Unicorn Shirt"
			*script_global(262145 + 14898).as<int64_t*>() = 1;//  "Marlowe Shirt"
			*script_global(262145 + 14899).as<int64_t*>() = 1;//  "Crest Shirt"
			*script_global(262145 + 23885).as<int64_t*>() = 1;//  "Crocs Bar T-Shirt"
			*script_global(262145 + 23886).as<int64_t*>() = 1;//  "Base5 T-Shirt"
			*script_global(262145 + 23887).as<int64_t*>() = 1;//  "BOBO T-Shirt"
			*script_global(262145 + 23888).as<int64_t*>() = 1;//  "Bitch'n'Dog T-Shirt"
			*script_global(262145 + 23890).as<int64_t*>() = 1;//  "Vivisection T-Shirt"
			*script_global(262145 + 23893).as<int64_t*>() = 1;//  "Vinyl Countdown T-Shirt"
			*script_global(262145 + 23895).as<int64_t*>() = 1;//  "Victory Fist T-Shirt"
			*script_global(262145 + 23898).as<int64_t*>() = 1;//  "Homie Sharp T-Shirt"
			*script_global(262145 + 8009).as<int64_t*>() = 1;//  "Statue of Happiness T-shirt"
			//Knock Offs T - shirts:
			*script_global(262145 + 23901).as<int64_t*>() = 1;//  "Fake Perseus T-Shirt"
			*script_global(262145 + 23902).as<int64_t*>() = 1;//  "Fake Santo Capra T-Shirt"
			*script_global(262145 + 23903).as<int64_t*>() = 1;//  "Fake Dix White T-Shirt"
			*script_global(262145 + 23904).as<int64_t*>() = 1;//  "Fake Le Chien Crew T-Shirt"
			*script_global(262145 + 23905).as<int64_t*>() = 1;//  "Fake Enema T-Shirt"
			*script_global(262145 + 23906).as<int64_t*>() = 1;//  "Fake Dix Gold T-Shirt"
			*script_global(262145 + 23907).as<int64_t*>() = 1;//  "Fake Le Chien No2 T-Shirt"
			*script_global(262145 + 23908).as<int64_t*>() = 1;//  "Fake Seesanta Nove T-Shirt"
			*script_global(262145 + 23909).as<int64_t*>() = 1;//  "Fake Didier Sachs T-Shirt"
			*script_global(262145 + 23910).as<int64_t*>() = 1;//  "Fake Vapid T-Shirt"
			//Manufactures:
			*script_global(262145 + 14888).as<int64_t*>() = 1;//  "Grotti Shirt"
			*script_global(262145 + 17244).as<int64_t*>() = 1;//  "Western Brand White Tee"
			*script_global(262145 + 17245).as<int64_t*>() = 1;//  "Western Brand Black Tee"
			*script_global(262145 + 17246).as<int64_t*>() = 1;//  "Western Logo White Tee"
			*script_global(262145 + 17247).as<int64_t*>() = 1;//  "Western Logo Black Tee"
			*script_global(262145 + 17248).as<int64_t*>() = 1;//  "Steel Horse Solid Logo Tee"
			*script_global(262145 + 17249).as<int64_t*>() = 1;//  "Steel Horse Logo Tee"
			*script_global(262145 + 17250).as<int64_t*>() = 1;//  "Steel Horse Brand White Tee"
			*script_global(262145 + 17251).as<int64_t*>() = 1;//  "Steel Horse Brand Black Tee"
			*script_global(262145 + 17252).as<int64_t*>() = 1;//  "Nagasaki White Tee"
			*script_global(262145 + 17253).as<int64_t*>() = 1;//  "Nagasaki White And Red Tee"
			*script_global(262145 + 17254).as<int64_t*>() = 1;//  "Nagasaki Black Tee"
			*script_global(262145 + 17255).as<int64_t*>() = 1;//  "Purple Helmets Black Tee"
			*script_global(262145 + 17256).as<int64_t*>() = 1;//  "Principe Black Tee"
			*script_global(262145 + 17257).as<int64_t*>() = 1;//  "Steel Horse Black Hoodie"
			*script_global(262145 + 17258).as<int64_t*>() = 1;//  "Steel Horse White Hoodie"
			*script_global(262145 + 17259).as<int64_t*>() = 1;//  "Western Black Hoodie"
			*script_global(262145 + 17260).as<int64_t*>() = 1;//  "Western White Hoodie"
			*script_global(262145 + 17261).as<int64_t*>() = 1;//  "Nagasaki White Hoodie"
			*script_global(262145 + 17262).as<int64_t*>() = 1;//  "Nagasaki White And Red Hoodie"
			*script_global(262145 + 17263).as<int64_t*>() = 1;//  "Nagasaki Black Hoodie"
			*script_global(262145 + 17264).as<int64_t*>() = 1;//  "Purple Helmets Black Hoodie"
			*script_global(262145 + 17265).as<int64_t*>() = 1;//  "Principe Hoodie Black"
			//Movie shirts:

			*script_global(262145 + 11658).as<int64_t*>() = 1;//  "MELTDOWN"
			*script_global(262145 + 11659).as<int64_t*>() = 1;//  "VINEWOOD_ZOMBIE"
			*script_global(262145 + 11660).as<int64_t*>() = 1;//  "I_MARRIED_MY_DAD"
			*script_global(262145 + 11661).as<int64_t*>() = 1;//  "DIE_ALREADY_4"
			*script_global(262145 + 11662).as<int64_t*>() = 1;//  "THE_SHOULDER_OF_ORION_II"
			*script_global(262145 + 11663).as<int64_t*>() = 1;//  "NELSON_IN_NAPLES"
			*script_global(262145 + 11664).as<int64_t*>() = 1;//  "THE_MANY_WIVES_OF_ALFREDO_SMITH"
			*script_global(262145 + 11665).as<int64_t*>() = 1;//  "AN_AMERICAN_DIVORCE"
			*script_global(262145 + 11666).as<int64_t*>() = 1;//  "THE_LONELIEST_ROBOT"
			*script_global(262145 + 11667).as<int64_t*>() = 1;//  "CAPOLAVORO"
			*script_global(262145 + 12304).as<int64_t*>() = 1;//  "Vinewood Zombie Shirt"
			*script_global(262145 + 12305).as<int64_t*>() = 1;//  "Knife After Dark Shirt"
			*script_global(262145 + 12306).as<int64_t*>() = 1;//  "The Simian Shirt"
			*script_global(262145 + 12307).as<int64_t*>() = 1;//  "Zombie Liberals In The Midwest Shirt"
			*script_global(262145 + 12308).as<int64_t*>() = 1;//  "Twilight Knife Shirt"
			*script_global(262145 + 12309).as<int64_t*>() = 1;//  "Butchery and Other Hobbies Shirt"
			*script_global(262145 + 12310).as<int64_t*>() = 1;//  "Cheerleader Massacre 3 Shirt"
			*script_global(262145 + 12311).as<int64_t*>() = 1;//  "Cannibal Clown Shirt"
			*script_global(262145 + 12312).as<int64_t*>() = 1;//  "Hot Serial Killer Stepmom Shirt"
			*script_global(262145 + 12313).as<int64_t*>() = 1;//  "Splatter And Shot Shirt"
			*script_global(262145 + 12314).as<int64_t*>() = 1;//  "Meathook For Mommy Shirt"
			*script_global(262145 + 12315).as<int64_t*>() = 1;//  "Psycho Swingers Shirt"
			*script_global(262145 + 12316).as<int64_t*>() = 1;//  "Vampires On The Beach Shirt"
			*script_global(262145 + 14892).as<int64_t*>() = 1;//  "Meltdown Shirt"
			//Radio Station T-shirts:
			*script_global(262145 + 23884).as<int64_t*>() = 1;//  "Emotion 98.3 Radio T-Shirt"
			*script_global(262145 + 23889).as<int64_t*>() = 1;//  "KJAH Radio T-Shirt"
			*script_global(262145 + 23891).as<int64_t*>() = 1;//  "K-ROSE Radio T-Shirt"
			*script_global(262145 + 23892).as<int64_t*>() = 1;//  "FLASH Radio T-Shirt"
			*script_global(262145 + 23894).as<int64_t*>() = 1;//  "Fever 105 Radio T-Shirt"
			*script_global(262145 + 23896).as<int64_t*>() = 1;//  "K-DST Radio T-Shirt"
			*script_global(262145 + 23897).as<int64_t*>() = 1;//  "Bounce FM Radio T-Shirt"
			*script_global(262145 + 24409).as<int64_t*>() = 1;//  "LS UR T-Shirt"
			*script_global(262145 + 24410).as<int64_t*>() = 1;//  "Non-Stop-Pop FM T-Shirt"
			*script_global(262145 + 24411).as<int64_t*>() = 1;//  "Radio Los Santos T-Shirt"
			*script_global(262145 + 24412).as<int64_t*>() = 1;//  "Los Santos Rock Radio T-Shirt"
			*script_global(262145 + 24413).as<int64_t*>() = 1;//  "Blonded Los Santos 97.8 FM T-Shirt"
			*script_global(262145 + 24414).as<int64_t*>() = 1;//  "West Coast Talk Radio T-Shirt"
			*script_global(262145 + 24415).as<int64_t*>() = 1;//  "Radio Mirror Park T-Shirt"
			*script_global(262145 + 24416).as<int64_t*>() = 1;//  "Rebel Radio T-Shirt"
			*script_global(262145 + 24417).as<int64_t*>() = 1;//  "Channel X T-Shirt"
			*script_global(262145 + 24418).as<int64_t*>() = 1;//  "Vinewood Boulevard Radio T-Shirt"
			*script_global(262145 + 24419).as<int64_t*>() = 1;//  "FlyLo FM T-Shirt"
			*script_global(262145 + 24420).as<int64_t*>() = 1;//  "Space 103.2 T-Shirt"
			*script_global(262145 + 24421).as<int64_t*>() = 1;//  "West Coast Classics T-Shirt"
			*script_global(262145 + 24422).as<int64_t*>() = 1;//  "East Los FM T-Shirt"
			*script_global(262145 + 24423).as<int64_t*>() = 1;//  "The Lab T-Shirt"
			*script_global(262145 + 24424).as<int64_t*>() = 1;//  "The Lowdown 91.1 T-Shirt"
			*script_global(262145 + 24425).as<int64_t*>() = 1;//  "WorldWide FM T-Shirt"
			*script_global(262145 + 24426).as<int64_t*>() = 1;//  "Soulwax FM T-Shirt"
			*script_global(262145 + 24427).as<int64_t*>() = 1;//  "Blue Ark T-Shirt"
			*script_global(262145 + 24428).as<int64_t*>() = 1;//  "Blaine County Radio T-Shirt"
			//Clubs T - shirts:
			*script_global(262145 + 24369).as<int64_t*>() = 1;//  "Maisonette Los Santos T-Shirt"
			*script_global(262145 + 24370).as<int64_t*>() = 1;//  "Studio Los Santos T-Shirt"
			*script_global(262145 + 24371).as<int64_t*>() = 1;//  "Galaxy T-Shirt"
			*script_global(262145 + 24372).as<int64_t*>() = 1;//  "Gefängnis T-Shirt"
			*script_global(262145 + 24373).as<int64_t*>() = 1;//  "Omega T-Shirt"
			*script_global(262145 + 24374).as<int64_t*>() = 1;//  "Technologie T-Shirt"
			*script_global(262145 + 24375).as<int64_t*>() = 1;//  "Paradise T-Shirt"
			*script_global(262145 + 24376).as<int64_t*>() = 1;//  "The Palace T-Shirt"
			*script_global(262145 + 24377).as<int64_t*>() = 1;//  "Tony's Fun House T-Shirt"
			//DJ T - shirts:
			*script_global(262145 + 24584).as<int64_t*>() = 1;//  "White Solomun Logo Tee"
			*script_global(262145 + 24585).as<int64_t*>() = 1;//  "White Solomun Pocket Logo Tee"
			*script_global(262145 + 24586).as<int64_t*>() = 1;//  "Black And Yellow Solomun Tee"
			*script_global(262145 + 24587).as<int64_t*>() = 1;//  "Black Solomun White Logo Tee"
			*script_global(262145 + 24588).as<int64_t*>() = 1;//  "Black And White Solomun Tee"
			*script_global(262145 + 24589).as<int64_t*>() = 1;//  "Black Solomun Pocket Logo Tee"
			*script_global(262145 + 24590).as<int64_t*>() = 1;//  "Dixon Box logo Tee"
			*script_global(262145 + 24591).as<int64_t*>() = 1;//  "Dixon Pocket logo Tee"
			*script_global(262145 + 24592).as<int64_t*>() = 1;//  "White Dixon Wilderness Tee"
			*script_global(262145 + 24593).as<int64_t*>() = 1;//  "Dixon Green Logo Tee"
			*script_global(262145 + 24594).as<int64_t*>() = 1;//  "Dixon Glitch Logo Tee"
			*script_global(262145 + 24595).as<int64_t*>() = 1;//  "Black Dixon Repeated Logo Tee"
			*script_global(262145 + 24596).as<int64_t*>() = 1;//  "Tale Of Us Box Logo Tee"
			*script_global(262145 + 24597).as<int64_t*>() = 1;//  "White Tale Of Us Logo Tee"
			*script_global(262145 + 24598).as<int64_t*>() = 1;//  "White Tale Of Us Emb. Tee"
			*script_global(262145 + 24599).as<int64_t*>() = 1;//  "Black Tale Of Us 0Logo Tee"
			*script_global(262145 + 24600).as<int64_t*>() = 1;//  "Tale Of Us Stacked Logo Tee"
			*script_global(262145 + 24601).as<int64_t*>() = 1;//  "Tale Of Us Afterlight Tee"
			*script_global(262145 + 24602).as<int64_t*>() = 1;//  "White The Black Madonna Tee"
			*script_global(262145 + 24603).as<int64_t*>() = 1;//  "Black The Black Madonna Tee"
			*script_global(262145 + 24604).as<int64_t*>() = 1;//  "White The Black Madonna Emb. Tee"
			*script_global(262145 + 24605).as<int64_t*>() = 1;//  "White The Black Madonna Init. Tee"
			*script_global(262145 + 24606).as<int64_t*>() = 1;//  "Black The Black Madonna Init. Tee"
			*script_global(262145 + 24607).as<int64_t*>() = 1;//  "The Black Madonna We Believe Tee"
			//Unlock Hoodies :
			*script_global(262145 + 20816).as<int64_t*>() = 1;//  "BLACK_AMMUNATION_HOODIE"
			*script_global(262145 + 20820).as<int64_t*>() = 1;//  "BLACK_HAWK_AND_LITTLE_HODDIE"
			*script_global(262145 + 20823).as<int64_t*>() = 1;//  "BLACK_SHREWSBURY_HOODIE"
			*script_global(262145 + 20825).as<int64_t*>() = 1;//  "BLACK_WARSTOCK_HOODIE"
			*script_global(262145 + 20830).as<int64_t*>() = 1;//  "WHITE_COIL_HOODIE"
			*script_global(262145 + 20832).as<int64_t*>() = 1;//  "WHITE_HAWK_AND_LITTLE_HOODIE"
			*script_global(262145 + 20836).as<int64_t*>() = 1;//  "WHITE_SHREWSBURY_HOODIE"
			*script_global(262145 + 20839).as<int64_t*>() = 1;//  "WHITE_VOM_FEUER_HOODIE"
			//Unlock Shirts :
			*script_global(262145 + 20817).as<int64_t*>() = 1;//  "BLACK_AMMUNATION_TEE"
			*script_global(262145 + 20819).as<int64_t*>() = 1;//  "BLACK_COIL_TEE"
			*script_global(262145 + 20821).as<int64_t*>() = 1;//  "BLACK_HAWK_AND_LITTLE_LOGO_TEE"
			*script_global(262145 + 20822).as<int64_t*>() = 1;//  "BLACK_HAWK_AND_LITTLE_TEE"
			*script_global(262145 + 20826).as<int64_t*>() = 1;//  "GREEN_VOM_FEUER_TEE"
			*script_global(262145 + 20829).as<int64_t*>() = 1;//  "WHITE_AMMUNATION_TEE"
			*script_global(262145 + 20831).as<int64_t*>() = 1;//  "WHITE_COIL_TEE"
			*script_global(262145 + 20833).as<int64_t*>() = 1;//  "WHITE_HAWK_AND_LITTLE_TEE"
			*script_global(262145 + 20834).as<int64_t*>() = 1;//  "WHITE_SHREWSBURY_TEE"
			*script_global(262145 + 20837).as<int64_t*>() = 1;//  "WHITE_SHREWSBURY_LOGO_TEE"
			*script_global(262145 + 20841).as<int64_t*>() = 1;//  "YELLOW_VOM_FEUER_LOGO_TEE"
			*script_global(262145 + 20842).as<int64_t*>() = 1;//  "YELLOW_VOM_FEUER_TEE"
			*script_global(262145 + 20843).as<int64_t*>() = 1;//  "YELLOW_WARSTOCK_TEE"
			*script_global(262145 + 20844).as<int64_t*>() = 1;//  "BLUE_R*_CLASS_OF_98"
			*script_global(262145 + 20845).as<int64_t*>() = 1;//  "RED_R*_CLASS_OF_98"
			*script_global(262145 + 20846).as<int64_t*>() = 1;//  "NOISE_ROCKSTAR_LOGO_TEE"
			*script_global(262145 + 20847).as<int64_t*>() = 1;//  "NOISE_TEE"
			*script_global(262145 + 20848).as<int64_t*>() = 1;//  "RAZOR_TEE"
			*script_global(262145 + 20849).as<int64_t*>() = 1;//  "BLACK_ROCKSTAR_CAMO"
			*script_global(262145 + 20850).as<int64_t*>() = 1;//  "WHITE_ROCKSTAR_CAMO"
			*script_global(262145 + 20851).as<int64_t*>() = 1;//  "KNUCKLEDUSTER_POCKET_TEE"
			*script_global(262145 + 20852).as<int64_t*>() = 1;//  "ROCKSTAR_LOGO_BLACKED_OUT_TEE"
			*script_global(262145 + 20853).as<int64_t*>() = 1;//  "ROCKSTAR_LOGO_WHITE_OUT_TEE"
			*script_global(262145 + 25290).as<int64_t*>() = 1;//  "Kifflom Tee"
			//Wireframe Bodysuits:
			*script_global(262145 + 23087).as<int64_t*>() = 1;//  "Green Wireframe Bodysuit"
			*script_global(262145 + 23088).as<int64_t*>() = 1;//  "Orange Wireframe Bodysuit"
			*script_global(262145 + 23089).as<int64_t*>() = 1;//  "Blue Wireframe Bodysuit"
			*script_global(262145 + 23090).as<int64_t*>() = 1;//  "Pink Wireframe Bodysuit"
			*script_global(262145 + 23091).as<int64_t*>() = 1;//  "Yellow Wireframe Bodysuit"
			//Stunt Suits:
			*script_global(262145 + 16503).as<int64_t*>() = 1;//  "White Jock Cranley Suit"
			*script_global(262145 + 16504).as<int64_t*>() = 1;//  "Blue Jock Cranley Suit"
			*script_global(262145 + 16505).as<int64_t*>() = 1;//  "Red Jock Cranley Suit"
			*script_global(262145 + 16506).as<int64_t*>() = 1;//  "Gold Jock Cranley Suit"
			*script_global(262145 + 16507).as<int64_t*>() = 1;//  "Black Jock Cranley Suit"
			*script_global(262145 + 16508).as<int64_t*>() = 1;//  "Pink Jock Cranley Suit"
			*script_global(262145 + 16509).as<int64_t*>() = 1;//  "Silver Jock Cranley Suit"
			//Arena DLC Unlocks 1.57:
			//Manufacturers Shirts :
			*script_global(262145 + 25341).as<int64_t*>() = 1;//  "Albany Tee"
			*script_global(262145 + 25342).as<int64_t*>() = 1;//  "Albany Vintage Tee"
			*script_global(262145 + 25343).as<int64_t*>() = 1;//  "Annis Tee"
			*script_global(262145 + 25344).as<int64_t*>() = 1;//  "Benefector Tee"
			*script_global(262145 + 25345).as<int64_t*>() = 1;//  "BF Tee"
			*script_global(262145 + 25346).as<int64_t*>() = 1;//  "Bollokan Tee"
			*script_global(262145 + 25347).as<int64_t*>() = 1;//  "Bravado Tee"
			*script_global(262145 + 25348).as<int64_t*>() = 1;//  "Brute Tee"
			*script_global(262145 + 25349).as<int64_t*>() = 1;//  "Buckingham Tee"
			*script_global(262145 + 25350).as<int64_t*>() = 1;//  "Canis Tee"
			*script_global(262145 + 25351).as<int64_t*>() = 1;//  "Chariot Tee"
			*script_global(262145 + 25352).as<int64_t*>() = 1;//  "Cheval Tee"
			*script_global(262145 + 25353).as<int64_t*>() = 1;//  "Classigue Tee"
			*script_global(262145 + 25354).as<int64_t*>() = 1;//  "Coil Tee"
			*script_global(262145 + 25355).as<int64_t*>() = 1;//  "Declasse Tee"
			*script_global(262145 + 25356).as<int64_t*>() = 1;//  "Dewbauchee Tee"
			*script_global(262145 + 25357).as<int64_t*>() = 1;//  "Dilettante Tee"
			*script_global(262145 + 25358).as<int64_t*>() = 1;//  "Dinka Tee"
			*script_global(262145 + 25359).as<int64_t*>() = 1;//  "Dundreary Tee"
			*script_global(262145 + 25360).as<int64_t*>() = 1;//  "Emperor Tee"
			*script_global(262145 + 25361).as<int64_t*>() = 1;//  "Enus Tee"
			*script_global(262145 + 25362).as<int64_t*>() = 1;//  "Fathom Tee"
			*script_global(262145 + 25363).as<int64_t*>() = 1;//  "Gallivanter Tee"
			*script_global(262145 + 25364).as<int64_t*>() = 1;//  "Grotti Tee"
			*script_global(262145 + 25365).as<int64_t*>() = 1;//  "Hijak Tee"
			*script_global(262145 + 25366).as<int64_t*>() = 1;//  "HVT Tee"
			*script_global(262145 + 25367).as<int64_t*>() = 1;//  "Imponte Tee"
			*script_global(262145 + 25368).as<int64_t*>() = 1;//  "Invetero Tee"
			*script_global(262145 + 25369).as<int64_t*>() = 1;//  "Jobuilt Tee"
			*script_global(262145 + 25370).as<int64_t*>() = 1;//  "Karin Tee"
			*script_global(262145 + 25371).as<int64_t*>() = 1;//  "Lampadati Tee"
			*script_global(262145 + 25372).as<int64_t*>() = 1;//  "Maibatsu Tee"
			*script_global(262145 + 25373).as<int64_t*>() = 1;//  "Mamba Tee"
			*script_global(262145 + 25374).as<int64_t*>() = 1;//  "Mammoth Tee"
			*script_global(262145 + 25375).as<int64_t*>() = 1;//  "MTL Tee"
			*script_global(262145 + 25376).as<int64_t*>() = 1;//  "Obey Tee"
			*script_global(262145 + 25377).as<int64_t*>() = 1;//  "Ocelot Tee"
			*script_global(262145 + 25378).as<int64_t*>() = 1;//  "Overflod Tee"
			*script_global(262145 + 25379).as<int64_t*>() = 1;//  "Pegassi Tee"
			*script_global(262145 + 25380).as<int64_t*>() = 1;//  "Pfister Tee"
			*script_global(262145 + 25381).as<int64_t*>() = 1;//  "Progen Tee"
			*script_global(262145 + 25382).as<int64_t*>() = 1;//  "Rune Tee"
			*script_global(262145 + 25383).as<int64_t*>() = 1;//  "Schyster Tee"
			*script_global(262145 + 25384).as<int64_t*>() = 1;//  "Shitzu Tee"
			*script_global(262145 + 25385).as<int64_t*>() = 1;//  "Truffade Tee"
			*script_global(262145 + 25386).as<int64_t*>() = 1;//  "Ubermacht Tee"
			*script_global(262145 + 25387).as<int64_t*>() = 1;//  "Vapid Tee"
			*script_global(262145 + 25388).as<int64_t*>() = 1;//  "Vulcar Tee"
			*script_global(262145 + 25389).as<int64_t*>() = 1;//  "Weeny Tee"
			*script_global(262145 + 25390).as<int64_t*>() = 1;//  "Willard Tee"
			*script_global(262145 + 25391).as<int64_t*>() = 1;//  "Albany Nostalgia Tee"
			*script_global(262145 + 25392).as<int64_t*>() = 1;//  "Albany USA Tee"
			*script_global(262145 + 25393).as<int64_t*>() = 1;//  "Albany Dealership Tee"
			*script_global(262145 + 25394).as<int64_t*>() = 1;//  "Annis JPN Tee"
			*script_global(262145 + 25395).as<int64_t*>() = 1;//  "BF Surfer Tee"
			*script_global(262145 + 25396).as<int64_t*>() = 1;//  "Bollokan Prairie Tee"
			*script_global(262145 + 25397).as<int64_t*>() = 1;//  "Bravado Stylized Tee"
			*script_global(262145 + 25398).as<int64_t*>() = 1;//  "Brute Impregnable Tee"
			*script_global(262145 + 25399).as<int64_t*>() = 1;//  "Brute Heavy Duty Tee"
			*script_global(262145 + 25400).as<int64_t*>() = 1;//  "Buckingham Luxe Tee"
			*script_global(262145 + 25401).as<int64_t*>() = 1;//  "Canis USA Tee"
			*script_global(262145 + 25402).as<int64_t*>() = 1;//  "Canis American Legend Tee"
			*script_global(262145 + 25403).as<int64_t*>() = 1;//  "Canis Wolf Tee"
			*script_global(262145 + 25404).as<int64_t*>() = 1;//  "Cheval Marshall Tee"
			*script_global(262145 + 25405).as<int64_t*>() = 1;//  "Coil USA Tee"
			*script_global(262145 + 25406).as<int64_t*>() = 1;//  "Coil Raiden Tee"
			*script_global(262145 + 25407).as<int64_t*>() = 1;//  "Declasse Logo Tee"
			*script_global(262145 + 25408).as<int64_t*>() = 1;//  "Declasse Girl Tee"
			//Festive Sweaters :
			*script_global(262145 + 25409).as<int64_t*>() = 1;//  "Burger Shot Festive Sweater"
			*script_global(262145 + 25410).as<int64_t*>() = 1;//  "Red Bleeder Festive Sweater"
			*script_global(262145 + 25411).as<int64_t*>() = 1;//  "Blue Bleeder Festive Sweater"
			*script_global(262145 + 25412).as<int64_t*>() = 1;//  "Blue Cluckin' Festive Sweater"
			*script_global(262145 + 25413).as<int64_t*>() = 1;//  "Green Cluckin' Festive Sweater"
			*script_global(262145 + 25414).as<int64_t*>() = 1;//  "Blue Slaying Festive Sweater"
			*script_global(262145 + 25415).as<int64_t*>() = 1;//  "Green Slaying Festive Sweater"
			*script_global(262145 + 25416).as<int64_t*>() = 1;//  "Hail Santa Festive Sweater"
			*script_global(262145 + 25417).as<int64_t*>() = 1;//  "Merrry Sprunkmas Festive Sweater"
			*script_global(262145 + 25418).as<int64_t*>() = 1;//  "Ice Cold Sprunk Festive Sweater"
			//Casino DLC Unlocks 1.57:
			//Casino Shirts :
			*script_global(262145 + 26525).as<int64_t*>() = 1;//  "The Diamond Classics Tee"
			*script_global(262145 + 26526).as<int64_t*>() = 1;//  "The Diamond Vintage Tee"
			*script_global(262145 + 26527).as<int64_t*>() = 1;//  "Red The Diamond Resort LS Tee"
			*script_global(262145 + 26528).as<int64_t*>() = 1;//  "Blue The Diamond Resort LS Tee"
			*script_global(262145 + 26529).as<int64_t*>() = 1;//  "Red The Diamond Resort Tee"
			*script_global(262145 + 26530).as<int64_t*>() = 1;//  "Blue D Casino Tee"
			*script_global(262145 + 26531).as<int64_t*>() = 1;//  "Red The Diamond Classic Tee"
			//Arcade Shirts :
			*script_global(262145 + 27814).as<int64_t*>() = 1;//  "Street Crimes Boxart Tee"
			*script_global(262145 + 27815).as<int64_t*>() = 1;//  "Street Crimes Logo Tee"
			*script_global(262145 + 27816).as<int64_t*>() = 1;//  "Claim What's Yours Tee"
			*script_global(262145 + 27817).as<int64_t*>() = 1;//  "Choose Your Side Tee"
			*script_global(262145 + 27818).as<int64_t*>() = 1;//  "Street Crimes Color Gangs Tee"
			*script_global(262145 + 27819).as<int64_t*>() = 1;//  "Street Crimes Red Gangs Tee"
			*script_global(262145 + 27820).as<int64_t*>() = 1;//  "White Street Crimes Icons Tee"
			*script_global(262145 + 27821).as<int64_t*>() = 1;//  "Black Street Crimes Icons Tee"
			*script_global(262145 + 27822).as<int64_t*>() = 1;//  "Invade and Persuade Logo Tee"
			*script_global(262145 + 27823).as<int64_t*>() = 1;//  "Mission I Tee"
			*script_global(262145 + 27824).as<int64_t*>() = 1;//  "Mission II Tee"
			*script_global(262145 + 27825).as<int64_t*>() = 1;//  "Mission IV Tee"
			*script_global(262145 + 27826).as<int64_t*>() = 1;//  "Mission III Tee"
			*script_global(262145 + 27827).as<int64_t*>() = 1;//  "Invade and Persuade Boxart Tee"
			*script_global(262145 + 27828).as<int64_t*>() = 1;//  "Invade and Persuade Invader Tee"
			*script_global(262145 + 27829).as<int64_t*>() = 1;//  "Invade and Persuade Suck Tee"
			*script_global(262145 + 27830).as<int64_t*>() = 1;//  "Invade and Persuade Jets Tee"
			*script_global(262145 + 27831).as<int64_t*>() = 1;//  "Invade and Persuade Gold Tee"
			*script_global(262145 + 27832).as<int64_t*>() = 1;//  "Invade and Persuade Hero Tee"
			*script_global(262145 + 27833).as<int64_t*>() = 1;//  "Invade and Persuade Barrels Tee"
			//Summer DLC Unlocks 1.57:
			*script_global(262145 + 29181).as<int64_t*>() = 1;// BCTR Aged Tee
			*script_global(262145 + 29182).as<int64_t*>() = 1;// BCTR Tee
			*script_global(262145 + 29183).as<int64_t*>() = 1;// Cultstoppers Aged Tee
			*script_global(262145 + 29184).as<int64_t*>() = 1;// Cultstoppers Tee
			*script_global(262145 + 29185).as<int64_t*>() = 1;// Daily Globe Tee
			*script_global(262145 + 29186).as<int64_t*>() = 1;// Daily Globe Aged Tee
			*script_global(262145 + 29187).as<int64_t*>() = 1;// Eyefind Aged Tee
			*script_global(262145 + 29188).as<int64_t*>() = 1;// Eyefind Tee
			*script_global(262145 + 29189).as<int64_t*>() = 1;// Facade Aged Tee
			*script_global(262145 + 29190).as<int64_t*>() = 1;// Facade Tee
			*script_global(262145 + 29191).as<int64_t*>() = 1;// Fruit Aged Tee
			*script_global(262145 + 29192).as<int64_t*>() = 1;// Fruit Tee
			*script_global(262145 + 29193).as<int64_t*>() = 1;// LSHH Aged Tee
			*script_global(262145 + 29194).as<int64_t*>() = 1;// LSHH Tee
			*script_global(262145 + 29195).as<int64_t*>() = 1;// MyRoom Aged Tee
			*script_global(262145 + 29196).as<int64_t*>() = 1;// MyRoom Tee
			*script_global(262145 + 29197).as<int64_t*>() = 1;// Rebel Aged Tee
			*script_global(262145 + 29198).as<int64_t*>() = 1;// Rebel Tee
			*script_global(262145 + 29199).as<int64_t*>() = 1;// Six Figure Aged Tee
			*script_global(262145 + 29200).as<int64_t*>() = 1;// Six Figure Tee
			*script_global(262145 + 29201).as<int64_t*>() = 1;// Trash Or Treasure Aged Tee
			*script_global(262145 + 29202).as<int64_t*>() = 1;// Trash Or Treasure Tee
			*script_global(262145 + 29203).as<int64_t*>() = 1;// TW@ Logo Aged Tee
			*script_global(262145 + 29204).as<int64_t*>() = 1;// TW@ Logo Tee
			*script_global(262145 + 29205).as<int64_t*>() = 1;// Vapers Den Aged Tee
			*script_global(262145 + 29206).as<int64_t*>() = 1;// Vapers Den Tee
			*script_global(262145 + 29207).as<int64_t*>() = 1;// Winglt Aged Tee
			*script_global(262145 + 29208).as<int64_t*>() = 1;// Winglt Tee
			*script_global(262145 + 29209).as<int64_t*>() = 1;// ZiT Aged Tee
			*script_global(262145 + 29210).as<int64_t*>() = 1;// ZiT Tee
			*script_global(262145 + 29211).as<int64_t*>() = 1;// Green Dot Tech Mask
			*script_global(262145 + 29212).as<int64_t*>() = 1;// Orange Dot Tech Mask
			*script_global(262145 + 29213).as<int64_t*>() = 1;// Blue Dot Tech Mask
			*script_global(262145 + 29214).as<int64_t*>() = 1;// Pink Dot Tech Mask
			*script_global(262145 + 29215).as<int64_t*>() = 1;// Lemon Sports Track Pants
			*script_global(262145 + 29216).as<int64_t*>() = 1;// Lemon Sports Track Top
			//Perico DLC Unlocks 1.57:
			//T - shirts / Jackets / Sweaters / :
			*script_global(262145 + 29688).as<int64_t*>() = 1;// Panther varsity jacket
			*script_global(262145 + 29689).as<int64_t*>() = 1;// Panther tour jacket
			*script_global(262145 + 29690).as<int64_t*>() = 1;// Broker prolaps basketball top
			*script_global(262145 + 29691).as<int64_t*>() = 1;// Panic prolaps basketball top
			*script_global(262145 + 29692).as<int64_t*>() = 1;// Gussét frog Tee
			*script_global(262145 + 29693).as<int64_t*>() = 1;// Warped still slipping tee
			*script_global(262145 + 29694).as<int64_t*>() = 1;// Yellow Still slipping tee
			*script_global(262145 + 29695).as<int64_t*>() = 1;// Black Rockstar  tee
			*script_global(262145 + 29696).as<int64_t*>() = 1;// Black exsorbeo 720 logo tee
			*script_global(262145 + 29697).as<int64_t*>() = 1;// Manor PRBG tee
			*script_global(262145 + 29698).as<int64_t*>() = 1;// Manor Tie - dye tee
			*script_global(262145 + 29699).as<int64_t*>() = 1;// Open wheel sponsor tee
			*script_global(262145 + 29700).as<int64_t*>() = 1;// Rockstar yellow pattern tee
			*script_global(262145 + 29701).as<int64_t*>() = 1;// Rockstar gray pattern tee
			*script_global(262145 + 29702).as<int64_t*>() = 1;// Rockstar rolling tee
			*script_global(262145 + 29703).as<int64_t*>() = 1;// Santo capra patterns sweater
			*script_global(262145 + 29704).as<int64_t*>() = 1;// Rockstar studio colors sweater
			*script_global(262145 + 29705).as<int64_t*>() = 1;// Bigness jackal sweater
			*script_global(262145 + 29706).as<int64_t*>() = 1;// Bigness tie - dye sweater
			*script_global(262145 + 29707).as<int64_t*>() = 1;// Bigness faces sweater
			//Shorts :
			*script_global(262145 + 29708).as<int64_t*>() = 1;// Broker prolaps basketball shorts
			*script_global(262145 + 29709).as<int64_t*>() = 1;// Panic prolaps basketball shorts
			*script_global(262145 + 29710).as<int64_t*>() = 1;// Exorbeo 720 Sports shorts
			*script_global(262145 + 29711).as<int64_t*>() = 1;// Bigness tie - dye sports pants
			//Caps :
			*script_global(262145 + 29712).as<int64_t*>() = 1;// Enus yeti cap(forward, backard)
			*script_global(262145 + 29713).as<int64_t*>() = 1;//  720 cap(forward, backard)
			*script_global(262145 + 29714).as<int64_t*>() = 1;// EXsorbeo 720 cap(forward, backard)
			*script_global(262145 + 29715).as<int64_t*>() = 1;// Güffy Double Logo Forwards Cap(forward, backard)
			*script_global(262145 + 29716).as<int64_t*>() = 1;// Rockstar cap(forward, backard)
			//Glow Bracelets :
			*script_global(262145 + 29717).as<int64_t*>() = 1;// Blue bangles
			*script_global(262145 + 29718).as<int64_t*>() = 1;// Red bangles
			*script_global(262145 + 29719).as<int64_t*>() = 1;// Pink bangles
			*script_global(262145 + 29720).as<int64_t*>() = 1;// Yellow bangles
			*script_global(262145 + 29721).as<int64_t*>() = 1;// Orange bangles
			*script_global(262145 + 29722).as<int64_t*>() = 1;// Green bangles
			*script_global(262145 + 29723).as<int64_t*>() = 1;// Redand blue bangles
			*script_global(262145 + 29724).as<int64_t*>() = 1;// Yellowand orange bangles
			*script_global(262145 + 29725).as<int64_t*>() = 1;// Greenand pink bangles
			*script_global(262145 + 29726).as<int64_t*>() = 1;// Rainbow bangles
			*script_global(262145 + 29727).as<int64_t*>() = 1;// Sunset bangles
			*script_global(262145 + 29728).as<int64_t*>() = 1;// Tropical bangles
			//Glow Glasses :
			*script_global(262145 + 29729).as<int64_t*>() = 1;// Blueand pink glow shades
			*script_global(262145 + 29730).as<int64_t*>() = 1;// Red glow shades
			*script_global(262145 + 29731).as<int64_t*>() = 1;// Orange glow shades
			*script_global(262145 + 29732).as<int64_t*>() = 1;// Yellow glow shades
			*script_global(262145 + 29733).as<int64_t*>() = 1;// Green glow shades
			*script_global(262145 + 29734).as<int64_t*>() = 1;// Blue glow shades
			*script_global(262145 + 29735).as<int64_t*>() = 1;// Pink glow shades
			*script_global(262145 + 29736).as<int64_t*>() = 1;// Blueand magenta glow shades
			*script_global(262145 + 29737).as<int64_t*>() = 1;// Purpleand yellow glow shades
			*script_global(262145 + 29738).as<int64_t*>() = 1;// Blueand yellow glow shades
			*script_global(262145 + 29739).as<int64_t*>() = 1;// Pinkand yellow glow shades
			*script_global(262145 + 29740).as<int64_t*>() = 1;// Redand yellow glow shades
			//Glow Necklaces :
			*script_global(262145 + 29741).as<int64_t*>() = 1;// Blue glow necklace
			*script_global(262145 + 29742).as<int64_t*>() = 1;// Red glow necklace
			*script_global(262145 + 29743).as<int64_t*>() = 1;// Pink glow necklace
			*script_global(262145 + 29744).as<int64_t*>() = 1;// Yellow glow necklace
			*script_global(262145 + 29745).as<int64_t*>() = 1;// Orange glow necklace
			*script_global(262145 + 29746).as<int64_t*>() = 1;// Green glow necklace
			*script_global(262145 + 29747).as<int64_t*>() = 1;// Festival glow necklace
			*script_global(262145 + 29748).as<int64_t*>() = 1;// Carnival glow necklace
			*script_global(262145 + 29749).as<int64_t*>() = 1;// Tropical glow necklace
			*script_global(262145 + 29750).as<int64_t*>() = 1;// Hot glow necklace
			*script_global(262145 + 29751).as<int64_t*>() = 1;// Neon glow necklace
			*script_global(262145 + 29752).as<int64_t*>() = 1;// Party glow necklace
			*script_global(262145 + 29753).as<int64_t*>() = 1;// Sunset glow necklace
			*script_global(262145 + 29754).as<int64_t*>() = 1;// Radiant glow necklace
			*script_global(262145 + 29755).as<int64_t*>() = 1;// Sunrise glow necklace
			*script_global(262145 + 29756).as<int64_t*>() = 1;// Session glow necklace
			//Full Head Masks :
			*script_global(262145 + 29761).as<int64_t*>() = 1;// Green calavera mask
			*script_global(262145 + 29762).as<int64_t*>() = 1;// Navy calavera mask
			*script_global(262145 + 29763).as<int64_t*>() = 1;// Cherry calavera mask
			*script_global(262145 + 29764).as<int64_t*>() = 1;// Orange calavera mask
			*script_global(262145 + 29765).as<int64_t*>() = 1;// Purple calavera mask
			*script_global(262145 + 29766).as<int64_t*>() = 1;// Dark blue calavera mask
			*script_global(262145 + 29767).as<int64_t*>() = 1;// Lavender calavera mask
			*script_global(262145 + 29768).as<int64_t*>() = 1;// Yellow calavera mask
			*script_global(262145 + 29769).as<int64_t*>() = 1;// Pink calavera mask
			*script_global(262145 + 29770).as<int64_t*>() = 1;// Neon stich emissive mask
			*script_global(262145 + 29771).as<int64_t*>() = 1;// Vibrant stich emissive mask
			*script_global(262145 + 29772).as<int64_t*>() = 1;// Pink stich emissive mask
			*script_global(262145 + 29773).as<int64_t*>() = 1;// Blue stich emissive mask
			*script_global(262145 + 29774).as<int64_t*>() = 1;// Neon skull emissive mask
			*script_global(262145 + 29775).as<int64_t*>() = 1;// Vibrant skull emissive mask
			*script_global(262145 + 29776).as<int64_t*>() = 1;// Pink skull emissive mask
			*script_global(262145 + 29777).as<int64_t*>() = 1;// Orange skull emissive mask
			*script_global(262145 + 29778).as<int64_t*>() = 1;// Dark x - ray emissive mask
			*script_global(262145 + 29779).as<int64_t*>() = 1;// Bright x - ray emissive mask
			*script_global(262145 + 29780).as<int64_t*>() = 1;// Purple x - ray emissive mask
			//Special Glasses :
			*script_global(262145 + 30345).as<int64_t*>() = 1;// Midnight tint oversized shades
			*script_global(262145 + 30346).as<int64_t*>() = 1;// Sunset tint oversized shades
			*script_global(262145 + 30347).as<int64_t*>() = 1;// Black tint oversized shades
			*script_global(262145 + 30348).as<int64_t*>() = 1;// Blue tint oversized shades
			*script_global(262145 + 30349).as<int64_t*>() = 1;// Gold tint oversized shades
			*script_global(262145 + 30350).as<int64_t*>() = 1;// Green tint oversized shades
			*script_global(262145 + 30351).as<int64_t*>() = 1;// Orange tint oversized shades
			*script_global(262145 + 30352).as<int64_t*>() = 1;// Red tint oversized shades
			*script_global(262145 + 30353).as<int64_t*>() = 1;// Pink tint oversized shades
			*script_global(262145 + 30354).as<int64_t*>() = 1;// Yellow tint oversized shades
			*script_global(262145 + 30355).as<int64_t*>() = 1;// Lemon tint oversized shades
			*script_global(262145 + 30356).as<int64_t*>() = 1;// Gold rimmed oversized shades
			*script_global(262145 + 30357).as<int64_t*>() = 1;// White checked round shades
			*script_global(262145 + 30358).as<int64_t*>() = 1;// Pink checked round shades
			*script_global(262145 + 30359).as<int64_t*>() = 1;// Yellow checked round shades
			*script_global(262145 + 30360).as<int64_t*>() = 1;// Red checked round shades
			*script_global(262145 + 30361).as<int64_t*>() = 1;// White round shades
			*script_global(262145 + 30362).as<int64_t*>() = 1;// Black round shades
			*script_global(262145 + 30363).as<int64_t*>() = 1;// Pink tinted round shades
			*script_global(262145 + 30364).as<int64_t*>() = 1;// Blue titned round shades
			*script_global(262145 + 30365).as<int64_t*>() = 1;// Green checked round shades
			*script_global(262145 + 30366).as<int64_t*>() = 1;// Blue checked round shades
			*script_global(262145 + 30367).as<int64_t*>() = 1;// Orange checked round shades
			*script_global(262145 + 30368).as<int64_t*>() = 1;// Green tinted round shades
			*script_global(262145 + 30369).as<int64_t*>() = 1;// Brown square shades
			*script_global(262145 + 30370).as<int64_t*>() = 1;// Yellow square shades
			*script_global(262145 + 30371).as<int64_t*>() = 1;// Black square shades
			*script_global(262145 + 30372).as<int64_t*>() = 1;// Tortoiseshell square shades
			*script_global(262145 + 30373).as<int64_t*>() = 1;// Green square shades
			*script_global(262145 + 30374).as<int64_t*>() = 1;// Red square shades
			*script_global(262145 + 30375).as<int64_t*>() = 1;// Pink tinted square shades
			*script_global(262145 + 30376).as<int64_t*>() = 1;// Blue tinted suared shades
			*script_global(262145 + 30377).as<int64_t*>() = 1;// White square shades
			*script_global(262145 + 30378).as<int64_t*>() = 1;// Pink square shades
			*script_global(262145 + 30379).as<int64_t*>() = 1;// All white square shades
			*script_global(262145 + 30380).as<int64_t*>() = 1;// Mono square shades
			//Some DJ T - shirts:
			*script_global(262145 + 30390).as<int64_t*>() = 1;// Palms Trax LS Tee
			*script_global(262145 + 30391).as<int64_t*>() = 1;// Moodymann Whatupdoe Tee
			*script_global(262145 + 30392).as<int64_t*>() = 1;// Moodymann Big D Tee
			*script_global(262145 + 30393).as<int64_t*>() = 1;// Keinemusik Cayo Perico Tee
			*script_global(262145 + 30394).as<int64_t*>() = 1;// Still Slipping Blarneys Tee
			*script_global(262145 + 30395).as<int64_t*>() = 1;// Still Slipping Friend Tee
			//Tuners DLC Unlocks 1.57:
				//T - shirts / Jackets / Coveralls:
			*script_global(262145 + 30657).as<int64_t*>() = 1;// Black Banshee Tee
			*script_global(262145 + 30658).as<int64_t*>() = 1;// Blue Banshee Tee
			*script_global(262145 + 30659).as<int64_t*>() = 1;// Banshee Hoodie
			*script_global(262145 + 30660).as<int64_t*>() = 1;// LS Customs Tee
			*script_global(262145 + 30661).as<int64_t*>() = 1;// LS Customs Coveralls
			*script_global(262145 + 30662).as<int64_t*>() = 1;// LS Customs Tour Jacket
			*script_global(262145 + 30663).as<int64_t*>() = 1;// LS Customs Varsity
			*script_global(262145 + 30664).as<int64_t*>() = 1;// Sprunk Varsity
			*script_global(262145 + 30665).as<int64_t*>() = 1;// eCola Varsity
			*script_global(262145 + 30673).as<int64_t*>() = 1;// Rockstar Games Typeface Tee
			*script_global(262145 + 30674).as<int64_t*>() = 1;// Wasted!Tee
			*script_global(262145 + 30675).as<int64_t*>() = 1;// Baseball Bat Tee
			*script_global(262145 + 30676).as<int64_t*>() = 1;// Knuckleduster Tee
			*script_global(262145 + 30677).as<int64_t*>() = 1;// Rampage Tee
			*script_global(262145 + 30678).as<int64_t*>() = 1;// Penitentiary Coveralls
			*script_global(262145 + 30679).as<int64_t*>() = 1;// White Born x Raised Tee
			//Caps :
			*script_global(262145 + 30666).as<int64_t*>() = 1;// Sprunk Forwards Cap
			*script_global(262145 + 30667).as<int64_t*>() = 1;// eCola Forwards Cap
			//Bodysuits :
			*script_global(262145 + 30668).as<int64_t*>() = 1;// eCola Bodysuit
			*script_global(262145 + 30669).as<int64_t*>() = 1;// Sprunk Bodysuit
			//Parachute bags :
			*script_global(262145 + 30670).as<int64_t*>() = 1;// Sprunk Parachute Bag
			*script_global(262145 + 30671).as<int64_t*>() = 1;// eCola Parachute Bag
			*script_global(262145 + 30672).as<int64_t*>() = 1;// Halloween Parachute Bag
			//Other Stuff :
			*script_global(262145 + 23899).as<int64_t*>() = 1;// Please Stop Me Mask
			*script_global(262145 + 23900).as<int64_t*>() = 1;// Highflyer Parachute Bag
			//--Casino Store--1.57
			*script_global(262145 + 27028).as<int64_t*>() = 1; //Ace Mask
			*script_global(262145 + 27029).as<int64_t*>() = 1;//Ace Mask
			*script_global(262145 + 27030).as<int64_t*>() = 1;//Ace Mask
			*script_global(262145 + 27031).as<int64_t*>() = 1;//Ace Mask
			//Paintings:
			*script_global(262145 + 27443).as<int64_t*>() = 18200;// Howler
			*script_global(262145 + 27509).as<int64_t*>() = 22500;// Stay Connected
			*script_global(262145 + 27698).as<int64_t*>() = 22500;// (chips)Skull
			*script_global(262145 + 27699).as<int64_t*>() = 22500;// (chips)Skull
			*script_global(262145 + 27700).as<int64_t*>() = 22500;// (chips)Skull
			*script_global(262145 + 27701).as<int64_t*>() = 22500;// (chips)Skull
			*script_global(262145 + 27702).as<int64_t*>() = 22500;// (chips)Skull
			*script_global(262145 + 27703).as<int64_t*>() = 22500;// (chips)Skull
			//- Returning player bonus content offline / online:
			*script_global(151130).as<int64_t*>() = 2;
			//Raygun:
			*script_global(102284).as<int64_t*>() = 90;
			*script_global(102285).as<int64_t*>() = 1;

		} QUEUE_JOB_END_CLAUSE
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