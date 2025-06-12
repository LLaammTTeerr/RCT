#include "GameState.h"
#include "ResourceManager.h"

WelcomeState::WelcomeState() : BackgroundTexturePath("../resource/image/WelcomeScreen.png")  {
    
    
    // Set up sprite with texture from ResourceManager
    BackgroundSprite.setTexture(ResourceManager::getInstance().getTexture(BackgroundTexturePath));

    // Optional: Scale to fit screen
    // backgroundSprite.setScale(scaleX, scaleY);
}

void WelcomeState::render(sf::RenderWindow& window) {
    // window.draw(backgroundSprite);
}

void WelcomeState::update(float deltaTime) {
    // Update logic here
}

void WelcomeState::handleInput(void) {
    // Handle input
}

void WelcomeState::processEvents(void) {
    // Process events
}

void WelcomeState::handleEvents(void) {
    // Handle events
}