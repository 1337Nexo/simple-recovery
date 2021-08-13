#include "common.hpp"
#include "stat_loader.h"
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
	void stat_loader::render()
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
	}

	std::filesystem::path stat_loader::get_stats_config()
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

		file_path /= "stat_loader.json";

		return file_path;
	}

	nlohmann::json stat_loader::get_stats_json()
	{
		auto file_path = get_stats_config();
		nlohmann::json locations;
		std::ifstream file(file_path);

		if (!file.fail())
			file >> locations;

		return locations;
	}

	std::vector<std::string> stat_loader::list_stats()
	{
		std::vector<std::string> return_value;
		auto json = get_stats_json();
		for (auto& item : json.items())
			return_value.push_back(item.key());
		return return_value;
	}

	void stat_loader::load_stat_menu(std::string& selected_stat, stats_json::stats_json& stat_obj)
	{
		if (!selected_stat.empty())
		{
			auto events = get_stats_json();
			if (events[selected_stat].is_null())
				return;
			stat_obj = events[selected_stat].get<stats_json::stats_json>();
		}
	}

	void stat_loader::save_stat(char* stat_name, stats_json::stats_json& stat_obj)
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

	void stat_loader::delete_stat(std::string name)
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