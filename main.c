#include <stdio.h>
#include <time.h>

void wait(int);

int main()
{
      int hours, minutes, seconds, s;
      time_t t;
      struct tm *tm;
       
      tm = localtime(&t);
      printf("Enter the amount of hours: ");
      scanf("%d", &hours);
      printf("Enter the amount of minutes: ");
      scanf("%d", &minutes);
      printf("Enter the number of seconds: ");
      scanf("%d", &seconds);
      s = seconds + (minutes*60) + (hours*60*60);

      while(s > 0)
      {
      	 tm->tm_sec = s%60;
     	 tm->tm_hour = (s/3600); 
     	 tm->tm_min = (s%3600)/60;
     	 printf("%02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
     	 s--;
     	 wait(1);
      }
      puts("Time is up!");
     
     
    return 0;
}

void wait(int sec)
{
     clock_t end_wait;
     end_wait = clock() + sec * CLOCKS_PER_SEC;
     while (clock() < end_wait){}
}
