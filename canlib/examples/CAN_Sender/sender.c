#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "can_driver.h"
#define TAM 100

// Global variables
s_PORT Port = {
    "vcan0",
    "125K"};

void help(void)
{
    printf("**************************************************************\n");
    printf("*  Can_Sender                                                *\n");
    printf("*                                                            *\n");
    printf("*  A simple example for PC. The Program implement two CAN    *\n");
    printf("*  nodes in diferent processes . A sender and a receiver.    *\n");
    printf("*  Both communicate together                                 *\n");
    printf("*                                                            *\n");
    printf("*   Usage:                                                   *\n");
    printf("*   ./CanSender                                              *\n");
    printf("*                                                            *\n");
    printf("**************************************************************\n");
}
static void
print_message(Message const *m)
{
    unsigned char len = 0;
    if (!m)
    {
        printf("Message error");
        return;
    }
    printf("message: ID %X, Size %d bytes, Data [ ", m->cob_id, m->len);
    while (len < m->len)
    {
        printf("%X", m->data[len]);
        len++;
        if (len < m->len)
        {
            printf(", ");
        }
    }
    printf(" ];\n");
}

void send_task(CAN_HANDLE fd)
{
    Message msg = {0x0A, 0, 1, {1}};
    while (1)
    {
        msg.data[0] = msg.data[0] + 1;
        sendCAN(fd, &msg);
        printf("-s: Sending: ");
        print_message(&msg);
        printf("\n \n");
        sleep(1);
    }
}

int main(int argc, char **argv)
{

    CAN_HANDLE canfd = NULL;
    /*if (argc < 2)
    {
        help();
        return 0;
    }*/
    
    // If it is a sender
    
    /*if (!strcmp(argv[1], "-s"))
    {*/
        canfd = openCAN(&Port);
        if (canfd == NULL)
        {
            printf("Error Openning the CAN Port, Exiting. \n");
            return -1;
        }
        printf("Starting the Sender task (-s)\n");
        send_task(canfd);
        closeCAN(canfd);
    //} 
    
    /*else
    {
        printf("Invalid argument, please follow the usage bellow. \n \n");
        help();
    }*/
    return 0;
}

