# SFML_VS2022_CMAKE_64-Bit
This template project serves as a foundational structure for developing applications using Visual Studio as the Integrated Development Environment (IDE), CMake as the build system, and SFML (Simple and Fast Multimedia Library) for graphics and multimedia functionality.

# Loading assets
An assets directory is set up with in this template project to simplify the storing and loading of assets.

[Example loading texture]
```
{
    ...
    sf::Texture texture;
    bool result = texture.loadFromFile("assets/texture/player.png");
    ...
}
```

# Running your application
When the application builds, all the required shared libs (dll's) and assets are copied over to the build directory.
This will allow the application to be run directly from the build folder.
