#include <GameEngine.h>
#include <SFML/Graphics.hpp>

int main(void) {
  GameEngine& game = GameEngine::instance();
  game.render();

 
  return 0;
}