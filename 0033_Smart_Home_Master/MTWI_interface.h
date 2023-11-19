/*
 * MTWI_interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_
#define MTWI_READ 			1
#define MTWI_WRITE 			2

void MTWI_voidInit(void);

void MTWI_voidStart(void);

void MTWI_voidWriteAddressWithOrder(u8 Copy_u7SlaveAddress,u8 copy_u8ReadOrWrite);
void MTWI_voidWriteData(u8 Copy_u8Data);

u8 MTWI_u8ReadWithACK(void);

void MTWI_voidStop(void);

u8 MTWI_u8GetStatus(void);


#endif /* MTWI_INTERFACE_H_ */
