#include <SFML/Graphics.hpp>
#include "constants.h"
#include "textures.h"
#include "player.h"
#include "walls.h"

WallManager g_walls;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Communism win!");

    textures::setTextures();

    Player* player = new Player(textures::player_texture, sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), PLAYER_START_HP);

    g_walls.addWall({WINDOW_WIDTH, 20.f}, {0.f, 0.f});
    g_walls.addWall({WINDOW_WIDTH, 20.f}, {0.f, WINDOW_HEIGHT - 20.f});
    g_walls.addWall({20.f, WINDOW_HEIGHT}, {0.f, 0.f});
    g_walls.addWall({20.f, WINDOW_HEIGHT}, {WINDOW_WIDTH - 20.f, 0.f});

    g_walls.addWall({60.f, 350.f}, {180.f, 120.f});
    g_walls.addWall({60.f, 350.f}, {600.f, 120.f});
    g_walls.addWall({60.f, 125.f}, {390.f, 120.f});
    g_walls.addWall({60.f, 125.f}, {390.f, 345.f});

    sf::Clock clock;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 300;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player->Update(time);

        window.clear(sf::Color::White);

        g_walls.draw(window);

        window.draw(player->getSprite());

        window.display();
    }

    delete player;
    return 0;
}
