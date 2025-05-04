//
// Created by nicof on 5/4/2025.
//

#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>

class Score {
public:
    Score();

    void increase(int amount);
    void reset();
    void render(sf::RenderWindow& window);
    int getScore() const;

private:
    int score;
    sf::Font font;
    sf::Text scoreText;

    void updateText();
};

#endif //SCORE_H
