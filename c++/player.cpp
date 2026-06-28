#include "player.h"
#include "PlayerController.h"
#include "constants.h"
#include <iostream>

Player::Player(sf::Texture& texture, sf::Vector2f start_pos, float health) {
    getSprite().setTexture(texture);
    getSprite().setScale(0.05f, 0.05f);

    m_pos = start_pos;
    m_health = health;
    m_controller = PlayerController::getPlayerController();

    m_size = sf::Vector2f(
        getSprite().getGlobalBounds().width,
        getSprite().getGlobalBounds().height
    );

    getSprite().setPosition(m_pos);
}

Player::~Player() {}

void Player::Update(float time) {
    m_state = State::IDLE;
    m_controller->controllPlayer(this, time);

    //std::cout << "m_pos: " << m_pos.x << ", " << m_pos.y << std::endl;

    if (m_state == State::RUN) {

    }
    else {

    }

    getSprite().setPosition(m_pos);

    /*std::cout << "sprite pos/bounds: "
        << m_sprite.getPosition().x << ", " << m_sprite.getPosition().y
        << " / " << m_sprite.getGlobalBounds().width << "x"
        << m_sprite.getGlobalBounds().height << std::endl;*/
}

void Player::setState(State state) {
    m_state = state;
}

sf::FloatRect Player::getGlobalBounds() const {
    return getSprite().getGlobalBounds();
}
