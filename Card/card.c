/*
 * card.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#include "card.h"
#include "string.h"
#include "stdio.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	printf("Please Enter The Card Holder Name: ");
	scanf(" ");
	gets(cardData->cardHolderName);
	if(strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) < 20)
	{
		return WRONG_NAME ;
	}
	return OK;
}

EN_cardError_t getCardExpireDate(ST_cardData_t *cardData)
{
	printf("Please Enter The Expire Date In Format MM/YY: ");
	gets(cardData->cardExpirationDate);
	if(strlen(cardData->cardExpirationDate) != 5 || (cardData->cardExpirationDate)[2] != '/' )
	{
		return WRONG_EXP_DATE ;
	}
	return OK;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
	printf("Please Enter The PAN: ");
	gets(cardData->primaryAccountNumber);
	if(strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) < 16)
	{
		return WRONG_PAN ;
	}
	return OK;
}
