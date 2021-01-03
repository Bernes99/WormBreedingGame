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

void Menu::initWorldSizeButtons()
{
	std::vector<Button*> tmp;
	for (int i = 0; i < 2; i++)
	{

		for (int i = 0; i < 4; i++)
		{
			tmp.push_back(new Button());
		}
		sets.push_back(tmp);
		tmp.clear();
		if (i==0)
		{
			sets[i][0]->setValue(10);
		}
		else
		{
			sets[i][0]->setValue(10);
		}
	}
	int j = 0;
	int k = 0;
	sf::String name;
	for (int i = 0; i < 2; i++)
	{
		if (i % 2 == 0 && i != 0)
		{
			j = 0;
			k++;
		}
		sets[i][0]->valueFild();
		sets[i][0]->setColor(120, 120, 120, 255);
		sets[i][0]->setPosition(j * sets[i][0]->getButton().getSize().x * 3 + 30, k * sets[i][0]->getButton().getSize().y * 5 + 40);
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
			break;
		case 0:
			name = L"rozmiar œwiata X";
			break;
		case 1:
			name = L"rozmiar œwiata Y";
			break;
		default:
			name = L"zapomnia³em dodaæ";
			break;
		}
		sets[i][3]->nameFild(name);
		//sets[i][3]->setNamePosition(j * sets[i][0]->getButton().getSize().x * 3 + 20, k * sets[i][0]->getButton().getSize().y * 5 + 40+20);
		sets[i][3]->setNamePosition(sets[i][0]->getButton().getPosition().x - 10, k * sets[i][0]->getButton().getSize().y * 5);

		j++;
	}

	send = new Button();

	send->valueFild();
	send->nameFild(L"Start");
	send->setColor(148, 50, 183, 255);
	send->setSize(180.f, 60.f);
	send->setPosition(150 - send->getButton().getSize().x/2,150 - send->getButton().getSize().y/2);
	send->setTextFixPosition();
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
		sets[i][0]->setPosition( j* sets[i][0]->getButton().getSize().x*5 + 30, k * sets[i][0]->getButton().getSize().y*5 + 40);
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
			break;
		case 0:
			name = L"m³ode z 1 lêgu";
			break;
		case 1:
			name = L"pr. odnawiania sie jedzenia";
			break;
		case 2:
			name = L"pr. g³odu robaka";
			break;
		case 3:
			name = L"max rozmiar";
			break;
		case 4:
			name = L"okres dojrzewania(% max ¿ycia)";
			break;
		case 5:
			name = L"max czas bez jedzenia";
			break;
		case 6:
			name = L"czas wyklucia jajka";
			break;
		case 7:
			name = L"czas miêdzy kolejnym jajem";
			break;
		case 8:
			name = L"max d³. ¿ycia";
			break;
		case 9:
			name = L"pr. zjadania jedzenia";
			break;
		case 10:
			name = L"max jedzenia na 1 polu";
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
		sets[i][0]->setValue(data->countNewWorms);
	}
	if (i == 1)
	{
		sets[i][0]->setValue(data->restoreFoodTime);
	}
	if (i == 2)
	{
		sets[i][0]->setValue(data->hungerSpan);
	}
	if (i == 3)
	{
		sets[i][0]->setValue(data->maxScale);
	}
	if (i == 4)
	{
		sets[i][0]->setValue(data->notMature);
	}
	if (i == 5)
	{
		sets[i][0]->setValue(data->maxHungerTime);

	}
	if (i == 6)
	{
		sets[i][0]->setValue(data->eggIncubate);

	}
	if (i == 7)
	{
		sets[i][0]->setValue(data->leyEggSpan);

	}
	if (i == 8)
	{
		sets[i][0]->setValue(data->maxLifeTime);

	}
	if (i == 9)
	{
		sets[i][0]->setValue(data->eatSpeed);

	}
	if (i == 10)
	{
		sets[i][0]->setValue(data->maxFood);

	}


}

Menu::Menu(variable* pData)
{
	
	this->data = pData;
	initButtons();
}

Menu::Menu(variable* pData, bool worldSize)
{
	if (worldSize)
	{
		initWorldSizeButtons();
	}

}

