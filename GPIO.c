#include "GPIO.h" /*no se enlazan solos, por lo que tengo que ponerlo así porque las funciones necesitan su prototipo*/

#define ADIRECTION 0xB6014 /*Defino lo que debo sumarle a los GPIOs para llegar al PORT DATA DIRECTION REGISTER*/
#define BDIRECTION 0xB5054
#define CDIRECTION 0xB4094
#define DDIRECTION 0xB30D4
#define EDIRECTION 0xB2114
#define OFFSET 0x4

#define PDORA 0x400FF000 /*Defino los INPUTS y OUTPUTS direction register*/
#define PDIRA 0x400FF010
#define PDORB 0x400FF040
#define PDIRB 0x400FF050
#define PDORC 0x400FF080
#define PDIRC 0x400FF090
#define PDORD 0x400FF0C0
#define PDIRD 0x400FF0D0
#define PDORE 0x400FF100
#define PDIRE 0x400FF110

#define GPIO 0x100

int bgOutIN; /*Como no va a ser usada por el main la dejo aqui y no la pongo en el .h, si no en el .c del .h*/

void fnPinMODE (long dwPort,int bPin, int bOut_In)
{
long *dwpPort;
long *dwpPortDirection;

	bgOutIN = bOut_In;
	switch(dwPort)
	{
	case A:
		dwpPort = (long *) (dwPort + OFFSET*bPin); /*Se hace la suma para llegar al pin deseaso y activarlo como GPIO*/
		*dwpPort = GPIO;
		dwpPortDirection = (long *) (dwPort+ADIRECTION); /*Solo va cambiando lo que se le suma para llegar a DIRECTIONREGISTER*/
		*dwpPortDirection |= (bOut_In << bPin);
		break;
	case B:
		dwpPort = (long *) (dwPort + OFFSET*bPin);
		*dwpPort = GPIO;
		dwpPortDirection = (long *) (dwPort+BDIRECTION);
		*dwpPortDirection |= (bOut_In << bPin);
		break;
	case C:
		dwpPort = (long *) (dwPort + OFFSET*bPin);
		*dwpPort = GPIO;
		dwpPortDirection = (long *) (dwPort+CDIRECTION);
		*dwpPortDirection |= (bOut_In << bPin);
		break;
	case D:
		dwpPort = (long *) (dwPort + OFFSET*bPin);
		*dwpPort = GPIO;
		dwpPortDirection = (long *) (dwPort+DDIRECTION);
		*dwpPortDirection |= (bOut_In << bPin);
		break;
	case E:
		dwpPort = (long *) (dwPort + OFFSET*bPin);
		*dwpPort = GPIO;
		dwpPortDirection = (long *) (dwPort+EDIRECTION);
		*dwpPortDirection |= (bOut_In << bPin);
		break;
	default:
		dwpPort = (long *) dwPort;
		*dwpPort = GPIO;
		dwpPortDirection = (long *) (dwPort+BDIRECTION);
		*dwpPortDirection = 0;
	}
}

void fnDigitalwrite (long dwPortagain, int bPinagain, int bOn_Off)
{
long *dwpPortagain;
	switch(dwPortagain)
	{
	case A:
		if(bgOutIN == OUTPUT)
		{
			dwpPortagain = (long *)PDORA;
		  if(bOn_Off == 0)
		  {
			*dwpPortagain &= ~(1 << bPinagain);
		  }
		  if(bOn_Off == 1)
		  {
			*dwpPortagain |= (bOn_Off << bPinagain);
		  }
		}
			break;
	case B:
		if(bgOutIN == OUTPUT)
		{
			dwpPortagain = (long *)PDORB;
			  if(bOn_Off == 0)
			  {
				*dwpPortagain &= ~(1 << bPinagain); /*x and 1 es x y x and 0 es 0, Este es necesario para hacer mis apagados*/
			  }
			  if(bOn_Off == 1)
			  {
				*dwpPortagain |= (bOn_Off << bPinagain);
			  }
		}
			break;
	case C:
		if(bgOutIN == OUTPUT)
		{
			dwpPortagain = (long *)PDORC;
			  if(bOn_Off == 0)
			  {
				*dwpPortagain &= ~(1 << bPinagain);
			  }
			  if(bOn_Off == 1)
			  {
				*dwpPortagain |= (bOn_Off << bPinagain);
			  }
		}
			break;
	case D:
		if(bgOutIN == OUTPUT)
		{
			dwpPortagain = (long *)PDORD;
			  if(bOn_Off == 0)
			  {
				*dwpPortagain &= ~(1 << bPinagain);
			  }
			  if(bOn_Off == 1)
			  {
				*dwpPortagain |= (bOn_Off << bPinagain);
			  }
		}
			break;
	case E:
		if(bgOutIN == OUTPUT)
		{
			dwpPortagain = (long *)PDORE;
			  if(bOn_Off == 0)
			  {
				*dwpPortagain &= ~(1 << bPinagain);
			  }
			  if(bOn_Off == 1)
			  {
				*dwpPortagain |= (bOn_Off << bPinagain);
			  }
		}
			break;
	default:
		dwpPortagain = (long *)PDORA;
		*dwpPortagain = 0;
	}
}
