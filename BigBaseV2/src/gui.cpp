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

#include "gui/base_tab.h"

namespace big
{
	void gui::dx_init()
	{
		ImGui::GetStyle( ).FrameRounding = 4.0f;
		ImGui::GetStyle( ).FramePadding = ImVec2( 5, 5 );
		ImGui::GetStyle( ).GrabRounding = 4.0f;
		ImGui::GetStyle( ).ChildRounding = 4.0f;

		ImGuiStyle& style = ImGui::GetStyle( );
		style.Colors[ ImGuiCol_Text ] = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );
		style.Colors[ ImGuiCol_TextDisabled ] = ImVec4( 0.50f, 0.50f, 0.50f, 1.00f );
		style.Colors[ ImGuiCol_WindowBg ] = ImVec4( 0.13f, 0.14f, 0.15f, 1.00f );
		style.Colors[ ImGuiCol_ChildBg ] = ImVec4( 0.13f, 0.14f, 0.15f, 1.00f );
		style.Colors[ ImGuiCol_PopupBg ] = ImVec4( 0.13f, 0.14f, 0.15f, 1.00f );
		style.Colors[ ImGuiCol_Border ] = ImVec4( 0.43f, 0.43f, 0.50f, 0.50f );
		style.Colors[ ImGuiCol_BorderShadow ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
		style.Colors[ ImGuiCol_FrameBg ] = ImVec4( 0.25f, 0.25f, 0.25f, 1.00f );
		style.Colors[ ImGuiCol_FrameBgHovered ] = ImVec4( 0.38f, 0.38f, 0.38f, 1.00f );
		style.Colors[ ImGuiCol_FrameBgActive ] = ImVec4( 0.67f, 0.67f, 0.67f, 0.39f );
		style.Colors[ ImGuiCol_TitleBg ] = ImVec4( 0.08f, 0.08f, 0.09f, 1.00f );
		style.Colors[ ImGuiCol_TitleBgActive ] = ImVec4( 0.08f, 0.08f, 0.09f, 1.00f );
		style.Colors[ ImGuiCol_TitleBgCollapsed ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.51f );
		style.Colors[ ImGuiCol_MenuBarBg ] = ImVec4( 0.14f, 0.14f, 0.14f, 1.00f );
		style.Colors[ ImGuiCol_ScrollbarBg ] = ImVec4( 0.02f, 0.02f, 0.02f, 0.53f );
		style.Colors[ ImGuiCol_ScrollbarGrab ] = ImVec4( 0.31f, 0.31f, 0.31f, 1.00f );
		style.Colors[ ImGuiCol_ScrollbarGrabHovered ] = ImVec4( 0.41f, 0.41f, 0.41f, 1.00f );
		style.Colors[ ImGuiCol_ScrollbarGrabActive ] = ImVec4( 0.51f, 0.51f, 0.51f, 1.00f );
		style.Colors[ ImGuiCol_CheckMark ] = ImVec4( 0.11f, 0.64f, 0.92f, 1.00f );
		style.Colors[ ImGuiCol_SliderGrab ] = ImVec4( 0.11f, 0.64f, 0.92f, 1.00f );
		style.Colors[ ImGuiCol_SliderGrabActive ] = ImVec4( 0.08f, 0.50f, 0.72f, 1.00f );
		style.Colors[ ImGuiCol_Button ] = ImVec4( 0.25f, 0.25f, 0.25f, 1.00f );
		style.Colors[ ImGuiCol_ButtonHovered ] = ImVec4( 0.38f, 0.38f, 0.38f, 1.00f );
		style.Colors[ ImGuiCol_ButtonActive ] = ImVec4( 0.67f, 0.67f, 0.67f, 0.39f );
		style.Colors[ ImGuiCol_Header ] = ImVec4( 0.22f, 0.22f, 0.22f, 1.00f );
		style.Colors[ ImGuiCol_HeaderHovered ] = ImVec4( 0.25f, 0.25f, 0.25f, 1.00f );
		style.Colors[ ImGuiCol_HeaderActive ] = ImVec4( 0.67f, 0.67f, 0.67f, 0.39f );
		style.Colors[ ImGuiCol_Separator ] = style.Colors[ ImGuiCol_Border ];
		style.Colors[ ImGuiCol_SeparatorHovered ] = ImVec4( 0.41f, 0.42f, 0.44f, 1.00f );
		style.Colors[ ImGuiCol_SeparatorActive ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.95f );
		style.Colors[ ImGuiCol_ResizeGrip ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
		style.Colors[ ImGuiCol_ResizeGripHovered ] = ImVec4( 0.29f, 0.30f, 0.31f, 0.67f );
		style.Colors[ ImGuiCol_ResizeGripActive ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.95f );
		style.Colors[ ImGuiCol_Tab ] = ImVec4( 0.08f, 0.08f, 0.09f, 0.83f );
		style.Colors[ ImGuiCol_TabHovered ] = ImVec4( 0.33f, 0.34f, 0.36f, 0.83f );
		style.Colors[ ImGuiCol_TabActive ] = ImVec4( 0.23f, 0.23f, 0.24f, 1.00f );
		style.Colors[ ImGuiCol_TabUnfocused ] = ImVec4( 0.08f, 0.08f, 0.09f, 1.00f );
		style.Colors[ ImGuiCol_TabUnfocusedActive ] = ImVec4( 0.13f, 0.14f, 0.15f, 1.00f );
		style.Colors[ ImGuiCol_PlotLines ] = ImVec4( 0.61f, 0.61f, 0.61f, 1.00f );
		style.Colors[ ImGuiCol_PlotLinesHovered ] = ImVec4( 1.00f, 0.43f, 0.35f, 1.00f );
		style.Colors[ ImGuiCol_PlotHistogram ] = ImVec4( 0.90f, 0.70f, 0.00f, 1.00f );
		style.Colors[ ImGuiCol_PlotHistogramHovered ] = ImVec4( 1.00f, 0.60f, 0.00f, 1.00f );
		style.Colors[ ImGuiCol_TextSelectedBg ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.35f );
		style.Colors[ ImGuiCol_DragDropTarget ] = ImVec4( 0.11f, 0.64f, 0.92f, 1.00f );
		style.Colors[ ImGuiCol_NavHighlight ] = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
		style.Colors[ ImGuiCol_NavWindowingHighlight ] = ImVec4( 1.00f, 1.00f, 1.00f, 0.70f );
		style.Colors[ ImGuiCol_NavWindowingDimBg ] = ImVec4( 0.80f, 0.80f, 0.80f, 0.20f );
		style.Colors[ ImGuiCol_ModalWindowDimBg ] = ImVec4( 0.80f, 0.80f, 0.80f, 0.35f );
	}


	void gui::dx_on_tick()
	{
		TRY_CLAUSE
		{
			ImGui::SetNextWindowSize(ImVec2(783, 729), ImGuiCond_FirstUseEver);
			if (ImGui::Begin("simple-recovery"))
			{
				ImGui::BeginTabBar("tabbar");
				base_tab::render_base_tab();
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
