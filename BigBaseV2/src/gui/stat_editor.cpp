#include "common.hpp"
#include "stat_editor.h"
#include "imgui.h"
#include "script.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "gta_util.hpp"
#include "features.hpp"
#include "gui.hpp"
#include "misc/cpp/imgui_stdlib.h"
#include "imgui_internal.h"
#include "helpers/helper.hpp"

using namespace big;

namespace big
{
	void stat_editor::render()
	{
		if (ImGui::BeginTabItem("Stat Editor"))
		{
			ImGui::Text("a classic stat editor");
			static std::string stat_name{ "MPPLY_KILLS_PLAYERS" };
			static int stat_type = 0;
			static int integer_value = 0;
			static float float_value = 0.00f;
			static bool boolean_value = false;
			static float increment_value = 0.00f;
			if (ImGui::InputText("###stat", &stat_name, ImGuiInputTextFlags_CharsUppercase))
			{
				const auto hash = rage::joaat(stat_name);
				g_fiber_pool->queue_job([hash]
				{
					if (stat_type == 0)
					{
						STATS::STAT_GET_INT(hash, &integer_value, true);
					}
					else if (stat_type == 1)
					{
						STATS::STAT_GET_BOOL(hash, &boolean_value, true);
					}
				});
			}
			ImGui::RadioButton("INT", &stat_type, 0); ImGui::SameLine();
			ImGui::RadioButton("BOOL", &stat_type, 1); ImGui::SameLine();
			ImGui::RadioButton("FLOAT", &stat_type, 2); ImGui::SameLine();
			ImGui::RadioButton("INCREMENT", &stat_type, 3);
			if (stat_type == 0)
			{
				ImGui::InputScalar("###int", ImGuiDataType_S32, &integer_value);
			}
			else if (stat_type == 1)
			{
				ImGui::Checkbox("###bool", &boolean_value);
			}
			else if (stat_type == 2)
			{
				ImGui::InputFloat("###float", &float_value, 0.1f, 1.0f, "%.3f");
			}
			else if (stat_type == 3)
			{
				ImGui::InputFloat("###increment", &increment_value, 10.0f, 100.0f, "%.3f");
			}
			if (ImGui::Button("Apply Value"))
			{
				std::string character_index = "MP" + std::to_string(g_local_player.character_index);
				LOG_INFO("stat_name {}", stat_name);
				stat_name = std::regex_replace(stat_name, std::regex(R"(\$)"), "");
				stat_name = std::regex_replace(stat_name, std::regex(R"(\MPX)"), character_index);
				stat_name = std::regex_replace(stat_name, std::regex(R"(\MPx)"), character_index);
				LOG_INFO("stat_name_after_regex {}", stat_name);

				const auto hash = rage::joaat(stat_name);
				LOG_INFO("hash {}\n", hash);
				g_fiber_pool->queue_job([hash]
				{
					if (stat_type == 0)
					{
						if (STATS::STAT_SET_INT(hash, integer_value, TRUE))
							STATS::STAT_GET_INT(hash, &integer_value, TRUE);
					}
					else if (stat_type == 1)
					{
						if (STATS::STAT_SET_BOOL(hash, boolean_value, TRUE))
							STATS::STAT_GET_BOOL(hash, &boolean_value, TRUE);
					}
					else if (stat_type == 2)
					{
						if (STATS::STAT_SET_FLOAT(hash, float_value, TRUE))
							STATS::STAT_GET_FLOAT(hash, &float_value, TRUE);
					}
					else if (stat_type == 3)
					{
						STATS::STAT_INCREMENT(hash, increment_value);
						STATS::STAT_GET_FLOAT(hash, &increment_value, TRUE);
					}
				});
			}
			ImGui::SameLine();
			if (ImGui::Button("Get Value"))
			{
				std::string character_index = "MP" + std::to_string(g_local_player.character_index);
				LOG_INFO("stat_name {}", stat_name);
				stat_name = std::regex_replace(stat_name, std::regex(R"(\$)"), "");
				stat_name = std::regex_replace(stat_name, std::regex(R"(\MPX)"), character_index);
				stat_name = std::regex_replace(stat_name, std::regex(R"(\MPx)"), character_index);
				LOG_INFO("stat_name_after_regex {}", stat_name);

				const auto hash = rage::joaat(stat_name);
				LOG_INFO("hash {}\n", hash);
				g_fiber_pool->queue_job([hash]
				{
					if (stat_type == 0)
					{
						STATS::STAT_GET_INT(hash, &integer_value, true);
					}
					else if (stat_type == 1)
					{
						STATS::STAT_GET_BOOL(hash, &boolean_value, true);
					}
					else if (stat_type == 2)
					{
						STATS::STAT_GET_FLOAT(hash, &float_value, true);
					}
					else if (stat_type == 3)
					{
						STATS::STAT_GET_FLOAT(hash, &increment_value, true);
					}
				});
			}
			if (ImGui::CollapsingHeader("Packed Bool Editor"))
			{
				ImGui::Text("a packed bool editor that probably no one will use it");
				ImGui::Text("you need to find the index by looking at gta scripts");
				ImGui::Text("the function that handles the packed bool stats is func_19945");
				ImGui::Text("you can find it by looking at freemode.c or other scripts, ctrl+f will be useful");
				ImGui::Text("the 1st parameter is the INDEX");
				ImGui::Text("the 2nd parameter is the VALUE");
				ImGui::Text("you can ignore the 3rd and the 4th parameter");
				ImGui::Text("example:");
				ImGui::Text("func_19945(31736, 1, -1, 1);");
				ImGui::Text("this packed bool index is responsible to 'The Frontier' special outfit");
				static int b_index = 31736;
				static bool pbe_value = true;
				ImGui::PushItemWidth(200);
				ImGui::InputScalar("Index##1", ImGuiDataType_S32, &b_index);
				ImGui::PopItemWidth();
				ImGui::Checkbox("Value##pbevalue", &pbe_value);
				if (ImGui::Button("Set Packed Bool Value"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_packed_bool(b_index, pbe_value ? 1 : 0);
					} QUEUE_JOB_END_CLAUSE
				}
			}

			if (ImGui::CollapsingHeader("Packed Int Editor"))
			{
				ImGui::Text("too complex, no explanation");
				static int i_index = 22058;
				static int pie_value = 20;
				ImGui::PushItemWidth(200);
				ImGui::InputScalar("Index##2", ImGuiDataType_S32, &i_index);
				ImGui::InputScalar("Value##pievalue", ImGuiDataType_S32, &pie_value);
				ImGui::PopItemWidth();
				if (ImGui::Button("Set Packed Int Value"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_packed_int(i_index, pie_value);
					} QUEUE_JOB_END_CLAUSE
				}
			}
			ImGui::Separator();
			ImGui::EndTabItem();
		}
	}
}