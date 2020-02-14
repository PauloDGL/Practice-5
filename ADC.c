#include "ADC.h"
#include "MKL27Z644.h"
#include "GPIO.h"

void fnADC (void)
{
	SIM -> SCGC6 |= SIM_SCGC6_ADC0(ON); /*Activo el reloj para el ADC*/
	PORTE->PCR[20] |= PORT_PCR_MUX(OFF); /*Activo el Puerto E20 como opción de ADC*/
	ADC0 -> CFG1 |=  ADC_CFG1_ADLPC(OFF); /*Indico que mi ADC estará en configuración de poder normal*/
	ADC0 -> CFG1 |=  ADC_CFG1_ADIV(0b00); /*Indico que voy a dividir mi reloj de ADC por 1*/
	ADC0 -> CFG1 |=  ADC_CFG1_ADLSMP(0b00); /*Indico que mi ADC va a tomar muestras en un periodo de tiempo corto*/
	ADC0 -> CFG1 |=  ADC_CFG1_MODE(0b11); /*Indico que mi ADC sera de 16-bits*/
	ADC0 -> CFG1 |=  ADC_CFG1_ADICLK(0b00); /*Indico que usaré para mi ADC el Bus CLOCK*/
	ADC0 -> CFG2 |= ADC_CFG2_MUXSEL(OFF); /*Selecciono el canal a del ADC*/
	ADC0 -> CFG2 |= ADC_CFG2_ADHSC(OFF); /*Selecciono el modo de conversión de datos normal*/
	ADC0 -> CFG2 |= ADC_CFG2_ADLSTS(0b00); /*Selecciono el tiempo de muestro que tiene por defecto el ADC*/
	ADC0->SC2 &=ADC_SC2_ACFE(OFF); /*Desactivo la función de comparación del ADC*/
	ADC0->SC3 |= ADC_SC3_ADCO(ON); /*Activo la conversión de datos de manera continua*/
	ADC0 ->SC1[0] &= ADC_SC1_AIEN(OFF); /*Desactivo la interrupción que se da cuando es completada una interrupción*/
	ADC0 ->SC1[0] |= ADC_SC1_DIFF(OFF) ; /*Indico que mi ADC me entregará conversiones de un solo extremo*/
	ADC0 -> SC1[0] &= ADC_SC1_ADCH(0b00000); /*Selecciono el DADP0 como mi canal de entrada*/
}


