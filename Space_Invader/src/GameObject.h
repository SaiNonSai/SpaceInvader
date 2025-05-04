// GameObject.h
// Base class for all visible objects in the game

#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
public:
  // Constructor/Destructor
  GameObject();
  ~GameObject();

  // Sprite setup
  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
  void setSprite(sf::Sprite* sprite);

  // Visibility
  bool isVisible();
  void setIsVisible(bool isVisible);
  void remove();

  // Speed
  int getSpeed() const;
  void setSpeed(int speed);

protected:
  sf::Sprite* sprite = nullptr;

private:
  int speed = 0;
  bool is_visible = true;
};

#endif // SPACEINVADERS_GAMEOBJECT_H
