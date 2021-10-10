#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "asm/arch/lib/creator_pxa270_lcd.h"
#include "asm/arch/lib/def.h"
#include "creator_lib.h"


int main(int argc,char **argv){
	int fd,ret,a=3,b=10,c=0,d=11,e=6,f=10,g=11,h=10,bar=0,bar2=0,jum=0,jumpmode=0,j_c=0,point=0,pointt=0,twice=1;
	unsigned short key;
	lcd_write_info_t display;
	fd=open("/dev/lcd",O_RDWR);
	
	if(fd<0){
		printf("open /dev error\n");	
		return(-1);
	}
	while(1){
		//while(twice==1){
//a=3;b=10;c=0;d=11;e=6;f=10;g=11;h=10;bar=0;bar2=0;jum=0;jumpmode=0;j_c=0;point=0;pointt=0;twice=0;

		ioctl(fd,KEY_IOCTL_CHECK_EMTPY,&key);
		ioctl(fd,KEY_IOCTL_GET_CHAR,&key);

		/*display.Count=sprintf((char*)display.Msg, "%c", key&0xf);
		LCD_Cursor(fd,2,2);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);*/

		LCD_fClearScreen(fd);
		display.Count=sprintf((char*)display.Msg, "R");
		LCD_Cursor(fd,a,b);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);
		if( (key & 0xff) == '7'&& jumpmode==0){
			jumpmode=1;
			key=0xff;
			//ioctl(fd,KEY_IOCTL_CLEAR,key);
		}
		if(jum>=220 && jumpmode==1){
			if(j_c==0)
				b--;
			else {
				b++;
			}
			if(b==8){
				j_c=1;
				//jumpmode=0;
			}
			if(b==10){
				j_c=0;
				jumpmode=0;
				//key=0xff;
			}
			jum=0;
		}
		//Delay(1000)
		
		
		display.Count=sprintf((char*)display.Msg, "---------------");
		LCD_Cursor(fd,c,d);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);
		
		display.Count=sprintf((char*)display.Msg, "|");	
		LCD_Cursor(fd,e,f);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);
		if(bar==300){		
		e--;
		point++;
		if((point%10)==0){
		pointt++;
	        }	

		if(e==0){
		e=15;

		}
		bar=0;
		}

	


	ioctl(fd,_7SEG_IOCTL_ON,NULL);
	_7SEG_put_led(fd,_7SEG_ALL,0x00);
	_7SEG_put_led(fd,_7SEG_D7_INDEX,(pointt)%10);
	_7SEG_put_led(fd,_7SEG_D8_INDEX,(point)%10);

	
		if((pointt%10)==2&&(point%10)==0){
		display.Count=sprintf((char*)display.Msg, "W I N");	
		LCD_Cursor(fd,4,3);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);
/*	if( (key & 0xff) == '8'){
		a=3;b=10;c=0;d=11;e=6;f=10;g=11;h=10;bar=0;bar2=0;jum=0;jumpmode=0;j_c=0;point=0;pointt=0;
		key=0xff;
		continue;
}*/
		break;
}

	



		display.Count=sprintf((char*)display.Msg, "@");
		LCD_Cursor(fd,g,h);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);

		if(a==e&&b==f||a==g&&b==h){
		display.Count=sprintf((char*)display.Msg, "F A I L");	
		LCD_Cursor(fd,4,3);
		ret=ioctl(fd,LCD_IOCTL_WRITE,&display);
/*	if( (key & 0xff) == '8'){
		a=3;b=10;c=0;d=11;e=6;f=10;g=11;h=10;bar=0;bar2=0;jum=0;jumpmode=0;j_c=0;point=0;pointt=0;
		key=0xff;
		continue;
}*/
		break;
		
		}


		if(bar2==350){
		g--;
		if(g==0){
		g=15;
		}
		bar2=0;
		}
		bar++;		
		bar2++;


		if(jumpmode==1){
			jum++;
		}
}	
//}if



	close(fd);
	return 0;
}

