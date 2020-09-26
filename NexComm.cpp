/*!
@file    NexComm.cpp
@brief   CPP file of the class NexComm. This class is used for comunicate to Nextion display
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

#include <stdio.h>
#include <iostream>
#include <cstring>

#include "NexComm.h"
#include "serialib.h"

// Serial object
serialib serial;


NexComm::NexComm(char* serialPort, int bd)
{
	serialPortName = serialPort;
	baudrate = bd;
	StartComm(serialPortName, baudrate);
}

NexComm::~NexComm()
{
}

unsigned char NexComm::StartComm(char* serialPort, int bd)
{
	printf("Start Connection %s@%d\n", serialPort, bd);
	char errorOpening = serial.openDevice(serialPort, bd);
	// If connection fails, return the error code otherwise, display a success message
	if (errorOpening != 1)
	{
		printf("Fail to connect to %s @ %d\n", serialPort, bd);
		return 0;
	}
	else {
		printf("Successful connection to %s @ %d\n", serialPort, bd);
		return 1;
	}
}

void NexComm::SendCmd(char* cmd, bool tail, bool header)
{
    serial.writeString(cmd);
    if (tail)
    {
		CmdTail();
    }
}

void NexComm::CmdTail()
{
	serial.writeChar('ÿ');
	serial.writeChar('ÿ');
	serial.writeChar('ÿ');
}

void NexComm::SoftReset()
{
	SendCmd("rest", true, false);
}

bool NexComm::Connect()
{
    return false;
}
