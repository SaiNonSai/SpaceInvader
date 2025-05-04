// Alien.h
// Alien class for Space Invaders, inherits from GameObject

#ifndef SPACEINVADERSSFML_ALIEN_H
#define SPACEINVADERSSFML_ALIEN_H

#include "GameObject.h"

class Alien : public GameObject
{
private:
  // Visibility flag
  bool is_visible = true;

  // Not used in logic currently
  int remaining_aline = 0;

  // Horizontal movement direction (1 = right, -1 = left)
  int direction_x = 1;

public:
  // Visibility
  bool isVisible() const;
  void setIsVisible(bool isVisible);

  // Direction getters/setters
  int getDirection_x() const;
  void setDirection_x(int directionX);

  // Collision check with window borders
  bool checkwallcollision(sf::RenderWindow& window);

  // Optional: Aline counter (not actively used)
  int getRemainingAline() const;
  void setRemainingAline(int remainingAline);
};

#endif // SPACEINVADERSSFML_ALIEN_H
