#define SIM5  0x40048038
#define CLOCK_ON 0x3E00

#define A 0x40049000 /*Defino las direcciones donde debo declarar GPIOs*/
#define B 0x4004A000
#define C 0x4004B000
#define D 0x4004C000
#define E 0x4004D000

#define OUTPUT 1
#define INPUT 0
#define ON 1
#define OFF 0

extern void fnPinMODE (long dwPort, int bPin, int bOut_In);
extern void fnDigitalwrite (long dwPortagain, int bPinagain, int bOn_Off);

/*Si quisiera declarar una variable global seria con extern intx*/
