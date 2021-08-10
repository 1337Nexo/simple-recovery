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
#include "base_tab.h"
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
	void base_tab::render_base_tab()
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
					*script_global(262145).at(19995).as<int*>() = ballisticarmorvalue;
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
			static bool packed_bool_value{};
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
					helper::set_mass_packed_bool(packed_bool_value, 0, 192);
					helper::set_mass_packed_bool(packed_bool_value, 192, 384);
					helper::set_mass_packed_bool(packed_bool_value, 513, 705);
					helper::set_mass_packed_bool(packed_bool_value, 705, 1281);
					helper::set_mass_packed_bool(packed_bool_value, 2919, 3111);
					helper::set_mass_packed_bool(packed_bool_value, 3111, 3879);
					helper::set_mass_packed_bool(packed_bool_value, 4207, 4399);
					break;
				}
				case 1:
				{
					helper::set_mass_packed_bool(packed_bool_value, 6029, 6413);
					break;
				}
				case 2:
				{
					helper::set_mass_packed_bool(packed_bool_value, 7385, 7641);
					break;
				}
				case 3:
				{
					helper::set_mass_packed_bool(packed_bool_value, 9361, 9553);
					break;
				}
				case 4:
				{
					helper::set_mass_packed_bool(packed_bool_value, 15369, 15561);
					break;
				}
				case 5:
				{
					helper::set_mass_packed_bool(packed_bool_value, 15562, 15946);
					break;
				}
				case 6:
				{
					helper::set_mass_packed_bool(packed_bool_value, 15946, 16010);
					break;
				}
				case 7:
				{
					helper::set_mass_packed_bool(packed_bool_value, 18098, 18162);
					break;
				}
				case 8:
				{
					helper::set_mass_packed_bool(packed_bool_value, 22066, 22194);
					break;
				}
				case 9:
				{
					helper::set_mass_packed_bool(packed_bool_value, 24962, 25538);
					break;
				}
				case 10:
				{
					helper::set_mass_packed_bool(packed_bool_value, 26810, 27258);
					break;
				}
				case 11:
				{
					helper::set_mass_packed_bool(packed_bool_value, 28098, 28354);
					break;
				}
				case 12:
				{

					helper::set_mass_packed_bool(packed_bool_value, 28355, 28483);
					break;
				}
				case 13:
				{
					helper::set_mass_packed_bool(packed_bool_value, 30227, 30355);
					break;
				}
				case 14:
				{

					helper::set_mass_packed_bool(packed_bool_value, 30355, 30483);
					break;
				}
				case 15:
				{
					helper::set_mass_packed_bool(packed_bool_value, 30515, 30707);
					break;
				}
				case 16:
				{
					helper::set_mass_packed_bool(packed_bool_value, 31707, 32283);
					break;
				}
				}
			}

			ImGui::Text("_SU20PSTAT_BOOL -> Summer Update.\n_CASINOPSTAT_BOOL -> Casino DLC.\n_CASINOHSTPSTAT_BOOL -> Casino Heist DLC (arcade stuff etc.).\n_DLCGUNPSTAT_BOOL -> Gun Running DLC (bunker research).\n_ARENAWARSPSTAT_BOOL -> Arena Wars DLC.\n_HISLANDPSTAT_BOOL -> Cayo Perico Heist DLC (golden gun etc.).\n_DLCBIKEPSTAT_BOOL -> Bikers DLC.\n_TUNERPSTAT_BOOL -> Tuners DLC.");

			ImGui::Separator();
			ImGui::Text("Unlocks");
			static int unlock{};
			const char* const unlocks[]{ "Bools", "Ints", "Stats", "Modded Run", "Shotaro", "Cayo Perico Heist", "Diamond Casino Heist", "Bunker Research", "Reset Mental State", "Gold Business Battle Trophy"};
			ImGui::PushItemWidth(185.f);
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
				}
			}
			ImGui::PopItemWidth();

			if (ImGui::CollapsingHeader("Diamond Casino Heist"))
			{
				diamond_casino_heist::do_presentation_layer();
			}
			ImGui::EndTabItem();
		}

		stat_editor::render();

		if (ImGui::BeginTabItem("Settings"))
		{
			ImGui::Text("thanks to:");
			ImGui::Text("pocakking (bigbasev2)\nspankerincrease (bigbasev2-fix, diamond casino heist)\ngir489 (is the second personality of spankerincrease, lol)\ndatlimabean04 (bigbasev2-fix)\nsub1to (could not remember)\njonaaa (increment stat)\npolivilas (for the inspiration)\nShirabrixx82 (get rp value, rig slot machines, get into personal vehicle)");
			ImGui::Separator();
			if (ImGui::Button("Unload"))
			{
				g_running = false;
			}
			ImGui::EndTabItem();
		}
	}
}
