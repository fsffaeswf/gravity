#pragma once
#include "settings.h"
#include "game_obj.h"

class Player  {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float
		speedx, speedy,
		speed = 0,
		dx = 0,
		dy = 0;

	int hp = 100; 
	bool onGround = true;

	//float maxSpeed = 10.f;

	enum stateObject{stay,right,left,up,down,jump}state;
public:
	Player();
	void update(float time);
	void draw(sf::RenderWindow& window);
	void control();
	void isGround();
};

Player::Player() {
	texture.loadFromFile(PlayerFileName);
	sprite.setTexture(texture);
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	
}

//bool Player::Ground() {};
void Player::isGround() {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sf::Vector2f pos = sprite.getPosition();
	/*if (pos.y + bounds.height/2 >= WINDOW_HEIGHT) { onGround = true;};*/
}
void Player::update(float time) {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sf::Vector2f pos = sprite.getPosition();
	sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - bounds.height/2);
	
	control();
	switch (state)
	{
	case right: dx = speed; break;
	case left: dx = -speed; break;
	case up: break;
	case down: break;
	case jump: break;
	case stay: break;	
	}
	speedx += dx * time;
	speedy += dy * time;
	speed = 0;
	sprite.move(speedx,speedy);
	if(!onGround)dy = dy + 0.0015 * time;
	if (speedy > 0) { 
		onGround = true;
		dy = 0;
	}
}

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		state = left;
		speed = 0.3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		state = right;
		speed = 0.3;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (onGround)) {
		state = jump; dy = -1; onGround = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		state = down;

	}
}


void Player::draw(sf::RenderWindow& window) { window.draw(sprite); };

