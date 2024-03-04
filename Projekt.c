#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
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