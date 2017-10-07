//#include "windows.h"
#include <SFML\Graphics.hpp>
#include "Display.h"
//#include <string>
#include <iostream>
#include <memory>
#include "windows.h"

int main(void) {

	int one_time_loop = 0;

	FreeConsole();

	using namespace std;

	//for checking keypress and closing window
	sf::Event event;
	//window object
	sf::RenderWindow window(sf::VideoMode(1000, 700), "!!!!");
	sf::RenderWindow window2(sf::VideoMode(1000, 700), "!!!!");


	std::unique_ptr<DISPLAY> ptextdisplay(new DISPLAY(50, 50));  // * textdisplay();


	sf::Font Fontforscore;

	if (!Fontforscore.loadFromFile("ARIALBD.ttf"))
	{
		exit(1);
	}

	ptextdisplay->SetFont(Fontforscore);


	while (window.isOpen())
	{


		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();  
			}

			if (event.type == sf::Event::KeyPressed)
			{


				//shoots at asteroid
				if (event.key.code == sf::Keyboard::Space)
				{
					exit(-1);
				}


			}

		}


		
					   	
		string test = "abcdefghij mnopqrs 12345678 45678";
					   							   //

		while (one_time_loop == 0)
		{
			one_time_loop = 1;

			ptextdisplay->DrawMessage(window, window2, test);
			window.draw(ptextdisplay->GetText());


			window.display();

		}

		}


	}
