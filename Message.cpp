#include "Message.h""
#include <string.h>

#include <vector>


static int HIGHEST_CONVERSATION_NUM = 0;

using namespace std;


message::message( int statement_number_index, int conv_number_index  )
{

	
	//index
	active_statement_index = 0;
	//total_num_messages = total_number_messages;
	HIGHEST_CONVERSATION_NUM++;
	conversation_number_index = HIGHEST_CONVERSATION_NUM;
	statement_num_index = statement_number_index;
	
	//!!!!!!!!!!
	//highest_statement_num = statement_number_index;
	
	conversation_number_index = conv_number_index;


	
	

}



//loads message into conversation side, multiple messages each in there own vector
void message::Load_Message(int heard_id, int heard_from_one, int heard_from_two, int from_messenger, string in_string, int conversation_index_ID, int statement_num, bool is_spaced, bool is_yes_no )
{

	
	int latest_statment_num = Check_For_Latest_Message_Index();

	

	Configure_Message(is_spaced, is_yes_no, in_string, conversation_index_ID, statement_num, heard_from_one, heard_from_two, from_messenger);
	
	

}


void message::Configure_Message(bool is_spaced, bool is_yes_no, string in_string, int  conv_id_index, int statement_id_index, int by1, int by2, int from  )
{

	
	conversation_side  message_array1[1];

	message_array1[0].space_used = is_spaced;
	message_array1[0].yes_no_used = is_yes_no;
	message_array1[0].conversation_num_index = conv_id_index;
	message_array1[0].part_num_index = statement_id_index;
	message_array1[0].heard_by_one = by1;
	message_array1[0].heard_by_two = by2;
	message_array1[0].said_by =  from;
	message_array1[0].statement = in_string;

	message_array.push_back(message_array1[0]);

	total_num_messages++;

	
}
int message::Check_For_Latest_Message_Index()

{
	
	return(statement_num_index);


}

int message::Get_Next_Conversation_Statement_Num_Index()//conversation_ID)
{

	return(statement_num_index + 1);

}


void message::Set_Conversation_Current_Statement_Num_Index(int statement_number_index)
{


	statement_num_index = statement_number_index;
}

string message::Check_For_Space(int statement_number_index)
{
	//portability issue?
	if (message_array[statement_number_index].space_used == 1)
	{
		
		return(Get_Out_Bound_String());
		
	
	}

	return(NULL);
	

}




//displays active string
string message::GetCommentString()
{
	return message_array[active_statement_index].statement;

}


int message::Get_Active_Statement_Index()
{

	return (active_statement_index);

}


string message::Get_Message_With_Statement_Num(int statement_number_index)
{

	return message_array[statement_number_index].statement;


}









