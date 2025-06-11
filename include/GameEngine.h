#pragma once
#include <SFML/Graphics.hpp>
class GameEngine {
private:
    sf::RenderWindow window;
    std::optional<sf::Event> event;
public:
    GameEngine(void);
    ~GameEngine(void) = default;

    void update(void);
    void render(void);
    static GameEngine& instance(void);
};

