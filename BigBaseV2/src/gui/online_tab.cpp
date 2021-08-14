#include "common.hpp"
#include "imgui.h"
#include "script.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "gta_util.hpp"
#include "features.hpp"
#include "gui.hpp"
#include "script_local.hpp"
#include "stat_editor.h"
#include "online_tab.h"
#include "script_global.hpp"
#include "gta/VehicleValues.h"
#include "misc/cpp/imgui_stdlib.h"
#include "local_player.hpp"
#include "imgui.cpp"
#include "diamond_casino_heist.h"
#include "helpers/helper.hpp"

using namespace big;

namespace big
{
	void online_tab::render()
	{
		if (ImGui::BeginTabItem("Online"))
		{
			ImGui::Text("Ballistic Equipment");
			static int ballisticarmorvalue;
			ImGui::InputInt("##bvalue", &ballisticarmorvalue);
			ImGui::SameLine();
			if (ImGui::Button("Set Ballistic Armor Value"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					*script_global(262145).at(19995).as<int*>() = ballisticarmorvalue; // tuneables_processing
				} QUEUE_JOB_END_CLAUSE
			}
			ImGui::Separator();
			ImGui::Text("Helpful shit");
			if (ImGui::Button("Clear Wanted Level"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					if (auto player_info = gta_util::get_local_playerinfo())
						if (player_info->m_is_wanted)
							player_info->m_wanted_level = 0;
				} QUEUE_JOB_END_CLAUSE
			}
			ImGui::SameLine();
			if (ImGui::Button("Stop Cutscene"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
				} QUEUE_JOB_END_CLAUSE
			}
			ImGui::SameLine();
			if (ImGui::Button("Go Into Personal Vehicle"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					*script_global(2409299).at(8).as<int*>() = 1;
				} QUEUE_JOB_END_CLAUSE
			}
			ImGui::Separator();
			ImGui::Text("Rank");
			static int level{};
			ImGui::PushItemWidth(200);
			ImGui::InputInt("Rank##r", &level);
			ImGui::PopItemWidth();
			ImGui::SameLine();
			if (ImGui::Button("Apply"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					if (level >= 0 && level <= 8000)
					{
						STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_GLOBALXP"), helper::get_rp_value(level), true);
						if (g_local_player.character_index == 0)
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_XP_FM"), helper::get_rp_value(level), TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_SET_RP_GIFT_ADMIN"), helper::get_rp_value(level), TRUE);
						}
						else
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_XP_FM"), helper::get_rp_value(level), TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_SET_RP_GIFT_ADMIN"), helper::get_rp_value(level), TRUE);
						}
					}
				} QUEUE_JOB_END_CLAUSE
			}

			ImGui::Separator();
			ImGui::Text("Packed Bools");
			static int packed_bool{};
			static bool packed_bool_value = true;
			const char* const packed_bools[]{ "_NGPSTAT_BOOL", "_NGTATPSTAT_BOOL", "_NGDLCPSTAT_BOOL", "_DLCBIKEPSTAT_BOOL", "_DLCGUNPSTAT_BOOL", "_GUNTATPSTAT_BOOL", "_DLCSMUGCHARPSTAT_BOOL", "_GANGOPSPSTAT_BOOL", "_BUSINESSBATPSTAT_BOOL", "_ARENAWARSPSTAT_BOOL", "_CASINOPSTAT_BOOL", "_CASINOHSTPSTAT_BOOL", "_HEIST3TATTOOSTAT_BOOL", "_SU20PSTAT_BOOL", "_SU20TATTOOSTAT_BOOL", "_HISLANDPSTAT_BOOL", "_TUNERPSTAT_BOOL" };
			ImGui::PushItemWidth(300.f);
			ImGui::Combo("Packed Bools", &packed_bool, packed_bools, (int)(sizeof(packed_bools) / sizeof(*packed_bools)));
			ImGui::PopItemWidth();
			ImGui::SameLine();
			ImGui::Checkbox("Packed Bool Value", &packed_bool_value);
			ImGui::SameLine();
			if (ImGui::Button("Apply Packed Bool"))
			{
				switch (packed_bool)
				{
				case 0:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 0, 192);
						helper::set_mass_packed_bool(packed_bool_value, 513, 705);
						helper::set_mass_packed_bool(packed_bool_value, 2919, 3111);
						helper::set_mass_packed_bool(packed_bool_value, 3111, 3879);
						helper::set_mass_packed_bool(packed_bool_value, 4207, 4399);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 1:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 6029, 6413);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 2:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 7385, 7641);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 3:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 9361, 9553);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 4:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 15369, 15561);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 5:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 15562, 15946);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 6:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 15946, 16010);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 7:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 18098, 18162);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 8:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 22066, 22194);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 9:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 24962, 25538);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 10:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 26810, 27258);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 11:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 28098, 28354);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 12:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 28355, 28483);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 13:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 30227, 30355);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 14:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 30355, 30483);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 15:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 30515, 30707);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 16:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_mass_packed_bool(packed_bool_value, 31707, 32283);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				}
			}

			ImGui::Text("_SU20PSTAT_BOOL -> Summer Update.\n_CASINOPSTAT_BOOL -> Casino DLC.\n_CASINOHSTPSTAT_BOOL -> Casino Heist DLC (arcade stuff etc.).\n_DLCGUNPSTAT_BOOL -> Gun Running DLC (bunker research).\n_ARENAWARSPSTAT_BOOL -> Arena Wars DLC.\n_HISLANDPSTAT_BOOL -> Cayo Perico Heist DLC (golden gun etc.).\n_DLCBIKEPSTAT_BOOL -> Bikers DLC.\n_TUNERPSTAT_BOOL -> Tuners DLC.");

			ImGui::Separator();
			ImGui::Text("Unlocks");
			static int unlock{};
			const char* const unlocks[]{ "Bools", "Ints", "Stats", "Modded Run", "Shotaro", "Cayo Perico Heist", "Diamond Casino Heist", "Bunker Research", "Reset Mental State", "Gold Business Battle Trophy", "Unhide Gunlocker Weapons" };
			ImGui::PushItemWidth(300.f);
			ImGui::Combo("Unlocks", &unlock, unlocks, (int)(sizeof(unlocks) / sizeof(*unlocks)));
			ImGui::SameLine();
			if (ImGui::Button("Unlock"))
			{
				switch (unlock)
				{
				case 0:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::bool_unlocks();
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 1:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::int_unlocks();
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 2:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						if (g_local_player.character_index == MP0)
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_STAM"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_STRN"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_FLY"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_STL"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_LUNG"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_DRIV"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_SCRIPT_INCREASE_SHO"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_FM_HEALTH_1_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_FM_HEALTH_2_UNLCK"), -1, TRUE);
						}
						else
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_STAM"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_STRN"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_FLY"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_STL"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_LUNG"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_DRIV"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_SCRIPT_INCREASE_SHO"), 100, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_FM_HEALTH_1_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_FM_HEALTH_2_UNLCK"), -1, TRUE);
						}
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 3:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						if (g_local_player.character_index == MP0)
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_ABILITY_1_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_ABILITY_2_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_ABILITY_3_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_FM_ABILITY_1_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_FM_ABILITY_2_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CHAR_FM_ABILITY_3_UNLCK"), -1, TRUE);
						}
						else
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_ABILITY_1_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_ABILITY_2_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_ABILITY_3_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_FM_ABILITY_1_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_FM_ABILITY_2_UNLCK"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CHAR_FM_ABILITY_3_UNLCK"), -1, TRUE);
						}
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 4:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						if (g_local_player.character_index == MP0)
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CRDEADLINE"), 5, TRUE);
						}
						else
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CRDEADLINE"), 5, TRUE);
						}
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 5:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						if (g_local_player.character_index == MP0)
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_LOSTANDFOUND"), 500000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_SUNSET"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_TREASURE_HUNTER"), 1000000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_WRECK_DIVING"), 1000000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_KEINEMUSIK"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_PALMS_TRAX"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_MOODYMANN"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_FILL_YOUR_BAGS"), 10000000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_AWD_WELL_PREPARED"), 50, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_H4_PLAYTHROUGH_STATUS"), 3, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_INTELGATHER"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_COMPOUNDINFILT"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_LOOT_FINDER"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_MAX_DISRUPT"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_THE_ISLAND_HEIST"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_GOING_ALONE"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_TEAM_WORK"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_MIXING_UP"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_PRO_THIEF"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_CAT_BURGLAR"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_ONE_OF_THEM"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_GOLDEN_GUN"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_ELITE_THIEF"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_PROFESSIONAL"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_HELPING_OUT"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_COURIER"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_PARTY_VIBES"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_HELPING_HAND"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP0_AWD_ELEVENELEVEN"), TRUE, TRUE);
						}
						else
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_LOSTANDFOUND"), 500000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_SUNSET"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_TREASURE_HUNTER"), 1000000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_WRECK_DIVING"), 1000000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_KEINEMUSIK"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_PALMS_TRAX"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_MOODYMANN"), 1800000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_FILL_YOUR_BAGS"), 10000000, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_AWD_WELL_PREPARED"), 50, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_H4_PLAYTHROUGH_STATUS"), 3, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_INTELGATHER"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_COMPOUNDINFILT"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_LOOT_FINDER"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_MAX_DISRUPT"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_THE_ISLAND_HEIST"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_GOING_ALONE"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_TEAM_WORK"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_MIXING_UP"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_PRO_THIEF"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_CAT_BURGLAR"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_ONE_OF_THEM"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_GOLDEN_GUN"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_ELITE_THIEF"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_PROFESSIONAL"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_HELPING_OUT"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_COURIER"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_PARTY_VIBES"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_HELPING_HAND"), TRUE, TRUE);
							STATS::STAT_SET_BOOL(RAGE_JOAAT("MP1_AWD_ELEVENELEVEN"), TRUE, TRUE);
						}
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 6:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						if (g_local_player.character_index == MP0)
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_H3_COMPLETEDPOSIX"), 0, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CAS_HEIST_FLOW"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_H3OPT_ACCESSPOINTS"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP0_H3OPT_POI"), -1, TRUE);
						}
						else
						{
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_H3_COMPLETEDPOSIX"), 0, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CAS_HEIST_FLOW"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_H3OPT_ACCESSPOINTS"), -1, TRUE);
							STATS::STAT_SET_INT(RAGE_JOAAT("MP1_H3OPT_POI"), -1, TRUE);
						}
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 7:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_packed_bool(15381, 1);
						helper::set_packed_bool(15382, 1);
						helper::set_packed_bool(15428, 1);
						helper::set_packed_bool(15429, 1);
						helper::set_packed_bool(15430, 1);
						helper::set_packed_bool(15431, 1);
						helper::set_packed_bool(15491, 1);
						helper::set_packed_bool(15432, 1);
						helper::set_packed_bool(15433, 1);
						helper::set_packed_bool(15434, 1);
						helper::set_packed_bool(15435, 1);
						helper::set_packed_bool(15436, 1);
						helper::set_packed_bool(15437, 1);
						helper::set_packed_bool(15438, 1);
						helper::set_packed_bool(15439, 1);
						helper::set_packed_bool(15447, 1);
						helper::set_packed_bool(15448, 1);
						helper::set_packed_bool(15449, 1);
						helper::set_packed_bool(15450, 1);
						helper::set_packed_bool(15451, 1);
						helper::set_packed_bool(15452, 1);
						helper::set_packed_bool(15453, 1);
						helper::set_packed_bool(15454, 1);
						helper::set_packed_bool(15455, 1);
						helper::set_packed_bool(15456, 1);
						helper::set_packed_bool(15457, 1);
						helper::set_packed_bool(15458, 1);
						helper::set_packed_bool(15459, 1);
						helper::set_packed_bool(15460, 1);
						helper::set_packed_bool(15461, 1);
						helper::set_packed_bool(15462, 1);
						helper::set_packed_bool(15463, 1);
						helper::set_packed_bool(15464, 1);
						helper::set_packed_bool(15465, 1);
						helper::set_packed_bool(15466, 1);
						helper::set_packed_bool(15467, 1);
						helper::set_packed_bool(15468, 1);
						helper::set_packed_bool(15469, 1);
						helper::set_packed_bool(15470, 1);
						helper::set_packed_bool(15471, 1);
						helper::set_packed_bool(15472, 1);
						helper::set_packed_bool(15473, 1);
						helper::set_packed_bool(15474, 1);
						helper::set_packed_bool(15492, 1);
						helper::set_packed_bool(15493, 1);
						helper::set_packed_bool(15494, 1);
						helper::set_packed_bool(15495, 1);
						helper::set_packed_bool(15496, 1);
						helper::set_packed_bool(15497, 1);
						helper::set_packed_bool(15498, 1);
						helper::set_packed_bool(15499, 1);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 8:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						STATS::STAT_SET_FLOAT(RAGE_JOAAT("MPPLY_PLAYER_MENTAL_STATE"), 0.f, true);
						if (g_local_player.character_index == MP0)
						{
							STATS::STAT_SET_FLOAT(RAGE_JOAAT("MP0_PLAYER_MENTAL_STATE"), 0.f, true);
						}
						else
						{
							STATS::STAT_SET_FLOAT(RAGE_JOAAT("MP1_PLAYER_MENTAL_STATE"), 0.f, true);
						}
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 9:
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_packed_int(22058, 20);
					} QUEUE_JOB_END_CLAUSE
						break;
				}
				case 10:
				{
					//int func_2723(int iParam0)
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
						break;
				}
				}
			}
			ImGui::PopItemWidth();

			if (ImGui::CollapsingHeader("Diamond Casino Heist"))
			{
				diamond_casino_heist::do_presentation_layer();
			}
			ImGui::EndTabItem();
		}
	}
}
