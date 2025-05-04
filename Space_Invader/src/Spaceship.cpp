//
// Created by Sai on 2/21/2023.
//
#include "Spaceship.h"
bool Ship::outofbound(sf::RenderWindow& window)
{
  float x = sprite->getPosition().x;
  float width = sprite->getGlobalBounds().width;
  float windowWidth = static_cast<float>(window.getSize().x);

  if (x < 0) {
    sprite->setPosition(0, sprite->getPosition().y);
    return true;
  }

  if (x + width > windowWidth) {
    sprite->setPosition(windowWidth - width, sprite->getPosition().y);
    return true;
  }

  return false;
}
