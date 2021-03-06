#pragma once

#include <SFML/Graphics.hpp>
#include "Message.h"

static int MAXCONVERSATIONNUM = 0;



class DISPLAY {

public:

	std::vector <message> alltheconversations;

	void ClearOutBox(sf::RenderWindow & windowtyp, float width);


	void Get_Space_Is_Used(int conversation_num, int statement_num);
	void Wait_For_Space_Press();
	
	std::string Get_String_Message(int conversation_num , int statement_num);


	DISPLAY(  int, int, int displau_width, int display_height, int v_offset, int num_lines);
	void DrawMessage(sf::RenderWindow & windowtype, int convnum) ;
	void SetFont(sf::Font & theFont);
	void SetFont1(sf::Font & theFont);
	void Configure_Display(int num_of_display_lines, int width_of_display_rect, int the_font_size, int padding, int e);


	sf::Text GetText();

	int Get_Highest_Statement_Number(int conversation_number);
	int Get_Highest_Conversation_Number(int conversation_number);

	int Get_Active_Statement_Number_Index(int conv_num_index);
	//int Get_Active_Conversation_Number();




	

	//int Get_Active_Statement_Number(int conv_number);
	
	//holds space or yes / no statement
	//sf::Text message_holder;
	sf::Text textmessage;
	sf::Text textmessage1;
	sf::Font font;

	int font_size;
	int width_of_display_rectangle;
	int total_lines;
	int horizontal_pixel_adjustment;


	int space_is_used;
	int scoreamount;
	int width;
	int height;
	int each_vertical_offset_is;
	int highest_statement_number;

	float display_x_setting;
	float display_y_setting;


	string message_string;
	

	
	int active_statement_number;



};