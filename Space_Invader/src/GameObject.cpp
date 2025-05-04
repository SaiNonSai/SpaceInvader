#include "GameObject.h"

GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
  if (sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if(!texture.loadFromFile(filename))
  {
    return false;
  }
  sprite->setTexture(texture);
  return true;
}
int GameObject::getSpeed() const
{
  return speed;
}
void GameObject::setSpeed(int speed)
{
  GameObject::speed = speed;
}
bool GameObject::isVisible()
{
  return is_visible;
}
void GameObject::setIsVisible(bool isVisible)
{
  is_visible = isVisible;
}
void GameObject::remove()
{
  delete sprite;
}