   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Parser V4.11.5 - 29 Dec 2015
   3                     ; Generator (Limited) V4.4.4 - 27 Jan 2016
   4                     ; Optimizer V4.4.4 - 27 Jan 2016
  52                     ; 40 void main(void)
  52                     ; 41 {
  54                     .text:	section	.text,new
  55  0000               _main:
  59                     ; 43  GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  61  0000 4be0          	push	#224
  62  0002 4b08          	push	#8
  63  0004 ae500f        	ldw	x,#20495
  64  0007 cd0000        	call	_GPIO_Init
  66  000a 85            	popw	x
  67  000b               L12:
  68                     ; 48     GPIO_WriteReverse(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS);
  70  000b 4b08          	push	#8
  71  000d ae500f        	ldw	x,#20495
  72  0010 cd0000        	call	_GPIO_WriteReverse
  74  0013 aeffff        	ldw	x,#65535
  75  0016 84            	pop	a
  76                     ; 49     Delay(0xFFFF);
  78  0017 cd0000        	call	_Delay
  81  001a 20ef          	jra	L12
 115                     ; 54 void Delay(uint16_t nCount)
 115                     ; 55 {
 116                     .text:	section	.text,new
 117  0000               _Delay:
 119  0000 89            	pushw	x
 120       00000000      OFST:	set	0
 123  0001 2003          	jra	L54
 124  0003               L34:
 125                     ; 59     nCount--;
 127  0003 5a            	decw	x
 128  0004 1f01          	ldw	(OFST+1,sp),x
 129  0006               L54:
 130                     ; 57   while (nCount != 0)
 132  0006 1e01          	ldw	x,(OFST+1,sp)
 133  0008 26f9          	jrne	L34
 134                     ; 61 }
 137  000a 85            	popw	x
 138  000b 81            	ret	
 173                     ; 72 void assert_failed(u8* file, u32 line)
 173                     ; 73 { 
 174                     .text:	section	.text,new
 175  0000               _assert_failed:
 179  0000               L76:
 180  0000 20fe          	jra	L76
 193                     	xdef	_main
 194                     	xdef	_Delay
 195                     	xdef	_assert_failed
 196                     	xref	_GPIO_WriteReverse
 197                     	xref	_GPIO_Init
 216                     	end
