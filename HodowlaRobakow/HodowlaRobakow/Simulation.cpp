#include "Simulation.h"

// fukncje inicjaliozujace
void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Symulacja Robak�w");
	this->optionWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Symulacja Robak�w Opcje");
    menu = new Menu();

}

Simulation::Simulation()
{
    this->initWindow();
}

Simulation::~Simulation()
{
    delete this->window;
    delete this->optionWindow;

}

void Simulation::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent)|| this->optionWindow->pollEvent(this->sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
        {
            this->optionWindow->close();
            this->window->close();
        }   
    }
}

void Simulation::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

void Simulation::update()
{
    this->updateSFMLEvents();
    this->menu->update();
}

void Simulation::render()
{
    this->window->clear();
    this->optionWindow->clear();

    //window.draw(shape);
    this->menu->drawMenu(this->optionWindow);
    this->window->display();
    this->optionWindow->display();
}

void Simulation::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << std::endl;
}