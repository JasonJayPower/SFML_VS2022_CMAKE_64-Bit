#pragma once

namespace Scene {
    using ID = int;
    inline constexpr auto None     = -1; // Used to end the program
    inline constexpr auto Title    =  0;
    inline constexpr auto Game     =  1;
    inline constexpr auto Count    =  2; // Update this to always be > previous value ^^^
}  // namespace Scene
