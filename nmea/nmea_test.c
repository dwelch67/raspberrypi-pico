
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char data[10000];
unsigned int dataoff;
unsigned int datalen;

unsigned int uart_recv ( void )
{
	if(dataoff>=datalen) exit(0);
	return(data[dataoff++]);
}

unsigned char new_time[6];
unsigned char last_time[6];
unsigned char new_valid;

void show_time ( void )
{
	unsigned int ra;
	for(ra=0;ra<6;ra++) printf("%u",new_time[ra]);
	printf("\n");
}

#include "nmea.c"

int main ( void )
{
	FILE *fp;
	
	dataoff=0;
	fp=fopen("nmea.log","rt");
	if(fp==NULL)
	{
		return(0);
	}
	datalen=fread(data,1,sizeof(data),fp);
	fclose(fp);
	if(datalen==0) return(1);
	printf("%u bytes\n",datalen);
	
	timezone=5;
	
	last_time[0]=0;
	last_time[1]=0;
	last_time[2]=0;
	last_time[3]=0;
	last_time[4]=0;
	last_time[5]=0;
	
	new_time[0]=0;
	new_time[1]=0;
	new_time[2]=0;
	new_time[3]=0;
	new_time[4]=0;
	new_time[5]=0;
	
	do_nmea();
	
	return(0);
}

