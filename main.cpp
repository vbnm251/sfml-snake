#include <SFML/Graphics.hpp>
#include "game/Game.h"
#include "X11/Xlib.h"

int main()
{
    XInitThreads();

    sf::RenderWindow window(sf::VideoMode(game::WIDTH, game::HEIGHT), "Snake game");
    game::Game game(&window);

    window.clear(sf::Color::White);
    game.setupGame();
    window.display();

    game.gameLoop();

    return 0;
}