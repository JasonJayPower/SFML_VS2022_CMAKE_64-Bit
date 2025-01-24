#pragma once

#include <memory>

#include "Assets/Consts.hpp"

template <typename T, typename E>
class AssetManager
{
    using Assets = std::unique_ptr<T[]>;

  public:
    AssetManager(E e)
        : m_assets{ std::make_unique<T[]>(e) } 
    {}

    const T& get(E id) const noexcept {
        return m_assets[id];
    }

    template <typename... Args>
    const T& loadFromFile(E id, Args&&... args) {
        m_assets[id].loadFromFile(std::forward<Args>(args)...);
        return m_assets[id];
    }

  private:
    Assets m_assets;
};
