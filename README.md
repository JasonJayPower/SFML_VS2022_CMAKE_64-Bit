# SFML_VS2022_CMAKE_64-Bit
This template project serves as a foundational structure for developing applications using Visual Studio as the Integrated Development Environment (IDE), CMake as the build system, and SFML (Simple and Fast Multimedia Library) for graphics and multimedia functionality.

# Cloning the repository
When cloning a project that utilizes Git submodules, you're not only obtaining the main repository but also fetching any external dependencies or libraries linked to the project.

```git clone --recurse-submodules https://github.com/JasonJayPower/SFML_VS2022_CMAKE_64-Bit.git```

If at any point you'd like to fetch and update the linked dependencies, you can do so by running:
```git submodule update```
or, to pull the latest updates to this repo as well as the linked dependencies:
```git pull --recurse-submodules```
Alternatively, you can automate this process so it occurs any time you pull down changes by running:
```git config pull.recurseSubmodules on-demand && git config submodule.recurse true```

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

# Troubleshooting
### I'm trying to run the project, but its failing on the line `add_subdirectory(libs/sfml)`.
If the project is failing to import the SFML subdirectory, it's likely that the dependency on the SFML submodule was not setup correctly.
To correct this, please follow the steps in the [next section](#ive-cloned-the-project-but-forgot-to-include-the---recurse-submodules-argument-what-do-i-do).

### I've cloned the project, but forgot to include the `--recurse-submodules` argument. What do I do?
If you've cloned the project but have forgotten to link the SFML submodule, you can do so with the following git commands:
1. Initialise the submodules:
```
git submodule init
```
2. Fetch and update the submodules:
```
git submodule update
```