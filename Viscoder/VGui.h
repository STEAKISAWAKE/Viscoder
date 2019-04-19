#pragma once
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class VGui
{
public:
	void static GUI() {

		ImGui::BeginGroup();

			if (ImGui::BeginMainMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("New", "CTRL+N")) {}
					if (ImGui::MenuItem("Open", "CTRL+O")) {}
					ImGui::Separator();
					if (ImGui::MenuItem("Save", "CTRL+S")) {}

					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Edit"))
				{
					if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
					if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
					ImGui::Separator();
					if (ImGui::MenuItem("Cut", "CTRL+X")) {}
					if (ImGui::MenuItem("Copy", "CTRL+C")) {}
					if (ImGui::MenuItem("Paste", "CTRL+V")) {}
					
					ImGui::EndMenu();
				}

				ImGui::EndMainMenuBar();
			}

			const char* items[] = { "Casual", "Dark", "Light" };
			static const char* current_item = "Light";
			ImGuiComboFlags flags = ImGuiComboFlags_NoArrowButton;

			ImGuiStyle& style = ImGui::GetStyle();
			float w = ImGui::CalcItemWidth();
			float spacing = style.ItemInnerSpacing.x;
			float button_sz = ImGui::GetFrameHeight();
			ImGui::PushItemWidth(w - spacing * 2.0f - button_sz * 2.0f);
			if (ImGui::BeginCombo("Style", current_item, ImGuiComboFlags_NoArrowButton))
			{
				for (int n = 0; n < IM_ARRAYSIZE(items); n++)
				{
					bool is_selected = (current_item == items[n]);
					if (ImGui::Selectable(items[n], is_selected))
						current_item = items[n];
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}

				if (current_item == "Casual") {
					ImGui::StyleColorsClassic();
				}
				else if (current_item == "Dark") {
					ImGui::StyleColorsDark();
				}
				else {
					ImGui::StyleColorsLight();
				}

				ImGui::EndCombo();
			}
			ImGui::PopItemWidth();
			

			ImGui::Begin("Quick Blocks");
			
				ImGui::Button("Create Function");
			ImGui::End();

		ImGui::EndGroup();
	}
};

