void main(){
int LDR;
int x;
char z;
ANSELA=0xFF;
ANSELC=0;
ANSELD=0;

TRISA=0xFF;
TRISD=0;

UART1_Init(9600);
Delay_ms(100);
while(1){

LDR=ADC_Read(1);

if (LDR<=5000 && LDR>2700){

UART1_Write_Text("The room is very bright");

UART1_Write(13);
UART1_Write(10);
Delay_ms(1000);
UART1_Write_Text("Press a to return to the optimum light intensity");

UART1_Write(13);
UART1_Write(10);
Delay_ms(1000);

if (UART_Data_Ready()) {
z=UART_Read();

switch (z){
case 'H':PORTD=0b01111110;break;
case 'V':PORTD=0xFF;break;
case 'L':PortD=0b00011000 ;break;
case 'D':PORTD=0x00;break;
case 'N':PORTD=0b00111100;break;
default:PORTD=0x00;
} 

}
}
 
 if (LDR<=2700 && LDR>1000){

UART1_Write_Text("The room is bright");

UART1_Write(13);
UART1_Write(10);
Delay_ms(1000);
UART1_Write_Text("Press a to return to the optimum light intensity");

UART1_Write(13);
UART1_Write(10);
 Delay_ms(1000);

if (UART_Data_Ready()) {
z=UART_Read();

switch (z){
case 'H':PORTD=0b01111110;break;
case 'V':PORTD=0xFF;break;
case 'L':PortD=0b00011000 ;break;
case 'D':PORTD=0x00;break;
case 'N':PORTD=0b00111100;break;

default:
PORTD=0b01010101;
      }

}

}

 if (LDR>=0 && LDR<1000){

UART1_Write_Text("The room is dark");

UART1_Write(13);
UART1_Write(10);
Delay_ms(1000);
UART1_Write_Text("Press a to return to the optimum light intensity");

UART1_Write(13);
UART1_Write(10);
Delay_ms(1000);
if (UART_Data_Ready()) {
z=UART_Read();

switch (z){
case 'H':PORTD=0b01111110;break;
case 'V':PORTD=0xFF;break;
case 'L':PortD=0b00011000 ;break;
case 'D':PORTD=0x00;break;
case 'N':PORTD=0b00111100;break;
default:
PORTD=0xFF;
      }
}

Delay_ms(2000);
}        

}   }