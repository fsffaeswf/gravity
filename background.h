
#pragma once
#include "settings.h"
#include "game_obj.h"

class Background:GameObject {
public:
	Background();
	void draw(sf::RenderWindow& window);
	void update();
};

Background::Background() {
	//sprite.setScale(1.2f, 1.2f);
	texture.loadFromFile(BackgroundFileName);
	sprite.setTexture(texture);
	sprite.setPosition(0.f, 0.f);
}

void Background::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Background::update() {};