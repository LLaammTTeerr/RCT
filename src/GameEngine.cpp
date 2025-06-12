#include "GameEngine.h"
#include "constants.h"
#include "SceneManager.h"
#include <mutex>
#include "SFML/Graphics.hpp"

GameEngine::GameEngine(void) {
  window.create(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Roller Coaster Tycoon", sf::Style::Titlebar | sf::Style::Close);
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);
  window.setKeyRepeatEnabled(false);
  window.setMouseCursorVisible(true);
  window.setPosition(sf::Vector2i(0, 0));
  window.clear(sf::Color::White);
  sceneManager.pushScene(new WelcomeScene());
}

void GameEngine::update(void) {

}
  
void GameEngine::render(void) {
  while (window.isOpen()) {
    while ((event = window.pollEvent())) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (!sceneManager.isEmpty()) {
        sceneManager.currentScene()->handleEvents(window, event);
      }
    }
    window.clear(sf::Color::White);

    sceneManager.render(window);
    if (!sceneManager.isEmpty()) {
      sceneManager.currentScene()->update(0.0f);
      sceneManager.currentScene()->handleInput();
    }
    
    window.display();
  }
  window.close();
}

GameEngine& GameEngine::getInstance(void) {
  static GameEngine* instance = nullptr;
  static std::mutex mutex;
  
  if (instance == nullptr) {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr) {
      instance = new GameEngine();
    }
  }
  return *instance;
}