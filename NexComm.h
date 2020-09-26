/*!
@file    NexComm.h
@brief   Header file of the class NexComm. This class is used for comunicate to Nextion display
@author  Carlos Vaello (karlvaello)
@date	 2020-09-26

This is part of the NexLib used to fully control a Nextion display over serial port.

The MIT License (MIT)

Copyright (c) 2020 Carlos Vaello

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#pragma once
#include <stdio.h>



class NexComm
{
public:

	char* serialPortName;
	int baudrate;

	/**
		@brief NexComm constructor.

		@param serialPort	serial port where display is connected
		@param bd			serial communication baudrate
	*/
	NexComm(char* serialPort, int bd);

	/**
		@brief NexComm destructor.
	*/
	~NexComm();

	/**
	@brief This function is uses to star display serial connection

	@details  Send a connection test command ("connect") + CmdTail()

	@param	serialPort		serial port name to open
	@param	bd				serial communication baudrate
	@return result of serial comm start (1=OK, other = fail).
	*/
	unsigned char StartComm(char* serialPort, int bd);


	/**
		@brief Used to send a standart Nextion command

		@details send a command over serial 

		@param	cmd		String cmd
		@param	tail	add command termination add the endd of the string cmd
		@param	header	add header comand
		@return result of connection test.
	*/
	void SendCmd(char* cmd, bool tail, bool header);

	/**
		@brief nextion command termination

		@details send "ÿÿÿ" over serial port
	*/
	void CmdTail();

	void SoftReset();


	/**
		@brief This function is uses to test display connection
		
		@details  Send a connection test command ("connect") + CmdTail()

		@param no params.
		@return result of connection test.
	*/
	bool Connect();
};

