#include "ResourceManager.h"
#include <iostream>

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager* instance = nullptr;
    static std::mutex mutex;
    
    // Use double-checked locking to ensure thread safety
    if (instance == nullptr) {
      std::lock_guard<std::mutex> lock(mutex);
      if (instance == nullptr) {
        instance = new ResourceManager();
      }
    }
    return *instance;
}

sf::Texture& ResourceManager::getTexture(const std::string& filename) {
    auto it = textures.find(filename);
    if (it == textures.end()) {
        // Texture not loaded, load it now
        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(filename)) {
            std::cerr << "Failed to load texture: " << filename << std::endl;
            throw std::runtime_error("Failed to load texture: " + filename);
        }
        textures[filename] = std::move(texture);
    }
    return *textures[filename];
}

sf::Font& ResourceManager::getFont(const std::string& filename) {
    auto it = fonts.find(filename);
    if (it == fonts.end()) {
        auto font = std::make_unique<sf::Font>();
        if (!font->openFromFile(filename)) {
            std::cerr << "Failed to load font: " << filename << std::endl;
            throw std::runtime_error("Failed to load font: " + filename);
        }
        fonts[filename] = std::move(font);
    }
    return *fonts[filename];
}

void ResourceManager::preloadTexture(const std::string& filename) {
    getTexture(filename); // This will load it if not already loaded
} 

void ResourceManager::preloadFont(const std::string& filename) {
    getFont(filename);
}

void ResourceManager::clear() {
    textures.clear();
    fonts.clear();
}