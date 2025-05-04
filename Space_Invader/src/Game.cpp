#include "Game.h"
#include "Alien.h"
#include "GameOver.h"
#include <iostream>

// Constructor
Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

// Destructor
Game::~Game()
{

}

// Initialize game components
bool Game::init()
{
  initMenu();
  initSpaceship();
  initAliens();
  initShots();
  return true;
}

// Initialize main menu
void Game::initMenu()
{
  font.loadFromFile("Data/Fonts/open-sans/OpenSans-ExtraBold.ttf");
  menu.setString("Press Enter To Play");
  menu.setFont(font);
  menu.setCharacterSize(50);
  menu.setFillColor(sf::Color::White);
  menu.setPosition(window.getSize().x / 2 - menu.getGlobalBounds().width / 2,
                   window.getSize().y / 2 - menu.getGlobalBounds().height / 2);
}

// Initialize countdown text
void Game::initCountdownText()
{
  font.loadFromFile("Data/Fonts/open-sans/OpenSans-ExtraBold.ttf");
  countdownText.setString("3");
  countdownText.setCharacterSize(100);
  countdownText.setFont(font);
  countdownText.setFillColor(sf::Color::White);
  countdownText.setPosition(window.getSize().x / 2 - countdownText.getGlobalBounds().width / 2,
                            window.getSize().y / 2- countdownText.getGlobalBounds().height / 2);
}

// Initialize player's spaceship
void Game::initSpaceship()
{
  spaceship.initialiseSprite(ship_texture, "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");
  spaceship.getSprite()->setScale(0.75, 0.75);
  spaceship.getSprite()->setPosition(
    window.getSize().x / 2 - spaceship.getSprite()->getGlobalBounds().width / 2,
    620);
}

// Initialize aliens in a grid formation
void Game::initAliens()
{
  float spacing_x = 20.0f;
  float spacing_y = 30.0f;
  int index = 0;

  // Type 1 aliens
  for (int row = 0; row < ALIEN_ROWS; row++)
  {
    for (int col = 0; col < ALIEN_COLS; col++)
    {
      if (index >= NUM_ALIEN_TYPE_1) break;

      alien[index].initialiseSprite(alien_texture, "Data/Images/Alien UFO pack/PNG/shipBeige_manned.png");
      alien[index].getSprite()->setScale(0.5, 0.5);

      float alienWidth = alien[index].getSprite()->getGlobalBounds().width;
      float alienHeight = alien[index].getSprite()->getGlobalBounds().height;

      float x = col * (alienWidth + spacing_x);
      float y = row * (alienHeight + spacing_y) + 50;

      alien[index].getSprite()->setPosition(x, y);
      alien[index].setSpeed(200);
      index++;
    }
  }

  // Type 2 aliens
  int index2 = 0;
  for (int row = 0; row < ALIEN2_ROWS; row++)
  {
    for (int col = 0; col < ALIEN2_COLS; col++)
    {
      if (index2 >= NUM_ALIEN_TYPE_2) break;

      alien_2[index2].initialiseSprite(alien_texture, "Data/Images/Alien UFO pack/PNG/shipGreen_manned.png");
      alien_2[index2].getSprite()->setScale(0.5, 0.5);

      float alienWidth = alien_2[index2].getSprite()->getGlobalBounds().width;
      float alienHeight = alien_2[index2].getSprite()->getGlobalBounds().height;

      float totalWidth = ALIEN2_COLS * (alienWidth + spacing_x);
      float offsetX = (window.getSize().x - totalWidth) / 2.0f;

      float x = offsetX + col * (alienWidth + spacing_x);
      float y = row * (alienHeight + spacing_y) + 150;

      alien_2[index2].getSprite()->setPosition(x, y);
      alien_2[index2].setSpeed(200);
      index2++;
    }
  }
}

// Initialize bullets
void Game::initShots()
{
  for (int i = 0; i < no_of_shot; i++)
  {
    shots[i].initialiseSprite(bullet_texture, "Data/Images/Alien UFO pack/PNG/laserBlue1.png");
    shots[i].getSprite()->setScale(0.25, 0.25);
    shots[i].getSprite()->setPosition(500, 500);
  }
}

// Game update logic
void Game::update(float dt)
{
  if (in_countdown)
    {
      updateCountdown(dt);
      return;
    }
  checkWinCondition();
  spaceship.outofbound(window);
  updateAliens(dt);
  updateShots(dt);
}

// Check if all aliens are destroyed
void Game::checkWinCondition()
{
  bool allAliensGone = true;
  for (int i = 0; i < NUM_ALIEN_TYPE_1 && allAliensGone; i++)
  {
    if (alien[i].isVisible())
    {
      allAliensGone = false;
    }
  }


  for (int k = 0; k < NUM_ALIEN_TYPE_2 && allAliensGone; k++)
  {
    if (alien_2[k].isVisible())
    {
      allAliensGone = false;
    }
  }

  if (allAliensGone)
  {
    std::cout << "All aliens gone! You won!" << std::endl;
    game_over1 = true;
    in_game = false;
    player_won = true;
    game_over.setWin(true);
  }
}

