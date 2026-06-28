#include "collision.h"

bool CollisionManager::checkCollision(
    const sf::FloatRect& playerBounds,
    const std::vector<sf::RectangleShape>& walls,
    sf::Vector2f& correction
) {
    for (const auto& wall : walls) {
        if (playerBounds.intersects(wall.getGlobalBounds())) {
            correction = sf::Vector2f(0.f, 0.f);
            return true;
        }
    }
    return false;
}

bool CollisionManager::checkCollisionWithOffset(
    const sf::FloatRect& playerBounds,
    const std::vector<sf::RectangleShape>& walls,
    const sf::Vector2f& offset
) {
    sf::FloatRect moved = playerBounds;
    moved.left += offset.x;
    moved.top += offset.y;
    for (const auto& wall : walls) {
        if (moved.intersects(wall.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}
