// Copyright (C) 2016 Samy Bensaid
// This file is part of the TealDemo project.
// For conditions of distribution and use, see copyright notice in LICENSE

#include "factory.hpp"

Ndk::EntityHandle make_character(Ndk::WorldHandle& w, const CharacterInfos& infos)
{
    Ndk::EntityHandle e = w->CreateEntity();

    infos.sprite->SetSize(static_cast<float>(infos.imgsize.x), static_cast<float>(infos.imgsize.y));
    infos.sprite->SetOrigin({ 0.f, 0.f, 0.f }); // Bug fix until new version

    auto& gfx = e->AddComponent<Ndk::GraphicsComponent>();
    gfx.Attach(infos.sprite, Def::CHARACTERS_LAYER);

    e->AddComponent<Ndk::NodeComponent>();

    e->AddComponent<LifeComponent>(infos.maxhp);
    e->AddComponent<FightComponent>();

    e->AddComponent<CDirectionComponent>(infos.o);
    e->AddComponent<PositionComponent>(infos.defL.x, infos.defL.y);

    auto& dpos = e->AddComponent<DefaultGraphicsPosComponent>(infos.defG.x, infos.defG.y);
    e->GetComponent<Ndk::NodeComponent>().SetPosition(dpos.x, dpos.y);


    e->AddComponent<MoveToComponent>();
    e->AddComponent<PathComponent>();
    //e->addComponent<Components::InventoryComponent>();

    e->AddComponent<AnimationComponent>(infos.imgsize, infos.maxframe, infos.animState);

    return e;
}