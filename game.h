#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <vector>
#include<Windows.h>
#include "player.h"
#include "background.h"
#include "meteor.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	Background background;
	std::vector<Meteor*> meteors;
	sf::Clock clock;
public:
	
	Game() {
		window.create(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
		//spawnMeteors(15);
		window.setFramerateLimit(FPS);

	}

	void chek_events() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				
				window.close();
		}
	}
	void update() {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart(); 
		time = time / 800; //скорость игры
		player.update(time);
		background.update();
		/*for (int i = 0; i < meteors.size(); i++) {
			meteors.at(i)->update();
		}*/
	}


	void chek_collisons() {
	}
	void draw() {
		window.clear();
		
		background.draw(window);
		/*for (int i = 0; i < meteors.size(); i++) {
			window.draw(meteors.at(i)->getSprite());
		}*/
		player.draw(window);
		window.display();
	}

	void play() {
		while (window.isOpen())
		{
			chek_events();
			update();
			chek_collisons();
			draw();
		}
	}
};