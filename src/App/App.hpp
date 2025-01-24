#pragma once

#include <memory>

#include "Audio/AudioPlayer.hpp"
#include "Assets/AssetManager.hpp"
#include "Assets/Consts.hpp"
#include "Input/Keyboard.hpp"
#include "Scene/Consts.hpp"
#include "SharedContext.hpp"

class BaseScene;

namespace sf {
    class Event;
    class Font;
    class SoundBuffer;
    class Texture;
    class RenderWindow;
}  // namespace sf

class SceneManager;

class App
{
    using TexMgr    = AssetManager<sf::Texture, Texture::ID>;
    using FntMgr    = AssetManager<sf::Font, Font::ID>;
    using SfxMgr    = AssetManager<sf::SoundBuffer, SFX::ID>;
    using Window    = std::unique_ptr<sf::RenderWindow>;
    using CurrScene = BaseScene*;
    using Scenes    = std::array<std::unique_ptr<BaseScene>, Scene::Count>;

  public:
    App();
    ~App();

    bool init();
    void run();

  private:
    void processEvents();
    void update();
    void render();


    SharedContext m_ctx;

    AudioPlayer m_audioPlayer;

    Keyboard    m_keyboard;

    TexMgr      m_texMgr;
    FntMgr      m_fntMgr;
    SfxMgr      m_sfxMgr;
                
    CurrScene   m_currScene;
    Scenes      m_scenes;
                
    Window      m_window;
};              
