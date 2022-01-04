#include "common.hpp"
#include "stat_editor.h"
#include "imgui.h"
#include "script.hpp"
#include "script_global.hpp"
#include "misc/cpp/imgui_stdlib.h"
#include "imgui_internal.h"
#include "Helpers/Helper.hpp"
using namespace big;

namespace big
{
	void stat_editor::render()
	{
		if (ImGui::BeginTabItem("Editor"))
		{
			ImGui::Separator();
			if (ImGui::CollapsingHeader(u8"Stat Edit###1"))
			{
				ImGui::PushItemWidth(350.0f);
				static int stat_type, int_value, read_int_value;
				static BOOL bool_value, read_bool_value;
				static int64_t date_value[7], read_date_value[7];
				static float float_value, read_float_value, increment_value, read_increment_value;
				static std::string stat_name{ "MPPLY_KILLS_PLAYERS" }, userid_value{}, read_userid_value{}, string_value{}, read_string_value{}, Error_value{};
				ImGui::InputText("###stat", &stat_name, ImGuiInputTextFlags_CharsUppercase);
				ImGui::RadioButton("INT", &stat_type, 0); ImGui::SameLine();
				ImGui::RadioButton("BOOL", &stat_type, 1); ImGui::SameLine();
				ImGui::RadioButton("FLOAT", &stat_type, 2); ImGui::SameLine();
				ImGui::RadioButton("INCREMENT", &stat_type, 3); ImGui::SameLine();
				ImGui::RadioButton("DATE", &stat_type, 4); ImGui::SameLine();
				ImGui::RadioButton("USERID", &stat_type, 5); ImGui::SameLine();
				ImGui::RadioButton("STRING", &stat_type, 6);
				ImGui::PopItemWidth();
				if (stat_type == 0)
				{
					ImGui::PushItemWidth(300.0f);
					ImGui::InputScalar("###int", ImGuiDataType_S32, &int_value);
					ImGui::BeginDisabled();
					ImGui::InputScalar("###read_int_value", ImGuiDataType_S32, &read_int_value);
					ImGui::EndDisabled();
					ImGui::PopItemWidth();
				}
				else if (stat_type == 1)
				{
					ImGui::Checkbox("###bool", (bool*)&bool_value);
					ImGui::BeginDisabled();
					ImGui::Checkbox("###read_bool", (bool*)&read_bool_value);
					ImGui::EndDisabled();
				}
				else if (stat_type == 2)
				{
					ImGui::PushItemWidth(250.0f);
					ImGui::InputScalar("###float", ImGuiDataType_Float, &float_value);
					ImGui::BeginDisabled();
					ImGui::InputFloat("###read_float_value", &read_float_value, 0.0f, 0.0f);
					ImGui::EndDisabled();
					ImGui::PopItemWidth();
				}
				else if (stat_type == 3)
				{
					ImGui::PushItemWidth(250.0f);
					ImGui::InputScalar("###increment", ImGuiDataType_Float, &increment_value);
					ImGui::BeginDisabled();
					ImGui::InputFloat("###increment_value", &read_increment_value, 0.0f, 0.0f);
					ImGui::EndDisabled();
					ImGui::PopItemWidth();
				}
				else if (stat_type == 4)
				{
					ImGui::PushItemWidth(50.0f);
					ImGui::InputScalar("Year###year", ImGuiDataType_U32, &date_value[0]); ImGui::SameLine();
					ImGui::InputScalar("Mon###month", ImGuiDataType_U32, &date_value[1]); ImGui::SameLine();
					ImGui::InputScalar("Day###day", ImGuiDataType_U32, &date_value[2]); ImGui::SameLine();
					ImGui::InputScalar("Hour###hour", ImGuiDataType_U32, &date_value[3]); ImGui::SameLine();
					ImGui::InputScalar("Min###minute", ImGuiDataType_U32, &date_value[4]); ImGui::SameLine();
					ImGui::InputScalar("Sec###second", ImGuiDataType_U32, &date_value[5]); ImGui::SameLine();
					ImGui::InputScalar("Ms###millisecond", ImGuiDataType_U32, &date_value[6]); ImGui::SameLine();
					ImGui::BeginDisabled();
					ImGui::InputScalar("Year###read_year", ImGuiDataType_U32, &read_date_value[0]); ImGui::SameLine();
					ImGui::InputScalar("Mon###read_month", ImGuiDataType_U32, &read_date_value[1]); ImGui::SameLine();
					ImGui::InputScalar("Day###read_day", ImGuiDataType_U32, &read_date_value[2]); ImGui::SameLine();
					ImGui::InputScalar("Hour###read_hour", ImGuiDataType_U32, &read_date_value[3]); ImGui::SameLine();
					ImGui::InputScalar("Min###read_minute", ImGuiDataType_U32, &read_date_value[4]); ImGui::SameLine();
					ImGui::InputScalar("Sec###read_second", ImGuiDataType_U32, &read_date_value[5]); ImGui::SameLine();
					ImGui::InputScalar("Ms###read_millisecond", ImGuiDataType_U32, &read_date_value[6]); ImGui::SameLine();
					ImGui::EndDisabled();
					ImGui::PopItemWidth();
					ImGui::TextColored(ImVec4(1, 0, 0, 1), fmt::format(Error_value).c_str());
				}
				else if (stat_type == 5)
				{
					ImGui::PushItemWidth(300.0f);
					ImGui::InputText("###userid", &userid_value, ImGuiInputTextFlags_None);
					ImGui::BeginDisabled();
					ImGui::InputText("###read_userid", &read_userid_value, ImGuiInputTextFlags_None);
					ImGui::EndDisabled();
					ImGui::PopItemWidth();
				}
				else if (stat_type == 6)
				{
					ImGui::PushItemWidth(300.0f);
					ImGui::InputText("###string", &string_value, ImGuiInputTextFlags_None);
					ImGui::BeginDisabled();
					ImGui::InputText("###read_string", &read_string_value, ImGuiInputTextFlags_None);
					ImGui::EndDisabled();
					ImGui::PopItemWidth();
				}
				if (ImGui::Button(u8"Write Value"))
				{
					std::string character_index = "MP" + std::to_string(g_local_player.character_index);
					//LOG_INFO("stat_name {}", stat_name);
					stat_name = std::regex_replace(stat_name, std::regex(R"(\$)"), "");
					stat_name = std::regex_replace(stat_name, std::regex(R"(\MPX)"), character_index);
					stat_name = std::regex_replace(stat_name, std::regex(R"(\MPx)"), character_index);
					//LOG_INFO("stat_name_after_regex {}", stat_name);
					const auto hash = rage::joaat(stat_name);
					//LOG_INFO("hash {}\n", hash);
					g_fiber_pool->queue_job([hash]
						{
							if (stat_type == 0)
							{
								STATS::STAT_SET_INT(hash, int_value, true);
								STATS::STAT_GET_INT(hash, &read_int_value, true);
								//LOG_INFO("read_int_value {}\n", read_int_value);

							}
							else if (stat_type == 1)
							{
								STATS::STAT_SET_BOOL(hash, bool_value, true);
								STATS::STAT_GET_BOOL(hash, &read_bool_value, true);
								//LOG_INFO("read_Bool_value {}\n", read_bool_value);
							}
							else if (stat_type == 2)
							{
								STATS::STAT_SET_FLOAT(hash, float_value, true);
								STATS::STAT_GET_FLOAT(hash, &read_float_value, true);
								//LOG_INFO("read_float_value {}\n", read_float_value);
							}
							else if (stat_type == 3)
							{
								STATS::STAT_INCREMENT(hash, increment_value);
								STATS::STAT_GET_FLOAT(hash, &read_increment_value, true);
								//LOG_INFO("read_INCREMENT {}\n", read_increment_value);
							}
							else if (stat_type == 4)
							{
								int time[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
								int64_t year = date_value[0], Mon = date_value[1], day = date_value[2], Hour = date_value[3], Minute = date_value[4], Second = date_value[5], Mil = date_value[6];
								if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
								{//如果是闰年
									time[1] = 29;
									if (0 <= day && day <= time[Mon - 1] && 0 <= Mon && Mon <= 12 && 0 <= Hour && Hour < 24 && 0 <= Minute && Minute < 60 && 0 <= Second && Second < 60 && 0 <= Mil && Mil < 1000)
									{
										//LOG_INFO(u8"日期输入正确\n");
										STATS::STAT_SET_DATE(hash, (int*)&date_value[0], 7, true);
										STATS::STAT_GET_DATE(hash, (int*)&read_date_value[0], 7, true);
										Error_value = {};
									}
									else
									{
										Error_value = { "Date or time input is illegal, recheck input data " };
									}
								}
								else
								{//不是闰年
									if (0 <= day && day <= time[Mon - 1] && 0 <= Mon && 12 >= Mon && 0 <= Hour && Hour < 24 && 0 <= Minute && Minute < 60 && 0 <= Second && Second < 60 && 0 <= Mil && Mil < 1000)
									{
										STATS::STAT_SET_DATE(hash, (int*)&date_value[0], 7, true);
										STATS::STAT_GET_DATE(hash, (int*)&read_date_value[0], 7, true);
										Error_value = {};
									}
									else
									{
										Error_value = { "Date or time input is illegal, recheck input data " };
									}
								}
							}
							else if (stat_type == 5)
							{
								STATS::STAT_SET_USER_ID(hash, userid_value.c_str(), true);
								//LOG_INFO("userid_value {}\n", userid_value.c_str());
								read_userid_value = STATS::STAT_GET_USER_ID(hash);
								//LOG_INFO("read_userid_value {}\n", read_userid_value);
							}
							else if (stat_type == 6)
							{
								STATS::STAT_SET_STRING(hash, string_value.c_str(), true);
								//LOG_INFO("String_value {}\n", string_value.c_str());
								read_string_value = STATS::STAT_GET_STRING(hash, true);
								//LOG_INFO("read_String_value {}\n", read_string_value);
							}
						});
				}
				ImGui::SameLine();
				if (ImGui::Button("Read Value"))
				{
					std::string character_index = "MP" + std::to_string(g_local_player.character_index);
					//LOG_INFO("stat_name {}", stat_name);
					stat_name = std::regex_replace(stat_name, std::regex(R"(\$)"), "");
					stat_name = std::regex_replace(stat_name, std::regex(R"(\MPX)"), character_index);
					//LOG_INFO("stat_name_after_regex {}", stat_name);
					const auto hash = rage::joaat(stat_name);
					//LOG_INFO("hash {}\n", hash);
					g_fiber_pool->queue_job([hash]
						{
							if (stat_type == 0)
							{
								STATS::STAT_GET_INT(hash, &read_int_value, true);
							}
							else if (stat_type == 1)
							{
								STATS::STAT_GET_BOOL(hash, &read_bool_value, true);
							}
							else if (stat_type == 2)
							{
								STATS::STAT_GET_FLOAT(hash, &read_float_value, true);
							}
							else if (stat_type == 3)
							{
								STATS::STAT_GET_FLOAT(hash, &read_increment_value, true);
							}
							else if (stat_type == 4)
							{
								STATS::STAT_GET_DATE(hash, (int*)&read_date_value[0], 7, true);
								//LOG_INFO("GET Year{} Month{} Day{} Hour{} Minute{} Second{} Millisecond{}\n", read_date_value[0], read_date_value[1], read_date_value[2], read_date_value[3], read_date_value[4], read_date_value[5], read_date_value[6]);
							}
							else if (stat_type == 5)
							{
								read_userid_value = STATS::STAT_GET_USER_ID(hash);
								//LOG_INFO("read_userid_value: {}\n", read_userid_value);
							}
							else if (stat_type == 6)
							{
								read_string_value = STATS::STAT_GET_STRING(hash, true);
								//LOG_INFO("read_String_value {}\n", read_string_value);
							}
						});
				}
			}
			ImGui::Separator();
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
				static bool b_value = true;
				ImGui::PushItemWidth(100.0f);
				ImGui::InputScalar("Index##1", ImGuiDataType_S32, &b_index);
				ImGui::PopItemWidth();
				ImGui::Checkbox("Value##bvalue", &b_value);
				if (ImGui::Button(u8"Write Packed Bool"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_packed_bool(b_index, b_value ? 1 : 0);
					} QUEUE_JOB_END_CLAUSE
				}
				ImGui::SameLine();
				if (ImGui::Button(u8"Read Packed Bool"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						b_value = helper::get_packed_bool(b_index);
						//LOG_INFO("Get Bool Done {}, {}", b_index, b_value);
					} QUEUE_JOB_END_CLAUSE
				}
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader("Packed Int Edit"))
			{
				ImGui::TextColored(ImVec4(1, 1, 0, 1), "22050>=5 TERBYTE Wholesale price\n22058>=20 Gold Business Battle Trophy \n22063=20 Monkey car");
				static int i_index = 22058, pie_value = 20;
				ImGui::PushItemWidth(100.0f);
				ImGui::InputScalar("Index##2", ImGuiDataType_S32, &i_index);
				ImGui::InputScalar("Value##pievalue", ImGuiDataType_S32, &pie_value);
				ImGui::PopItemWidth();
				if (ImGui::Button(u8"Write Packed Int"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::set_packed_int(i_index, pie_value);
						//LOG_INFO(fmt::format("Set Int Done. {}, {}", i_index, pie_value));
					} QUEUE_JOB_END_CLAUSE
				}
				ImGui::SameLine();
				if (ImGui::Button(u8"Read Packed Int"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						pie_value = helper::get_packed_int(i_index);
						//LOG_INFO(fmt::format("Get Int Done. {}, {}", i_index, pie_value));
					} QUEUE_JOB_END_CLAUSE
				}
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader(u8"Get packed values in batch"))
			{
				ImGui::TextColored(ImVec4(1, 1, 0, 1), u8"Value %%appdata%%\\BigBaseV2\\BigBaseV2.txt generate");
				static int MinIndex, MaxIndex;
				ImGui::PushItemWidth(100.0f);
				ImGui::InputScalar(u8"Min Value", ImGuiDataType_S32, &MinIndex);
				ImGui::InputScalar(u8"Max Value", ImGuiDataType_S32, &MaxIndex);
				ImGui::PopItemWidth();
				if (ImGui::Button(u8"Get Packed Bool Value"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::get_mass_packed_bool(MinIndex, MaxIndex);
					} QUEUE_JOB_END_CLAUSE
				}
				ImGui::SameLine();
				if (ImGui::Button(u8"Get Packed Int Value"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						helper::get_mass_packed_int(MinIndex, MaxIndex);
					} QUEUE_JOB_END_CLAUSE
				}
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader(u8"Global Edit"))
			{
				static int type;
				static int64_t Global = 262145, index[5], SetIntValue, GetIntValue;
				static float SetFloatValue, GetFloatValue;
				ImGui::PushItemWidth(150.0f);
				ImGui::InputScalar("Global", ImGuiDataType_S32, &Global);
				ImGui::InputScalar("Index###f0_index", ImGuiDataType_S32, &index[0]);
				ImGui::InputScalar("Index###f1_index", ImGuiDataType_S32, &index[1]);
				ImGui::InputScalar("Index###f2_index", ImGuiDataType_S32, &index[2]);
				ImGui::InputScalar("Index###f3_index", ImGuiDataType_S32, &index[3]);
				ImGui::InputScalar("Index###f4_index", ImGuiDataType_S32, &index[4]);
				ImGui::PopItemWidth();
				ImGui::RadioButton("INT###GINT", &type, 0); ImGui::SameLine();
				ImGui::RadioButton("FLOAT###GFLOAT", &type, 1);
				if (type == 0)
				{
					ImGui::PushItemWidth(150.0f);
					ImGui::InputScalar(u8"设置INT数值###SetIntValue", ImGuiDataType_S32, &SetIntValue);
					ImGui::BeginDisabled();//禁止交互
					ImGui::InputScalar(u8"当前INT数值###GetIntValue", ImGuiDataType_S32, &GetIntValue);
					ImGui::EndDisabled();//允许交互
					ImGui::PopItemWidth();
				}
				else if (type == 1)
				{
					ImGui::PushItemWidth(150.0f);
					ImGui::InputScalar(u8"设置FLOAT数值###SetFloatValue", ImGuiDataType_Float, &SetFloatValue);
					ImGui::BeginDisabled();//禁止交互
					ImGui::InputFloat(u8"当前FLOAT数值###GetFloatValue", &GetFloatValue, 0.00f, 0.00f, "%.6f");
					ImGui::EndDisabled();//允许交互
					ImGui::PopItemWidth();
				}
				if (ImGui::Button(u8"Write Global Value"))
				{
					if (type == 0)
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							*script_global(Global + index[0] + index[1] + index[2] + index[3] + index[4]).as<int64_t*>() = SetIntValue;
							GetIntValue = *script_global(Global + index[0] + index[1] + index[2] + index[3] + index[4]).as<int64_t*>();
						} QUEUE_JOB_END_CLAUSE
					}
					else if (type == 1)
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							*script_global(Global + index[0] + index[1] + index[2] + index[3] + index[4]).as<float*>() = SetFloatValue;
							GetFloatValue = *script_global(Global + index[0] + index[1] + index[2] + index[3] + index[4]).as<float*>();
						} QUEUE_JOB_END_CLAUSE
					}
				}
				ImGui::SameLine();
				if (ImGui::Button(u8"Read Global Value"))
				{
					if (type == 0)
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							GetIntValue = *script_global(Global + index[0] + index[1] + index[2] + index[3] + index[4]).as<int64_t*>();
						} QUEUE_JOB_END_CLAUSE
					}
					else if (type == 1)
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							GetFloatValue = *script_global(Global + index[0] + index[1] + index[2] + index[3] + index[4]).as<float*>();
						} QUEUE_JOB_END_CLAUSE
					}
				}
			}
			ImGui::Separator();
			ImGui::EndTabItem();
		}
	}
}