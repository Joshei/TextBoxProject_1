#pragma once

#include <SFML/Graphics.hpp>

class DISPLAY {

public:
	DISPLAY(int displau_width, int display_height);
	void DISPLAY::DrawMessage(sf::RenderWindow & windowtype, sf::RenderWindow & windowtype2,  std::string string);
	void DISPLAY::SetFont(sf::Font & theFont);
	sf::Text DISPLAY::GetText();



	
	//std::string teststring();
	//std::string processed_string();
	sf::Text textmessage;
	sf::Font font;
	
	int scoreamount;
	
	int width;
	int height;


};