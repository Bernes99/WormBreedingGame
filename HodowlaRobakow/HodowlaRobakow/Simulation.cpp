#include "Simulation.h"

// fukncje inicjaliozujace
void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(SIM_WINDOW_X,SIM_WINDOW_Y ), "Symulacja Robaków");
	this->optionWindow = new sf::RenderWindow(sf::VideoMode(MENU_WINDOW_X, MENU_WINDOW_Y), "Symulacja Robaków Opcje");
    
    sf::Image icon;
    if (!icon.loadFromFile("../Resources/Textures/worm.png"))
    {
        std::cout<<"nie zaladowano ikony";
    }
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    this->optionWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    worldSize = new int{ 15 };

    data = new variable;
    
    world = new World(*worldSize, *worldSize, data);
    menu = new Menu(*worldSize,data);

    view.reset(sf::FloatRect(-50.f, -50.f, SIM_WINDOW_X, SIM_WINDOW_Y));// ustawienie vidoku na normalny przesuniêty 
    window->setView(view);
   
}

Simulation::Simulation()
{
    this->initWindow();
}

Simulation::~Simulation()
{
    delete this->window;
    delete this->optionWindow;
    delete data;
    delete(menu);

}

void Simulation::updateSFMLEvents()
{

    mouseViewPos = (sf::Vector2i)(sf::Mouse::getPosition(*optionWindow));
    mouseSimViewPos = (sf::Vector2i)(sf::Mouse::getPosition(*window));
    while ( this->optionWindow->pollEvent(this->sfEvent)
        || this->window->pollEvent(this->sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
        {
            this->optionWindow->close();
            this->window->close();
        }
        
        if (sfEvent.type == sf::Event::MouseButtonPressed &&(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            menu->isClicked(mouseViewPos);
            world->isClicked(mouseSimViewPos);
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
