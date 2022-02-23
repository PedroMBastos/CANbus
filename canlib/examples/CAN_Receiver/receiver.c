#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "can_driver.h"
#define TAM 100

// Global variables
s_PORT Port = {
    "vcan0",
    "125K"};

void help(void)
{
    printf("**************************************************************\n");
    printf("*  Can_Receiver                                              *\n");
    printf("*                                                            *\n");
    printf("*  A simple example for PC. The Program implement two CAN    *\n");
    printf("*  nodes in diferent processes . A sender and a receiver.    *\n");
    printf("*  Both communicate together                                 *\n");
    printf("*                                                            *\n");
    printf("*   Usage:                                                   *\n");
    printf("*   ./CanReceiver                                            *\n");
    printf("*                                                            *\n");
    printf("**************************************************************\n");
}

long long current_timestamp() {
struct timeval te; 
gettimeofday(&te, NULL); // get current time
long long microseconds = te.tv_sec*1000000LL + te.tv_usec/1000; // calculate microseconds
printf("microseconds: %lld\n", microseconds);
return microseconds;
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

void receiver_task(CAN_HANDLE fd)
{
    Message msg = {0, 0, 2, {0}};
    while (1)
    {
        if (receiveCAN(fd, &msg) == 0)
        {
            printf("-r: Receiving: ");
            print_message(&msg);
            msg.data[1] = msg.data[0] + 2;
            msg.cob_id = msg.cob_id + 1;
            //current_timestamp();
            /*printf("Sending: ");
            print_message(&msg);
            sendCAN(fd, &msg);
            printf("\n \n");  */  
        }
        sleep(0.5);
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
    
    // If it is a receiver
    
    /*else if (!strcmp(argv[1], "-r"))
    {*/
        canfd = openCAN(&Port);
        if (canfd == NULL)
        {
            printf("Error Openning the CAN Port, Exiting. \n");
            return -1;
        }
        printf("Starting the Receiver task (-r) \n");
        receiver_task(canfd);
        closeCAN(canfd);
    /*}
    
    else
    {
        printf("Invalid argument, please follow the usage bellow. \n \n");
        help();
    }*/
    
    return 0;
}

