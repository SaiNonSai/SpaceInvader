//
// Created by nicof on 5/4/2025.
//

#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include <SFML/Graphics.hpp>

class AlienBullet
{
public:
    AlienBullet();
    void initialise(sf::Texture& texture, const std::string& path);
    void update(float dt);
    void render(sf::RenderWindow& window);
    void setVisible(bool visible);
    bool isVisible() const;
    sf::Sprite* getSprite();

private:
    sf::Sprite sprite;
    bool visible = false;
};

#endif // ALIEN_BULLET_H