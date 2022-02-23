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
    printf("*  Can_Database                                              *\n");
    printf("*                                                            *\n");
    printf("*  A simple example for PC. The Program implement two CAN    *\n");
    printf("*  nodes in diferent processes . A sender and a receiver.    *\n");
    printf("*  Both communicate together                                 *\n");
    printf("*                                                            *\n");
    printf("*   Usage:                                                   *\n");
    printf("*   ./CanDatabase                                            *\n");
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
        printf("%c", m->data[len]);
        len++;
        if (len < m->len)
        {
            printf(", ");
        }
    }
    printf(" ];\n");
}

struct CANDatabase_elem 
{
   char  id;
   char  mensagem[8];
};

struct CANDatabase_elem CANDatabase[TAM];

char searchID(struct CANDatabase_elem *CANDatabase, char Id_to_search)
{
    int i;

	for(i=0;i < TAM; i++)
	{
		if(CANDatabase[i].id == Id_to_search)
			return i;
	}
	return -1; //ID não encontrado
}

void data_task(CAN_HANDLE fd)
{
    //Message msg = {Arbitration Field, Control Field, Data, {CRC Field}}
    Message msg = {0x0C, 0, 8, {1}};
    
    int Id_to_search;

    while (1)
    {
        //msg.data[0] = msg.data[0] ;
        printf("-d: Message ID: ");
        scanf("%d", &Id_to_search);  
        strcpy(msg.data,CANDatabase[Id_to_search].mensagem);  
        printf("The message is: %d", Id_to_search);
        printf("\n \n");
        sendCAN(fd, &msg);
        sleep(1);
    }
}

int main(int argc, char **argv)
{
    CANDatabase[0].mensagem[0] = '0';
    CANDatabase[0].mensagem[1] = '1';
    CANDatabase[0].mensagem[2] = '2';
    CANDatabase[0].mensagem[3] = '3';
    CANDatabase[0].mensagem[4] = '4';
    CANDatabase[0].mensagem[5] = '5';
    CANDatabase[0].mensagem[6] = '6';
    CANDatabase[0].mensagem[7] = '7';

    CANDatabase[1].mensagem[0] = '8';
    CANDatabase[1].mensagem[1] = '9';
    CANDatabase[1].mensagem[2] = 'A';
    CANDatabase[1].mensagem[3] = 'B';
    CANDatabase[1].mensagem[4] = 'C';
    CANDatabase[1].mensagem[5] = 'D';
    CANDatabase[1].mensagem[6] = 'E';
    CANDatabase[1].mensagem[7] = 'F';
    
    CANDatabase[2].mensagem[0] = 'G';
    CANDatabase[2].mensagem[1] = 'H';
    CANDatabase[2].mensagem[2] = 'I';
    CANDatabase[2].mensagem[3] = 'J';
    CANDatabase[2].mensagem[4] = 'K';
    CANDatabase[2].mensagem[5] = 'L';
    CANDatabase[2].mensagem[6] = 'M';
    CANDatabase[2].mensagem[7] = 'N';
    
    CANDatabase[3].mensagem[0] = 'O';
    CANDatabase[3].mensagem[1] = 'P';
    CANDatabase[3].mensagem[2] = 'Q';
    CANDatabase[3].mensagem[3] = 'R';
    CANDatabase[3].mensagem[4] = 'S';
    CANDatabase[3].mensagem[5] = 'T';
    CANDatabase[3].mensagem[6] = 'U';
    CANDatabase[3].mensagem[7] = 'V';
    
    CANDatabase[4].mensagem[0] = 'W';
    CANDatabase[4].mensagem[1] = 'X'; 
    CANDatabase[4].mensagem[2] = 'Y';
    CANDatabase[4].mensagem[3] = 'Z';
    CANDatabase[4].mensagem[4] = '0';
    CANDatabase[4].mensagem[5] = '0';
    CANDatabase[4].mensagem[6] = '0';
    CANDatabase[4].mensagem[7] = '0';

    CAN_HANDLE canfd = NULL;
    
    /*if (argc < 2)
    {
        help();
        return 0;
    }*/
    
    //If it is to search the message
    
    /*else if (!strcmp(argv[1], "-d"))
    {*/
        canfd = openCAN(&Port);
        if (canfd == NULL)
        {
            printf("Error Openning the CAN Port, Exiting. \n");
            return -1;
        }
        printf("Starting the data task (-d) \n");
        data_task(canfd);
        closeCAN(canfd);
    /*}
    
    else
    {
        printf("Invalid argument, please follow the usage bellow. \n \n");
        help();
    }*/
    
    return 0;
}
