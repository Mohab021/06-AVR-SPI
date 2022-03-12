
#include <avr/io.h>
#include "AVR_Ports.h"
#include "AVR_GPIO_Declarations.h"
#include "AVR_SPI_Declarations.h"
#define F_CPU 4000000ul

int main(void)
{
	Pin_Direction(A, 0, input);
	SPI_Master_INT();
	
	while(1)
	{
		if( !(Pin_Read(A, 0)) )
		{
			SPI_Transmit('1');
			
			while( !(Pin_Read(A, 0)) ) ;
		}
	}
}

