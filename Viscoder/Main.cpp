#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "VGui.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Viscoder");
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	sf::CircleShape shape(10.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock deltaClock;

	ImGui::StyleColorsLight();

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

		window.clear(sf::Color::White);
		window.draw(shape);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}