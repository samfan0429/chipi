# include "Chikpi.h"
# include <iostream>

// Private functions
void Chikpi::initvariables()
{
    this->window = nullptr;
}

void Chikpi::initWindow()
{
    this->videomode.height = 720;
    this->videomode.width = 1300;
    this->window = new sf::RenderWindow(this->videomode, "ChikPi",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    // this->window->setVerticalSyncEnabled(true);
}

void Chikpi::initChiko()
{
    piano.reserve(10);
    piano.push_back(std::move(std::make_shared<Chikorita>("10E",700.f,450.f,60))); //60 is threshold
    piano.push_back(std::move(std::make_shared<Chikorita>("9D",200.f,450.f,60)));
    piano.push_back(std::move(std::make_shared<Chikorita>("8C",930.f,620.f,395))); //395 is threshold
    piano.push_back(std::move(std::make_shared<Chikorita>("7B",700.f,620.f,395))); 
    piano.push_back(std::move(std::make_shared<Chikorita>("6A",160.f,620.f,395))); 
    piano.push_back(std::move(std::make_shared<Chikorita>("5G",960.f,630.f,455))); //455 is threshold
    piano.push_back(std::move(std::make_shared<Chikorita>("4F",780.f,630.f,455))); 
    piano.push_back(std::move(std::make_shared<Chikorita>("3E",550.f,630.f,455)));
    piano.push_back(std::move(std::make_shared<Chikorita>("2D",330.f,630.f,455)));
    piano.push_back(std::move(std::make_shared<Chikorita>("1C",0.f,630.f,455)));
}

// Constructor & Destructor
Chikpi::Chikpi()
{
    this->initvariables();
    this->initWindow();
    this->initChiko();
}

Chikpi::~Chikpi()
{
    // std::cout << "Window deleted" << std::endl;
    delete this->window;
}

// Public

const bool Chikpi::running() const
{
    return this->window->isOpen();
}

void Chikpi::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }
                else if(this->ev.key.code==sf::Keyboard::Num1){
                    piano[9]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num2){
                    piano[8]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num3){
                    piano[7]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num4){
                    piano[6]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num5){
                    piano[5]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num6){
                    piano[4]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num7){
                    piano[3]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num8){
                    piano[2]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num9){
                    piano[1]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num0){
                    piano[0]->play();
                }
                break;
            case sf::Event::KeyReleased:
                if(this->ev.key.code==sf::Keyboard::Num1){
                    piano[9]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num2){
                    piano[8]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num3){
                    piano[7]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num4){
                    piano[6]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num5){
                    piano[5]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num6){
                    piano[4]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num7){
                    piano[3]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num8){
                    piano[2]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num9){
                    piano[1]->lift();
                }
                else if(this->ev.key.code==sf::Keyboard::Num0){
                    piano[0]->lift();
                }
        }
    }
}

void Chikpi::update()
{
    this->pollEvents();

    for(auto a:this->piano){
        a->update();
    }
}

void Chikpi::render()
{
    /*
        @return void
        - clear old frame
        - render objects
        - display the new frame
    */
    this->window->clear(sf::Color(255,255,255,255));

    for(auto a:this->piano){
        this->window->draw(*a);
    }

    this->window->display();
}