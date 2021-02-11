#ifndef VOICE_H
#define VOICE_H

# include <SFML/Audio.hpp>
# include <string>
# include <iostream>

/*
    This is the audio for each Chikorita.
*/
class Voice
{
private:
    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;
    sf::Sound voice;
    sf::Sound piano;

    void initVariables(std::string name);

public:
    Voice(std::string name);
    virtual ~Voice();
    void play();
};

#endif