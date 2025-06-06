class GameState {
public:
  virtual ~GameState(void);

  virtual void render(void) = 0;
};

class WelcomeState : public GameState {
public:
  WelcomeState(void);
  ~WelcomeState(void) override;

  void render(void) override;
};

class InGameState : public GameState {
public:
  InGameState(void);
  ~InGameState(void) override;

  void render(void) override;
};