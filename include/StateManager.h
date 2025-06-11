#pragma once
#include "GameState.h"
#include <vector>

class StateManager {
private:
  std::vector<GameState*> states;
public:
  StateManager() = default;
  ~StateManager();

  void pushState(GameState* state);
  void popState(void);
  void replaceState(GameState* state);
  void render(void);
  bool isEmpty(void) const;
  GameState* currentState(void) const;
  void clearStates(void);
};
