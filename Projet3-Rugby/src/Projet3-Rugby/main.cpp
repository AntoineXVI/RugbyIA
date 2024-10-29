#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "pch.h"
#include "GameManager.hpp"
#include "Utils.hpp"
#include "Entity.hpp"
#include "Player.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GamingCampus - Rugby - IA/StateMachines");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../../../src/Projet3-Rugby/Hack-Regular.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

	GameManager * game_manager = GameManager::Instantiate();
    game_manager->setWindow(&window);
    game_manager->setDeltaTime(0.f);
    auto entities = game_manager->GetEntities();

    sf::Clock clock;
    bool isSelectedL = false; //bool Left
    int playerClicked = -1;
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) //clic gauche 
            {
                std::cout << "letf clic\n";
                sf::Vector2f localPositionL = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                if (!isSelectedL) //teleport player
                {
                    playerClicked = Utils::isPlayerClicked(localPositionL, entities);
                    if (playerClicked != -1)
                    {
                        entities[playerClicked]->setColor(sf::Color::Green);
                        isSelectedL = true;
                    }
                }
                else
                {
                    entities[playerClicked]->setPosition(sf::Vector2f(localPositionL.x,localPositionL.y));
                    entities[playerClicked]->setColor(sf::Color::Red);
                    isSelectedL = false;
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //clic droit 
            {
                std::cout << "right clic\n";
                sf::Vector2f localPositionR = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                
                playerClicked = Utils::isPlayerClicked(localPositionR, entities);
                if (playerClicked != -1)
                {
                    dynamic_cast <Player*>(entities[playerClicked])->setState(Context::State::EnemyNear);
                }
            }
        }

        window.clear();
        window.clear(sf::Color(51, 153, 102));

        game_manager->Update();
        game_manager->Draw();

        window.display();

        game_manager->setDeltaTime(dt.asSeconds());
    }
}
