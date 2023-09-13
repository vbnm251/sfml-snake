#include "Game.h"
#include "Snake.h"
#include "Apple.h"
#include "SFML/Graphics.hpp"
#include <unistd.h>
#include <thread>
#include <atomic>

namespace game {
    Game::Game(sf::RenderWindow *w) {
        window = w;
    }

    void Game::setupGame() {
        int i = getRandomDigit(5, GAME_FIELD_SIZE - 5), j = getRandomDigit(5, GAME_FIELD_SIZE - 5);
        field[i][j] = SNAKE;

        snake = Snake({i, j});
        std::pair<float, float> p = calculateField(i, j);

        sf::RectangleShape square(sf::Vector2f((float)WIDTH / GAME_FIELD_SIZE, (float)HEIGHT / GAME_FIELD_SIZE));
        square.move(p.first, p.second);
        square.setFillColor(sf::Color::Green);

        window->draw(square);
    }

    void Game::gameLoop() {
        std::atomic_bool gameFinished = false;
        std::thread inputThread(&Snake::input, &snake, std::ref(gameFinished));
        Apple apple(field);

        while(!gameFinished && window->isOpen()) {
            sf::Event event{};
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            usleep((int)(100000.0 / snake.speed));

            if (!snake.move(field, apple)) {
                gameFinished = true;
            }

            printField(apple.coords);
        }
        gameFinished = true;
        inputThread.join();
        sleep(2);
    }

    void Game::printField(std::pair<int, int> apple) {
        window->clear(sf::Color::White);

        auto sn = snake.getSnake();
        for (auto [x, y]: sn) {
            auto cords = calculateField(x, y);
            sf::RectangleShape square(sf::Vector2f((float)WIDTH / GAME_FIELD_SIZE, (float)HEIGHT / GAME_FIELD_SIZE));
            square.move(cords.first, cords.second);
            square.setFillColor(sf::Color::Green);
            window->draw(square);
        }
        auto cords = calculateField(apple.first, apple.second);
        sf::RectangleShape square(sf::Vector2f((float)WIDTH / GAME_FIELD_SIZE, (float)HEIGHT / GAME_FIELD_SIZE));
        square.move(cords.first, cords.second);
        square.setFillColor(sf::Color::Red);
        window->draw(square);

        window->display();
    }

} // game