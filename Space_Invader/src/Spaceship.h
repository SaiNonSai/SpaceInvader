//
// Created by Sai on 2/21/2023.
//

#ifndef SPACEINVADERSSFML_SPACESHIP_H
#define SPACEINVADERSSFML_SPACESHIP_H


#include "GameObject.h"

class Ship : public GameObject
{
 public:
  bool outofbound(sf::RenderWindow& window);

 private:
};
#endif // SPACEINVADERSSFML_SPACESHIP_H