#include "App/App.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene/BaseScene.hpp"
#include "Scene/GameScene.hpp"
#include "Scene/TitleScene.hpp"

//    Keyboard m_keyboard;
//
////FontMgr m_fontMgr;
//TextureMgr m_texMgr;
//
//CurrScene m_currScene;
//Scenes m_scenes;
//
//RenderWindow m_window;
//
//SharedContext m_ctx;
//}
//;

App::App()
    : m_ctx        {}
    , m_audioPlayer{}
    , m_keyboard   {}
    , m_texMgr     { Texture::Count }
    , m_fntMgr     { Font::Count }
    , m_sfxMgr     { SFX::Count }
    , m_currScene  { nullptr }
    , m_scenes     { nullptr }
    , m_window     { nullptr }
{}

App::~App() = default;

bool App::init() {
    // Create RenderWindow
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 640, 480 }), "");
    m_window->setKeyRepeatEnabled(false);


    // Load assets;





    // Set up SharedContext
    m_ctx = {
        Scene::Title,
        &m_audioPlayer,
        &m_fntMgr, 
        &m_sfxMgr,
        &m_texMgr,
    };

    // Create all Scenes;
    m_scenes[Scene::Title] = std::make_unique<TitleScene>(Scene::Title, &m_ctx);
    m_scenes[Scene::Game]  = std::make_unique<GameScene>(Scene::Game, &m_ctx);

    // Initialise / Setup all scenes;
    for (auto& scene : m_scenes) {
        scene->init();
    }

    // Set current scene
    m_currScene = m_scenes[Scene::Title].get();

    return true;
}

void App::run() {
    const sf::Time TimePerFrame(sf::seconds(1.f / 60.f));

    sf::Time timeSinceLastUpdate = {};
    sf::Clock clock              = {};

    while (m_window->isOpen()) {
        render();

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate >= TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update();
            // Check do we need to swap scenes
            if (m_currScene->getID() != m_ctx.currSceneID) {
                if (m_ctx.currSceneID == Scene::None) {
                    m_window->close();
                } else {
                    m_currScene = m_scenes[m_ctx.currSceneID].get();
                }
            }
        }
    }
}

void App::processEvents() {
    m_keyboard.update();

    sf::Event e{};
    while (m_window->pollEvent(e)) {
        switch (e.type) {
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased: {
                m_keyboard.setKey(e.key.code);
            } break;
            case sf::Event::Closed: {
                m_window->close();
            } break;
            default: break;
        }
    }
    m_currScene->handleEvents(m_keyboard);
}

void App::update() {
    m_currScene->update();
}

void App::render() {
    m_window->clear(sf::Color::Blue);
    m_currScene->render(*m_window);
    m_window->display();
}
