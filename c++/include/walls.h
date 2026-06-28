#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class WallManager {
private:
    std::vector<sf::RectangleShape> m_walls;
public:
    WallManager() = default;

    void addWall(const sf::Vector2f& size, const sf::Vector2f& position);
    const std::vector<sf::RectangleShape>& getWalls() const;

    void draw(sf::RenderWindow& window) const;
};
