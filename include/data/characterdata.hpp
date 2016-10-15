// Copyright (C) 2016 Samy Bensaid
// This file is part of the Teal game.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef CHARACTERDATA_HPP
#define CHARACTERDATA_HPP

#include <Nazara/Math/Vector2.hpp>
#include <Nazara/Graphics/InstancedRenderable.hpp>
#include <Nazara/Graphics/Sprite.hpp>

#include "util/util.hpp"
#include "global.hpp"
#include "components/common/animationcomponent.hpp"

///
/// \struct CharacterData
///
/// \brief Contains all required attributes of a character
///        It is used by a character factory
///

struct CharacterData
{
    /// 
    /// \param size Size of the sprite's image
    /// \param pic Sprite of the character
    /// \param mf Max Frame (used for animation)
    /// \param dg Default graphics position (e.g. for it to fit in a tile)
    /// \param dl Default logic position
    /// \param mhp Max HPs (used for fights)
    /// \param o_ Default orientation
    /// 

    CharacterData(const Nz::Vector2ui& size, const Nz::SpriteRef& pic, unsigned mf = 0u,
                   const Nz::Vector2f& dg = {}, const Nz::Vector2ui& dl = {},
                   unsigned mhp = 100u, const AnimationComponent::AnimationState& animState_
                   = AnimationComponent::OnMove, const Orientation& o_ = Orientation::Down)

        : imgsize { size }, sprite { pic }, maxframe { mf }, defG { dg }, defL { dl }, 
        maxhp { mhp }, animState { animState_ }, o { o_ } {}

    ~CharacterData() = default;

    Nz::Vector2ui imgsize;
    Nz::SpriteRef sprite;
    unsigned maxframe; // animation frames

    Nz::Vector2f defG; // default graphics pos
    Nz::Vector2ui defL; // default logic pos

    unsigned maxhp;
    AnimationComponent::AnimationState animState;
    Orientation o;
};

#endif // CHARACTERDATA_HPP
