#include "Simulation.h"

// fukncje inicjaliozujace
void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(SIM_WINDOW_X,SIM_WINDOW_Y ), "Symulacja Robaków");
	this->optionWindow = new sf::RenderWindow(sf::VideoMode(MENU_WINDOW_X, MENU_WINDOW_Y), "Symulacja Robaków Opcje");
    menu = new Menu();
    world = new World(4,4);
}

Simulation::Simulation()
{
    this->initWindow();
}

Simulation::~Simulation()
{
    delete this->window;
    delete this->optionWindow;
    delete(menu);

}

void Simulation::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent)
        || this->optionWindow->pollEvent(this->sfEvent))
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
    this->world->update();
}

void Simulation::render()
{
    this->window->clear();
    this->optionWindow->clear();

    //window.draw(shape);
    this->menu->drawMenu(this->optionWindow);
    this->world->drawWorld(this->window,dt);
    this->window->display();
    this->optionWindow->display();
}

void Simulation::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();

    //system("cls");
    //std::cout << this->dt << std::endl;
}
