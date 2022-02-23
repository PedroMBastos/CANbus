#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#include "can_driver.h"
#define TAM 100

// Global variables
s_PORT Port = {
    "vcan0",
    "125K"};

void help(void)
{
    printf("**************************************************************\n");
    printf("*  Can_Ask                                                   *\n");
    printf("*                                                            *\n");
    printf("*  A simple example for PC. The Program implement two CAN    *\n");
    printf("*  nodes in diferent processes . A sender and a receiver.    *\n");
    printf("*  Both communicate together                                 *\n");
    printf("*                                                            *\n");
    printf("*   Usage:                                                   *\n");
    printf("*   ./CANAsk                                                 *\n");
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
        printf("%c", m->data[len]);
        len++;
        if (len < m->len)
        {
            printf(", ");
        }
    }
    printf(" ];\n");
}

void ask_task(CAN_HANDLE fd)
{
    
    Message msg = {0x0B, 0, 1, {1}};
    int number;
    while (1)
    {
        
        msg.data[0] = msg.data[0];
        printf("-a: Choose a number: ");
        scanf("%d", &number); 
        //msg.data[0]=number;
        if (number == (int)number) 
        { 
            //msg.data[0]=number;
            printf("The number is: %d", number);
            printf("\n \n");
            //current_timestamp();
            msg.data[0]=number;
            sendCAN(fd, &msg);
            sleep(1);
        }
        else
        {
            printf("Número Inválido \n");
        }
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
    
    //If it is to ask for a number
    
    /*else if (!strcmp(argv[1], "-a"))
    {*/
        canfd = openCAN(&Port);
        if (canfd == NULL)
        {
            printf("Error Openning the CAN Port, Exiting. \n");
            return -1;
        }
        printf("Starting the Asking task (-a) \n");
        ask_task(canfd);
        closeCAN(canfd);
    //}
    
    /*else
    {
        printf("Invalid argument, please follow the usage bellow. \n \n");
        help();
    }*/
    return 0;
}

