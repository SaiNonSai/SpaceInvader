// Alien.cpp
// Alien behavior implementation

#include "Alien.h"

// Check if alien is currently visible
bool Alien::isVisible() const
{
  return is_visible;
}

// Set visibility of the alien
void Alien::setIsVisible(bool isVisible)
{
  is_visible = isVisible;
}

// Check if the alien has hit the left or right wall of the window
bool Alien::checkwallcollision(sf::RenderWindow& window)
{
  return (sprite->getPosition().x < 0) ||
         (sprite->getPosition().x + sprite->getGlobalBounds().width > window.getSize().x);
}

// Get current horizontal movement direction
int Alien::getDirection_x() const
{
  return direction_x;
}

// Set horizontal movement direction
void Alien::setDirection_x(int directionX)
{
  direction_x = directionX;
}

// (Optional) Get the remaining aliens (unused in logic)
int Alien::getRemainingAline() const
{
  return remaining_aline;
}

// (Optional) Set the remaining aliens (unused in logic)
void Alien::setRemainingAline(int remainingAline)
{
  remaining_aline = remainingAline;
}