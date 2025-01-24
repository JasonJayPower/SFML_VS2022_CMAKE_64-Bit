#include "Joystick.hpp"

void Joystick::update() {
    m_prevState = m_currState;
}

//void Joystick::updateConnectedStatus(const uint32_t deviceID) {
//    m_currState[deviceID] ^= DeviceID;
//}

void Joystick::updateButton(const uint32_t deviceID, const uint32_t key) {
    //printf("Button %i\n", key);
    if (deviceID < MaxDevices) {
        m_currState[deviceID] ^= (1ull << key);
    }
}

void Joystick::updateAxis(const uint32_t deviceID, const uint32_t axis, const float position) {
    if (deviceID < MaxDevices) {
        const auto axisOffset = 32 + (axis * 2);

        if (position <= -DeadZone) {
            m_currState[deviceID] |= (1ull << axisOffset);
            m_currState[deviceID] &= ~(1ull << axisOffset + 1);
        } else if (position >= DeadZone) {
            m_currState[deviceID] &= ~(1ull << axisOffset);
            m_currState[deviceID] |=  (1ull << axisOffset + 1);
        } else {
            m_currState[deviceID] &= ~((1ull << axisOffset) | (1ull << (axisOffset + 1)));
        }
    }
}

bool Joystick::checkState(const uint32_t deviceID, const uint32_t key, const JoyStickState state) const {
    if (deviceID > MaxDevices) {
        return false;
    }

    const bool isCurrStateBitSet = (m_currState[deviceID] & (1ull << key)) != 0;
    const bool isPrevStateBitSet = (m_prevState[deviceID] & (1ull << key)) != 0;

    if (isPrevStateBitSet) {
        return !isCurrStateBitSet ? JoyStickState::Release == state : JoyStickState::Hold == state;
    }
    return (isCurrStateBitSet && (JoyStickState::Press == state || JoyStickState::Hold == state));
}
