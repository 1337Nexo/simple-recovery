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
		ImGui::GetStyle().WindowTitleAlign = { 0.5f, 0.5f };

		ImGui::GetStyle().FrameRounding = 4.0f;
		ImGui::GetStyle().FramePadding = ImVec2(5, 5);
		ImGui::GetStyle().GrabRounding = 4.0f;
		ImGui::GetStyle().ChildRounding = 4.0f;
		ImGui::GetStyle().WindowRounding = 3.0f;

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.23f, 0.26f, 0.32f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
		colors[ImGuiCol_Border] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.18f, 0.20f, 0.25f, 0.47f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.30f, 0.37f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.26f, 0.30f, 0.37f, 1.00f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.85f, 0.87f, 0.91f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.90f, 0.91f, 0.94f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.93f, 0.94f, 0.96f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.85f, 0.87f, 0.91f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.85f, 0.87f, 0.91f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.90f, 0.91f, 0.94f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.30f, 0.37f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.30f, 0.37f, 1.00f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.93f, 0.94f, 0.96f, 1.00f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.90f, 0.91f, 0.94f, 1.00f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.85f, 0.87f, 0.91f, 1.00f);
		colors[ImGuiCol_Tab] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.30f, 0.37f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.93f, 0.94f, 0.96f, 1.00f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.93f, 0.94f, 0.96f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.30f, 0.34f, 0.42f, 1.00f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
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
