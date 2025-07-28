/*
===========================================================================
    GLEAM ENGINE https://gleamengine.org
    Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include <memory>

#include <gleam/gleam.hpp>

#include "game.hpp"

class Tetris : public gleam::ApplicationContext {
public:
    auto Configure() -> void override {
        params.vsync = false;
        params.debug = true;
        params.title = "Tetris";
    }

    auto CreateScene() -> std::shared_ptr<gleam::Scene> override {
        return std::make_shared<Game>();
    }

    auto Update(float delta) -> bool override {
        return true;
    }
};

auto main() -> int {
    auto game = Tetris {};
    game.Start();

    return 0;
}