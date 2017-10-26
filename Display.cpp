#include <iostream>
#include <conio.h>

#include <string.h>

#include <SFML/Graphics.hpp>
#include "windows.h"

#include "Display.h"
#include "message.h"

using namespace std;
extern int gflag;




//PROBLEMS:
//consolidation needed between line number and new line number and needs checking line_number
//three resizing parts not rememberig why this was created.


//saved off for branch use


//let's see this...
	DISPLAY::DISPLAY(int display_width, int display_height, int vert_offset, int amount_of_total_lines, int display_origin_x, int display_origin_y) 
	{

		font_size = 18;
		horizontal_pixel_adjustment = 18;
		total_lines = 3;

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

		//test for a passed a null string, and a passed a one partial line
		
		
		//int amt_of_lines_for_this_message = -1;

		//round number one or two, round one collects how many
		int on_this_round = 1;


		//these are the previous j and total offset before they are changed for next line being
		//read in!
		int last_j = 0;
		int last_total_offset = 0;




		//first round checks the amount of lines for this message
		

		//this is new and the round alternates : 1 2 1 2 1 2 with a modulus at end of function
		//for a new 2 just started (on_this_round) the old values of j and offset have been reset
		//to the running right previous
		//if the value of : on_this_round is newly set to 1 than the two variables remain
		//as they have been left to continue diplaying the ongoing text message with offset
		//and j.  j is number of characters used to check for if message length is complete
		//so that the variable on_last_line is set.



		//there is a wrap around word removed
		int j = 1;

		//the change of the main sfml text object in characters so that it can start where it left off
		int total_offset = 0;
		
		//set in first round to one if "press the space" message is to be displayed.
		space_is_used = 0;


		//while (on_this_round < 3) {
		//this happens after every round
		while (1) {
		
			//these are the previous j and total offset before they are changed for next line being
			//read in!
			last_j = j;
			last_total_offset = total_offset;


			

		//indexes displayed characters
		int i = 0;
		//is how many characters have been displayed on each line and subtracted when
		
		
		
		//of is on first run is true this means that together with on_last_line
		//that the amount of characters for the message is set to the exact amount
		//of characters because no adjustments are needed.
		bool is_on_first_run = true;
		//to check if rectangle should be displayed.
		int first_run = 1;
		//number of characters on the current line is changed when finding the width of the 
		//the letters across the rectangle.  When the words wrap and the words need removeale
		//than this is reduced there.
		float num_chars_on_this_line = 0;
		
		
		//int last_word_started_at = 0;

		//*****
		//this is the amount of the letters of the word up against the right boundary
		//if there is no space on the next line than the amount of this variable is 
		//subtracted from j and from offset.
		int amt_letters_of_last_word = 0;
		
		//wrapping check uses this to find amount of display letters when there is 
		//and when there isn't wrapping on to the next line.
		int amt_of_letters_to_display = 0;

		//this is compared to width to find out if all the characters have been 
		//displayed because the width stays the same.
		float prevwidth = -1;
		float width = 0;

		//the length of string so that if all letters have been displayed than leave the function
		//that is constructing the message line.
		int length_string = message_string.length() - 1;
		
		//means there is a partial statement and it is the last statement of the messages
		int on_last_line = 0;
		
		//determined by the getlocalbounds is the vertical change after each line of display.
		int height = 0;

		//was used for checking display in another renderwindow
		//int height2 = 0;


		//the string name that is resized and displays the current indexing of the message_string
		std::string temporary_string;
		
		
		
		
		//Set and multiplied by number of lines to determine sizing of rectangle and  display of 
		//lines of characters
		int each_vertical_offset_is = 0;

		//???????????????????
		textmessage.setString(message_string);
		
		//holds the line number for determining what the current linenumber is within the functio
		//as text is set for display with the draw function of the sfml text object.
		int line_number = 0;
		//Needs to be consolidated with the above variable
		//int other_line_number = 0;

		//checks for the heigt of the characters by looking at the sfml text object
		//that loads the message_string
		each_vertical_offset_is = textmessage.getLocalBounds().height;
		

		

		

		
		 
		
			//in here displays one line per each iteration (next iteration is next line)
		 	while (1)
			{
				
				// current vertical line
				line_number++;

				//round 1 is for preemptive determination of number of lines in message
				//the display flag is turned off.
				//this function here determins if the space is to be used in the subsequent 
				//round two.  If space is used can break out of round loop because it is the
				//last line of text.
				
				//checks to see if space is used on the next round, important
				if (on_this_round == 1)
				{



					//CONSOLIDATE: CHANGE TOO (AROUND 301) : amt_of_lines_for_this_message = line_number;
					//other_line_number++;



					////////////////////


					//if this is so means that there is more text on next screen without its usage
					//so turn on spacing to be used variable

					//set yes/no around here later


					//determine if to use space...is there more than one screen full of text look at following
					//character if it is on the next line (even a space.)
					//if (other_line_number == total_lines + 1)
					if (line_number == (total_lines - 2) )
					
					{

						//check this maybe use a pointer os sorts
						char check_for_character = NULL;
						
						
						check_for_character = message_string[total_offset];

						//there is another line of text so that means that we will be using the
						//space printout display
						if (check_for_character)
						{
							
							space_is_used = 1;

							//break out of this second while loop and start outer loop next round 2.

							break;
						}

					}
				}
				


				//IN HERE ADDED OUTER WHILE ARE ALL THE VARIABLES RESET FOR USAGE?!?!?!

				

				amt_letters_of_last_word = 0;
				amt_of_letters_to_display = 0;

				
				//total_offset = total_offset + num_chars_on_this_line + 1 ;
				
				//sets the offset into the  message_string string
				total_offset = total_offset + num_chars_on_this_line;

				//a simple flag that could be replaced; makes both width and prewidth not equivalent when there started
				//as zero
				int one_through_count = 0;
				//the width of the characters is stored here for use in the functionality that follows
				float first_width = 0;
				//compared to first_width to see if the charactes fit into the displayed rectangle
				float width = 0;

				///////////////
				string message_string1;

				//PROBABLY PUT THIS SOMEWHERE ELSE
				//textmessage is for the message string parts, that is each line.
				//textmessage1 is for the display of space or yes no text from the message class.
				textmessage.setCharacterSize(font_size);
				textmessage1.setCharacterSize(font_size);
				
				textmessage1.setPosition(0, 0);
				textmessage1.setFillColor(sf::Color::Red);
				//textmessage.setString(temporary_string);
				
				
				//NEEDS CHANGING OF NAME taken from other program
				sf::Font Fontforscore;

				if (!Fontforscore.loadFromFile("ARIALBD.ttf"))
				{
					exit(1);
				}

				
				textmessage1.setFont(Fontforscore);

				num_chars_on_this_line = 1;


				
				//this while used to find the width approximation for the passed in integer
				//for width_of_display_rectangle by using a character and checking for the 
				//width.  This width is than used in the next while loop below.
				while (first_width <= width_of_display_rectangle)// > width)
				{

					

					message_string1.append("T");
					textmessage1.setString(message_string1);


					prevwidth = first_width;
					first_width = textmessage1.findCharacterPos(num_chars_on_this_line).x - textmessage1.findCharacterPos(0).x;
					
					//simple flag to make sure intial values of zero don't cause breaking inside braces
					if ((prevwidth == first_width) && (one_through_count != 0))

					{

						break;
					}

					one_through_count = 1;
					
					//probably not needed
					num_chars_on_this_line++;

				}



				//*****CONFUSED WHAT IS THIS
				//not used anymore
				//amt_of_lines_for_this_message = line_number;

				



				//was here for testing purposes
				//windowtype2.draw(textmessage);
				//windowtype2.display();



				
				
				num_chars_on_this_line = 1;


				
				//uses determined width above to keep the right amount of characters
				//that will fit in rectangle drawn below
				while (first_width > width)// 
				{

					//doesn't look right here
					//line_number++;

					if (j == (message_string.length()))
					{
						on_last_line = 1;
						break;
					}

					//****not an index starts at one, is the number of total characters for this ????????
					j++;


					prevwidth = width;
					width = textmessage.findCharacterPos(num_chars_on_this_line).x - textmessage.findCharacterPos(0).x;


					//if the same than all characters have been used...COMPARE THIS TO THE WHILE LOOP AND SOLVE ANY PROBLEMS
					if ((prevwidth == width) && (num_chars_on_this_line != 0))

					{

						break;
					}

					//used to keep track of how many characters fit within the width 
					num_chars_on_this_line++;

				}

				//line_number++;
				
				//old debug usage
				//windowtype2.draw(textmessage);
				//windowtype2.display();


				//erase this string called temporary string
 				temporary_string.erase(0, temporary_string.length() - 0);


				//////////CHECK THIS: confusing...these three conditions below seem
				//to be an adjustment from when the string was created in the second
				//while loop that adjusts the num_chars_on_this_line.

				//only line processed so just resize it normally 
				if (on_last_line   &&  is_on_first_run)
				{
					temporary_string.resize(num_chars_on_this_line);

				}

				
				else if (on_last_line)
				{

					temporary_string.resize(num_chars_on_this_line - 1);
				}



				//isn't last line
				else if (!on_last_line)
				{
					temporary_string.resize(num_chars_on_this_line + 1);
				}



				/////////////////////


				//create the string and total offset is the amount of offset into the entire sfml object
				//message_string.

				//for (i = 0; i < num_chars_on_this_line - 1; i++)
				for (i = 0; i < num_chars_on_this_line; i++)
				{

					temporary_string[i] = message_string[total_offset + i];


				}



				//CHECK :  could be wrapping because not on a last line which is a designation that
				//the line is partial
				if (on_last_line != 1)
				{
					//put here to check the next character below this for loop 
					int k = 0;
					//find number of characters up against right border
					for (k; k < num_chars_on_this_line; k++)
					{




						//if a space start the last word possiblity again 
						if (temporary_string[k] == ' ')
						{


							amt_letters_of_last_word = 0;

						}
						
						//is not a space so continue adding letters  until done or a space is finished with
						else
						{
							amt_letters_of_last_word++;
						}





					}





					//look at next characer to see if ending word is wrapped or displayed as is
					//ending right up against right border so check next space which is the 
					//next line's next character
					if (temporary_string[k] == ' ')
					{

						amt_of_letters_to_display = num_chars_on_this_line;

					}




					//there is a word wrapping around the right boundary
					else

					{

						//AN INTERESTING FAILURE CHECK IDEA

						//				if (amt_letters_of_last_word >= num_chars_on_this_line)
						//				{
						//					
						//					MessageBoxA(NULL, "error a word is to long", "title", MB_OK);
						//					exit(-1);
						//				
						//				}


						//if there is a word wrap onto next line than decrease.
						amt_of_letters_to_display = num_chars_on_this_line - amt_letters_of_last_word;



						//decrease these two variables that keep track of letters displayed and the offset
						//into the entire message, sfml text object.
					
						//the position of j is set to any unwrapped text
						//total offset is where the index is reading the test_string from

						j = j - amt_letters_of_last_word;
						total_offset = total_offset - amt_letters_of_last_word;

					}


					//resizes to the exact size of the string 
					temporary_string.resize(amt_of_letters_to_display);





					



				}//if for is not last line





				//add padding to rectangle decision needed.
				
				
				
				//sfml object textmessage loaded with a part of the entire string; one lines worth
				textmessage.setPosition(display_x_setting, display_y_setting + height);
				//textmessage.setCharacterSize(18);
				textmessage.setFillColor(sf::Color::Red);
				textmessage.setString(temporary_string);



				//displays the rectangle box one time for each new display of the text lines.
				sf::RectangleShape rectangle_box(sf::Vector2f(first_width + horizontal_pixel_adjustment, (float)(total_lines * each_vertical_offset_is)));

				rectangle_box.setFillColor(sf::Color(100, 250, 50));

				if (first_run == 1)
				{


					first_run = 2;
					windowtype.draw(rectangle_box);
				}

				//drawn on the rectangle the line of text.
				windowtype.draw(textmessage);
				

				//adjusts where the text is displayed vertically
				height = height + each_vertical_offset_is;
				//height2 = height2 + 50;


				sf::Text message_holder10;
				
				
				//JUST IN CASE IS NEEDED:

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



				
				 
				//on this round one is just getting information for space useage - if space is used because
				//there is more text than one screen full.
				
				
				//on this round uses a mod to alternate betweeen 1 and 2 over and over again
				//if modulated to 2, below this will change to 1 again to collect the space 
				//information once again.
				if ((on_this_round == 2) && ((space_is_used && on_last_line) || (space_is_used && ((line_number) == (total_lines - 2)))))
				{

					//loads the comment to be diplayed from message object
					string temp_string = message::Get_Out_Bound_String();

					//int length_of_string = temp_string.length();

					
					//ALL THIS COULD BE DONE AGAIN BETTER...LOOK OVER AND FIX
					if (gflag == 0)
					{
						gflag = 1;




						message_holder10.setFont(Fontforscore);
						message_holder10.setCharacterSize(font_size);
						message_holder10.setFillColor(sf::Color::Red);
						//message_holder10.setStyle(sf::Text::Bold);

						

					}


					message_holder10.setOrigin(0, 0);

					//Filled with space text 
					message_holder10.setString(temp_string);

					//displays properly on the y setting - vertical
					int y_for_space = display_y_setting + (total_lines - 2) * each_vertical_offset_is;


					//*****
					float x = message_holder10.getLocalBounds().width;



					//***** centers the comment text from message
					message_holder10.setPosition(((first_width - x) / 2), y_for_space);

					//was used for testing purposes
					//string test = message_holder10.getString();

					//CHECK THIS FOR THE CLEAR
					windowtype.draw(message_holder10);
					//windowtype.clear();



					//UNTESTED FOR NOW, if on non first information gathering round than is okay to display

					if (on_this_round == 2)
					{
						windowtype.display();//this is the one display int this function
						windowtype.clear();


						//lets check after space chang on this round and these two variables so that
						//first round check for next part of message is done.
						line_number = 0;

						//CHECK THIS (and consolidate)
						on_last_line = 0;


						//CHECK THIS : 
						Wait_For_Space_Press();


						//This will change below so that it is changed back to 1 because we are resetting 
						//the round to 1 and therefore checking the remaining message
						//to determine if the correct number of lines is for displaying
						//space again.
						
						
						////sets this to one below
						//on_this_round = -1;

						//CHECK RIGHT HERE FOR ANY PROBLEMA


					}



				}
				//otherwise not space and on last line so this means that it is displayable on screen completely.
				else if (on_last_line)
				{

					//not informatio gathering round : 1.
					if (on_this_round == 2) {
						windowtype.display();
						windowtype.clear();

						


					}
					break;

				}




				//////////////////




				//used for resizing the variable appropriatly higher up above.
				if (is_on_first_run)
				{
					is_on_first_run = false;
				}


				
				//SHOULDN"T BE USED HERE, LEAVING JUST IN CASE.

				//	if (on_this_round > 1)
				//	{
				//
				//		windowtype.display();
				//		windowtype.clear();
				//	}

				//	on_this_round++;


				//here make sure pring and wait for space and j and offset is correct



			}//emd while, for creating each line


			//here waiting for space for now for proper viewing
			
			if (on_this_round ==  2)
			{
				Wait_For_Space_Press();
			}

			
			
		
			//no longer round 1 or if space above was used would be equated to zero here.
			
			//alternates round 1 and round 2
			//on_this_round++;
			on_this_round = on_this_round % 2 + 1;
			
			//reset for round 2 because is known if space is to be used now.
			//if there is more text than the round will be more than two
			//for example if the round is three than there has been more text beyond a space
			//for each higher number means there are additional messages after the space

			//redo the same procedure as right before however if space is to be used has been determined
			//on the next round here than once again we use a information gathering tactic to determine
			//if space is used which means that the round is one again and the j and total_offset will not
			//change
			
			//after round 2 is round 1 again so the j and total offset stays the same.
			
			//this means reset j ans total_offsset every other time
			//this just started round 2 means reset the values
			//when on_this_round starts by equaling 1 than it is time to gather space information 
			//again so these two values stay how they are
			if (on_this_round == 2)
			{
				
				

				j = last_j;
				total_offset = last_total_offset;
				

			}
			if (on_this_round == 1)
			{

				if (space_is_used != 1)
					break;

			}


}//second while: for checking round. round one is information gathering. round two is displaying a message
 //if need to display more message than on_this_round needs to be changed to one again!

}


//TO COMMENT LATER
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				exit(-1);
			}

		}

	}



