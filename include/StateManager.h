#include <GameState.h>
#include <vector>

class StateManager {
private:
  std::vector<GameState*> states;
public:
  StateManager(void) = default;
  ~StateManager(void);

  void pushState(GameState* state);
  void popState(void);
  void replaceState(GameState* state);
  void render(void);
  bool isEmpty(void) const;
  GameState* currentState(void) const;
  void clearStates(void);
};

StateManager::StateManager(void) {}

StateManager::~StateManager(void) {
  clearStates();
}

void StateManager::pushState(GameState* state) {
  states.push_back(state);
}

void StateManager::popState(void) {
  if (!states.empty()) {
    delete states.back();
    states.pop_back();
  }
}

void StateManager::replaceState(GameState* state) {
  if (!states.empty()) {
    delete states.back();
    states.pop_back();
  }
  states.push_back(state);
}

void StateManager::render(void) {
  if (!states.empty()) {
    states.back()->render();
  }
}

bool StateManager::isEmpty(void) const {
  return states.empty();
}

GameState* StateManager::currentState(void) const {
  if (!states.empty()) {
    return states.back();
  }
  return nullptr;
}

void StateManager::clearStates(void) {
  for (GameState* state : states) {
    delete state;
  }
  states.clear();
}