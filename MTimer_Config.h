                       /************************************************************************
 						**               Created on: Dec 5, 2021                              **
                        **                Author: Ahmed Tarek                                 **           
						**                File Name : MTIMER_CONFIG                           **
						**                 V 1.1                                              **
						**         Description:Timer 0 Configruation                          **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/




#ifndef MTIMER_CONFIG_H
#define MTIMER_CONFIG_H

/**********************************************************/
/**********************************************************/
/***********Author: Abdallah Taha**************************/     
/***********File Name : MTIMER_CONFIG**********************/     
/***********Description:Select TIMER Mode *****************/
/***********NORMAL_MODE = 0  , CTC_MODE=1 *****************/
/***********    PWM_MODE = 2   ****************************/
/**********************************************************/
/**********************************************************/

#define TIMER0_MODE PWM_MODE

/**********************************************************/
/**********************************************************/
/***********Author: Abdallah Taha**************************/     
/***********File Name : MTIMER_CONFIG**********************/     
/***********Description:Select Prescalling ****************/
/***********No_Clock_Source = 0 , No_prescaling=1 *********/
/***********DIV_8 = 2 ,DIV_64=3 ,DIV_256=4  ***************/
/***********DIV_1024 = 5 ,Falling_Edge=6 ,Rising_Edge=7****/
/**********************************************************/
/**********************************************************/

#define TIMER0_PRESCALLING DIV_256

/**********************************************************/
/**********************************************************/
/***********Author: Abdallah Taha**************************/     
/***********File Name : MTIMER_CONFIG**********************/     
/***********Description:Select TIMER_OV_INTERRUPT *********/
/***********DISABLE = 0  , ENABLE=1 ***********************/
/**********************************************************/
/**********************************************************/

#define TIMER0_OV_INTERRUPT DISABLE 

/**********************************************************/
/**********************************************************/
/***********Author: Abdallah Taha**************************/     
/***********File Name : MTIMER_CONFIG**********************/     
/***********Description:Select Compare Mode ***************/
/***********Normal_Port= 1 , Toggle_OC0=2 *****************/
/***********Clear_OC0=3 , Set_OC0=4 ***********************/
/**********************************************************/
/**********************************************************/

#define TIMER0_COMPARE_MODE Clear_OC0

/**********************************************************/
/**********************************************************/
/***********Author: Abdallah Taha**************************/     
/***********File Name : MTIMER_CONFIG**********************/     
/***********Description:Select TIMER_CTC_INTERRUPT *********/
/***********DISABLE = 0  , ENABLE=1 ***********************/
/**********************************************************/
/**********************************************************/

#define TIMER0_CTC_INTERRUPT DISABLE 


#endif
