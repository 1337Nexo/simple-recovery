#pragma once

#include "common.hpp"
#include "natives.hpp"

namespace big
{
	namespace stats_json
	{
		struct stats_json
		{
			int stats = 1;
			std::vector<int> stat_type{};
			std::vector<std::string> stat_name{};
			std::vector<int> stat_int_value{};
			std::vector<bool> stat_bool_value{};
			std::vector<float> stat_float_value{};
		};
		static void to_json(nlohmann::json& j, const stats_json& attachment) {
			j = nlohmann::json{ {"stats", attachment.stats},
								{"stat_type", attachment.stat_type},
								{"stat_name", attachment.stat_name},
								{"stat_int_value", attachment.stat_int_value},
								{"stat_bool_value", attachment.stat_bool_value},
								{ "stat_float_value", attachment.stat_float_value },
			};
		}
		static void from_json(const nlohmann::json& j, stats_json& attachment) {
			j.at("stats").get_to(attachment.stats);
			j.at("stat_type").get_to(attachment.stat_type);
			j.at("stat_name").get_to(attachment.stat_name);
			j.at("stat_int_value").get_to(attachment.stat_int_value);
			j.at("stat_bool_value").get_to(attachment.stat_bool_value);
			j.at("stat_float_value").get_to(attachment.stat_float_value);
		}

	};

	class stat_loader
	{
	public:
		static void render();
	private:
		static std::filesystem::path get_stats_config();
		static nlohmann::json get_stats_json();
		static std::vector<std::string> list_stats();
		static void load_stat_menu(std::string& selected_stat, stats_json::stats_json& stat_obj);
		static void save_stat(char* stat_name, stats_json::stats_json& stat_obj);
		static void delete_stat(std::string name);
	};
};