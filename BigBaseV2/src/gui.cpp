#include "common.hpp"
#include "fiber_pool.hpp"
#include "gta/player.hpp"
#include "gta_util.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "memory/module.hpp"
#include "memory/pattern.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script.hpp"

#include <imgui.h>

#include "gui/online_tab.h"
#include "gui/stat_editor.h"
#include "gui/stat_loader.h"
#include "gui/settings_tab.h"

namespace big
{
	void gui::dx_init()
	{
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.00, 0.00, 0.00, 1.00);
		ImGui::GetStyle().Colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.696f, 0.00f, 0.80f);
		ImGui::GetStyle().Colors[ImGuiCol_TabHovered] = ImVec4(0.01, 1.00, 1.00, 0.43);
		ImGui::GetStyle().Colors[ImGuiCol_TabActive] = ImVec4(0.44, 0.81, 0.86, 0.66f);
		ImGui::GetStyle().WindowBorderSize = 1.0f;
		ImGui::GetStyle().FrameBorderSize = 1.0f;
		ImGui::GetStyle().ChildBorderSize = 1.0f;
		ImGui::GetStyle().WindowTitleAlign = { 0.5f, 0.5f };
		ImGui::GetStyle().ButtonTextAlign = { 0.5f, 0.5f };
		ImGui::GetStyle().WindowRounding = 7.0f;
		ImGui::GetStyle().GrabRounding = 3.0f;
		ImGui::GetStyle().FrameRounding = 3.0f;
		ImGui::GetStyle().DisplaySafeAreaPadding = { 3.f, 3.f };
		ImGui::GetStyle().ItemSpacing = { 10.f, 8.f };
		ImGui::GetStyle().ItemInnerSpacing = { 6.f, 6.f };
		ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive] = ImVec4(0.14, 0.18, 0.21, 0.73);
		ImGui::GetStyle().Colors[ImGuiCol_TitleBg] = ImVec4(0.00, 0.00, 0.00, 0.54);
		ImGui::GetStyle().Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00, 1.00, 1.00, 0.27);
	}

	void gui::dx_on_tick()
	{
		TRY_CLAUSE
		{
			ImGui::SetNextWindowSize(ImVec2(783, 729), ImGuiCond_FirstUseEver);
			if (ImGui::Begin("simple-recovery"))
			{
				ImGui::BeginTabBar("tabbar");
				online_tab::render();
				stat_editor::render();
				stat_loader::render();
				settings_tab::render();
				ImGui::EndTabBar();
			}
			ImGui::End();
		}
			EXCEPT_CLAUSE
	}

	void gui::script_init()
	{
	}

	void gui::script_on_tick()
	{
		TRY_CLAUSE
		{
			if (g_gui.m_opened)
			{
				PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
			}
		}
			EXCEPT_CLAUSE
	}

	void gui::script_func()
	{
		g_gui.script_init();
		while (true)
		{
			g_gui.script_on_tick();
			script::get_current()->yield();
		}
	}
}
