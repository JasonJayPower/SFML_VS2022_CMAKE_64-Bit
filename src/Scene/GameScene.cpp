#include "GameScene.hpp"
#include "GameScene.hpp"

#include <SFML/Graphics.hpp>

#include "SharedContext.hpp"

#include "Input/Keyboard.hpp"


GameScene::GameScene(Scene::ID id, SharedContext* context)
    : BaseScene{ id, context } 
{}

void GameScene::handleEvents(const Keyboard& keyboard) {
    if (keyboard.checkKeyState(Keyboard::Key::A, KeyState::Press)) {
        m_ctx->currSceneID = Scene::None;
    }
}

void GameScene::update() {
}

void GameScene::render(sf::RenderWindow& window) {
    sf::CircleShape c;
    c.setFillColor(sf::Color::Yellow);
    c.setRadius(100);
    window.draw(c);
}

void GameScene::init() {
}
