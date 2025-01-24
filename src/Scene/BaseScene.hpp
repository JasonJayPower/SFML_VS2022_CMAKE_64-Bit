#pragma once

#include "Scene/Consts.hpp"

namespace sf {
    class RenderWindow;
}
class Keyboard;
struct SharedContext;

using SceneID = int;

class BaseScene
{
  public:
    BaseScene(Scene::ID id, SharedContext* context)
        : m_id{ id }
        , m_ctx{ context } {
    }

    virtual ~BaseScene() = default;

    virtual void init()                                 = 0;
    virtual void handleEvents(const Keyboard& keyboard) = 0;
    virtual void update()                               = 0;
    virtual void render(sf::RenderWindow& window)       = 0;

    Scene::ID getID() const {
        return m_id;
    }

  protected:
    SharedContext* m_ctx;
    Scene::ID m_id;
};
