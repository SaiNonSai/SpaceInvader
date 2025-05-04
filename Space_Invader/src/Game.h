#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Alien.h"
#include "Spaceship.h"
#include "Vector2.h"
#include "Bullets.h"
#include "GameOver.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
  Game(sf::RenderWindow& window);
  ~Game();

  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

private:
  // Constants
  static const int NUM_ALIEN_TYPE_1 = 16;
  static const int NUM_ALIEN_TYPE_2 = 12;
  static const int no_of_shot = 100;

  // Game state flags
  bool in_menu = true;
  bool in_game = true;
  bool game_over1 = false;
  bool allAliensGone = true;
  bool player_won = false;

  // Window and menu
  sf::RenderWindow& window;
  sf::Font font;
  sf::Text menu;

  // Spaceship
  Ship spaceship;
  sf::Texture ship_texture;

  // Aliens
  Alien alien[NUM_ALIEN_TYPE_1];
  Alien alien_2[NUM_ALIEN_TYPE_2];
  sf::Texture alien_texture;

  static const int ALIEN_ROWS = 2;
  static const int ALIEN_COLS = 8; // 2×8 = 16 aliens

  static const int ALIEN2_ROWS = 2;
  static const int ALIEN2_COLS = 6; // 2×6 = 12 aliens = NUM_ALIEN_TYPE_2

  // Bullets
  Bullets shots[no_of_shot];
  sf::Texture bullet_texture;
  sf::Clock shotClock;       // clock to track time since last shot
  float shotCooldown = 0.3f; // 0.3 seconds cooldown between shots

  // Game over screen
  Gameover game_over;

  //Countdown
  bool in_countdown = false;
  sf::Clock countdownClock;
  int countdownValue = 3;
  sf::Text countdownText;

  // Initialization helpers
  void initMenu();
  void initCountdownText();
  void initSpaceship();
  void initAliens();
  void initShots();
  void resetGame();

  // Update helpers
  void checkWinCondition();
  void updateAliens(float dt);
  void updateShots(float dt);
  void updateCountdown(float dt);

  // Math
  float sin(float t);
};

#endif // SPACEINVADERS_GAME_H
