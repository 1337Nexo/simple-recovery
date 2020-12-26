#pragma once

#include <imgui.h>

namespace ImGui
{
	template<typename T>
	bool Bitfield(const char* name, T* param)
	{
		bool ret_val = false;
		ImGuiDataType type;
		size_t size = sizeof(T);
		if (size == 1LL)
			type = ImGuiDataType_U8;
		if (size == 2LL)
			type = ImGuiDataType_U16;
		if (size == 4LL)
			type = ImGuiDataType_U32;
		if (size == 8LL)
			type = ImGuiDataType_U64;
		
		if (ImGui::InputScalar(name, type, param, NULL, NULL, "%p", ImGuiInputTextFlags_CharsHexadecimal))
			ret_val = true;
		size_t bits = (size * 8LL) - 1LL;
		for (size_t i = bits; i < 0xFFFFFFFFFFFF; i--)
		{
			if (i % 4 == 0)
				ImGui::BeginGroup();
			if (*param & (1ULL << i))
			{
				ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32_BLACK_TRANS);
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(41, 134, 204, 255));
				if (ImGui::Button(fmt::format("1##{}{}", i, name).c_str()))
				{
					ret_val = true;
					*param ^= (1ULL << i);
				}
				ImGui::PopStyleColor(2);
			}
			else
			{
				ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32_BLACK_TRANS);
				if (ImGui::Button(fmt::format("0##{}{}", i, name).c_str()))
				{
					ret_val = true;
					*param ^= (1ULL << i);
				}
				ImGui::PopStyleColor();
			}
			if (i % 4 == 0)
			{
				ImGui::Text("%i", i);
				ImGui::EndGroup();
			}
			if(i % 16 != 0)
				ImGui::SameLine();
		}
		
		return ret_val;
	}
}