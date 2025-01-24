#include "Audio/AudioPlayer.hpp"

#include <SFML/Audio/SoundBuffer.hpp>

void AudioPlayer::play(const sf::SoundBuffer& soundBuffer) {
    auto sfx = std::find_if(m_sfx.begin(), m_sfx.end(), [](const auto& sfx) {
        return sfx.getStatus() == sf::SoundSource::Status::Stopped;
    });

    if (sfx != m_sfx.end()) {
        sfx->setBuffer(soundBuffer);
        sfx->play();
    }
}

void AudioPlayer::stopAllSfx() {
    for (auto& sfx : m_sfx) {
        sfx.stop();
    }
}
