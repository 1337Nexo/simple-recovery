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
		if (ImGui::BeginTabItem("Stat Loader"))
		{
			static stats_json::stats_json stat_obj{};
			ImGui::PushItemWidth(150);
			if (ImGui::InputInt("Stats", &stat_obj.stats, 1, 80))
			{
				if (stat_obj.stats == 0)
					stat_obj.stats = 1;
				if (stat_obj.stats > 250)
					stat_obj.stats = 250;
			}
			ImGui::PopItemWidth();
			stat_obj.stat_type.resize(stat_obj.stats);
			stat_obj.stat_name.resize(stat_obj.stats);
			stat_obj.stat_int_value.resize(stat_obj.stats);
			stat_obj.stat_bool_value.resize(stat_obj.stats);
			stat_obj.stat_float_value.resize(stat_obj.stats);
			ImGui::Separator();
			for (int i = 0; i < stat_obj.stats; i++)
			{
				ImGui::Text(fmt::format("Stat #{}", i + 1).c_str());
				ImGui::RadioButton(fmt::format("INT##{}", i + 1).c_str(), &stat_obj.stat_type[i], 0); ImGui::SameLine();
				ImGui::RadioButton(fmt::format("BOOL##{}", i + 1).c_str(), &stat_obj.stat_type[i], 1); ImGui::SameLine();
				ImGui::RadioButton(fmt::format("FLOAT##{}", i + 1).c_str(), &stat_obj.stat_type[i], 2);
				ImGui::PushItemWidth(450);
				ImGui::InputText(fmt::format("##name{}", i + 1).c_str(), &stat_obj.stat_name[i]);
				ImGui::PopItemWidth();
				if (stat_obj.stat_type[i] == 0)
				{
					ImGui::SameLine();
					ImGui::PushItemWidth(250);
					ImGui::InputInt(fmt::format("##int{}", i + 1).c_str(), &stat_obj.stat_int_value[i]);
					ImGui::PopItemWidth();
				}
				else if (stat_obj.stat_type[i] == 1)
				{
					ImGui::SameLine();
					bool stat_bool_value_tmp = stat_obj.stat_bool_value[i];
					if (ImGui::Checkbox(fmt::format("##bool{}", i + 1).c_str(), &stat_bool_value_tmp))
						stat_obj.stat_bool_value[i] = stat_bool_value_tmp;
				}
				else if (stat_obj.stat_type[i] == 2)
				{
					ImGui::SameLine();
					ImGui::PushItemWidth(250);
					ImGui::InputScalar(fmt::format("##float{}", i + 1).c_str(), ImGuiDataType_Float, &stat_obj.stat_float_value[i], NULL, NULL);
					ImGui::PopItemWidth();
				}
			}
			if (ImGui::Button("Set Stats"))
			{
				for (int i = 0; i < stat_obj.stats; i++)
				{
					const auto hash = rage::joaat(stat_obj.stat_name[i]);
					LOG(INFO) << hash;
					g_fiber_pool->queue_job([i, hash]
						{
							if (stat_obj.stat_type[i] == 0)
							{
								STATS::STAT_SET_INT(hash, stat_obj.stat_int_value[i], true);
							}
							else if (stat_obj.stat_type[i] == 1)
							{
								STATS::STAT_SET_BOOL(hash, stat_obj.stat_bool_value[i], true);
							}
							else if (stat_obj.stat_type[i] == 2)
							{
								STATS::STAT_SET_FLOAT(hash, stat_obj.stat_float_value[i], true);
							}
						});
				}
			}
			ImGui::Separator();
			auto stats = list_stats();
			static std::string selected_stat;
			ImGui::PushItemWidth(250);
			ImGui::Text("Saved Stats");
			if (ImGui::ListBoxHeader("##empty", ImVec2(200, 200)))
			{
				for (auto pair : stats)
				{
					if (ImGui::Selectable(pair.c_str(), selected_stat == pair))
						selected_stat = pair;
				}
				ImGui::ListBoxFooter();
			}
			ImGui::PopItemWidth();
			ImGui::SameLine();
			ImGui::BeginGroup();
			static char save_stat_name[50]{};
			ImGui::PushItemWidth(250);
			ImGui::InputText("##save_stat_name", save_stat_name, IM_ARRAYSIZE(save_stat_name));
			if (ImGui::Button("Save Stat"))
			{
				save_stat(save_stat_name, stat_obj);
			}
			ImGui::SameLine();
			if (ImGui::Button("Load Stat"))
			{
				load_stat_menu(selected_stat, stat_obj);
			}
			ImGui::SameLine();
			if (ImGui::Button("Delete Stat"))
			{
				if (!selected_stat.empty())
				{
					delete_stat(selected_stat);
					selected_stat.clear();
				}
			}
			ImGui::SameLine();
			if (ImGui::Button("Clear"))
			{
				stat_obj.stats = 1;
				stat_obj.stat_type.clear();
				stat_obj.stat_name.clear();
				stat_obj.stat_int_value.clear();
				stat_obj.stat_bool_value.clear();
				stat_obj.stat_float_value.clear();
			}
			ImGui::PopItemWidth();
			ImGui::EndGroup();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Stat Editor"))
		{
			ImGui::Text("a classic stat editor");
			ImGui::Text("you don't need to put $ at the start");
			ImGui::Text("it doesn't recognize MPX, just MP0 (1st character) or MP1 (2nd character)");
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
				const auto hash = rage::joaat(stat_name);
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

	std::filesystem::path stat_editor::get_stats_config()
	{
		auto file_path = std::filesystem::path(std::getenv("appdata"));
		file_path /= "BigBaseV2";

		if (!std::filesystem::exists(file_path))
		{
			std::filesystem::create_directory(file_path);
		}
		else if (!std::filesystem::is_directory(file_path))
		{
			std::filesystem::remove(file_path);
			std::filesystem::create_directory(file_path);
		}

		file_path /= "stat_editor.json";

		return file_path;
	}

	nlohmann::json stat_editor::get_stats_json()
	{
		auto file_path = get_stats_config();
		nlohmann::json locations;
		std::ifstream file(file_path);

		if (!file.fail())
			file >> locations;

		return locations;
	}

	std::vector<std::string> stat_editor::list_stats()
	{
		std::vector<std::string> return_value;
		auto json = get_stats_json();
		for (auto& item : json.items())
			return_value.push_back(item.key());
		return return_value;
	}

	void stat_editor::load_stat_menu(std::string& selected_stat, stats_json::stats_json& stat_obj)
	{
		if (!selected_stat.empty())
		{
			auto events = get_stats_json();
			if (events[selected_stat].is_null())
				return;
			stat_obj = events[selected_stat].get<stats_json::stats_json>();
		}
	}

	void stat_editor::save_stat(char* stat_name, stats_json::stats_json& stat_obj)
	{
		std::string stat_name_string = stat_name;
		if (!stat_name_string.empty())
		{
			auto json = get_stats_json();
			json[stat_name] = stat_obj;

			auto file_path = get_stats_config();
			std::ofstream file(file_path, std::ios::out | std::ios::trunc);
			file << json.dump(4);
			file.close();
			ZeroMemory(stat_name, sizeof(stat_name));
		}
	}

	void stat_editor::delete_stat(std::string name)
	{
		auto stats = get_stats_json();
		if (stats[name].is_null())
			return;
		stats.erase(name);
		auto file_path = get_stats_config();
		std::ofstream file(file_path, std::ios::out | std::ios::trunc);
		file << stats.dump(4);
		file.close();
	}
}