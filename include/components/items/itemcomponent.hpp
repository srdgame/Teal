// Copyright (C) 2018 Samy Bensaid
// This file is part of the Teal project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef ITEMCOMPONENT_HPP
#define ITEMCOMPONENT_HPP

#include <Nazara/Core/String.hpp>
#include <NDK/Component.hpp>

///
/// \struct ItemComponent
///
/// \note It must be in every items
///

struct ItemComponent : public Ndk::Component<ItemComponent>
{
    static Ndk::ComponentIndex componentIndex;
};

#endif // ITEMCOMPONENT_HPP
