#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Alien.h"
#include "Spaceship.h"
#include "Vector2.h"
#include "Bullets.h"
#include "GameOver.h"
#include "Score.h"
#include "AlienSpiral.h"
#include "AlienBullets.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


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
  static const int NUM_ALIEN_TYPE_1 = 4;
  static const int NUM_ALIEN_TYPE_2 = 6;
  static const int no_of_shot = 100;

  // Game state flags
  bool in_menu = true;
  bool in_game = true;
  bool game_over1 = false;
  bool player_won = false;

  // Window and menu
  sf::RenderWindow& window;
  sf::Font font;
  sf::Text menu;

  // Spaceship
  Ship spaceship;
  sf::Texture ship_texture;
  int playerLives = 3;
  sf::Texture lifeIconTexture;
  std::vector<sf::Sprite> lifeIcons;

  // Aliens
  Alien alien[NUM_ALIEN_TYPE_1];
  Alien alien_2[NUM_ALIEN_TYPE_2];
  sf::Texture alien_texture;

  static const int ALIEN_ROWS = 1;
  static const int ALIEN_COLS = 4;

  static const int ALIEN2_ROWS = 2;
  static const int ALIEN2_COLS = 3;

  //Spiral Alien
  static const int NUM_CENTIPEDE_SEGMENTS = 6;
  AlienSpiral centipede[NUM_CENTIPEDE_SEGMENTS];
  sf::Clock centipedeClock;
  bool centipedeLaunched = false;

  // Bullets
  Bullets shots[no_of_shot];
  sf::Texture bullet_texture;
  sf::Clock shotClock;       // clock to track time since last shot
  float shotCooldown = 0.3f; // 0.3 seconds cooldown between shots

  //Alien Bullets
  static const int MAX_ALIEN_BULLETS = 20;
  AlienBullet alienBullets[MAX_ALIEN_BULLETS];
  sf::Texture alienBulletTexture;
  sf::Clock alienShootClock;
  float alienShootInterval = 2.0f; // aliens shoot every 2 sec

  //Score
  Score score;

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
  void initSpiralAliens();
  void initAlienBullets();
  void initLives();
  void resetGame();

  // Update helpers
  void checkWinCondition();
  void updateAliens(float dt);
  void updateAlienBullets(float dt);
  void updateShots(float dt);
  void updateCountdown(float dt);


  // Math
  float sin(float t);
};

#endif // SPACEINVADERS_GAME_H
