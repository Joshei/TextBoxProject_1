#include <iostream>
#include <conio.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "windows.h"

#include "Display.h"


using namespace std;

//let's see this...
	DISPLAY::DISPLAY(int display_width, int display_height) 
	{
	
		width = display_width;
		height = display_height;
		
	}


	void DISPLAY::DrawMessage(sf::RenderWindow & windowtype, sf::RenderWindow & windowtype2,  string test_string)

	{

		
		bool is_on_first_run = true;
		int first_run = 1;

		float num_chars_on_this_line = 0;
		
		float text_width_pixels = 200;
		int last_index_printed = 0;

		

		

		int last_word_started_at = 0;
		int amt_letters_of_last_word = 0;
		int amt_of_letters_to_display = 0;

		float prevwidth = -1;
		float width = 0;
		int i = 0;


		int total_characters_read = 0;
		
		int length_string = test_string.length() - 1;
		
		int on_last_line = 0;
		int height = 0;
		int height2 = 0;


		
		int element_index = test_string.length() - 1;

		std::string temporary_string;
		
		
		int total_offset = 0;
		

		

		
		
		
		
		

		
		int j = 1;
		int run = 0;

		textmessage.setString(test_string);


		//num_chars_on_this_line = 0;


		
		
		while (1)
		{



			

			amt_letters_of_last_word = 0;

			amt_of_letters_to_display = 0;


			
		




				//total_offset = total_offset + num_chars_on_this_line + 1 ;
				total_offset = total_offset + num_chars_on_this_line;
			


			width = 0;

			num_chars_on_this_line = 1;
			

			//find number of characters by width
			while (text_width_pixels >= width)
			{

				


				


				

				
				
				if (j == (test_string.length() ))
				{
					on_last_line = 1;
					break;
				}
				
				j++;


				
				prevwidth = width;
				width = textmessage.findCharacterPos(num_chars_on_this_line).x - textmessage.findCharacterPos(0).x;




				
				//width = textmessage.getLocalBounds().width;

				if (prevwidth == width && num_chars_on_this_line != 0)
		
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
			
			//multipple lines processed
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

				temporary_string[i] = test_string[total_offset + i];
				

			}

				
				
				

			






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
					







				}//if for is not last line

			

			//add padd
			textmessage.setPosition(0, height);

			textmessage.setCharacterSize(14);
			textmessage.setFillColor(sf::Color::Red);


			//undderstands length?
			textmessage.setString(temporary_string);





			// x than y
			sf::RectangleShape rectangle_box(sf::Vector2f(text_width_pixels, 400));
			rectangle_box.setOrigin(0, 0);
			rectangle_box.setFillColor(sf::Color(100, 250, 50));

			if (first_run == 1)
			{
				first_run = 2;
				//windowtype.draw(rectangle_box);
			}


			windowtype.draw(textmessage);
			

			
			//passed in value here : 20.
			height = height + 40;
			height2 = height2 + 50;

			

			if (on_last_line)
			{
				break;
			}

			if (is_on_first_run)
			{
				is_on_first_run = false;
			}



	//emd while
		}
	
}


	sf::Text DISPLAY::GetText()
	{
		return(textmessage);
	}

	void DISPLAY::SetFont(sf::Font & theFont)
	{
		textmessage.setFont(theFont);



	}