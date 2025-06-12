#pragma once
#include <SFML/Graphics.hpp>

class RenderableObject {
public:
  virtual ~RenderableObject() = default;
  virtual void render(sf::RenderWindow& window) = 0;
};