#pragma once

#include <memory>
#include "windows.h"
#include "Message.h""
#include <string.h>
#include <vector>

using namespace std;

struct conversation_side
{
	int conversation_num_index;
	int part_num_index;
	bool space_used;
	bool yes_no_used;
	string statement;
	int heard_by_one;
	int heard_by_two;
	int said_by;



};



class message
{




public:

	message(int statement_number_index, int conv_number_index);


	static string Get_Out_Bound_String()
	{
		string out_bound_string = " [PRESS SPACE TO CONTINUE] ";
		return(out_bound_string);
	}


	//static string Get_Out_Bound_String();


	void Load_Message(int, int, int, int, string , int, int, bool, bool);
	
	int Check_For_Latest_Message_Index();
	void Configure_Message( bool, bool, string, int, int, int, int,int);
	int Get_Next_Conversation_Statement_Num_Index();
	void Set_Conversation_Current_Statement_Num_Index(int statement_number);
	
	int Get_Active_Statement_Index();
	string Get_Message_With_Statement_Num(int);


	//???
	string Check_For_Space(int statement_number);
	
	string GetCommentString();
	
	


	vector<conversation_side> message_array;
	//vector<conversation_side> conversation_part_2;
	//vector<conversation_side> conversation_part_3;

	int active_statement_index;
	int statement_num_index;
	int total_num_messages;
	int highest_statement_num;
	int conversation_number_index;

};
