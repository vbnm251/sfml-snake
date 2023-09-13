#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <random>

namespace game {
    const int WIDTH = 720, HEIGHT = 720;
    const int GAME_FIELD_SIZE = 40;

    enum Field {
        EMPTY,
        SNAKE,
        APPLE,
    };

    inline std::pair<float, float> calculateField(int i, int j) {
        return { WIDTH / GAME_FIELD_SIZE * i, HEIGHT / GAME_FIELD_SIZE * j };
    }

    inline int getRandomDigit(int l, int r) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(l,r);

        return (int)dist6(rng);
    }

    class Game {
    public:
        explicit Game(sf::RenderWindow *w);
        void setupGame();
        void gameLoop();

    private:
        sf::RenderWindow *window;
        int field[GAME_FIELD_SIZE][GAME_FIELD_SIZE]{};
        Snake snake = Snake(std::make_pair(-1, -1));

        void printField(std::pair<int, int> apple);
    };

} // game

#endif //SNAKE_GAME_H
