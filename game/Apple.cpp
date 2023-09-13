#include "Apple.h"
#include "Game.h"

namespace game {
    Apple::Apple(int (&field)[GAME_FIELD_SIZE][GAME_FIELD_SIZE]) {
        int i = getRandomDigit(0, GAME_FIELD_SIZE - 1), j = getRandomDigit(0, GAME_FIELD_SIZE - 1);
        while (field[i][j] == SNAKE) i = getRandomDigit(0, GAME_FIELD_SIZE - 1), j = getRandomDigit(0, GAME_FIELD_SIZE - 1);
        field[i][j] = APPLE;
        coords = std::make_pair(i, j);
    }

    Apple Apple::createNewApple(int (&field)[40][40]) const {
        field[coords.first][coords.second] = SNAKE;
        return Apple(field);
    }

} // game