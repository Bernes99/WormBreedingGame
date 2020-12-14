#include "Menu.h"



void Menu::initButtons()
{
	std::vector<Button*> tmp;
	for (int i = 0; i < setsNumber; i++)
	{
		
		for (int i = 0; i < 4; i++)
		{
			tmp.push_back(new Button());
		}
		sets.push_back(tmp);
		tmp.clear();
		initValues(i);
	}
	
	initSet();
	
}


void Menu::initSet()
{
	int j = 0;
	int k = 0;
	sf::String name;
	for (int i = 0; i < setsNumber; i++)
	{
		if (i % 2 ==0 && i!=0)
		{
			j = 0;
			k++;
		}
		sets[i][0]->valueFild();
		sets[i][0]->setColor(120, 120, 120, 255);
		sets[i][0]->setPosition( j* sets[i][0]->getButton().getSize().x*6 + 20, k * sets[i][0]->getButton().getSize().y*5 + 40);
		sets[i][0]->setTextFixPosition();



		sets[i][1]->upButton();
		sets[i][1]->setColor(60, 60, 60, 255);
		sets[i][1]->setPosition(
			sets[i][0]->getButton().getPosition().x + sets[i][0]->getButton().getSize().x + 2,
			sets[i][0]->getButton().getPosition().y - sets[i][0]->getButton().getSize().y / 2);
		sets[i][1]->setTextFixPosition();

		sets[i][2]->downButton();
		sets[i][2]->setColor(60, 60, 60, 255);
		sets[i][2]->setPosition(
			sets[i][0]->getButton().getPosition().x + sets[i][0]->getButton().getSize().x + 2,
			sets[i][0]->getButton().getPosition().y + sets[i][0]->getButton().getSize().y / 2);
		sets[i][2]->setTextFixPosition();

		switch (i)
		{
		case 0:
			name = L"Rozmiar mapy";
			
			break;
		case 1:
			name = L"m³ode z 1 lêgu";
			break;
		case 2:
			name = L"odpornoœæ na g³ód";
			break;
		case 3:
			name = L"regeneracji jedzenia";
			break;
		case 4:
			name = L"max rozmiar";
			break;
		case 5:
			name = L"max czas zycia";
			break;
		case 6:
			name = L"okres dojzewania(% max zycia)";
			break;
		default:
			name = L"zapomnia³em dodaæ";
			break;
		}
		sets[i][3]->nameFild(name);
		//sets[i][3]->setNamePosition(j * sets[i][0]->getButton().getSize().x * 3 + 20, k * sets[i][0]->getButton().getSize().y * 5 + 40+20);
		sets[i][3]->setNamePosition(sets[i][0]->getButton().getPosition().x-10, k * sets[i][0]->getButton().getSize().y * 5 );
		
		j++;
	}

}

void Menu::initValues(int i)
{
	if (i==0)
	{
		sets[i][0]->setValue(wroldSize);
	}
}

Menu::Menu(int wroldSize)
{
	this->wroldSize = wroldSize;
	initButtons();
	
	
}

void Menu::update() //const sf::Vector2f mousePos
{
	
	
}

void Menu::drawMenu(sf::RenderWindow* window)
{
	for (int i = 0; i <setsNumber; i++)
	{
		for (int j = 0;j < 4; j++)
		{
			//drawButton(window, sets[i]);
			window->draw(*sets[i][j]);
		}
	}
	
}

void Menu::isClicked(sf::Vector2i mousePos,int* worldSize)
{

	//std::cout << std::endl << sets[i][1]->getButton().getGlobalBounds().left << "  " << sets[i][1]->getButton().getGlobalBounds().top;
	if (sets[0][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[0][0]->increasValue(1);
		*worldSize = *worldSize + 1;
	}
	if (sets[0][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[0][0]->increasValue(-1);
	}
	if (sets[1][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[1][0]->increasValue(1);
	}
	if (sets[1][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[1][0]->increasValue(-1);
	}

	
}
