#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[LFXO]
// [LFXO]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// [GPIO]$

// $[TIMER0]
// TIMER0 CC0 on PB01
#ifndef TIMER0_CC0_PORT                         
#define TIMER0_CC0_PORT                          gpioPortB
#endif
#ifndef TIMER0_CC0_PIN                          
#define TIMER0_CC0_PIN                           1
#endif

// TIMER0 CC1 on PA00
#ifndef TIMER0_CC1_PORT                         
#define TIMER0_CC1_PORT                          gpioPortA
#endif
#ifndef TIMER0_CC1_PIN                          
#define TIMER0_CC1_PIN                           0
#endif

// TIMER0 CC2 on PC04
#ifndef TIMER0_CC2_PORT                         
#define TIMER0_CC2_PORT                          gpioPortC
#endif
#ifndef TIMER0_CC2_PIN                          
#define TIMER0_CC2_PIN                           4
#endif

// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// USART0 RX on PA09
#ifndef USART0_RX_PORT                          
#define USART0_RX_PORT                           gpioPortA
#endif
#ifndef USART0_RX_PIN                           
#define USART0_RX_PIN                            9
#endif

// USART0 TX on PA08
#ifndef USART0_TX_PORT                          
#define USART0_TX_PORT                           gpioPortA
#endif
#ifndef USART0_TX_PIN                           
#define USART0_TX_PIN                            8
#endif

// [USART0]$

// $[I2C1]
// [I2C1]$

// $[EUSART1]
// EUSART1 CS on PC00
#ifndef EUSART1_CS_PORT                         
#define EUSART1_CS_PORT                          gpioPortC
#endif
#ifndef EUSART1_CS_PIN                          
#define EUSART1_CS_PIN                           0
#endif

// EUSART1 RX on PC02
#ifndef EUSART1_RX_PORT                         
#define EUSART1_RX_PORT                          gpioPortC
#endif
#ifndef EUSART1_RX_PIN                          
#define EUSART1_RX_PIN                           2
#endif

// EUSART1 SCLK on PC03
#ifndef EUSART1_SCLK_PORT                       
#define EUSART1_SCLK_PORT                        gpioPortC
#endif
#ifndef EUSART1_SCLK_PIN                        
#define EUSART1_SCLK_PIN                         3
#endif

// EUSART1 TX on PC01
#ifndef EUSART1_TX_PORT                         
#define EUSART1_TX_PORT                          gpioPortC
#endif
#ifndef EUSART1_TX_PIN                          
#define EUSART1_TX_PIN                           1
#endif

// [EUSART1]$

// $[EUSART2]
// [EUSART2]$

// $[LCD]
// [LCD]$

// $[KEYSCAN]
// [KEYSCAN]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[VDAC0]
// [VDAC0]$

// $[PCNT0]
// [PCNT0]$

// $[LESENSE]
// [LESENSE]$

// $[HFXO0]
// [HFXO0]$

// $[I2C0]
// [I2C0]$

// $[EUSART0]
// [EUSART0]$

// $[PTI]
// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

