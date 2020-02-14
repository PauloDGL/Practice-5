#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "GPIO.h" /*Biblioteca donde se encuentran las funciones para habilitar puertos como GPIOs*/
#include "contador.h" /*Biblioteca donde se encuentra la función para realizar el BOUNCING*/
#include "ADC.h" /*Biblioteca donde se encuentra la función para configurar y usar el ADC*/

#define CONVERSION_ADC 0x4003b010 /*Es la dirección de memoria donde se guarda el resultado de la conversión del ADC*/
#define SEGUNDOS 30 /*Aqui indica durante cuántos segundos desea observar si es mayor a 40°C la temperatura*/
#define CUARENTAGRADOS  56440 /*56440 es el número que da el ADC para 400 mV, y sabiendo que mi LM35
                               por cada 1°C a su salida da 10 mV, en 40°C serían 400 mV por lo que
                               se toma el número 56440 como 40°C*/

void fnSegundo (void); /*Función donde se tiene el delay de 1 segundo*/
long *dwgpLeerboton; /*Apuntador para ver cuándo esta presionado o no el botón*/
long *dwgpClockenabled; /*Apuntador para habilitar los relojes de los puertos*/

int main(void)
{
int bContador; /*Variable para hacer la cuenta de los 30 segundos*/
long *dwpResultado; /*Apuntador para guardar el resultado de la conversión hecha por el ADC*/

	dwgpClockenabled = (long *) SIM5;
	*dwgpClockenabled = CLOCK_ON; /*Se da la habilitacion de todos los relojes*/
	dwgpLeerboton = (long *) BOTON; /*Con este apuntador voy a leer mi botón cuando este sea presionado*/
    fnPinMODE (B, 0, INPUT); /*Declaración de mis salidas y entradas*/
	fnPinMODE (D, 0, OUTPUT);
    fnPinMODE (D, 1, OUTPUT);
    fnPinMODE (D, 2, OUTPUT);
    fnPinMODE (D, 3, OUTPUT);
    fnADC(); /*Entra a la función del ADC para configurarlo*/
	dwpResultado = (long *) CONVERSION_ADC; /*Se apunta a la dirección de memoria donde esta el resultado*/

while(1)
{
	fnSegundo(); /*Es un delay que dura 1 segundo, por lo tanto cada segundo se toma una muestra de información de la TEMPERATURA*/

	if(*dwpResultado >= CUARENTAGRADOS)
	{
		bContador++; /*Se va sumando de uno en uno al contador hasta llegar a las muestras necesarias para entrar al BOUNCING*/

		if(bContador >= SEGUNDOS) /*Una vez que mi programa ha tomado las muestras necesarias entra a esta condicón*/
		{
		fnContador();  /*Donde se va a llevar a cabo la secuencia de Bouncing*/
		bContador = 0; /*Al salirse del bouncing con el botonazo, se reinicia el contador*/
		}
	}
	else
	{
		fnDigitalwrite (D, 1, ON); /*Si no esta a más de 40°C solamente se queda prendido el led rojo*/
		bContador = 0; /*El contador se mantiene en 0 si no hay ninguna muestra mayor o igual a 40°C*/
	}
}

return 0;
}

void fnSegundo (void)
{
long dwDelay = 925926;

	for (long dwCuenta=0; dwCuenta < dwDelay; dwCuenta++) /*Realiza una cuenta hasta 925926, que es igual a esperar un segundo*/
		dwCuenta += 1;

return;
}



