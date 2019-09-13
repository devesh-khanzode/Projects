#include<reg51.h>
sbit ldr=P1^0;
sbit light=P2^0;
sbit power=P2^1;
char countout=0,countin=0;
char count1=0;
void delay(unsigned int count) //Function to provide delay
{
int i,j;
for(i=0;i<count;i++)
for(j=0;j<1275;j++);
}
void IR1()  interrupt 0
 {
	 IE=0x00;
	 
	 if(countout==1)
	 {
		 count1--;
	 delay(50);
	 }
	 else
		 countin=1;
	 countout=0;
	 IE=0x85;
 }
void IR2()  interrupt 2
 {
	 IE=0x00;
	 if(countin==1)
	 {
		 count1++;
	 delay(50);
	 }
	 else
		 countout=1;
	 countin=0;
	 IE=0x85;
 }
void main()
{
	ldr=0;
IE=0x85;
while(1)
{
while(count1<=0)
{	light=0;
power=0;
}

power=1;
if(ldr==1)
light=0;
else
light=1;


}
}