#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 1920;
const float WINDOW_HEIGHT = 1080;

const size_t FPS = 60;

std::string PlayerFileName{ "images\\player.png" };
std::string BackgroundFileName{ "images\\background.png" };
std::string MeteorFileName{ "images\\meteor.png" };


const float meteor_speed = 10.f;

sf::Vector2f PlayerStartPos{ WINDOW_WIDTH / 2,WINDOW_HEIGHT/2 };

const float left_border = -300.f;
const float right_border = 1500.f;
//const float gravity_speed = 20.f;