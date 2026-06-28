#include "PlayerController.h"
#include "player.h"
#include "constants.h"
#include "walls.h"
#include "collision.h"
#include <iostream>

extern WallManager g_walls;

PlayerController* PlayerController::controller = nullptr;

PlayerController::~PlayerController() {
    delete controller;
}

PlayerController* PlayerController::getPlayerController() {
    if (!controller) {
        controller = new PlayerController();
    }

    return controller;
}

void PlayerController::controllPlayer(Player* player, float time) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= PLAYER_SPEED * time;
        player->setState(State::RUN);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += PLAYER_SPEED * time;
        player->setState(State::RUN);
    }

    sf::Vector2f old_pos = player->getPosition();
    sf::FloatRect bounds = player->getSprite().getGlobalBounds();

    if (!CollisionManager::checkCollisionWithOffset(bounds, g_walls.getWalls(), sf::Vector2f(movement.x, 0.f))) {
        player->setPosition(old_pos.x + movement.x, old_pos.y);
    } else {
        //std::cout << "Коллизия по горизонтале: " << std::endl;
    }

    player->getSprite().setPosition(player->getPosition());
    bounds = player->getSprite().getGlobalBounds();

    if (!CollisionManager::checkCollisionWithOffset(bounds, g_walls.getWalls(), sf::Vector2f(0.f, movement.y))) {
        player->setPosition(player->getPosition().x, old_pos.y + movement.y);
    } else {
        //std::cout << "Коллизия по вертикале" << std::endl;
    }

    player->getSprite().setPosition(player->getPosition());
    //std::cout << "Финальная позиция после движений: " << player->getPosition().x << ", " << player->getPosition().y << std::endl;
}
