#pragma once
#include "Object.h"
#include "Button.h"
#include "ResourceManager.h"

class Scene : public RenderableObject {
public:
  virtual void update(float) = 0;
  virtual void handleInput(void) = 0;
  virtual void handleEvents(sf::RenderWindow&, std::optional<sf::Event>&) = 0;
};

class WelcomeScene : public Scene {
public:
  WelcomeScene(void);
  ~WelcomeScene(void) = default;
  void update(float) override;
  void handleInput(void) override;
  void handleEvents(sf::RenderWindow&, std::optional<sf::Event>&) override;
  void render(sf::RenderWindow&) override;

  static const std::string WELCOME_BACKGROUND;
  static const std::string BUTTON_START;
  static const std::string BUTTON_LOAD;
  static const std::string BUTTON_EXIT;
private:
  Button startButton;
};

class GameScene : public Scene {
public:
  GameScene(void);
  ~GameScene(void) = default;
  void update(float) override;
  void handleInput(void) override;
  void handleEvents(sf::RenderWindow&, std::optional<sf::Event>&) override;
  void render(sf::RenderWindow&) override;
};