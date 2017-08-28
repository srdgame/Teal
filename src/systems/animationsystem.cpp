// Copyright (C) 2017 Samy Bensaid
// This file is part of the TealDemo project.
// For conditions of distribution and use, see copyright notice in LICENSE

#include <NDK/Components/GraphicsComponent.hpp>
#include "components/common/orientationcomponent.hpp"
#include "components/common/positioncomponent.hpp"
#include "components/common/renderablesstoragecomponent.hpp"
#include "def/gamedef.hpp"
#include "def/systemdef.hpp"
#include "util/gfxutil.hpp"
#include "util/util.hpp"
#include "util/animutil.hpp"
#include "systems/animationsystem.hpp"

AnimationSystem::AnimationSystem()
{
    Requires<AnimationComponent, Ndk::GraphicsComponent, PositionComponent, OrientationComponent, RenderablesStorageComponent>();
    SetUpdateRate(Def::MaxSystemUPS);
    SetUpdateOrder(Def::AnimationSystemUpdateOrder);
}

void AnimationSystem::OnUpdate(float elapsed)
{
    for (auto& e : GetEntities())
        updateAnimation(e);
}
