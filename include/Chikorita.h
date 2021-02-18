#ifndef CHIKORITA_H
#define CHIKORITA_H

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include "Voice.h"
# include <string>
# include <memory>
# include <iostream>

class Chikorita
{
    private:
        sf::Sprite ani;
        std::string name;
        sf::Texture closed;
        sf::Texture open;
        int initX,initY,threshold;

        std::shared_ptr<Voice> voice;
        bool playing;

        void initVariables(std::string name,int x,int y, int t);
        void setAudio(std::string name);

    public:
        Chikorita(std::string name,int x,int y, int t);
        
        //Copy Constructors
        Chikorita(const Chikorita& a);
        Chikorita &operator= (const Chikorita& a);
        
        virtual ~Chikorita();
        void play();
        void lift();
        void update();

        sf::Sprite getSprite();
};

#endif