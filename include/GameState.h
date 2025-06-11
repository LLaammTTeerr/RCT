#pragma once
class GameState {
public:
  virtual ~GameState(void) = 0;

  virtual void update(float deltaTime) = 0;
  virtual void handleInput(void) = 0;
  virtual void enter(void) = 0;
  virtual void exit(void) = 0;
  virtual void pause(void) = 0;
  virtual void resume(void) = 0;
  virtual void processEvents(void) = 0;
  virtual void handleEvents(void) = 0;
  virtual void render(void) = 0;
};

class WelcomeState : public GameState {
public:
  WelcomeState(void);
  ~WelcomeState(void) = default;
};

class MenuState : public GameState {
public:
  MenuState(void);
  ~MenuState(void) = default;
};
class InGameState : public GameState {
public:
  InGameState(void);
  ~InGameState(void) = default;
};