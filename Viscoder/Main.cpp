#include "imgui.h"


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "VGui.h"
#include <Windows.h>

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Viscoder");
	ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);





	sf::CircleShape shape(10.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock deltaClock;

	ImGui::StyleColorsLight();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	io.ConfigDockingWithShift = true;
	//io.ConfigViewportsNoAutoMerge = true;
	//io.ConfigViewportsNoTaskBarIcon = true;
	//io.ConfigViewportsNoDefaultParent = true;
	//io.ConfigDockingTabBarOnSingleWindows = true;
	//io.ConfigDockingTransparentPayload = true;

	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		
			if (sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, window.getSize().x, window.getSize().y);
				window.setView(sf::View(visibleArea));
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());



		VGui::GUI();
		ImGui::ShowDemoWindow();

		window.clear(sf::Color::White);
		window.draw(shape);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}