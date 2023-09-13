#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H

#include <utility>

namespace game {

    class Apple {
    public:
        explicit Apple(int (&field) [40][40]);
        Apple createNewApple(int (&field) [40][40]) const;
        std::pair<int, int> coords;
    };

} // game

#endif //SNAKE_APPLE_H
