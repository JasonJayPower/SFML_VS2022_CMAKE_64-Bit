#pragma once

#include <array>

enum class JoyStickState { None, Press, Hold, Release };

class Joystick
{
    static constexpr auto MaxDevices = 2;
    static constexpr auto DeadZone   = 50.f;

    using JoyStickStates = std::array<size_t, MaxDevices>;

  public:
    void update();

    //void updateConnectedStatus(const uint32_t deviceID);

    void updateButton(const uint32_t deviceID, const uint32_t key);

    void updateAxis(const uint32_t deviceID, const uint32_t axis, const float position);

    bool checkState(const uint32_t deviceID, const uint32_t key, const JoyStickState state) const;

  private:
    JoyStickStates m_prevState = {};
    JoyStickStates m_currState = {};
};
