#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <vector>

class SceneManager {
private:
  std::vector<Scene*> scenes;
public:
  SceneManager() = default;
  ~SceneManager();

  void pushScene(Scene* scene);
  void popScene(void);
  void replaceScene(Scene* scene);
  void render(sf::RenderWindow& window);
  bool isEmpty(void) const;
  Scene* currentScene(void) const;
  void clearScenes(void);
};