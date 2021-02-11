#ifndef CHIKORITA_H
#define CHIKORITA_H

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include "Voice.h"
# include <string>
# include <iostream>

class Chikorita: public sf::Sprite
{
    private:
        std::string name;
        sf::Texture animation[2];
        int initX,initY,threshold;

        Voice* voice;
        bool playing;

        void initVariables(std::string name,int x,int y, int t);
        void setAudio(std::string name);

    public:
        Chikorita(std::string name,int x,int y, int t);
        virtual ~Chikorita();
        void play();
        void lift();
        void update();
};

#endif