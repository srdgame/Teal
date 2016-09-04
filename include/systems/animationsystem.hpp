// Copyright (C) 2016 Samy Bensaid
// This file is part of the TealDemo project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef ANIMATIONSYSTEM_HPP
#define ANIMATIONSYSTEM_HPP

#include <NDK/System.hpp>
#include <Nazara/Graphics/Sprite.hpp>
#include <NDK/Components/GraphicsComponent.hpp>
#include "components.hpp"
#include "gamedef.hpp"
#include "util.hpp"

///
/// \class AnimationSystem
///
/// \brief Animates Graphics Items, as long as
///        they have a sprite attached to them
///

class AnimationSystem : public Ndk::System<AnimationSystem>
{
public:
    AnimationSystem()
    {
        Requires<AnimationComponent, Ndk::GraphicsComponent, PositionComponent, CDirectionComponent>();
        SetUpdateRate(Def::MAXFPS);
    }
    ~AnimationSystem() = default;

    static Ndk::SystemIndex systemIndex;

private:
    void OnUpdate(float elapsed) override;

    void UndefinedStateAnimation(); //used to log errors
    void MovingStateAnimation(unsigned startX, unsigned startY, Nz::SpriteRef gfx,
                              AnimationComponent& anim, bool moving);
};

#endif // ANIMATIONSYSTEM_HPP