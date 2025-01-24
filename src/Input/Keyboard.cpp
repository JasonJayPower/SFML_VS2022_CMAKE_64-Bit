#include "Keyboard.hpp"

void Keyboard::update() {
    m_prevState = m_currState;
}

void Keyboard::setKey(const Key key) {
    if (key != -1) {
        m_currState[0] ^= (1ull << key);
    }
}

bool Keyboard::checkKeyState(const Key key, KeyState state) const {
    if (key != -1) {
        const bool isCurrStateBitSet = (m_currState[0] & (1ull << key)) != 0;
        const bool isPrevStateBitSet = (m_prevState[0] & (1ull << key)) != 0;
        if (isPrevStateBitSet) {
            return !isCurrStateBitSet ? KeyState::Release == state : KeyState::Hold == state;
        }
        return (isCurrStateBitSet && (KeyState::Press == state || KeyState::Hold == state));
    }
    return false;
}
