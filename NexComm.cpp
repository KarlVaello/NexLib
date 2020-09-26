#include <stdio.h>
#include <iostream>
#include <cstring>

#include "NexComm.h"
#include "serialib.h"


void NexComm::SendCmd(char* cmd, bool tail, bool header)
{
    serial.writeString(cmd);
    if (tail)
    {
        
    }
}

bool NexComm::Connect()
{
    return false;
}
