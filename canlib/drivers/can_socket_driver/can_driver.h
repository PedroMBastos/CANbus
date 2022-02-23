/*
This file is part of CanFestival, a library implementing CanOpen Stack.

Copyright (C): Edouard TISSERANT and Francis DUPIN

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __can_driver_h__
#define __can_driver_h__

#define Message_Initializer             \
  {                                     \
    0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } \
  }

struct struct_s_PORT;

typedef struct struct_s_PORT s_PORT;
typedef void *CAN_HANDLE;

/**
 * @brief The CAN board configuration
 * @ingroup can
 * This structure is used to store the information about the 
 * port and baudrate. Used in openCAN function.
 * Usage - s_PORT Port= {"vcan0", "125K"};
 * 
 */

struct struct_s_PORT
{
  char *busname;  /**< The bus name on which the CAN board is connected */
  char *baudrate; /**< The board baudrate */
};

/** 
 * @brief The CAN message structure 
 * @ingroup can
 * This structure is used to store a new CAN message received or to prepare a new message
 * to be sent. Used in sendCAN and receiveCAN functions
 * Usage for this example- Message msg = {12,0,4,{1,2,3,4}};
 *       the values are: cob_id = 0x12;
 *                       rtr = 0;
 *                       len = 4;
 *                       data = {0x01,0x02,0x03,0x04} 
 */
typedef struct
{
  u_int16_t cob_id; /**< message's ID */
  u_int8_t rtr;     /**< remote transmission request. (0 if not rtr message, 1 if rtr message) */
  u_int8_t len;     /**< message's length (0 to 8) */
  u_int8_t data[8]; /**< message's datas */
} Message;

/**
 * @brief Receive a new CAN Message
 *
 * This function is used to pull a new message received on the CAN bus.
 * If the return of the function is succesful, the new message can be readed through Message object.
 * @param CAN_HANDLE object with the information about the opened CAN port;
 * @param Message *  pointer to a message to be received;
 * @return 0 if message received; 1 otherwise
 */
u_int8_t receiveCAN(CAN_HANDLE, Message *);

/**
 * @brief Send a new CAN Message
 *
 * This function is used to send a new message to the CAN bus.
 * If the return of the function is succesful, the new message was succefuly sent.
 * @param CAN_HANDLE object with the information about the opened CAN port;
 * @param Message *  pointer to a message to be send;
 * @return 0 if message sent; 1 otherwise
 */
u_int8_t sendCAN(CAN_HANDLE, Message const *);

/**
 * @brief Open a CAN socket Port
 *
 * This function is used to open a CAN socket port.
 * If the return of the function is succesful, the new message was succefuly sent.
 * @param s_PORT * object with the information about the CAN socket port;
 * @return CAN_HANDLE if socket is open succefully; NULL otherwise
 */
CAN_HANDLE openCAN(s_PORT *);

/**
 * @brief Close a CAN socket Port
 *
 * This function is used to close the CAN socket port.
 * If the return of the function is succesful, the new message was succefuly sent.
 * @param s_PORT * object with the information about the CAN socket port;
 * @return 0 if message sent; 1 otherwise
 */
u_int8_t closeCAN(CAN_HANDLE);

/**
 * @brief Change CAN Baudrate (Still not implemented)
 *
 * @param CAN_HANDLE object with the information about the opened CAN port;
 * @param char *  new baudrate
 * @return 0 if message sent; 1 otherwise
 */
u_int8_t canChangeBaudRate(CAN_HANDLE, char *);

#endif
