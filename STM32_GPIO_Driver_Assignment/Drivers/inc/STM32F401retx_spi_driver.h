/*
 * STM32F401retx_spi_driver.h
 *
 *  Created on: 10-Sept-2026
 *      Author: ADMIN
 */

#ifndef INC_STM32F401RETX_SPI_DRIVER_H_
#define INC_STM32F401RETX_SPI_DRIVER_H_

#include <stdint.h>
#include "STM32F401RE.h"

typedef struct
{
	uint8_t  SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_PinConfig_t;

typedef struct
{
	SPI_RegDef_t  *pSPIx;
	SPI_PinConfig_t  SPI_PinConfig;
	uint8_t *pTxBuffer;  /* !< To store the app. Tx buffer address > */
	uint8_t *pRxBuffer;
	uint32_t TxLen;/* !< To store Tx len > */
	uint32_t RxLen;
	uint8_t   TxState;	/* !< To store Tx state > */
	uint8_t RxState;	/* !< To store Rx state > */


}SPI_Handle_t;


#define SPI_DeviceMode_Slave     0
#define SPI_DeviceMode_Master    1

#define SPI_BusConfig_FD          0  //FULL DUPLEX
#define SPI_BusConfig_HD          1  //HALF DUPLEX
#define SPI_BUS_CONFIG_SIMPLEX_RX 2

#define SPI_DFF_8BITS           0
#define SPI_DFF_16BITS          1

#define SPI_CPOL_LOW            0
#define SPI_CPOL_HIGH           1

#define SPI_CPHA_FIRST_EDGE     0
#define SPI_CPHA_SECOND_EDGE    1

#define SPI_SSM_DI              0  // Hardware NSS
#define SPI_SSM_EN              1  // Software NSS


SPI_Init(SPI_Handle_t *pSPIHandle);

#endif /* INC_STM32F401RETX_SPI_DRIVER_H_ */
