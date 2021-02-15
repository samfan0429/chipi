# include "Chikorita.h"
# include <iostream>

// Constructor && destructor
Chikorita::Chikorita(std::string name, int x, int y, int t)
{
    this->initVariables(name,x,y, t);
}

Chikorita::~Chikorita()
{
    // std::cout <<"Destructor Called " <<std::endl;
    delete this->voice;
    this->animation->~Texture();
}

// Private setups
void Chikorita::setAudio(std::string name)
{
    voice = new Voice(name);
}

void Chikorita::initVariables(std::string name,int x,int y, int t){
    
    this->setAudio(name);

    this->name = name;
    
    if(!this->animation[0].loadFromFile("resource/img/"+name+"1.png"))
    {
        std::cout << "ERROR: NO PHOTO1" << std::endl;
    }
    if(!this->animation[1].loadFromFile("resource/img/"+name+"2.png"))
    {
        std::cout << "ERROR: NO PHOTO2" << std::endl;
    }
    this->setTexture(animation[0]);
    this->setScale(0.7f,0.7f);
    this->setPosition(x,y);

    this->initX = x;
    this->initY = y;

    this->threshold = t;

    this->playing = false;
    // if(this->animation[0].loadFromFile("resource/img/"+name+"1.png"))
    // {
    //     std::cout << name << "LOADED1 BB" << std::endl;
    // }
    // if(this->animation[1].loadFromFile("resource/img/"+name+"2.png"))
    // {
    //     std::cout << name << "LOADED2 BB" << std::endl;
    // }
}

// Public update due to input key
void Chikorita::play(){
    if(!this->playing)
    {   
        this->setPosition(this->initX,this->threshold);
        this->playing = true;
        this->setTexture(animation[1]);
        voice->play();
        // std::cout << this->name << " is being played!" << std::endl;
    }
}

void Chikorita::lift(){
    this->playing = false;
    this->setTexture(animation[0]);
}

void Chikorita::update()
{
    if(!this->playing && this->getPosition().y < this->initY)
    {
        // this->setPosition(this->initX,this->getPosition().y-1);
        // std::cout << this->getPosition().y << std::endl;
        this->move(0.f,2.5f);
    }
}