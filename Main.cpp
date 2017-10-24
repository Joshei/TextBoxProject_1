
#include <SFML\Graphics.hpp>
#include "Display.h"
#include <iostream>
#include <memory>
#include "windows.h"
#include "message.h"

int gflag = 0;

void Add_A_Message(int conv_num_index, string temp);
void Draw_A_Message(int statemtnt_num_index, sf::RenderWindow & window, int conv_num_index, int  vert_lines);



//for checking keypress and closing window
sf::Event event;
sf::RenderWindow window(sf::VideoMode(1000, 700), "!!!!");
//sf::RenderWindow window2(sf::VideoMode(1000, 700), "!!!!");



//int display_width, int display_height, int vert_offset, int amount_of_total_lines, int display_origin_x, int display_origin_y)

std::unique_ptr<DISPLAY> ptextdisplay(new DISPLAY(50, 50, 50, 10, 0, 0));  // * textdisplay();

	
																		  
																		 


int main(void) {


	//cout << "test";
	
	//SET ALREADY IN CONSTRUTOR WELL...FIX THAT

	//Configure_Display(int num_of_display_lines, int width_of_display_window, int the_font_size, int padding);
	ptextdisplay->Configure_Display(10,290,18, 10, 18);


	int one_time_loop = 0;

	FreeConsole();

	using namespace std;

	
	


	


	sf::Font Fontforscore;

	if (!Fontforscore.loadFromFile("ARIALBD.ttf"))
	{
		exit(1);
	}

	ptextdisplay->SetFont(Fontforscore);
	ptextdisplay->SetFont1(Fontforscore);

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
				if (event.key.code == sf::Keyboard::Escape)
				{
					exit(-1);
				}


			}

		}



		//make a vector of conversations and each conversation_side has a vector of structs

		//each message is a one sided conversation and takes a struct for each seperate message
		
		
					   	
		string test = "a b c d ef ghijklm no pqd r stuv  1234 56 789 0 123 45678 90 1234abc d ef";

		int checkthis = test.length();
		string test1 = "abc def ghi jkl mno pqr stu vwx yz 123 456 789 012 345 678 901 abc deg ghi";
		string test2 = "zabc zdef zghi zjkl zmno zpqr zstu zvwx zyz z123 z456 z789 z012 z345 z678 z901 zabc zdeg zghi";


		

		std::vector <message> alltheconversations;


		while (one_time_loop == 0)
		{  
			one_time_loop = 1;
			 


			//Configure_Message(bool is_spaced, bool is_yes_no, string in_string, int  conv_id, int statent_id, int by1, int by2, int from)
			
			string temp;
			temp = "This is a test to see how this iswor ki ng.  lets do a 21111 A";


			//message_string = Get_String_Message(convers_num_index, next_statement_number);
			//Add_A_Message(int conv_num, string )
			Add_A_Message(0, temp);
			Add_A_Message(0, test);


			//sf::RenderWindow & windowtype, sf::RenderWindow & windowtype2,  string test_string, int convers_num, int vert_line_length
			
			int input_statement_num_index = 0;
			
			

			
			//conv_num, vert lines....?!?!?!
			Draw_A_Message(input_statement_num_index, window, 0, 10);
			
			gflag = 0;
			
			Draw_A_Message(1, window, 0, 10);
			
			
		//	window.display();

		}

		}



	

	}

	//incomplete
	//bool is_spaced, bool is_yes_no, string in_string, int  conv_id, int statent_id, int by1, int by2, int from
	
	//message(int statement_number_index, int conv_number_index)
	void Add_A_Message(int conv_num_index, string temp)
	{
		
		
		//int next_statement_number_index = statement_number + 1;

		//int total_number_messages, int statement_numbers, int conv_number);

		

		ptextdisplay->alltheconversations.push_back(message(conv_num_index));
		
		int statement_number_index = ptextdisplay->alltheconversations[conv_num_index].Get_Active_Statement_Index();

		ptextdisplay->alltheconversations[conv_num_index].Configure_Message(true, false, temp, conv_num_index, (statement_number_index + 1),1,1,1);
	
	}





	void Draw_A_Message(int input_statement_num_index , sf::RenderWindow & window, int conv_num_index,int  vert_lines)
	{

		//int active_number = ptextdisplay->Get_Active_Statement_Number_Index(conv_num_index);//;// alltheconversations[1].Get_Active_Statement_Index();
		string message = ptextdisplay->Get_String_Message(conv_num_index, input_statement_num_index);// alltheconversations[1].Get_Message_With_Statement_Num(active_number + 1);


		ptextdisplay->DrawMessage(window,  conv_num_index);

	}