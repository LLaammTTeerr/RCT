#include "GameEngine.h"
#include <mutex>

GameEngine::GameEngine(void) {
    window.create(sf::VideoMode({1400, 790}), "Roller Coaster Tycoon");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setMouseCursorVisible(true);
    window.setPosition(sf::Vector2i(0, 0));
    window.clear(sf::Color::Black);
  }
  
  void GameEngine::update(void) {
  
  }
  
  void GameEngine::render(void) {
    sf::CircleShape circle(50); // Create circle outside the main loop
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({375, 275});
  
    while (window.isOpen()) {
      while (event = window.pollEvent()) {
        if (event -> is<sf::Event::Closed>()) {
          window.close();
        }
      }
      
      window.clear(sf::Color::Black);
      window.draw(circle); // Draw before display()
      window.display(); // Display after all drawing is done
    }
    window.close();
  }
  
  
  GameEngine& GameEngine::instance(void) {
      static GameEngine* instance = nullptr;
      static std::mutex mutex;
      
      // Use double-checked locking to ensure thread safety
      if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
          instance = new GameEngine();
        }
      }
      return *instance;
  }