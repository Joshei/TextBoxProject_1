#include <iostream>
#include <conio.h>

#include <string.h>

#include <SFML/Graphics.hpp>
#include "windows.h"

#include "Display.h"
#include "message.h"

using namespace std;


int g_the_width = 0;



//let's see this...
	DISPLAY::DISPLAY(int display_width, int display_height, int vert_offset, int amount_of_total_lines, int display_origin_x, int display_origin_y) 
	{
	

		
		width = 0;  // display_width;
		height = 0; //  display_height;
		each_vertical_offset_is = vert_offset;
		total_lines = amount_of_total_lines;
		display_x_setting = display_origin_x;
		display_y_setting = display_origin_y;
		//highest_statement_number = 0;
		//alltheconversations[0].highest_statement_num = 1;
		//alltheconversations[0].highest_statement_num = 1;

		
	}

	//change to both here...
	void DISPLAY::Get_Space_Is_Used(int conversation_num_index, int statement_num_index)
	{

		space_is_used = alltheconversations[conversation_num_index].message_array[statement_num_index].space_used;


	}

	
	string DISPLAY::Get_String_Message(int conversation_num_index, int statement_num_index)
	{
		message_string = alltheconversations[conversation_num_index].message_array[statement_num_index].statement;

		return(message_string);

	}


	// fix this
	int DISPLAY::Get_Highest_Statement_Number(int conversation_num_index)
	{
		highest_statement_number = alltheconversations[conversation_num_index].highest_statement_num;

		return(highest_statement_number);

	}

	int DISPLAY::Get_Highest_Conversation_Number(int conversation_num_index)
	{
		return(MAXCONVERSATIONNUM);

	}




	//five test_string changed to message_string in here
	void DISPLAY::DrawMessage(sf::RenderWindow & windowtype, sf::RenderWindow & windowtype2,  string test_string, int convers_num_index, int vert_line_length)

	{

		float text_width_pixels =  700;

		int space_is_used = 0;
		
		bool is_on_first_run = true;
		int first_run = 1;

		float num_chars_on_this_line = 0;
		
		
		int last_index_printed = 0;

		

		

		int last_word_started_at = 0;
		int amt_letters_of_last_word = 0;
		int amt_of_letters_to_display = 0;

		float prevwidth = -1;
		float width = 0;
		int i = 0;


		int total_characters_read = 0;
		
		
		//these about five all changed
		int length_string = message_string.length() - 1;
		
		int on_last_line = 0;
		int height = 0;
		int height2 = 0;


		
		int element_index = message_string.length() - 1;

		std::string temporary_string;
		
		
		int total_offset = 0;
		

		

		
		
		
		
		

		
		int j = 1;
		int run = 0;
		int each_vertical_offset_is = 0;

		textmessage.setString(message_string);
		
		
		each_vertical_offset_is = textmessage.getLocalBounds().height;
		


		int line_number = 0;

		
		
		while (1)
		{



			

			amt_letters_of_last_word = 0;

			amt_of_letters_to_display = 0;


			
		




				//total_offset = total_offset + num_chars_on_this_line + 1 ;
				total_offset = total_offset + num_chars_on_this_line;
			


			width = 0;

			num_chars_on_this_line = 1;
			

			//find number of characters by width
			while (text_width_pixels >= width)//text_width_pixels >= width)
			{
	


				/////////////////////////////


				//check if space is attributed and prints this as last line
				//and waits foir keypress.
			
				line_number++;

				


				
				if (j == (message_string.length() ))
				{
					on_last_line = 1;
					break;
				}
				
				j++;

			
				prevwidth = width;
				width = textmessage.findCharacterPos(num_chars_on_this_line).x - textmessage.findCharacterPos(0).x;
				

				
				//width = textmessage.getGlobalBounds().width;

				//text is complete for this line
				if ((prevwidth >= width )&& ( num_chars_on_this_line != 0))
		
				{
					
					break;
				}

			
				num_chars_on_this_line++;

			}

			
			textmessage.setPosition(300, height2);

			//  this causes a glitch, doesn't print second row
			windowtype2.draw(textmessage);

			windowtype2.display();

			//
			temporary_string.erase(0, temporary_string.length() - 0);
			
			
			
			

	
			
			
			//only line processed
			if (on_last_line   &&  is_on_first_run)
			{
				temporary_string.resize(num_chars_on_this_line);

			}
			
			//multiple lines processed
			else if (on_last_line)
			{

				temporary_string.resize(num_chars_on_this_line - 1);
			}

			

			

			
			//isn't last line
			else if (!on_last_line)
			{
				temporary_string.resize(num_chars_on_this_line + 1);
			}


			//for (i = 0; i < num_chars_on_this_line - 1; i++)
			for (i = 0; i < num_chars_on_this_line; i++)
			{

				temporary_string[i] = message_string[total_offset + i];
				

			}

				
				
				

			





				//could be wrapping
				if (on_last_line != 1)
				{

					int k = 0;
					//find number of characters ON right border
					for (k; k < num_chars_on_this_line; k++)
					{





						if (temporary_string[k] == ' ')
						{


							amt_letters_of_last_word = 0;

						}
						//is not a space
						else
						{
							amt_letters_of_last_word++;
						}





					}



					

					//look at next characer to see if ending word is wrapped or printed
					if (temporary_string[k] == ' ')
					{

						amt_of_letters_to_display = num_chars_on_this_line;

					}




					//there is a word wrapping around the right boundary
					else

					{
					
						if (amt_letters_of_last_word >= num_chars_on_this_line)
						{
							
							MessageBoxA(NULL, "error a word is to long", "title", MB_OK);
							exit(-1);

						}


						amt_of_letters_to_display = num_chars_on_this_line  - amt_letters_of_last_word ;

						


						j = j - amt_letters_of_last_word;
						total_offset = total_offset - amt_letters_of_last_word;

					}


					
					temporary_string.resize(amt_of_letters_to_display);
					




					//the position of j is set to any unwrapped text
					//total offset is where the index is reading the test_string from




				}//if for is not last line


			


			//add padd
			//general text
			textmessage.setPosition(display_x_setting, display_y_setting +  height);
			textmessage.setCharacterSize(14);
			textmessage.setFillColor(sf::Color::Red);
			textmessage.setString(temporary_string);


			
			
			
			
			//700 pixels equates too 357 for the_width!?!?!?!
			float the_width = textmessage.getLocalBounds().width;

			
			
			
			
			
			// 357 is the width of the rectangle
			sf::RectangleShape rectangle_box(sf::Vector2f(the_width , (float)(total_lines * each_vertical_offset_is)));
			
			rectangle_box.setFillColor(sf::Color(100, 250, 50));

			if (first_run == 1)
			{
				g_the_width = the_width;

				first_run = 2;
				windowtype.draw(rectangle_box);
			}


			windowtype.draw(textmessage);
			

			
			

			
			height = height + each_vertical_offset_is;
			height2 = height2 + 50;



			
			

			


			////////////////

			//either way either on last line with no wrapping or j is set

			//j is still set and so is offset
			
			
			
			//LOOK AT THIS!!!!!:
			
			
			space_is_used = 1;







			if ( (space_is_used && on_last_line  )  || (space_is_used && ((line_number) == (total_lines - 2) )))
			{


					string temp_string = message::Get_Out_Bound_String();

					int length_of_string = temp_string.length();

					
					
					sf::Font Fontforscore;

					if (!Fontforscore.loadFromFile("ARIALBD.ttf"))
					{
						exit(1);
					}

					

					message_holder.setFont(Fontforscore);
					message_holder.setCharacterSize(14);
					message_holder.setFillColor(sf::Color::Red);
					
					message_holder.setOrigin(0,0);
					
					message_holder.setString(temp_string);
					
					
					int y_for_space = display_y_setting + (total_lines - 2) * each_vertical_offset_is;

					int this_width = 0;
					
					float x = message_holder.getLocalBounds().width;


					
					//the_width : 357
					//message_holder.setPosition((66.5), y_for_space);
					message_holder.setPosition( ( (g_the_width - x )/2), y_for_space);

			
					windowtype2.close();

					
					
					
					windowtype.draw(message_holder);


					windowtype.display();

				


				Wait_For_Space_Press();

				ClearOutBox(windowtype);

				// - 1
				int next_statement_number = alltheconversations[convers_num_index].Get_Next_Conversation_Statement_Num_Index();
				

				message_string = Get_String_Message(convers_num_index, next_statement_number);
				

				textmessage.setString(message_string);

				//ClearOutBox( windowtype );


				

				height = 0;



			}

			else if (on_last_line)
				{

					break;
				}

			//////////////////










			if (is_on_first_run)
			{
				is_on_first_run = false;
			}



	//emd while
		}
	
}



int DISPLAY::Get_Active_Statement_Number_Index(int conversation_num_index)
{


	active_statement_number = alltheconversations[conversation_num_index].Get_Active_Statement_Index();// Get_Active_Display_Num();

	active_statement_number++;

	return(active_statement_number);


}

/*
   //int DISPLAY::Get_Active_Conversation_Number()
   //{
   //
   //eturn(alltheconversations[conversation_number].highest_statement_num;)
   //
   //}
*/




	sf::Text DISPLAY::GetText()
	{
		return(textmessage);
	}

	void DISPLAY::SetFont(sf::Font & theFont)
	{
		textmessage.setFont(theFont);



	}


	void DISPLAY::SetFont1(sf::Font & theFont)
	{
		message_holder.setFont(theFont);



	}


	
	int DISPLAY::ClearOutBox(sf::RenderWindow  & windowtype)
	{

		return(1);


		sf::RectangleShape rectangle_box(sf::Vector2f(display_x_setting, display_y_setting));
		rectangle_box.setFillColor(sf::Color(100, 250, 50));
		windowtype.draw(rectangle_box);

	}
	
	
	void DISPLAY::Wait_For_Space_Press()
	{
		int flag = 1;

		while (flag)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				flag = 0;
			}

		}

	}



