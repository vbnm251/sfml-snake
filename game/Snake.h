#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Apple.h"

#include "SFML/Graphics.hpp"
#include <vector>
#include <deque>
#include <atomic>

namespace game {

    enum SnakeDirection {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class Snake {
    public:
        explicit Snake(std::pair<int, int> cord);

        void input(std::atomic_bool& gameFinished);
        bool move(int (&field)[40][40], Apple & apple);
        std::vector<std::pair<int, int>> getSnake();

        float speed  = 1.0f;
    private:
        int direction;
        std::vector<std::pair<int, int>> snake;
    };

} // game


#endif //SNAKE_SNAKE_H
