#pragma once

namespace Texture {
    using ID                       = int;
    inline constexpr auto TextureA = 0;
    inline constexpr auto TextureB = 1;
    inline constexpr auto Count    = 2;  // Must be last
}  // namespace Texture

namespace Font {
    using ID                    = int;
    inline constexpr auto FontA = 0;
    inline constexpr auto FontB = 1;
    inline constexpr auto Count = 2;  // Must be last
}  // namespace Font

namespace SFX {
    using ID                    = int;
    inline constexpr auto SfxA  = 0;
    inline constexpr auto SfxB  = 1;
    inline constexpr auto Count = 2;  // Must be last
}  // namespace SFX

namespace Music {
    using ID                     = const char*;
    inline constexpr auto MusicA = 0;
    inline constexpr auto MusicA = 1;
    inline constexpr auto Count  = 2;  // Must be last
}  // namespace Music