// Copyright (C) 2016 Samy Bensaid
// This file is part of the Teal game.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef CHARACTERINFOS_HPP
#define CHARACTERINFOS_HPP

#include <Nazara/Math/Vector2.hpp>
#include <Nazara/Graphics/InstancedRenderable.hpp>

#include "util.hpp"
#include "global.hpp"
#include "components/common/animationcomponent.hpp"

///
/// \brief The CharacterInfos struct
///
/// This class contains all required attributes of a character
/// It is used by a character factory
///

struct CharacterInfos
{
    /// 
    /// \param size Size of the picture
    /// \param pic Picture of the character
    /// \param mf Max Frame (used for animation)
    /// \param dg Default graphics position
    /// \param dl Default logic position
    /// \param mhp Max HPs (used for fights)
    /// \param o_ Default orientation
    /// 

    CharacterInfos(const Nz::Vector2ui& size, const Nz::SpriteRef& pic, unsigned mf = 0,
                   const Nz::Vector2f& dg = {}, const Nz::Vector2ui& dl = {},
                   unsigned mhp = 100, const AnimationComponent::AnimationState& animState_
                   = AnimationComponent::Moving, const Orientation& o_ = Orientation::Down)

        : imgsize { size }, sprite { pic }, maxframe { mf }, defG { dg }, defL { dl }, 
        maxhp { mhp }, animState { animState_ }, o { o_ } {}

    ~CharacterInfos() = default;

    Nz::Vector2ui imgsize;
    Nz::SpriteRef sprite;
    unsigned maxframe; //animation frames

    Nz::Vector2f defG; //default graphics pos
    Nz::Vector2ui defL; //default logic pos

    unsigned maxhp;
    AnimationComponent::AnimationState animState;
    Orientation o;
};

#endif // CHARACTERINFOS_HPP