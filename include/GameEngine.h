#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include "SceneManager.h"

class GameEngine {
private:
  SceneManager sceneManager;
  sf::RenderWindow window;
  std::optional<sf::Event> event;
public:
  GameEngine(void);
  ~GameEngine(void) = default;

  void update(void);
  void render(void);
  static GameEngine& getInstance(void);
  sf::RenderWindow& getWindow(void) { return window; }
};