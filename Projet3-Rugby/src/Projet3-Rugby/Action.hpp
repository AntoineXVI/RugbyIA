#pragma once

class Player;

class Action
{
public:
    Action() {};
    virtual void Start(Player * player) = 0;
    virtual void Update(Player * player) = 0;
    virtual void End(Player * player) = 0;
    virtual ~Action() {};
};


//ALORS quelle la diff entre DefendAction et Attack ou alors c'est just move action qui poss�de plusieurs conditions 
//est ce que on a besoin de diff�rentee action qui move ou juste uine appel� par diif condition
//soir tu move vers la balle avec un espace
//soit tu move vers la balle jusqu'a collide
//dans mon update veridier qu'elle team a la balle
