﻿// Copyright (C) 2016 Samy Bensaid
// This file is part of the TealDemo project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef GFXUTIL_HPP
#define GFXUTIL_HPP

#include <Nazara/Graphics/Sprite.hpp>
#include <NDK/Components/GraphicsComponent.hpp>
#include <NDK/Components/NodeComponent.hpp>
#include <Nazara/Core/Color.hpp>
#include <Nazara/Utility/Image.hpp>
#include <vector>
#include "def/gamedef.hpp"
#include "global.hpp"
#include "components/common/positioncomponent.hpp"
#include "components/common/defaultgraphicsposcomponent.hpp"
#include "components/common/renderablesstoragecomponent.hpp"
#include "util/assert.hpp"
#include "util/mapposutil.hpp"
#include "util/entityutil.hpp"
#include "util/util.hpp"

inline void cloneRenderables(const Ndk::EntityHandle& e);
inline void cloneRenderables(Ndk::GraphicsComponent& gfx, RenderablesStorageComponent& renderables);

///
/// \fn getTileFromGlobalCoords
///
/// \brief Returns the tile located at the coords position
///
/// \param coords Global Coordinates of the tile (like mouse position)
///
/// \returns The logic position of the tile
///
/// \note Needs a scheme set with the initSchemeUtility function
///
/// \todo Add the z axis ?
///

extern AbsTile getTileFromGlobalCoords(const Nz::Vector2ui& coords);

///
/// \fn initSchemeUtility
///
/// \brief Sets the scheme the getTileFromGlobalCoords function will use
///
/// \todo Delete this function and find a better way
///

extern void initSchemeUtility(Nz::ImageRef newScheme);

///
/// \fn refreshGraphicsPos
///
/// \brief Refreshes the Graphics Position of an entity containing
///        a Sprite attached to a GraphicsComponent, using the
///        Position component of a logical entity
///

extern void refreshGraphicsPos(const Ndk::EntityHandle& logicEntity, const Ndk::EntityHandle& graphicalEntity);
inline void refreshGraphicsPos(const Ndk::EntityHandle& entity);

#include "gfxutil.inl"

#endif // GFXUTIL_HPP
