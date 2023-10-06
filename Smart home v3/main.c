/*
 * main.c
 *
 *  Created on: Jun 19, 2022
 *      Author: Eng Ahmed Tarek
 */

#include "STD_TYPES.h"
#include "MDIO_INTERFACE.h"
#include "HLCD_Interface.h"
#include "MURT_Interface.h"
#include "MGIE_Interface.h"
#include "MTimer_Interface.h"
#include "MADC_Interface.h"
#include "Smart_Home_Private.h"
#include <avr/delay.h>
u8 Login_Trial=False;
u8 Door_State=Closed;
u8 Login_state=OUT;
u8 Data=0;
int main(void)
{
	/*Super Loop*/
	while(1)
	{
		/*Login */
	while(!Login_Trial)
	{
MDIO_VoidSetPinDirection(PORTA,PIN7,OUTPUT);
MDIO_VoidSetPinValue(PORTA,PIN7,HIGH);

/*Password & ID */
	u8 *IDTrue[3]={0};
	u8 *PassTrue[3]={0};
/*Initialize Peripherals*/

URT_Init();
HLCD_VoidInit();
MADC_voidInit();
/*TIM0 Init*/
TIM0_Init();
u8 ID=0;
u8 Pass=0;

/*Password Check Function*/
void Pass_Check(void)
{
	Pass=0;

	HLCD_VoidSendCommand(0x01);
	HLCD_VoidSetPostion(0,0);
	HLCD_VoidSendString("Password:");
	for(u8 i=0;i<=3;i++)
	{
		/*Get Password From User*/
		Pass=URT_Recevier();
        URT_Transmitte(PassTrue[i]);
        /*Display Password On LCD*/
        HLCD_VoidSendChar('*');
        /*Store Password In Array*/
        PassTrue[i]=Pass;
	}
}

/*ID Check Function*/
void ID_CHECK(void)
{
	ID=0;
	HLCD_VoidSendCommand(0x01);
	HLCD_VoidSetPostion(0,0);
	HLCD_VoidSendString("ID:");
	for(u8 i=0;i<=3;i++)
	{
		/*Get ID From User*/
		ID=URT_Recevier();
        URT_Transmitte(IDTrue[i]);
        /*Display ID On LCD*/
        HLCD_VoidSendChar(ID);
        /*Store ID In Array*/
        IDTrue[i]=ID;
	}
}
/*Go To ID Check Function*/

u8 y=0;
u8 Pas=0;
for(y=0;y<3;y++)
{
		/*If Correct ID*/
	if(IDTrue[0]=='3'&&IDTrue[1]=='0'&&IDTrue[2]=='0'&&IDTrue[3]=='0')
	{
		y=4; //For Exit For Loop
		HLCD_VoidSendCommand(0x01);
		HLCD_VoidSetPostion(0,0);
		/*Go To Pass Check Function*/
		Pass_Check();

		for(Pas=0;Pas<3;Pas++)
		{
				/*If Correct Password*/
			if(PassTrue[0]=='1'&&PassTrue[1]=='0'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
			{
				Login_Trial=True;
				Pas=4; //For Exit For Loop
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidSetPostion(0,4);
				HLCD_VoidSendString("Hello");
				Login_state=IN;
			}

				/*If Incorrect Password*/
				else if(Pas<3)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong Pass Try Again");
					_delay_ms(1000);
					/*Go To Pass Check Function*/
					Pass_Check();
				}
				/*If Incorrect Password*/
				else if(Pas==3)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong Pass ");
					_delay_ms(1000);
					MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
					HLCD_VoidSendCommand(0x01);
				}
		}
	}
	else if(IDTrue[0]=='2'&&IDTrue[1]=='0'&&IDTrue[2]=='0'&&IDTrue[3]=='0')
		{
			y=4; //For Exit For Loop
			HLCD_VoidSendCommand(0x01);
			HLCD_VoidSetPostion(0,0);
			/*Go To Pass Check Function*/
			Pass_Check();

			for(Pas=0;Pas<3;Pas++)
			{
					/*If Correct Password*/
				if(PassTrue[0]=='1'&&PassTrue[1]=='2'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
				{
					Login_Trial=True;
					Pas=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,4);
					HLCD_VoidSendString("HELLO");
					Login_state=IN;
				}


					/*If Incorrect Password*/
					else if(Pas<3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass Try Again");
						_delay_ms(1000);
						/*Go To Pass Check Function*/
						Pass_Check();
					}
					/*If Incorrect Password*/
					else if(Pas==3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass ");
						_delay_ms(1000);
						MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
						HLCD_VoidSendCommand(0x01);
					}
			}
		}
	else if(IDTrue[0]=='3'&&IDTrue[1]=='0'&&IDTrue[2]=='0'&&IDTrue[3]=='0')
		{
			y=4; //For Exit For Loop
			HLCD_VoidSendCommand(0x01);
			HLCD_VoidSetPostion(0,0);
			/*Go To Pass Check Function*/
			Pass_Check();

			for(Pas=0;Pas<3;Pas++)
			{
					/*If Correct Password*/
				if(PassTrue[0]=='1'&&PassTrue[1]=='1'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
				{
					Login_Trial=True;
					Pas=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,4);
					HLCD_VoidSendString("HELLO");
					Login_state=IN;
				}


					/*If Incorrect Password*/
					else if(Pas<3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass Try Again");
						_delay_ms(1000);
						/*Go To Pass Check Function*/
						Pass_Check();
					}
					/*If Incorrect Password*/
					else if(Pas==3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass ");
						_delay_ms(1000);
						MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
						HLCD_VoidSendCommand(0x01);
					}
			}
		}

			/*If Incorrect ID*/
			else if(y<3)
			{


				HLCD_VoidSendCommand(0x01);
				HLCD_VoidSendString("Wrong ID Try Again");
				_delay_ms(1000);
				/*Go To ID Check Function*/
				ID_CHECK();

			}
			/*If Incorrect ID*/
			if(y==2)
			{
				Login_Trial=True;
				HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong ID ");
					_delay_ms(1000);
					/*Turn Off LCD */
					MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
					HLCD_VoidSendCommand(0x01);

			}
		}
}

		/*While ID & Password Correct*/
	while(Login_state)
	{
		/*Display Options On LCD*/

		_delay_ms(2000);
		HLCD_VoidSendCommand(0x01);
		HLCD_VoidSetPostion(0,0);
		HLCD_VoidSendString("a:O/D");
		HLCD_VoidSetPostion(0,7);
		HLCD_VoidSendString("b:C/D");
		HLCD_VoidSetPostion(1,0);
		HLCD_VoidSendString("c:Temp");
		HLCD_VoidSetPostion(1,7);
		HLCD_VoidSendString("d:LED");
		HLCD_VoidSetPostion(1,14);
		HLCD_VoidSendString("<");



		Data=URT_Recevier();
		if(Data=='a')
		{
			if(Door_State==Closed)
			{
				MDIO_VoidSetPinDirection(PORTB,3,OUTPUT);
			HLCD_VoidSendCommand(0x01);
			URT_SendString("Motor Left");
			HLCD_VoidSetPostion(0,0);
			HLCD_VoidSendString("Open Door");
			TIM0_FastPWM_Set_DutyCycle(13);
			Door_State=Open;

			}
			else if(Door_State==Open)
			{
				HLCD_VoidSendCommand(0x01);
							HLCD_VoidSetPostion(0,0);
							HLCD_VoidSendString("Door Already Open");
			}

		}

		else if(Data=='b')
		{
			if(Door_State==Open)
			{
				MDIO_VoidSetPinDirection(PORTB,3,OUTPUT);
			HLCD_VoidSendCommand(0x01);
			URT_SendString("Motor Right");
			HLCD_VoidSetPostion(0,0);
			HLCD_VoidSendString("Close Door");
			TIM0_FastPWM_Set_DutyCycle(75);
			Door_State=Closed;



			}
			else if(Door_State==Closed)
			{
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidSetPostion(0,0);
				HLCD_VoidSendString("Door Already Closed");
			}


		}
		else if(Data=='c')
		{
			  u32 Digital;

				 u16 milivolt;
				Digital= MADC_ReadData(0);
				milivolt=(Digital*5000UL)/1024UL;
				u32 temp=milivolt/10;
				HLCD_VoidSendNumber(temp);
				 HLCD_VoidSendString ("C");
				_delay_ms(3000);
				HLCD_VoidSendCommand(0b00000001);
		}


		else if(Data=='d')
				{
					HLCD_VoidSendCommand(0x01);
					MDIO_VoidSetPinDirection(PORTA,PIN0,OUTPUT);
					MDIO_VoidTogglePin(PORTA,PIN0);
					HLCD_VoidSetPostion(0,0);
					HLCD_VoidSendString("LED:ON/Off");

				}

		else if(Data=='<')
		{
			Login_state=OUT;
			Login_Trial=False;
		}

	} //End Program

} //End Super Loop
	return 0;
} //End Main
