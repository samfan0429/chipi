#ifndef CHIKPI_H
#define CHIKPI_H

# include <vector>
# include <memory>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>

# include "Chikorita.h"


// Main Application
class Chikpi
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;

    // Objects
    std::vector<std::shared_ptr<Chikorita>> piano;

    void initvariables();
    void initWindow();
    void initChiko();

public:
    Chikpi();
    virtual ~Chikpi();

    const bool running() const;

    void pollEvents();
    void update();
    void render();
};
 
#endif