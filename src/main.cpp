#include <GameEngine.h>

int main(void) {
  GameEngine& game = GameEngine::instance();
  game.render();
  return 0;
}