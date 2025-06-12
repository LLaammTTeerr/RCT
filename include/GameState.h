#pragma once
#include <SFML/Graphics.hpp>
class GameState {
public:
  virtual ~GameState(void) = 0;

  virtual void update(float deltaTime) = 0;
  virtual void handleInput(void) = 0;
  virtual void processEvents(void) = 0;
  virtual void handleEvents(void) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
};

class WelcomeState : public GameState {
public:
    WelcomeState(void);
    void update(float deltaTime) override;
    void handleInput(void) override;
    void processEvents(void) override;
    void handleEvents(void) override;
    void render(sf::RenderWindow& window) override;
    ~WelcomeState(void) = default;

private:
    sf::Sprite BackgroundSprite;
    std::string BackgroundTexturePath;
};

class MenuState : public GameState {
public:
  MenuState(void);
  ~MenuState(void) = default;
};
class InGameState : public GameState {
public:
  InGameState(void);
  ~InGameState(void) = default;
};