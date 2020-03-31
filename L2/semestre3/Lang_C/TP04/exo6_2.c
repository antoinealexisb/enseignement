#include <stdio.h>

int main()
{
//int anne = 2014;
int anne2 = 2014;
int annec = 0;
int age = 0;
int age_annee =0;
do{
	age_annee=0;
	anne2--;
	annec=anne2;
	age ++;
	for(int i=0; i<4; i++){
		age_annee+=annec%10;
		annec/=10;
	}
	if (age_annee == age)
	{
	printf("%d , %d \n", anne2, age);
	}
}while(age<36);
return(0);
}
