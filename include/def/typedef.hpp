// Copyright (C) 2018 Samy Bensaid
// This file is part of the Teal project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP

#include <Nazara/Core/String.hpp>
#include <Nazara/Math/Vector2.hpp>
#include <array>
#include <memory>
#include <vector>
#include <utility>
#include "util/variant.hpp"
#include "gamedef.hpp"

struct TileData;
using TileArray = std::array<TileData, Def::TileArraySize>;


using LuaBasicArgument = Variant<Nz::String, double, bool>;

struct LuaTableArgument
{
    std::vector<LuaBasicArgument> vars;
    std::vector<std::shared_ptr<LuaTableArgument>> tables;
};

using LuaArgument = LuaTableArgument;
using LuaArguments = LuaTableArgument;


template<class T>
struct Vector2Pair
{
    Nz::Vector2<T> first;
    Nz::Vector2<T> second;
};

using Vector2uPair = Vector2Pair<unsigned>;
using Vector2iPair = Vector2Pair<int>;
using Vector2fPair = Vector2Pair<float>;

template<class T>
struct Vector2Triplet
{
    Nz::Vector2<T> first;
    Nz::Vector2<T> second;
    Nz::Vector2<T> third;
};

using Vector2uTriplet = Vector2Triplet<unsigned>;
using Vector2iTriplet = Vector2Triplet<int>;
using Vector2fTriplet = Vector2Triplet<float>;

#endif // TYPEDEF_HPP
