#include <stdio.h>
int main(int argc, char* argv[])
{
	float reel;
	printf("rentrez un réel positif :");
	scanf("%f", &reel);
	printf("le nombre est : %f, est le nombre lu 10 fois est %.10f réel", reel, 10*reel);
	return(0);
}
