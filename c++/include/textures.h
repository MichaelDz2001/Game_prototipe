#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace textures {
    inline sf::Texture player_texture;

    static bool setTextures() {
        if (!player_texture.loadFromFile("Mayak.jpg")) {
            //std::cerr << "Ошибка загрузки текстуры" << std::endl;
            return false;
        } else {
            //std::cout << "Текстура прогрузилась" << std::endl;
            return true;
        }
    }
}

