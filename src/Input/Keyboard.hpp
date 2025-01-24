#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <array>


enum class KeyState { None, Press, Hold, Release };

class Keyboard
{
  public:
    using Key = sf::Keyboard::Key;

    void update();
    void setKey(const Key key);
    bool checkKeyState(const Key key, KeyState state) const;

  private:
    using KeyStates = std::array<size_t, 2>;

    KeyStates m_currState{};
    KeyStates m_prevState{};
};