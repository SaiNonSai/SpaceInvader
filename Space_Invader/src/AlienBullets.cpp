//
// Created by nicof on 5/4/2025.
//
#include "AlienBullets.h"

AlienBullet::AlienBullet() {}

void AlienBullet::initialise(sf::Texture& texture, const std::string& path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setScale(0.3f, 0.3f);
    sprite.setPosition(-100, -100); // off-screen
    visible = false;
}

void AlienBullet::update(float dt) {
    if (!visible) return;
    sprite.move(0.f, 300.f * dt);
    if (sprite.getPosition().y > 800) // below screen
        visible = false;
}

void AlienBullet::render(sf::RenderWindow& window) {
    if (visible)
        window.draw(sprite);
}

void AlienBullet::setVisible(bool v) { visible = v; }
bool AlienBullet::isVisible() const { return visible; }
sf::Sprite* AlienBullet::getSprite() { return &sprite; }