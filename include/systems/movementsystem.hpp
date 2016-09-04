// Copyright (C) 2016 Samy Bensaid
// This file is part of the TealDemo project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP

#include <NDK/System.hpp>
#include "components/common/pathcomponent.hpp"
#include "components/common/positioncomponent.hpp"
#include "components/common/cdirectioncomponent.hpp"
#include "gamedef.hpp"

///
/// \brief The MovementSystem class
///
/// Moves any entity which has a path and a position component.
/// If the path is empty, it does nothing
/// The move needs severals calls to update to be fully done
///

class MovementSystem : public Ndk::System<MovementSystem>
{
public:
    MovementSystem()
    {
        Requires<PathComponent, PositionComponent, CDirectionComponent>();
        SetUpdateRate(Def::MAXFPS);
    }
    ~MovementSystem() = default;

    static Ndk::SystemIndex systemIndex;

private:
    void OnUpdate(float elapsed) override;
};


#endif // MOVEMENTSYSTEM_HPP