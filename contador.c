#include "contador.h"
#include "GPIO.h"

extern long *dwgpLeerboton;

void fnContador(void)
{
int bEstado=0;
while (1)
{
	if(*dwgpLeerboton == 0)
	{
		if(bEstado<=6)
		{
			fnDelay();
 			fnBouncing(bEstado);
		}
		else
		{
			bEstado=0;
		}
		bEstado++;
	}
	else if(*dwgpLeerboton == 1)
	{
		fnDigitalwrite (D, 0, ON);
		fnDelay();
		fnDigitalwrite (D, 1, ON);
		fnDelay();
		fnDigitalwrite (D, 2, ON);
		fnDelay();
		fnDigitalwrite (D, 3, ON);
		fnDelay();
		fnDigitalwrite (D, 0, OFF);
		fnDelay();
		fnDigitalwrite (D, 1, OFF);
		fnDelay();
		fnDigitalwrite (D, 2, OFF);
		fnDelay();
		fnDigitalwrite (D, 3, OFF);
		{break;} /*Para salirme del ciclo while(1) y regresarme a contar*/
	}
}
}

void fnBouncing(int bEstado)
{
 	if(bEstado <= 6)
 	{
 		if(bEstado == 1)
 		{
 		fnDigitalwrite (D, 0, ON);
 		fnDigitalwrite (D, 1, OFF);
 		}
 		else if (bEstado == 2)
 		{
 		fnDigitalwrite (D, 1, ON);
 		fnDigitalwrite (D, 0, OFF);
 		}
 		else if (bEstado == 3)
 		{
 		fnDigitalwrite (D, 2, ON);
 		fnDigitalwrite (D, 1, OFF);
 		}
 		else if (bEstado == 4)
 		{
 		fnDigitalwrite (D, 3, ON);
 		fnDigitalwrite (D, 2, OFF);
 		}
 		else if (bEstado == 5)
 		{
 		fnDigitalwrite (D, 2, ON);
 		fnDigitalwrite (D, 3, OFF);
 		}
 		else if (bEstado == 6)
 		{
 		fnDigitalwrite (D, 1, ON);
 		fnDigitalwrite (D, 2, OFF);
 		}
 	}
}

void fnDelay()
{
	long dwDelay = 200000;

	for (long dwCuenta=0; dwCuenta < dwDelay; dwCuenta++)
		dwCuenta += 1;
}


