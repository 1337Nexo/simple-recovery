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
					*script_global(2671444).at(39).as<int*>() = 1;
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
						helper::STAT_SET_INT("MPPLY_GLOBALXP", helper::get_rp_value(level));
						helper::STAT_SET_INT("MPX_CHAR_XP_FM", helper::get_rp_value(level));
						helper::STAT_SET_INT("MPX_CHAR_SET_RP_GIFT_ADMIN", helper::get_rp_value(level));
					}
				} QUEUE_JOB_END_CLAUSE
			}

			ImGui::Separator();
			if (ImGui::CollapsingHeader("Packed Bools Unlocks"))
			{
				static int packed_bool{};
				static bool packed_bool_value = true;
				const char* const packed_bools[]{ "_NGPSTAT_BOOL", "_NGTATPSTAT_BOOL", "_NGDLCPSTAT_BOOL", "_DLCBIKEPSTAT_BOOL", "_DLCGUNPSTAT_BOOL", "_GUNTATPSTAT_BOOL", "_DLCSMUGCHARPSTAT_BOOL", "_GANGOPSPSTAT_BOOL", "_BUSINESSBATPSTAT_BOOL", "_ARENAWARSPSTAT_BOOL", "_CASINOPSTAT_BOOL", "_CASINOHSTPSTAT_BOOL", "_HEIST3TATTOOSTAT_BOOL", "_SU20PSTAT_BOOL", "_SU20TATTOOSTAT_BOOL", "_HISLANDPSTAT_BOOL", "_TUNERPSTAT_BOOL""_FIXERPSTAT_BOOL","_FIXERTATTOOSTAT_BOOL" };
				ImGui::PushItemWidth(300.f);
				ImGui::Combo("###Packed_Bools", &packed_bool, packed_bools, IM_ARRAYSIZE(packed_bools));
				ImGui::PopItemWidth();
				ImGui::Checkbox("Unlock/Lock", &packed_bool_value);
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
					case 17:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::set_mass_packed_bool(packed_bool_value, 32283, 32411);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 18:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::set_mass_packed_bool(packed_bool_value, 32411, 32475);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					}
				}
				ImGui::Text("_SU20PSTAT_BOOL -> Summer Update.\n_CASINOPSTAT_BOOL -> Casino DLC.\n_CASINOHSTPSTAT_BOOL -> Casino Heist DLC (arcade stuff etc.).\n_DLCGUNPSTAT_BOOL -> Gun Running DLC (bunker research).\n_ARENAWARSPSTAT_BOOL -> Arena Wars DLC.\n_HISLANDPSTAT_BOOL -> Cayo Perico Heist DLC (golden gun etc.).\n_DLCBIKEPSTAT_BOOL -> Bikers DLC.\n_TUNERPSTAT_BOOL -> Tuners DLC.");
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader("other Unlocks"))
			{
				ImGui::Text("Unlocks");
				static int unlock{};
				const char* const unlocks[]{ "Magic", "Bools", "Ints", "Modded Run", "Cayo Perico Heist", "Arcade", "Bunker", "Reset Mental State", "Night Clubs Decorations", "Vehicles Wholesale Price","Facility Decorations(Maintenance Area)","Holiday and Other","Unhide Gunlocker Weapons" };
				ImGui::PushItemWidth(300.f);
				ImGui::Combo("Unlocks", &unlock, unlocks, IM_ARRAYSIZE(unlocks));
				ImGui::PopItemWidth();
				ImGui::SameLine();
				if (ImGui::Button("Unlock"))
				{
					switch (unlock)
					{
					case 0:
					{
						helper::magic();
						break;
					}
					case 1:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::bool_unlocks();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 2:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::int_unlocks();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 3:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::STAT_SET_INT("MPX_CHAR_ABILITY_1_UNLCK", -1);
							helper::STAT_SET_INT("MPX_CHAR_ABILITY_2_UNLCK", -1);
							helper::STAT_SET_INT("MPX_CHAR_ABILITY_3_UNLCK", -1);
							helper::STAT_SET_INT("MPX_CHAR_FM_ABILITY_1_UNLCK", -1);
							helper::STAT_SET_INT("MPX_CHAR_FM_ABILITY_2_UNLCK", -1);
							helper::STAT_SET_INT("MPX_CHAR_FM_ABILITY_3_UNLCK", -1);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 4:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::STAT_SET_INT("MPX_AWD_LOSTANDFOUND", 500000);
							helper::STAT_SET_INT("MPX_AWD_SUNSET", 1800000);
							helper::STAT_SET_INT("MPX_AWD_TREASURE_HUNTER", 1000000);
							helper::STAT_SET_INT("MPX_AWD_WRECK_DIVING", 1000000);
							helper::STAT_SET_INT("MPX_AWD_KEINEMUSIK", 1800000);
							helper::STAT_SET_INT("MPX_AWD_PALMS_TRAX", 1800000);
							helper::STAT_SET_INT("MPX_AWD_MOODYMANN", 1800000);
							helper::STAT_SET_INT("MPX_AWD_FILL_YOUR_BAGS", 10000000);
							helper::STAT_SET_INT("MPX_AWD_WELL_PREPARED", 50);
							helper::STAT_SET_INT("MPX_H4_PLAYTHROUGH_STATUS", 3);
							helper::STAT_SET_BOOL("MPX_AWD_INTELGATHER", true);
							helper::STAT_SET_BOOL("MPX_AWD_COMPOUNDINFILT", true);
							helper::STAT_SET_BOOL("MPX_AWD_LOOT_FINDER", true);
							helper::STAT_SET_BOOL("MPX_AWD_MAX_DISRUPT", true);
							helper::STAT_SET_BOOL("MPX_AWD_THE_ISLAND_HEIST", true);
							helper::STAT_SET_BOOL("MPX_AWD_GOING_ALONE", true);
							helper::STAT_SET_BOOL("MPX_AWD_TEAM_WORK", true);
							helper::STAT_SET_BOOL("MPX_AWD_MIXING_UP", true);
							helper::STAT_SET_BOOL("MPX_AWD_PRO_THIEF", true);
							helper::STAT_SET_BOOL("MPX_AWD_CAT_BURGLAR", true);
							helper::STAT_SET_BOOL("MPX_AWD_ONE_OF_THEM", true);
							helper::STAT_SET_BOOL("MPX_AWD_GOLDEN_GUN", true);
							helper::STAT_SET_BOOL("MPX_AWD_ELITE_THIEF", true);
							helper::STAT_SET_BOOL("MPX_AWD_PROFESSIONAL", true);
							helper::STAT_SET_BOOL("MPX_AWD_HELPING_OUT", true);
							helper::STAT_SET_BOOL("MPX_AWD_COURIER", true);
							helper::STAT_SET_BOOL("MPX_AWD_PARTY_VIBES", true);
							helper::STAT_SET_BOOL("MPX_AWD_HELPING_HAND", true);
							helper::STAT_SET_BOOL("MPX_AWD_ELEVENELEVEN", true);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 5:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::set_stat_bit("MPX_CAS_HEIST_FLOW", 9); //Hidden Gunner
							helper::arcade();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 6:
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
							helper::STAT_SET_INT("MPX_SR_HIGHSCORE_1", 910);
							helper::STAT_SET_INT("MPX_SR_HIGHSCORE_2", 2500);
							helper::STAT_SET_INT("MPX_SR_HIGHSCORE_3", 3440);
							helper::STAT_SET_INT("MPX_SR_HIGHSCORE_4", 3340);
							helper::STAT_SET_INT("MPX_SR_HIGHSCORE_5", 4150);
							helper::STAT_SET_INT("MPX_SR_HIGHSCORE_6", 560);
							helper::STAT_SET_INT("MPX_SR_TARGETS_HIT", 270);
							helper::STAT_SET_INT("MPX_SR_WEAPON_BIT_SET", 262143);
							helper::STAT_SET_BOOL("MPX_SR_TIER_1_REWARD", true);
							helper::STAT_SET_BOOL("MPX_SR_INCREASE_THROW_CAP", true);
							helper::STAT_SET_BOOL("MPX_SR_TIER_3_REWARD", true);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 7:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::STAT_SET_FLOAT("MPPLY_PLAYER_MENTAL_STATE", 0.f);
							helper::STAT_SET_FLOAT("MPX_PLAYER_MENTAL_STATE", 0.f);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 8:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::night_clubs();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 9:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::vehicles_wholesale_price();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 10:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::facility();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 11:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::other();
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					case 12:
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							helper::set_packed_bool(7387, false);
							helper::set_packed_bool(7388, false);
							helper::set_packed_bool(7389, false);
							helper::set_packed_bool(7390, false);
							helper::set_packed_bool(7391, false);
							helper::set_packed_bool(7392, false);
							helper::set_packed_bool(7393, false);
							helper::set_packed_bool(7394, false);
							helper::set_packed_bool(7395, false);
							helper::set_packed_bool(7396, false);
							helper::set_packed_bool(7397, false);
							helper::set_packed_bool(7398, false);
							helper::set_packed_bool(7399, false);
							helper::set_packed_bool(7400, false);
							helper::set_packed_bool(7401, false);
							helper::set_packed_bool(7402, false);
							helper::set_packed_bool(7403, false);
							helper::set_packed_bool(7404, false);
							helper::set_packed_bool(7405, false);
							helper::set_packed_bool(7406, false);
							helper::set_packed_bool(7407, false);
							helper::set_packed_bool(7408, false);
							helper::set_packed_bool(7409, false);
							helper::set_packed_bool(7410, false);
							helper::set_packed_bool(7411, false);
							helper::set_packed_bool(7412, false);
							helper::set_packed_bool(7413, false);
							helper::set_packed_bool(7414, false);
							helper::set_packed_bool(7415, false);
							helper::set_packed_bool(7416, false);
							helper::set_packed_bool(7417, false);
							helper::set_packed_bool(7418, false);
							helper::set_packed_bool(7419, false);
							helper::set_packed_bool(7420, false);
							helper::set_packed_bool(7421, false);
							helper::set_packed_bool(7422, false);
							helper::set_packed_bool(7423, false);
							helper::set_packed_bool(7424, false);
							helper::set_packed_bool(7425, false);
							helper::set_packed_bool(7426, false);
							helper::set_packed_bool(7427, false);
							helper::set_packed_bool(7428, false);
							helper::set_packed_bool(7429, false);
							helper::set_packed_bool(7430, false);
							helper::set_packed_bool(7431, false);
							helper::set_packed_bool(7432, false);
							helper::set_packed_bool(7433, false);
							helper::set_packed_bool(7434, false);
							helper::set_packed_bool(7435, false);
							helper::set_packed_bool(7436, false);
							helper::set_packed_bool(7437, false);
							helper::set_packed_bool(7438, false);
							helper::set_packed_bool(7439, false);
							helper::set_packed_bool(7440, false);
							helper::set_packed_bool(7441, false);
							helper::set_packed_bool(7442, false);
							helper::set_packed_bool(7443, false);
							helper::set_packed_bool(7444, false);
							helper::set_packed_bool(7445, false);
							helper::set_packed_bool(7446, false);
							helper::set_packed_bool(7447, false);
							helper::set_packed_bool(7448, false);
							helper::set_packed_bool(7449, false);
							helper::set_packed_bool(7466, false);
							helper::set_packed_bool(7621, false);
							helper::set_packed_bool(7622, false);
							helper::set_packed_bool(7623, false);
							helper::set_packed_bool(7624, false);
							helper::set_packed_bool(7625, false);
							helper::set_packed_bool(7626, false);
							helper::set_packed_bool(7627, false);
							helper::set_packed_bool(15441, false);
							helper::set_packed_bool(15442, false);
							helper::set_packed_bool(15443, false);
							helper::set_packed_bool(15444, false);
							helper::set_packed_bool(15445, false);
							helper::set_packed_bool(15446, false);
							helper::set_packed_bool(18100, false);
							helper::set_packed_bool(18101, false);
							helper::set_packed_bool(18102, false);
							helper::set_packed_bool(18103, false);
							helper::set_packed_bool(18104, false);
							helper::set_packed_bool(18105, false);
							helper::set_packed_bool(15995, false);
							helper::set_packed_bool(15548, false);
							helper::set_packed_bool(25241, false);
							helper::set_packed_bool(25242, false);
							helper::set_packed_bool(25243, false);
							helper::set_packed_bool(25518, false);
							helper::set_packed_bool(25519, false);
							helper::set_packed_bool(30321, false);
							helper::set_packed_bool(30322, false);
							helper::set_packed_bool(30323, false);
							helper::set_packed_bool(28259, false);
							helper::set_packed_bool(28260, false);
							helper::set_packed_bool(28261, false);
							helper::set_packed_bool(7386, false);
						} QUEUE_JOB_END_CLAUSE
							break;
					}
					}
				}
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader("Ballistic Equipment Value"))
			{
				ImGui::Text("Ballistic Equipment");
				static int ballisticarmorvalue;
				ImGui::InputInt("##bvalue", &ballisticarmorvalue);
				ImGui::SameLine();
				if (ImGui::Button("Set Ballistic Armor Value"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						*script_global(262145).at(20082).as<int*>() = ballisticarmorvalue; // tuneables_processing -156036296
					} QUEUE_JOB_END_CLAUSE
				}
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader("Diamond Casino Heist"))
			{
				diamond_casino_heist::do_presentation_layer();
			}
			ImGui::EndTabItem();
		}
	}
}
