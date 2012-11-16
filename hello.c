/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual
        
        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf       
*/

 
#define UART1_BASE 0xe0001000
#define UART1_TxRxFIFO0 ((unsigned int *) (UART1_BASE + 0x30))

volatile unsigned int * const TxRxFIFO0 = UART1_TxRxFIFO0;
	 
void print_uart1(const char *s) 
{
    while(*s != '\0') 
    {     /* Loop until end of string */
	 *TxRxFIFO0 = (unsigned int)(*s); /* Transmit char */
	 s++; /* Next char */
    }
}
	 
void c_entry() 
{
   print_uart1("Hello world!\n");
}