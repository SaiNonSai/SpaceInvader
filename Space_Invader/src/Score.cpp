//
// Created by nicof on 5/4/2025.
//
#include "Score.h"

Score::Score() : score(0)
{
    font.loadFromFile("Data/Fonts/open-sans/OpenSans-ExtraBold.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    updateText();
}

void Score::increase(int amount) {
    score += amount;
    updateText();
}

void Score::reset() {
    score = 0;
    updateText();
}

void Score::render(sf::RenderWindow& window) {
    window.draw(scoreText);
}

int Score::getScore() const {
    return score;
}

void Score::updateText() {
    scoreText.setString("Score: " + std::to_string(score));
}
