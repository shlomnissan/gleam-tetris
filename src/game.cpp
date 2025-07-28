/*
===========================================================================
    GLEAM ENGINE https://gleamengine.org
    Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include "game.hpp"

Game::Game() {
    mesh_ = gleam::Mesh::Create(
        gleam::CubeGeometry::Create(),
        gleam::PhongMaterial::Create(0x049EF4)
    );
    this->Add(mesh_);

    auto ambient_light = gleam::AmbientLight::Create({0xFFFFFF, 0.4f});
    this->Add(ambient_light);

    auto point_light = gleam::PointLight::Create({0xFFFFFF, 1.0f});
    point_light->transform.SetPosition({2.0f, 2.0f, 2.0f});
    this->Add(point_light);
}

auto Game::OnAttached(gleam::SharedContext* context) -> void {
    context->Parameters().camera->TranslateZ(3.0f);
}

auto Game::OnUpdate(float delta) -> void {
    mesh_->RotateX(1.0 * delta);
    mesh_->RotateY(1.0 * delta);
}