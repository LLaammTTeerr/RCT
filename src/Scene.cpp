#include "Scene.h"
#include "ResourceManager.h"
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