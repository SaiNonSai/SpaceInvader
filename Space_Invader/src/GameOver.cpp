// GameOver.cpp
// Handles game over screen rendering and logic

#include <iostream>
#include "GameOver.h"

// Constructor
Gameover::Gameover()
{
  init();
}

// Initialize game over text and options
void Gameover::init()
{
  font.loadFromFile("Data/Fonts/open-sans/OpenSans-ExtraBold.ttf");

  // Main game over text
  Gameover_text.setFont(font);
  Gameover_text.setFillColor(sf::Color::White);
  Gameover_text.setPosition(200, 300);

  // Options: Yes and No
  for (int i = 0; i < 2; i++)
  {
    option_text[i].setFont(font);
    option_text[i].setFillColor(sf::Color::White);
    option_text[i].setPosition(200, 400);
  }
  option_text[1].move(0, 50); // Move "No" lower

  option_text[0].setString("Yes");
  option_text[1].setString("No");
}

// Update text content and highlight based on state
void Gameover::update()
{
  // Update header based on win state
  if (win)
  {
    Gameover_text.setString("You won!! Would you like to play again?");
  }
  else
  {
    Gameover_text.setString("Game Over!! Would you like to play again");
  }

  // Reset font and default color
  for (int i = 0; i < 2; i++)
  {
    option_text[i].setFont(font);
    option_text[i].setFillColor(sf::Color::White);
  }

  // Update visible selection
  option_text[0].setString("Yes");
  option_text[1].setString("No");

  if (option)
  {
    option_text[0].setFillColor(sf::Color::White);
    option_text[0].setString("> Yes <");
  }
  else
  {
    option_text[1].setFillColor(sf::Color::White);
    option_text[1].setString("> No <");
  }
}

// Set whether the player won or lost
void Gameover::setWin(bool playerWon)
{
  win = playerWon;
}

// Return whether the player confirmed an option
bool Gameover::isFinished() const
{
  return finished;
}

// Return selected option (true = Yes, false = No)
bool Gameover::getOption() const
{
  return option;
}

// Reset the game over menu state
void Gameover::reset()
{
  finished = false;
  option = true;
  win = false;
}


// Render game over elements to window
void Gameover::render(sf::RenderWindow& window)
{
  window.draw(Gameover_text);
  for (int i = 0; i < 2; i++)
  {
    window.draw(option_text[i]);
  }
}

// Handle player input for option selection and confirmation
void Gameover::handleInput(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
      option = true;
    else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
      option = false;
    else if (event.key.code == sf::Keyboard::Enter)
      finished = true;
  }
}
