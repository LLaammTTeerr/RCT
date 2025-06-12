#include "Scene.h"
#include "constants.h"

const std::string WelcomeScene::WELCOME_BACKGROUND = "welcome_background.png";
const std::string WelcomeScene::BUTTON_START = "button_start.png";
const std::string WelcomeScene::BUTTON_LOAD = "button_load.png";
const std::string WelcomeScene::BUTTON_EXIT = "button_exit.png";

WelcomeScene::WelcomeScene(void) : startButton({400, 700}, {130, 190}) {
  startButton.setTexture(ResourceManager::getInstance().getTexture(BUTTON_START));
  ResourceManager::getInstance().preloadTexture(WELCOME_BACKGROUND);
  //ResourceManager::getInstance().preloadTexture(BUTTON_LOAD);
  //ResourceManager::getInstance().preloadTexture(BUTTON_EXIT);
}

void WelcomeScene::update(float deltaTime) {
  // Update logic for the welcome scene
}

void WelcomeScene::handleInput(void) {
  // Handle input for the welcome scene
}

void WelcomeScene::handleEvents(sf::RenderWindow& window, std::optional<sf::Event>& event) {
  startButton.handleEvents(window, event);
}

void WelcomeScene::render(sf::RenderWindow& window) {
  sf::Sprite background(ResourceManager::getInstance().getTexture(WELCOME_BACKGROUND));
  background.setPosition({0, 0});
  background.setScale({
    static_cast<float>(WINDOW_WIDTH) / background.getGlobalBounds().size.x,
    static_cast<float>(WINDOW_HEIGHT) / background.getGlobalBounds().size.y
  });
  window.draw(background);
  startButton.render(window);
}


GameScene::GameScene(void) {
  ResourceManager::getInstance().preloadTexture("grass.png");
}

void GameScene::update(float deltaTime) {
  // Update game logic here
}

void GameScene::handleInput(void) {
  // Handle input for the game scene here
}

void GameScene::handleEvents(sf::RenderWindow& window, std::optional<sf::Event>& event) {
  // Handle events for the game scene here
}

void GameScene::render(sf::RenderWindow& window) {
  const int GRID_WIDTH = 64;
  const int GRID_HEIGHT = 64;
  const int TILE_WIDTH = 64;
  const int TILE_HEIGHT = 32;
  float scaleX = 64.f / 16.f;  // 4.0
  float scaleY = 32.f / 8.f;   // ~4.571
  sf::VertexArray diamond(sf::PrimitiveType::LineStrip, 5);
  sf::Sprite grass(ResourceManager::getInstance().getTexture("grass.png"));
  grass.setOrigin({TILE_WIDTH / 2.0f, TILE_HEIGHT / 2.0f});
  grass.setScale({scaleX, scaleY});

for (int y = 0; y < GRID_HEIGHT; ++y) {
    for (int x = 0; x < GRID_WIDTH; ++x) {
        float screenX = (x - y) * (TILE_WIDTH / 2.f) + window.getSize().x / 2;
        float screenY = (x + y) * (TILE_HEIGHT / 2.f);

        grass.setPosition({screenX, screenY});
        window.draw(grass);

        // Diamond corners relative to center (scaled to 64x32)
        diamond[0].position = sf::Vector2f(screenX, screenY - TILE_HEIGHT / 2.f); // top
        diamond[1].position = sf::Vector2f(screenX + TILE_WIDTH / 2.f, screenY);  // right
        diamond[2].position = sf::Vector2f(screenX, screenY + TILE_HEIGHT / 2.f); // bottom
        diamond[3].position = sf::Vector2f(screenX - TILE_WIDTH / 2.f, screenY);  // left
        diamond[4].position = diamond[0].position; // close the loop

        for (int i = 0; i < 5; ++i)
            diamond[i].color = sf::Color::Red;

        window.draw(diamond);
    }
}
}