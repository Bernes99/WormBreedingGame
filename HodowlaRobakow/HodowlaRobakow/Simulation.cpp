#include "Simulation.h"

// fukncje inicjaliozujace
void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Symulacja Robaków");
	
}

Simulation::Simulation()
{
    this->initWindow();
}

Simulation::~Simulation()
{
    delete this->window;
}

void Simulation::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Simulation::run()
{
    while (this->window->isOpen())
    {
        this->updateSFMLEvents();
    }
}

void Simulation::update()
{
    this->updateSFMLEvents();
}

void Simulation::render()
{
    this->window->clear();

    //window.draw(shape);
    
    this->window->display();
}
