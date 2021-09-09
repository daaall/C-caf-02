#include <stdio.h>
#include <time.h>

typedef struct tm tm;

int main (){
	time_t temps;
	time(&temps);
	printf("la date daujourdui est : %s \n",ctime(&temps));
	
	time_t date;
	tm temps1;
	date=time(NULL);
	temps1= *localtime(&date);
	printf("%d-%d-%d %d:%d:%d ",temps1.tm_year+1900,temps1.tm_mon+1,temps1.tm_mday,temps1.tm_hour,temps1.tm_min,temps1.tm_sec);
	
}