void Menu::update() //const sf::Vector2f mousePos
{
	for (int i = 0; i <setsNumber; i++)
	{
		if (i == 0)
		{
			data->countNewWorms = sets[i][0]->getValue();
		}
		if (i == 1)
		{
			data->restoreFoodTime = sets[i][0]->getValue();
		}
		if (i == 2)
		{
			data->hungerSpan = sets[i][0]->getValue();
		}
		if (i == 3)
		{
			data->maxScale = sets[i][0]->getValue();
		}
		if (i == 4)
		{
			data->notMature = sets[i][0]->getValue();
		}
		if (i == 5)
		{
			data->maxHungerTime = sets[i][0]->getValue();

		}
		if (i == 6)
		{
			data->eggIncubate = sets[i][0]->getValue();

		}
		if (i == 7)
		{
			data->leyEggSpan = sets[i][0]->getValue();

		}
		if (i == 8)
		{
			data->maxLifeTime = sets[i][0]->getValue();

		}
		if (i == 9)
		{
			data->eatSpeed = sets[i][0]->getValue();

		}
		if (i == 10)
		{
			data->maxFood = sets[i][0]->getValue();

		}
	}
	
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

void Menu::isClicked(sf::Vector2i mousePos)
{
	/*countNewWorms*/
	if (sets[0][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[0][0]->increasValue(1,0,100);
		
	}
	if (sets[0][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[0][0]->increasValue(-1,0,100);
	}

	/*restoreFoodTime*/
	if (sets[1][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[1][0]->increasValue(1, 1, 120);
	}
	if (sets[1][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[1][0]->increasValue(-1, 1, 120);
	}

	/*hungerSpan*/
	if (sets[2][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[2][0]->increasValue(0.1f, 0.1f, 20.f);
	}
	if (sets[2][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[2][0]->increasValue(-0.1f, 0.1f, 20.f);
	}

	/*maxScale*/
	if (sets[3][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[3][0]->increasValue(0.1f, 1.0f, 2.4f);
	}
	if (sets[3][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[3][0]->increasValue(-0.1f, 1.0f, 2.4f);
	}

	/*notMature*/
	if (sets[4][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[4][0]->increasValue(0.1f, 0.1f, 0.5f);
	}
	if (sets[4][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[4][0]->increasValue(-0.1f, 0.1f, 0.5f);
	}

	/*maxHungerTime*/
	if (sets[5][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[5][0]->increasValue(1, 1, 10);
	}
	if (sets[5][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[5][0]->increasValue(-1, 1, 10);
	}

	/*eggIncubate*/
	if (sets[6][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[6][0]->increasValue(1, 1, 10);
	}
	if (sets[6][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[6][0]->increasValue(-1, 1, 10);
	}

	/*leyEggSpan*/
	if (sets[7][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[7][0]->increasValue(1, 1, 20);
	}
	if (sets[7][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[7][0]->increasValue(-1, 1, 20);
	}

	/*maxLifeTime*/
	if (sets[8][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[8][0]->increasValue(1, 1, 240);
	}
	if (sets[8][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[8][0]->increasValue(-1, 1, 240);
	}

	/*eatSpeed*/
	if (sets[9][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[9][0]->increasValue(0.1f, 0.1f, 20.f);
	}
	if (sets[9][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[9][0]->increasValue(-0.1f, 0.1f, 20.f);
	}

	/*maxFood*/
	if (sets[10][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[10][0]->increasValue(1, 1, 300);
	}
	if (sets[10][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[10][0]->increasValue(-1, 1, 300);
	}

	
}

bool Menu::isClickedWorldSize(sf::Vector2i mousePos, sf::Vector2i *worldSize)
{
	/*worldSizeX*/
	if (sets[0][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[0][0]->increasValue(1, 1, 15);

	}
	if (sets[0][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[0][0]->increasValue(-1, 1, 15);
	}

	/*worldSizeY*/
	if (sets[1][1]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[1][0]->increasValue(1, 1, 33);
	}
	if (sets[1][2]->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		sets[1][0]->increasValue(-1, 1, 33);
	}
	/*send*/
	if (send->getButton().getGlobalBounds().contains(sf::Vector2f(mousePos)))
	{
		std::cout << sets[1][0]->getValue() << sets[0][0]->getValue();	
		*worldSize = sf::Vector2i(sets[0][0]->getValue(), sets[1][0]->getValue());
		return true;
	}
	return false;
}

void Menu::drawWorldSizeMenu(sf::RenderWindow* window)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//drawButton(window, sets[i]);
			window->draw(*sets[i][j]);
		}
	}
	window->draw(*send);
}

