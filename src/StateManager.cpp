#include "StateManager.h"
#include "GameEngine.h"
StateManager::~StateManager() {
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
    states.back()->render(GameEngine::instance().getWindow());
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