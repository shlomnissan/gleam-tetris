/*
===========================================================================
    GLEAM ENGINE https://gleamengine.org
    Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#pragma once

#include <memory>

#include <gleam/gleam.hpp>

class Game : public gleam::Scene {
public:
    Game();

    auto OnAttached(gleam::SharedContext* context) -> void override;

    auto OnUpdate(float delta) -> void override;

private:
    std::shared_ptr<gleam::Mesh> mesh_;
};