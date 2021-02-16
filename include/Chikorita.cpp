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
    ani.~Sprite();
    open.~Texture();
    closed.~Texture();
}

// Copy Constructor
// Chikorita::Chikorita(Chikorita& a)
// {
//     int x=1;
// }

// Private setups
void Chikorita::setAudio(std::string name)
{
    voice = std::make_shared<Voice>(name);
}

void Chikorita::initVariables(std::string name,int x,int y, int t){
    
    this->setAudio(name);

    this->name = name;
    
    if(!closed.loadFromFile("resource/img/"+name+"1.png"))
    {
        std::cout << "ERROR: NO PHOTO1" << std::endl;
    }
    if(!open.loadFromFile("resource/img/"+name+"2.png"))
    {
        std::cout << "ERROR: NO PHOTO2" << std::endl;
    }
    ani.setTexture(closed);
    ani.setScale(0.7f,0.7f);
    ani.setPosition(x,y);

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
        ani.setPosition(this->initX,this->threshold);
        this->playing = true;
        ani.setTexture(open);
        voice->play();
        // std::cout << this->name << " is being played!" << std::endl;
    }
}

void Chikorita::lift(){
    this->playing = false;
    ani.setTexture(closed);
    // std::cout << this->name << " is being lifted!" << std::endl;
}

void Chikorita::update()
{
    if(!this->playing && this->ani.getPosition().y < this->initY)
    {
        ani.move(0.f,2.5f);
    }
}

sf::Sprite Chikorita::getSprite(){
    return this->ani;
}