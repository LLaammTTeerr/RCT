#include <SFML/Graphics.hpp>

class GameEngine {
private:
  sf::RenderWindow window;
  std::optional<sf::Event> event;
public:
  GameEngine(void);
  ~GameEngine(void);

  void update(void);
  void render(void);
  static GameEngine& instance(void);
};

GameEngine::GameEngine(void) {
  window.create(sf::VideoMode({800, 600}), "Game Engine");
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);
  window.setKeyRepeatEnabled(false);
  window.setMouseCursorVisible(true);
  window.setActive(true);
  window.setPosition(sf::Vector2i(100, 100));
  window.setSize(sf::Vector2u(800, 600));
  window.setTitle("Game Engine");
  window.clear(sf::Color::Black);
}

GameEngine::~GameEngine(void) {

}

void GameEngine::update(void) {

}

void GameEngine::render(void) {
  while (window.isOpen()) {
    while (event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    window.display();
  }
  window.close();
}

GameEngine& GameEngine::instance(void) {
  static GameEngine instance;
  return instance;
}