#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <mutex>

class ResourceManager {
public:
  static ResourceManager& getInstance();
  
  sf::Texture& getTexture(std::string filename);
  
  sf::Font& getFont(std::string filename);
  
  void preloadTexture(std::string filename);
  void preloadFont(std::string filename);
private:
  ResourceManager() = default;
  ~ResourceManager() = default;
  ResourceManager(const ResourceManager&) = delete;
  ResourceManager& operator=(const ResourceManager&) = delete;
  
  std::unordered_map<std::string, sf::Texture> textures;
  std::unordered_map<std::string, sf::Font> fonts;
};