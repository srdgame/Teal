// Copyright (C) 2018 Samy Bensaid
// This file is part of the Teal project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef GRAPHICALITEMDATA_HPP
#define GRAPHICALITEMDATA_HPP

#include <NDK/Entity.hpp>
#include <Nazara/Math/Vector2.hpp>
#include "components/common/logicentityidcomponent.hpp"
#include "global.hpp"

struct GraphicalItemData
{
    GraphicalItemData(const Ndk::EntityHandle& logicItem_, const Nz::Vector2f& size_, const Nz::Vector2f& offset_, LogicEntityIdComponent::GraphicalItemType itemType_)
        : logicItem { logicItem_ }, size { size_ }, offset { offset_ }, itemType { itemType_ } {}

    Ndk::EntityHandle logicItem;
    Nz::Vector2f size;
    Nz::Vector2f offset;
    LogicEntityIdComponent::GraphicalItemType itemType;
};

#endif // GRAPHICALITEMDATA_HPP
