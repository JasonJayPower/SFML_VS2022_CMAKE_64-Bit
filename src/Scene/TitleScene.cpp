#include "TitleScene.hpp"

#include <SFML/Graphics.hpp>

#include "Scene/consts.hpp"

#include "SharedContext.hpp"

#include "Input/Keyboard.hpp"

TitleScene::TitleScene(Scene::ID id, SharedContext* context)
    : BaseScene{ id, context } 
{}

void TitleScene::handleEvents(const Keyboard& keyboard) {
    if (keyboard.checkKeyState(Keyboard::Key::A, KeyState::Press)) {
        m_ctx->currSceneID = Scene::Game;
    }
}

void TitleScene::update()
{

}

void TitleScene::render(sf::RenderWindow& window) 
{
    sf::CircleShape c;
    c.setFillColor(sf::Color::Green);
    c.setRadius(100);
    window.draw(c);
}

void TitleScene::init()
{
}

