#pragma once
#include "Scene/BaseScene.hpp"

struct SharedContext;

class GameScene final : public BaseScene
{
  public:
    GameScene(Scene::ID id, SharedContext* context);

    void init() override;
    void handleEvents(const Keyboard& keyboard) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

  private:
    // Game Functions
};