// Update alien movement and collisions
void Game::updateAliens(float dt)
{
  bool shouldReverse = false;

  // Check if any type 1 alien hits the wall
  for (int i = 0; i < NUM_ALIEN_TYPE_1; i++)
  {
    if (!alien[i].isVisible())
    {
      continue;
    }
    if (alien[i].checkwallcollision(window))
      {
        shouldReverse = true;
        break;
      }
  }

  // Update position and handle collisions for type 1 aliens
  for (int i = 0; i < NUM_ALIEN_TYPE_1; i++)
  {
    if (!alien[i].isVisible()) continue;

    if (shouldReverse)
    {
      alien[i].setDirection_x(-alien[i].getDirection_x());
      alien[i].getSprite()->move(0, 10.0f);
    }

    alien[i].getSprite()->move(alien[i].getDirection_x() * alien[i].getSpeed() * dt, 0);

    for (int j = 0; j < no_of_shot; j++)
    {
      if (shots[j].isVisible() && alien[i].isVisible() &&
          shots[j].getSprite()->getGlobalBounds().intersects(alien[i].getSprite()->getGlobalBounds()))
      {
        shots[j].setIsVisible(false);
        alien[i].setIsVisible(false);
      }
    }

    if (alien[i].getSprite()->getGlobalBounds().intersects(spaceship.getSprite()->getGlobalBounds()))
    {
      game_over1 = true;
      in_game = false;
      player_won = false;
      game_over.setWin(false);
    }
  }

  bool shouldReverse2 = false;
  for (int k = 0; k < NUM_ALIEN_TYPE_2; k++) {
    if (!alien_2[k].isVisible()) continue;
    if (alien_2[k].checkwallcollision(window)) {
      shouldReverse2 = true;
      break;
    }
  }

  // Update position and handle collisions for type 2 aliens
  for (int k = 0; k < NUM_ALIEN_TYPE_2; k++) {
    if (!alien_2[k].isVisible()) continue;

    if (shouldReverse2)
    {
      alien_2[k].setDirection_x(-alien_2[k].getDirection_x());
      alien_2[k].getSprite()->move(0, 10.0f);
    }

    alien_2[k].getSprite()->move(alien_2[k].getDirection_x() * alien_2[k].getSpeed() * dt, 0);

    for (int j = 0; j < no_of_shot; j++)
    {
      if (shots[j].isVisible() && alien_2[k].isVisible() &&
          shots[j].getSprite()->getGlobalBounds().intersects(alien_2[k].getSprite()->getGlobalBounds()))
      {
        shots[j].setIsVisible(false);
        alien_2[k].setIsVisible(false);
      }
    }

    if (alien_2[k].getSprite()->getGlobalBounds().intersects(spaceship.getSprite()->getGlobalBounds()))
    {
      game_over1 = true;
      in_game = false;
      player_won = false;
      game_over.setWin(false);
    }
  }
}

// Update bullets
void Game::updateShots(float dt)
{
  for (int i = 0; i < no_of_shot; i++)
  {
    if (shots[i].isVisible())
    {
      shots[i].getSprite()->move(0, -1000.f * dt);
      if (shots[i].getSprite()->getPosition().y < 0)
      {
        shots[i].setIsVisible(false);
      }
    }
  }
}

// Update countdown timer before game starts
void Game::updateCountdown(float dt)
{
  if (in_countdown)
  {
    float elapsed = countdownClock.getElapsedTime().asSeconds();

    if (elapsed >= 1.0f)
    {
      countdownValue--;
      countdownClock.restart();

      if (countdownValue <= 0)
      {
        in_countdown = false;
        in_game = true;
      }
      else
      {
        countdownText.setString(std::to_string(countdownValue));
        countdownText.setPosition(
            window.getSize().x / 2 - countdownText.getGlobalBounds().width / 2,
            window.getSize().y / 2 - countdownText.getGlobalBounds().height / 2);
      }
    }
  }
}

// Render game objects based on current state
void Game::render()
{
  if (in_menu)
  {
    window.draw(menu);
  }
  else if (in_countdown)
  {
    window.draw(countdownText);
  }
  else if (in_game)
  {
    window.draw(*spaceship.getSprite());
    for (int i = 0; i < no_of_shot; i++)
    {
      if (shots[i].isVisible())
      {
        window.draw(*shots[i].getSprite());
      }
    }
    for (int i = 0; i < NUM_ALIEN_TYPE_1; i++)
    {
      if (alien[i].isVisible())
      {
        window.draw(*alien[i].getSprite());
      }
    }

    for (int k = 0; k < NUM_ALIEN_TYPE_2; k++)
    {
      if (alien_2[k].isVisible())
      {
        window.draw(*alien_2[k].getSprite());
      }
    }
  }
  else if (game_over1)
  {
    game_over.update();
    game_over.render(window);
  }
}

// Handle keyboard input
void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Enter)
  {
    in_menu = false;
    in_countdown = true;
    countdownValue = 3;
    initCountdownText();
    countdownClock.restart();
  }

  if (game_over1)
  {
    if (!game_over.isFinished())
      {
        game_over.handleInput(event);
      }
    else {
      if (game_over.getOption())
        {
          resetGame(); // restart
        }
      else
        {
          window.close(); // quit
        }
    }
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    spaceship.getSprite()->move(-50.f, 0.f);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    spaceship.getSprite()->move(50.f, 0.f);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    if (shotClock.getElapsedTime().asSeconds() >= shotCooldown)
    {
      for (int i = 0; i < no_of_shot; i++)
      {
        if (!shots[i].isVisible())
        {
          shots[i].getSprite()->setPosition(
            spaceship.getSprite()->getPosition().x +
            spaceship.getSprite()->getGlobalBounds().width / 2 -
            shots[i].getSprite()->getGlobalBounds().width / 2,
            spaceship.getSprite()->getPosition().y);
          shots[i].setIsVisible(true);
          shotClock.restart();
          break;
        }
      }
    }
  }
}

//Reset Game
void Game::resetGame()
{
  game_over1 = false;
  player_won = false;
  in_menu = true;
  in_game = false;
  in_countdown = false;
  countdownValue = 3;
  game_over.reset();

  init(); // reinitialize the whole game
}
