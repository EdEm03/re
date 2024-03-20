#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int Measurement(int **Values)
{

        time_t currentTime;
        time(&currentTime);

        struct tm *localTime = localtime(&currentTime);

        int x=0;
        
        int lefutas=100;

        int minute = localTime->tm_min;
        int second = localTime->tm_sec;

        if((minute%15)*60+second>100)
        lefutas=(minute%15)*60+second;

	(*Values)[0] = 0;

    for (int i = 1; i < lefutas; i++)
    {
        double randomNum = (double)rand() / RAND_MAX;  // Random lebegőpontos szám 0 és 1 között

        if (randomNum < 0.428571)
            (*Values)[i] = (*Values)[i - 1] + 1;
        else if (randomNum < 0.857142)
            (*Values)[i] = (*Values)[i - 1] - 1; 

    }
    
    return 0;
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    if (argc > 1) {
        

        time_t currentTime;
        time(&currentTime);
        struct tm *localTime = localtime(&currentTime);
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;
        int *olvasasok=(int *)malloc(((minute%15)*60+second) * sizeof(int));


        if (strcmp(argv[1], "--version") == 0) {
            printf("0.1\n2024.02.23.\nKeszito: EdEm\n");
        } else if (strcmp(argv[1], "--help") == 0) {
            printf("Hazsnalhato parancssori argumentumok: \n"
                   "--version - a Jelenlegi verzio leirasa\n"
                   "--help - hasznalhato parancssori argumentuomok\n"
                   "-send vagy -receive - A program uzemmod megadasa, alapertelmezett -send\n"
                   "-file vagy -socket - A kommunikacio mod megadasa, -file az alapertelmezett.\n");
        } else if (strcmp(argv[1], "-send") == 0) {

            printf("A program uzemmodja: send\n");

            for (int i = 0; i < ((minute%15)*60+second); i++)
            {
            	Measurement(&olvasasok);
                printf("%d\n",olvasasok[i]);
            }
            
            printf("A program uzemmodja: send\n");


        } else if (strcmp(argv[1], "-receive") == 0) {
            printf("A program uzemmodja: receive\n");
        } else if (strcmp(argv[1], "-file") == 0) {
            printf("A program kommunikacios modja: file\n");
        } else if (strcmp(argv[1], "-socket") == 0) {
            printf("A program kommunikacios modja: socket\n");
        } else {
            printf("Hazsnalhato parancssori argumentumok: \n"
                   "--version - a Jelenlegi verzio leirasa\n"
                   "--help - hasznalhato parancssori argumentuomok\n"
                   "-send vagy -receive - A program uzemmod megadasa, alapertelmezett -send\n"
                   "-file vagy -socket - A kommunikacio mod megadasa, -file az alapertelmezett.\n");
        }


    }



    return 0;
}
