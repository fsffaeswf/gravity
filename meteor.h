#pragma once
#include "settings.h"
#include "game_obj.h"

class Meteor :public GameObject {
private:
	int damage;
	float speed;
public:
	Meteor(sf::Vector2f pos, sf::Vector2f fspeed);
	void update();
	void draw(sf::RenderWindow& window);
	void setRandomPosition();
	sf::Sprite getSprite();
};

Meteor::Meteor(sf::Vector2f pos, sf::Vector2f fspeed) {
	texture.loadFromFile(MeteorFileName);
	sprite.setPosition(pos);
	sprite.setTexture(texture);
}

void Meteor::setRandomPosition() {
	float x;
	int choice = rand() % 2147483647;
	if (choice < 2147483647 / 2) {
		x = -50.f;
		speed = meteor_speed;
	}
	else {
	x = WINDOW_WIDTH + 50.f;
	speed = -meteor_speed;
	}


	float y;
	choice = rand() % 5;
	if (choice == 1) { y = 0; }
	else if (choice == 2) { y = 270; }
	else if (choice == 3) { y = 540; }
	else if (choice == 4) { y = 810; }

	/*float speedx = rand() % 11 - 5.f;
	float speedy = rand() % 11 - 5.f;*/
	sprite.setPosition(x, y);
}
void Meteor::update() {
	sprite.move(speed,0);
	sf::Vector2f pos = sprite.getPosition();
	if (pos.x < left_border || pos.x>right_border) {
		setRandomPosition();
	}
}
void Meteor::draw(sf::RenderWindow& window) { window.draw(sprite); }

sf::Sprite Meteor::getSprite() { return sprite; }