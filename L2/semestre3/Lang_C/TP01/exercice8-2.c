#include <stdio.h>
int main(int argc, char* argv[])
{
	double reel;
	printf("rentrez un réel positif :");
	scanf("%lf", &reel);
	printf("le nombre est : %f, est le nombre lu 10 fois est %.15f réel", reel, 10*reel);
	return(0);
}
