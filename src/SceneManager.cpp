#include "SceneManager.h"

SceneManager::~SceneManager() {
  clearScenes();
}

void SceneManager::pushScene(Scene* scene) {
  scenes.push_back(scene);
}

void SceneManager::popScene(void) {
  if (!scenes.empty()) {
    delete scenes.back();
    scenes.pop_back();
  }
}

void SceneManager::replaceScene(Scene* scene) {
  if (!scenes.empty()) {
    delete scenes.back();
    scenes.pop_back();
  }
  scenes.push_back(scene);
}

void SceneManager::render(sf::RenderWindow& window) {
  if (!scenes.empty()) {
    scenes.back()->render(window);
  }
}

bool SceneManager::isEmpty(void) const {
  return scenes.empty();
}

Scene* SceneManager::currentScene(void) const {
  if (!scenes.empty()) {
    return scenes.back();
  }
  return nullptr;
}

void SceneManager::clearScenes(void) {
  for (Scene* scene : scenes) {
    delete scene;
  }
  scenes.clear();
}