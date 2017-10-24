#include <iostream>
#include <conio.h>

#include <string.h>

#include <SFML/Graphics.hpp>
#include "windows.h"

#include "Display.h"
#include "message.h"

using namespace std;
extern int gflag;


int gvar = 0;

//saved off for branch use


//let's see this...
	DISPLAY::DISPLAY(int display_width, int display_height, int vert_offset, int amount_of_total_lines, int display_origin_x, int display_origin_y) 
	{

		font_size = 18;
		horizontal_pixel_adjustment = 18;
		total_lines = 10;

		//width_of_display_rectangle = 290;

	
		
		
		width = 0;  // display_width;
		height = 0; //  display_height;
		each_vertical_offset_is = vert_offset;
		
		
		
		
		
		display_x_setting = display_origin_x;
		display_y_setting = display_origin_y;
		//highest_statement_number = 0;
		//alltheconversations[0].highest_statement_num = 1;
		//alltheconversations[0].highest_statement_num = 1;

		
	}


	void DISPLAY::Configure_Display(int num_of_display_lines, int width_of_display_rect, int the_font_size, int padding, int extra_pixel_adjustment)
	{

		font_size = the_font_size;
		total_lines = num_of_display_lines;
		width_of_display_rectangle = width_of_display_rect;
		horizontal_pixel_adjustment = extra_pixel_adjustment;

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




	//void Configure_Display(int num_of_display_lines, int width_of_display_window, int the_font_size, padding);
	
	
	void DISPLAY::DrawMessage(sf::RenderWindow & windowtype, int convers_num_index) 

	{


		//passed a null string, passed a one partial line
		int amt_of_lines_for_this_message = -1;

		int on_this_round = 1;

		//first round checks the amount of lines for this message
		while (on_this_round < 3) {

		int i = 0;
		int j = 1;

		space_is_used = 0;
		
		bool is_on_first_run = true;
		int first_run = 1;

		float num_chars_on_this_line = 0;
		
		
		
		

		

		int last_word_started_at = 0;
		int amt_letters_of_last_word = 0;
		int amt_of_letters_to_display = 0;

		float prevwidth = -1;
		float width = 0;
		
		int length_string = message_string.length() - 1;
		
		int on_last_line = 0;
		
		int height = 0;
		int height2 = 0;


		//int element_index = message_string.length() - 1;

		std::string temporary_string;
		
		int total_offset = 0;
		
		
		int run = 0;
		int each_vertical_offset_is = 0;

		textmessage.setString(message_string);
		
		
		each_vertical_offset_is = textmessage.getLocalBounds().height;
		
		int line_number = 0;

		int other_line_number = 0;

		
		
		//total lines used for message singular
		

			//at end now
			//on_this_round++;

			//next line starts here checks if at the end of message and there is 
			//still message left 
			while (1)
			{

				//round 1 is for preemptive determination of number of lines in message
				//turns off display with flag.
				//this function here determins if space is to be used in the subsequent 
				//round two.  If space is used can break out of round loop.
				if (on_this_round == 1)
				{



					//CHANGE TOO (AROUND 301) : amt_of_lines_for_this_message = line_number;
					other_line_number++;



					////////////////////


					//if this is so means that there is more text on next screen with no space 
					//so turn on space useage

					//looking at next line after all text for checking use of space comment
					//and than yes/no only. Set in here!


					//determine if to use space...
					if (other_line_number == total_lines + 1)
					{//check if any characters even space

						//check this maybe use a pointer os sorts
						char check_for_character = NULL;
						check_for_character = message_string[total_offset];

						//turn on space because there is more text beyond the last line of text
						if (check_for_character)
						{
							//is more lines so there is use of space text
							space_is_used = 1;

							//break out of this second while loop and start outer loop next round while.

							break;
						}

					}
				}
				///////////

				//NOT NEEDED!
	//			//DUPLICATE POSSIBLE BELOW MAYBE A BETTER SOLUTION : fix sign too!
	//			else if (j >= message_string.length())
	//			{
	//
	//			
	//			}



				//IN HERE ADDED OUTER WHILE ARE ALL THE VARIABLES RESET FOR USAGE?!?!?!

				//current vertical line
				line_number++;

				amt_letters_of_last_word = 0;
				amt_of_letters_to_display = 0;

				
				//total_offset = total_offset + num_chars_on_this_line + 1 ;
				total_offset = total_offset + num_chars_on_this_line;


				int one_through_count = 0;
				float first_width = 0;
				float width = 0;

				///////////////
				string message_string1;

				//CHECHK THIS
				textmessage.setCharacterSize(font_size);
				textmessage1.setCharacterSize(font_size);
				textmessage1.setPosition(0, 0);
				textmessage1.setFillColor(sf::Color::Red);
				//textmessage.setString(temporary_string);
				sf::Font Fontforscore;

				if (!Fontforscore.loadFromFile("ARIALBD.ttf"))
				{
					exit(1);
				}

				
				textmessage1.setFont(Fontforscore);

				num_chars_on_this_line = 1;


				
				//to get width of text in pixels : maybe 290

				while (first_width <= width_of_display_rectangle)// > width)
				{

					

					message_string1.append("T");
					textmessage1.setString(message_string1);



					


					prevwidth = first_width;
					first_width = textmessage1.findCharacterPos(num_chars_on_this_line).x - textmessage1.findCharacterPos(0).x;
					//first_width = textmessage1.getLocalBounds().width;


					//width = textmessage.getGlobalBounds().width;

					//text is complete for this line
					if ((prevwidth == first_width) && (one_through_count != 0))

					{

						break;
					}

					one_through_count = 1;
					num_chars_on_this_line++;

				}



				//out of determiner that we have number of lines for this message

				//is total of linenumber of message when there is break
				amt_of_lines_for_this_message = line_number;

				line_number = 0;




				//windowtype2.draw(textmessage);

				//windowtype2.display();


				//////////////

				num_chars_on_this_line = 1;














				//find number of characters by width - width = : 496
				while (first_width > width)// 
				{

					line_number++;

					if (j == (message_string.length()))
					{
						on_last_line = 1;
						break;
					}

					j++;


					prevwidth = width;
					width = textmessage.findCharacterPos(num_chars_on_this_line).x - textmessage.findCharacterPos(0).x;

					//width = textmessage.getGlobalBounds().width;

					//text is complete for this line
					if ((prevwidth == width) && (num_chars_on_this_line != 0))

					{

						break;
					}


					num_chars_on_this_line++;

				}

				//move this...!
				//ClearOutBox(windowtype, first_width);


				//old debug usage
				//windowtype2.draw(textmessage);
				//windowtype2.display();


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

						//				if (amt_letters_of_last_word >= num_chars_on_this_line)
						//				{
						//					
						//					MessageBoxA(NULL, "error a word is to long", "title", MB_OK);
						//					exit(-1);
						//				
						//				}


						amt_of_letters_to_display = num_chars_on_this_line - amt_letters_of_last_word;




						j = j - amt_letters_of_last_word;
						total_offset = total_offset - amt_letters_of_last_word;

					}



					temporary_string.resize(amt_of_letters_to_display);





					//the position of j is set to any unwrapped text
					//total offset is where the index is reading the test_string from




				}//if for is not last line





			//add padd
			//general text
				textmessage.setPosition(display_x_setting, display_y_setting + height);
				//textmessage.setCharacterSize(18);
				textmessage.setFillColor(sf::Color::Red);
				textmessage.setString(temporary_string);




				sf::RectangleShape rectangle_box(sf::Vector2f(first_width + horizontal_pixel_adjustment, (float)(total_lines * each_vertical_offset_is)));

				rectangle_box.setFillColor(sf::Color(100, 250, 50));

				if (first_run == 1)
				{


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


		//		space_is_used = 1;




				sf::Text message_holder10;
				//sf::RenderWindow windowtype3(sf::VideoMode(700, 1000), "a");










				

				/*

				//first check for any characters after the located last line
				//if is more than total_lines, than on space is activated.

				//	if ((amt_of_lines_for_this_message < total_lines - 2 )  ||
				//		(amt_of_lines_for_this_message > total_lines  -2  ))  
					
				
				//with this condition there will be no space...
				
				if (amt_of_lines_for_this_message != (total_lines - 2))
				{
					space_is_used = 0;

				}


				*/



				
				 
				///on this round means where is checked for total lines off message
				if ((on_this_round > 1) && ((space_is_used && on_last_line) || (space_is_used && ((line_number) == (total_lines - 2)))))
				{


					string temp_string = message::Get_Out_Bound_String();

					int length_of_string = temp_string.length();

					//sf::Font Fontforscore;

					if (gflag == 0)
					{
						gflag = 1;




						message_holder10.setFont(Fontforscore);
						message_holder10.setCharacterSize(font_size);
						message_holder10.setFillColor(sf::Color::Red);
						//message_holder10.setStyle(sf::Text::Bold);

						//windowtype2.close();

					}


					message_holder10.setOrigin(0, 0);



					message_holder10.setString(temp_string);

					int y_for_space = display_y_setting + (total_lines - 2) * each_vertical_offset_is;



					float x = message_holder10.getLocalBounds().width;




					message_holder10.setPosition(((first_width - x) / 2), y_for_space);


					//windowtype2.close();


					string test = message_holder10.getString();

					//windowtype3.clear();
					windowtype.draw(message_holder10);
					//windowtype.clear();



					if (on_this_round > 1)
					{
						windowtype.display();//this is the one display int this function
						windowtype.clear();
						gvar = 1;
					
						//check this supposed is spaced displayed so back to beginning of while create lines 
						//with reset variables all necessary, check!
				//		Wait_For_Space_Press();
						line_number = 0;
						//CHECK THIS
						on_last_line = 0;
						



					}










					///Wait_For_Space_Press();

 



					//ClearOutBox( windowtype );




					//height = 0;
					//breaks out of while create each line and waits for space

					//break;



				}

				





				else if (on_last_line)
				{


					if (on_this_round > 1) {
						windowtype.display();
						windowtype.clear();

						


					}
					break;

				}




				//////////////////










				if (is_on_first_run)
				{
					is_on_first_run = false;
				}


				


				//	if (on_this_round > 1)
				//	{
				//
				//		windowtype.display();
				//		windowtype.clear();
				//	}

				//	on_this_round++;


				//here make sure pring and wait for space and j and offset is correct




			}//emd while, for creating each line


			//here waiting for space
			
			if (on_this_round != 1)
			{
				Wait_For_Space_Press();
			}

		

			on_this_round++;

}//second while: for checking round to know number of lines : got here by break?!?!?

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
//		message_holder.setFont(theFont);



	}


	
	void DISPLAY::ClearOutBox(sf::RenderWindow  & windowtype, float first_width)
	{

		
		//the_width , (float)(total_lines * each_vertical_offset_is)));
		//sf::RectangleShape rectangle_box(sf::Vector2f((first_width + 10), (float)(total_lines * each_vertical_offset_is)));
		//rectangle_box.setFillColor(sf::Color(100, 250, 50));
		//windowtype.draw(rectangle_box);

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



