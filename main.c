/*
 * main.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#include "Application/app.h"
#include "stdio.h"

int main(void)
{
	setbuf(stdout, NULL);
	int x;
	do
	{
		appStart();
		printf("Enter 0 To Make Another Transaction or Any Number To Exit\n");
		scanf("%d",&x);
	}while(x == 0);


	return 0;
}
