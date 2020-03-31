/* Fichier couleur.c*/
#include "couleurs.h"

void rouge(){
    printf("\033[1;31m");
}

void jaune(){
    printf("\033[1;33m");

}

void vert(){
    printf("\033[1;32m");
}

void vert_blink(){
    printf("\033[5;32m");
}

void magenta(){
    printf("\033[1;35m");
}

void orange(){
    printf("\033[1;33m");
}


void reset(){
    printf("\033[0m");
}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}
