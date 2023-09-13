#include "Snake.h"

#include "Game.h"

#include <iostream>
using namespace std;

namespace game {
    Snake::Snake(std::pair<int, int> cord) {
        snake.push_back(cord);
        direction = SnakeDirection::UP;
    }

    void Snake::input(std::atomic_bool &gameFinished) {
        while (!gameFinished) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                if (direction != RIGHT) direction = LEFT;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                if (direction != DOWN) direction = UP;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (direction != LEFT) direction = RIGHT;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (direction != UP) direction = DOWN;
            }
        }
    }

    bool Snake::move(int (&field)[40][40], Apple &apple) {
        std::pair<int, int> head = snake.front();
        switch (direction) {
            case UP:
                if (head.second - 1 < 0 || field[head.first][head.second-1] == SNAKE) return false;
                head.second--;
                break;
            case DOWN:
                if (head.second + 1 >= 40 || field[head.first][head.second+1] == SNAKE) return false;
                head.second++;
                break;
            case LEFT:
                if (head.first - 1 < 0 || field[head.first-1][head.second]  == SNAKE) return false;
                head.first--;
                break;
            case RIGHT:
                if (head.first + 1 >= 40 || field[head.first+1][head.second]  == SNAKE) return false;
                head.first++;
                break;
        }

        if (head == apple.coords) {
            apple = apple.createNewApple(field);
            snake.push_back(snake.back());
            speed+=0.05f;
        } else
            field[snake.back().first][snake.back().second] = EMPTY;

        for (int i = (int)snake.size() - 1; i >= 1; i--)
            snake[i] = snake[i - 1];
        snake.front() = head;

        field[head.first][head.second] = SNAKE;

        return true;
    }

    std::vector<std::pair<int, int>> Snake::getSnake() {
        return snake;
    }
}// game