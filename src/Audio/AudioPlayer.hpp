#pragma once

#include <SFML/Audio/Sound.hpp>
#include <array>

class AudioPlayer
{
  public:
    void play(const sf::SoundBuffer& soundBuffer);

    void stopAllSfx();

  private:
    static constexpr auto MaxSFX = 32;

    std::array<sf::Sound, MaxSFX> m_sfx;
};
