#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "can_driver.h"

// Global variables
s_PORT Port= {"vcan0", "125K"}; // The Configuration are identical for the master and slave

void help(void)
{
  printf("**************************************************************\n");
  printf("*  Can_Complete                                              *\n");
  printf("*                                                            *\n");
  printf("*  A simple example for PC. The Program implement two CAN    *\n");
  printf("*  nodes in diferent processes . A sender and a receiver.    *\n");
  printf("*  Both communicate together                                 *\n");
  printf("*                                                            *\n");
  printf("*                                                            *\n");
  printf("*                                                            *\n");
  printf("*   Usage:                                                   *\n");
  printf("*   ./Can_Compelete_Simple [OTPION]                          *\n");
  printf("*                                                            *\n");
  printf("*    -s: To configure as the sender                          *\n");
  printf("*                                                            *\n");
  printf("*    -r: To configure as a receiver                          *\n");
  printf("*                                                            *\n");
  printf("*    -a: To configure to ask                                 *\n");
  printf("*                                                            *\n");
  printf("*    -d: To choose message from database                     *\n");
  printf("*                                                            *\n");
  printf("**************************************************************\n");
}
static void print_message(Message const *m)
{
    unsigned char len=0;
    if (!m)
    {
        printf("Message error");
        return;
    }
    printf("message: ID %X, Size %d bytes, Data [ ", m->cob_id, m->len);
    while(len < m->len)
    {
        printf("%X",m->data[len]);
        len ++;
        if (len < m->len)
        {
            printf(", ");
        }
    }
    printf(" ];\n");
}

void receiver_task(CAN_HANDLE fd)
{
    Message msg = {0,0,2,{0}};
    while(1)
    {
        if (!receiveCAN(fd, &msg))
        {
            print_message(&msg);
            msg.data[0] = msg.data[1] + 2;
            msg.cob_id = msg.cob_id + 1;
            sendCAN(fd, &msg);
        }
        sleep(0.5);
    }
}

void send_task(CAN_HANDLE fd)
{
    Message msg = {0x0C,0,2,{0}};
    while(1)
    {
        msg.data[0] = msg.data[0] + 1;
        sendCAN(fd, &msg);
        print_message(&msg);
        sleep(1);
    }
}
int main(int argc,char **argv)
{

    CAN_HANDLE canfd = NULL;
    canfd = openCAN(&Port);
    if(!canfd)
    {
        printf("Big error");
        return -1;
    }
    send_task(canfd);
    closeCAN(canfd);
    return 0;
}
