#include <iostream>
#include "walls.h"

void WallManager::addWall(const sf::Vector2f& size, const sf::Vector2f& position) {
    //std::cout << "Добавление стены: размер = (" << size.x << ", " << size.y << "), позиция = (" << position.x << ", " << position.y << ")" << std::endl;
    sf::RectangleShape wall(size);
    wall.setFillColor(sf::Color::Red);
    wall.setPosition(position);
    m_walls.push_back(wall);
}

const std::vector<sf::RectangleShape>& WallManager::getWalls() const {
    return m_walls;
}

void WallManager::draw(sf::RenderWindow& window) const {
    for (const auto& wall : m_walls) {
        //std::cout << "Нарисовать стену в: " << wall.getPosition().x << ", " << wall.getPosition().y << std::endl;
        window.draw(wall);
    }
}
