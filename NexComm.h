#pragma once
#include <stdio.h>



class NexComm
{
public:

	/**
		@brief This function is uses to test display connection

		@details  Send a connection test command ("connect") + CmdTail()

		@param	cmd		String cmd
		@param	tail	add command termination add the endd of the string cmd
		@param	header	add header comand
		@return result of connection test.
	*/
	void SendCmd(char* cmd, bool tail, bool header);

	/**
		@brief This function is uses to test display connection
		
		@details  Send a connection test command ("connect") + CmdTail()

		@param no params.
		@return result of connection test.
	*/
	bool Connect();
};

