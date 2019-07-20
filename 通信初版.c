/*
数据包组成：
0x5A|0|data_len(int)|0|...|0x5F
*/
int *recieve_data(int *data,int len)
{

	static unsigned char state = 0;
	static unsigned char 

	unsigned char rec = ReadComData(0);

	switch(state)
	{
		case 0:
		{
			if(rec==0x5A)
			state=1;
		}
		break;
		case 1:
		{
			char index=0;
			while(rec!=0x5F)
			{
				*(data+index)=rec;
				index++;
			}
			if((index+1)==len)
			{
			state=2;
			}
			else ;

		}
		case 2:
		{
			return data;
		}
	}
	return 
}
