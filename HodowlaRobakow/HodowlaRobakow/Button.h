#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Button : public sf::Drawable
{

private:
	sf::RectangleShape button; /// kaszat³t przycisku
	sf::Text text; /// tekst przycisku 
	sf::Font font; /// font przycisk
	float value=0; /// wartosc zmiennej

	
public:
	
	/// <summary>
	/// konstruktor ³aduj¹cy fonta
	/// </summary>
	Button();
	//~Button();

	/// <summary>
	/// ustawia przycisk jako przycisk dodawania
	/// </summary>
	void upButton();

	/// <summary>
	/// ustawia przycisk jako przycisk odejmowania
	/// </summary>
	void downButton();

	/// <summary>
	/// ustawia pozycje przycisku w oknie
	/// </summary>
	/// <param name="x">szerokoœæ od lewej</param>
	/// <param name="y">wysokosc od góry</param>
	void setPosition(int x, int y);

	/// <summary>
	/// ustawia kolor t³a przycisku wed³ug schemat RGBA
	/// </summary>
	/// <param name="r">RED</param>
	/// <param name="g">GREAN</param>
	/// <param name="b">BLUE</param>
	/// <param name="a">ALPHA</param>
	void setColor(int r, int g, int b, int a);


	/// <summary>
	/// zwraca zmienna kszta³tu przycisku
	/// </summary>
	/// <returns>kszta³t prostok¹ta </returns>
	sf::RectangleShape getButton();

	/// <summary>
	/// zwraca tekst przycisku
	/// </summary>
	/// <returns>tekst przycisku</returns>
	sf::Text getButtonText();

	/// <summary>
	/// ustawiwia pozycje tekstu wzgledem przycisku
	/// </summary>
	void setTextFixPosition();

	/// <summary>
	/// ustawia przycisk jako pole z wartosci¹ 
	/// </summary>
	void valueFild();

	/// <summary>
	/// metoda wirtualna pozwalajaca rysowaæ przycisk bezpoœrednio jako obiekt klasy
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(button, states);
		target.draw(text, states);
	}

	/// <summary>
	/// ustawia podany tekst oraz domyslny kolor oraz wielkoœæ czcionki
	/// </summary>
	/// <param name="text"> - tekst jaki ma siê wyœwietlaæ </param>
	void nameFild(sf::String text);

	/// <summary>
	/// ustawia pozycje pola nazwy na ekranie
	/// </summary>
	/// <param name="x"> - pozycja x </param>
	/// <param name="y"> - pozycja y </param>
	void setNamePosition(int x, int y);

	/// <summary>
	/// zmienia wartoœæ zmiennej o podan¹ wartoœæ o ile nie przekracza podanych granic wartoœci
	/// </summary>
	/// <param name="i"> - o ile zmieniæ wartoœæ</param>
	/// <param name="downLimit"> - dolny milit wartoœci zmiennej </param>
	/// <param name="upLimit"> - górna granica wartoœci zmiennej </param>
	void increasValue(float i, float downLimit, float upLimit);

	/// <summary>
	/// ustawia wartoœæ zniennej na podan¹
	/// </summary>
	/// <param name="i"> - wartoœæ na jak¹ ma byc zmieniona vartoœæ zmiennej</param>
	void setValue(float i);

	/// <summary>
	/// zwraca wartoœæ zmiennej na przycisku
	/// </summary>
	/// <returns> - wartoœæ zmiennej na przycisku</returns>
	float getValue();


	/// <summary>
	/// ustawia precyzje wyœwiatlania wartoœci i zwraca go jako string
	/// </summary>
	/// <param name="num"> - liczba jaka trzeba zaokr¹gliæ </param>
	/// <param name="precision"> do ilu liczb po przecinku chcesz zaokr¹gliæ </param>
	/// <returns> - zaokr¹glony napis</returns>
	std::string precision(float num, int precision);


	/// <summary>
	/// ustawia rozmiar przycisku na podany rozmiar
	/// </summary>
	/// <param name="x"> - szerokoœæ </param>
	/// <param name="y"> - wysokoœæ </param>
	void setSize(float x, float y);
};



