void LCD_Init (void)  /* LCD Initialize function */
{
	LCD_Dir = 0xFF;		/* Make LCD port direction as o/p */
	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	
	LCD_Command(0x33);
	LCD_Command(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_Command(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);	/* Display on cursor off */
	LCD_Command(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_Command(0x01);	/* Clear display screen */
}
