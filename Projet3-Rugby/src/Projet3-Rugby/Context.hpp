#pragma once
namespace Context
{
    enum class State
    {
        // Ajoutez vos états ici
        Idle,
        Defend,
        Attack,
        GetBall,
        EnemyNear
    };
    enum class Team
    {
        // Ajoutez vos états ici
        Blue,
        Red
    };

    enum class Post
    {
        // Ajoutez vos états ici
        Top,
        Mid,
        Bot
    };
};
