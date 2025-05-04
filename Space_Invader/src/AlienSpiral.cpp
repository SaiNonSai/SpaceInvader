//
// Created by nicof on 5/4/2025.
//
#include "AlienSpiral.h"
#include <cmath>
AlienSpiral::AlienSpiral() : delay (0.f)
{

}

void AlienSpiral::initialiseSprite(sf::Texture& texture, const std::string& filename, float delayOffset)
{
    GameObject::initialiseSprite(texture, filename);
    setIsVisible(true);
    getSprite()->setScale(0.5f, 0.5f);
    delay = delayOffset;
}

void AlienSpiral::update(float globalTime)
{
    float t = globalTime - delay;
    if (t < 0) return;

    float radius = 50 + t * 20;
    float angle = t * 2;

    float x = 400 + radius * std::cos(angle);
    float y = 100 + radius * std::sin(angle) * 0.5f;

    getSprite()->setPosition(x, y);

    if (y > 800 || x < 0 || x > 800)
        setIsVisible(false);
}