// # include <iostream>
/*
    @Author SoupAndWife (Real Name: Sun Gyu Park)
    Illustrator: Pokemon Drunk Oak
    
    All major copyrights belong to Nintendo. This is not used for marketing or for any business. All secondary products belonging in the resource folder belongs to Pokemon Drunk Oak.
    If one wants to use the resource files (images, audio files), please consult with Youtuber, Pokemon Drunk Oak, the original illustrator of the resources.
    
    모든 기본 저작권은 닌텐도에 있고 2차 창작용으로 만들어진 일러스트들은 Pokemon Drunk Oak님이 작성해주신고로 일러스트를 사용하시고 싶은 분은 직접적인 상담 부탁드립니다.
    이 파일은 상업적인 목적과 일절 상관이 없는 개인적인 취미 생활이니 이를 빼돌려서 악용할 경우 법정에서 면담을 나누게 돼는 힘든 삶이 양쪽에게 기다립니다.
    
    E-mail (Code Author): jappan4212@gmail.com
    E-mail (Pokemon Drunk Oak): drunkoak@gmail.com
*/
# include <Windows.h>
# include <memory>

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
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, 0);

    // Init Game
    std::unique_ptr<Chikpi> game = std::make_unique<Chikpi>();

    // sf::Texture texture;
    // if(!texture.loadFromFile("resource/img/1C1.png")){
    //     std::cout<< "No 1C1 loaded" << std::endl;
    // } else{
    //     std::cout<< "1C1 loaded" << std::endl;
    // }

    while (game->running())
    {
        game->update();

        game->render();
    }

    return 0;
}
