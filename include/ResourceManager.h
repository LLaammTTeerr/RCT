#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class ResourceManager {
public:
    static ResourceManager& getInstance();
    
    // Load and get texture
    sf::Texture& getTexture(const std::string& filename);
    
    // Load and get font
    sf::Font& getFont(const std::string& filename);
    
    // Preload resources
    void preloadTexture(const std::string& filename);
    void preloadFont(const std::string& filename);
    
    // Clear all resources
    void clear();

private:
    ResourceManager() = default;
    ~ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
};