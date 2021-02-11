// # include <iostream>
# include <Windows.h>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include "Chikorita.h"
# include "Chikpi.h"
# include "Voice.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // HWND hwnd = GetConsoleWindow();
    // ShowWindow(hwnd, 0);

    // Init Game
    Chikpi game = Chikpi();

    // sf::Texture texture;
    // if(!texture.loadFromFile("resource/img/1C1.png")){
    //     std::cout<< "No 1C1 loaded" << std::endl;
    // } else{
    //     std::cout<< "1C1 loaded" << std::endl;
    // }

    while (game.running())
    {
        game.update();

        game.render();
    }

    return 0;
}