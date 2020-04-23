#include <GetSysTimeMs.h>
#include <SetThousandthS.h>
#include <GetCompassB.h>
#include <GetADUltraSound.h>
#include <GetADScable10.h>
#include <GetCompoI3.h>

#include <HardwareInfo.c>

#define COMPASS 	GetCompassB(_COMPASS_S_)

#define US_F 	GetADUltraSound(_ADULTRASOUND_F_)
#define US_L 	GetADUltraSound(_ADULTRASOUND_L_)
#define US_B 	GetADUltraSound(_ADULTRASOUND_B_)
#define US_R 	GetADUltraSound(_ADULTRASOUND_R_)

#define IR_T 			GetRemoIR(_FLAMEDETECT_T_)
#define IR_MAX_ID 		(GetCompoI3(_COMPOUNDEYE3_F_, 9) >= GetCompoI3(_COMPOUNDEYE3_B_, 9) 			\
                         ? GetCompoI3(_COMPOUNDEYE3_F_, 8) - 1 : GetCompoI3(_COMPOUNDEYE3_B_, 8) + 6)

#define ABS(x) 	((x) >= 0 ? (x) : (-x))

void demoInit()
{
	SysCom_Init(0, 115200, 0);
}

void updMot()
{
	static unsigned char state = 0;
	static unsigned char len = 0;
	static unsigned char chk = 0;
	static unsigned char recChk = 0;
	static unsigned char idx = 0;
	static unsigned char buf[16] = {};
	
	unsigned char rec = ReadComData(0);
	
	switch(state)
	{
		case 0:
		{
			if(rec == 0x5A)
				state = 1;
		}
		break;
		
		case 1:
		{
			len = rec;
			state = 2;
		}
		
		case 2:
		{
			recChk = rec;
			state = 3;
		}
		
		case 3:
		{
			if(idx < len)
			{
				buf[idx] = rec;
				idx++;
			}
			else
			{
				state = 4;
			}
		}
		
		case 4:
		{
			chk ^= 0x5A ^ len;
			
			for(int i = 0; i < len; i++)
				chk ^= buf[i];
			
			if(chk == recChk)
			{
				SetMotor(_MOTOR_FL_, ABS(buf[1] - 100), buf[1] >= 100 ? 2 : 0);
				SetMotor(_MOTOR_B_, ABS(buf[2] - 100), buf[2] >= 100 ? 2 : 0);
				SetMotor(_MOTOR_FR_, ABS(buf[3] - 100), buf[3] >= 100 ? 2 : 0);
			}
			
			state = 0;
			len = 0;
			chk = 0;
			recChk = 0;
			idx = 0;
		}
	}
	
	updMot();
	
	SetThousandthS(10);
}

void OM(float vel, float dir, float face)
{
	float buf[3] = {vel, dir, face};
	unsigned char chk = 0x5A ^ 0xC0 ^ 12;
	
	for(int i = 0; i < 12; i++)
		chk ^= ((unsigned char *)buf)[i];
	
	ComSendByte(0, 0x5A);
	ComSendByte(0, 0xC0);
	ComSendByte(0, 12);
	ComSendByte(0, chk);
	
	for(int i = 0; i < 12; i++)
		ComSendByte(0, ((unsigned char *)buf)[i]);
	
	SetThousandthS(10);
}

void OMT(float vel, float dir, float face, float time)
{
	unsigned long t = GetSysTimeMs();
	
	while(GetSysTimeMs() < t * 1000)
	{
		OM(vel, dir, face);
	}
	
	OM(0, 0, face);
}

void find(float vel, float face, unsigned char thr)
{
	static const dir[] = {150, 120, 90, 0, -90, -120, -150,
	                      -180, -210, -240, 90, 240, 210, 180};
	
	while(IR_T < thr)
	{
		OM(vel, dir[IR_MAX_ID], face);
	}
	
	OM(0, 0, face);
}

void demo()
{
	demoInit();
	
	OMT(0.5, 0.0, 0.0, 2.5);
}