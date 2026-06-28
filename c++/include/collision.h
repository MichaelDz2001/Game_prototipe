#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class CollisionManager {
public:
    static bool checkCollision(
        const sf::FloatRect& playerBounds,
        const std::vector<sf::RectangleShape>& walls,
        sf::Vector2f& correction
    );
    
    static bool checkCollisionWithOffset(
        const sf::FloatRect& playerBounds,
        const std::vector<sf::RectangleShape>& walls,
        const sf::Vector2f& offset
    );
};
