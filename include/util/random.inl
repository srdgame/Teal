// Copyright (C) 2018 Samy Bensaid
// This file is part of the Teal project.
// For conditions of distribution and use, see copyright notice in LICENSE

template<class Generator>
typename RandomNumber<Generator>::result_type RandomNumber<Generator>::operator()()
{
    return generator();
}

template<class Generator>
constexpr typename RandomNumber<Generator>::result_type RandomNumber<Generator>::min()
{
    return generator.min();
}

template<class Generator>
constexpr typename RandomNumber<Generator>::result_type RandomNumber<Generator>::max()
{
    return generator.max();
}
