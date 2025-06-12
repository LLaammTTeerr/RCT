#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include "constants.h"

ResourceManager& ResourceManager::getInstance() {
  static ResourceManager* instance = nullptr;
  static std::mutex mutex;

  if (instance == nullptr) {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr) {
      instance = new ResourceManager();
    }
  }
  return *instance;
}

sf::Texture& ResourceManager::getTexture(std::string filename) {
  filename = IMAGE_PATH + filename;
  auto it = textures.find(filename);
  if (it == textures.end()) {
    sf::Texture texture;
    assert(texture.loadFromFile(filename));
    textures[filename] = std::move(texture);
  }
  return textures[filename];
}

sf::Font& ResourceManager::getFont(std::string filename) {
  filename = FONT_PATH + filename;
  auto it = fonts.find(filename);
  if (it == fonts.end()) {
    sf::Font font;
    assert(font.openFromFile(filename));
    fonts[filename] = std::move(font);
  }
  return fonts[filename];
}

void ResourceManager::preloadTexture(std::string filename) {
  getTexture(filename);
} 

void ResourceManager::preloadFont(std::string filename) {
  getFont(filename);
}