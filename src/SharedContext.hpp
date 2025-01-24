#pragma once

#include "Assets/Consts.hpp"
#include "Scene/Consts.hpp"

template <typename T, typename E>
class AssetManager;

class AudioPlayer;
class Keyboard;

namespace sf {
    class Font;
    class SoundBuffer;
    class Texture;
}  // namespace sf

struct SharedContext {
    Scene::ID currSceneID                          = Scene::Title;
    AudioPlayer* audioPlayer                       = nullptr;
    AssetManager<sf::Font, Font::ID>* fntMgr       = nullptr;
    AssetManager<sf::SoundBuffer, SFX::ID>* sfxMgr = nullptr;
    AssetManager<sf::Texture, Texture::ID>* texMgr = nullptr;
};
