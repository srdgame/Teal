// Copyright (C) 2018 Samy Bensaid
// This file is part of the Teal project.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef PRODUCERS_HPP
#define PRODUCERS_HPP

#include <memory>
#include <Nazara/Core/ObjectRef.hpp>
#include <Nazara/Core/ObjectHandle.hpp>

// These producers are mainly used by the Cache class
// But they can also be used without it !

template<class T>
struct SharedPointerProducer
{
    using Type = T;

    template<class... Args>
    static std::shared_ptr<T> create(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
};

template<class T>
struct RawPointerProducer
{
    using Type = T;

    template<class... Args>
    static T* create(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...).release();
    }
};

template<class T>
struct NzObjectRefProducer
{
    using Type = T;

    template<class... Args>
    static Nz::ObjectRef<T> create(Args&&... args)
    {
        return T::New(std::forward<Args>(args)...);
    }
};

template<class T>
struct NzObjectRefCopier
{
    using Type = T;

    template<class... Args>
    static Nz::ObjectRef<T> create(Args&&... args)
    {
        Nz::ObjectRef<T> res { std::forward<Args>(args)... };
        return res;
    }
};

template<class T>
struct NzObjectHandleProducer
{
    using Type = T;

    template<class... Args>
    static Nz::ObjectHandle<T> create(Args&&... args)
    {
        Nz::ObjectHandle<T> res(std::forward<Args>(args)...);
        return res;
    }
};

#endif // PRODUCERS_HPP
