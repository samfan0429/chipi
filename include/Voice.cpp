# include "Voice.h"

// Private
void Voice::initVariables(std::string name)
{
    if(!this->buffer1.loadFromFile("resource/audio/"+name+".wav") || !this->buffer2.loadFromFile("resource/piano/"+name+".wav")){
        std::cout << "Audio not found!" << std::endl;
    } 
    voice.setBuffer(buffer1);
    piano.setBuffer(buffer2);
}

// Construct & Destructor
Voice::Voice(std::string name)
{
    this->initVariables(name);
}

Voice::~Voice()
{
    // std::cout << "Sound gone" << std::endl;
    this->buffer1.~SoundBuffer();
    this->buffer2.~SoundBuffer();
    this->voice.~Sound();
    this->piano.~Sound();
}

// Public
void Voice::play()
{
    
    this->voice.play();
    this->piano.play();
}