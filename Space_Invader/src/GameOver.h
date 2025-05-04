// GameOver.h
// Handles the game over menu interface

#ifndef SPACEINVADERSSFML_GAMEOVER_H
#define SPACEINVADERSSFML_GAMEOVER_H

#include <SFML/Graphics.hpp>

class Gameover
{
public:
  // Constructor
  Gameover();

  // Main update/render loop
  void update();
  void render(sf::RenderWindow& window);

  // Set result (win/lose)
  void setWin(bool playerWon);

  // Input handling for menu
  void handleInput(sf::Event event);

  // State access
  bool isFinished() const;
  bool getOption() const;
  void reset();

private:
  // Setup text/fonts
  void init();

  // Font and text objects
  sf::Font font;
  sf::Text Gameover_text;
  sf::Text option_text[2];

  // Menu logic
  bool option = true;   // true = Yes, false = No
  bool win = false;     // Player win state
  bool finished = false; // Whether player confirmed
};

#endif // SPACEINVADERSSFML_GAMEOVER_H
