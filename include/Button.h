#pragma once
#include <optional>
#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public RenderableObject {
private:
  std::optional<sf::Sprite> sprite;

  sf::Vector2f position;
  sf::Vector2f size;

  Button(const Button&) = delete;
  Button& operator=(const Button&) = delete;
public:
  ~Button(void) {}
  Button(void) = delete;
  Button(const sf::Vector2f& position, const sf::Vector2f& size) : position(position), size(size) {

  }

  void setTexture(const sf::Texture& texture) {
    if (!sprite.has_value()) {
      sprite.emplace(texture);
    } else {
      sprite.value().setTexture(texture);
    }
    sprite.value().setPosition(position);
    sprite.value().setScale({
      size.x / sprite.value().getGlobalBounds().size.x,
      size.y / sprite.value().getGlobalBounds().size.y
    });
  }

  void render(sf::RenderWindow& window) override {
    sf::RectangleShape rect;
    rect.setPosition(position);
    rect.setSize(size);
    rect.setFillColor(sf::Color(0, 0, 0, 200));
    window.draw(rect);
    if (sprite.has_value()) {
      window.draw(sprite.value());
    }
  }

  void handleEvents(sf::RenderWindow& window, std::optional<sf::Event>& event) {
   if (event.has_value() and event->is<sf::Event::MouseButtonPressed>()) {
      sf::Mouse::Button btn = event.value().getIf<sf::Event::MouseButtonPressed>()->button;
      if (btn == sf::Mouse::Button::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (sprite.has_value() && sprite.value().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
          // do something
        }
      }
    }
  }
};