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
    delete this;
}

// Public
void Voice::play()
{
    
    this->voice.play();
    this->piano.play();
}