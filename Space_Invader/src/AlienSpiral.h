#ifndef SPACEINVADERSSFML_CENTIPEDEALIEN_H
#define SPACEINVADERSSFML_CENTIPEDEALIEN_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class AlienSpiral : public GameObject
{
public:
    AlienSpiral();

    void initialiseSprite(sf::Texture& texture, const std::string& filename, float delayOffset);
    void update(float time);  // Use global time, not deltaTime

private:
    float delay;  // Offset in time for this segment
};

#endif