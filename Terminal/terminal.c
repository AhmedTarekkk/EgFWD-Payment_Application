/*
 * terminal.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#include "terminal.h"
#include "string.h"
#include "stdio.h"

EN_terminalError_t getTransactionDate (ST_terminalData_t * termData)
{
	printf("Please Enter The Transaction Date as DD/MM/YYYY : ");
	gets(termData->transactionDate);
	if(strlen(termData->transactionDate) != 10 || (termData->transactionDate)[2] != '/' || (termData->transactionDate)[5] != '/' )
	{
		return WRONG_DATE ;
	}
	return Ok;
}

EN_terminalError_t isCardExpried (ST_terminalData_t termData ,ST_cardData_t cardData)
{
	/* DD/MM/YYYY MM/YY 	13/04/2023  05/25	*/
	int expireDate = (cardData.cardExpirationDate[3]-'0')*1000 + (cardData.cardExpirationDate[4]-'0')*100 + (cardData.cardExpirationDate[0]-'0')*10 + cardData.cardExpirationDate[1]-'0';
	int transactiontDate = (termData.transactionDate[8]-'0')*1000 + (termData.transactionDate[9]-'0')*100 + (termData.transactionDate[3]-'0')*10 + termData.transactionDate[4]-'0';
	if(expireDate < transactiontDate)
	{
		return EXPIRED_CARD;
	}
	return Ok;
}

EN_terminalError_t isValidCardPAN (ST_cardData_t * cardData)
{
	return Ok;
}

EN_terminalError_t getTransactionAmount (ST_terminalData_t * termData)
{
	printf("Please Enter The Transaction Amount: ");
	scanf("%f",&(termData->transAmount));
	if(termData->transAmount <= 0)
	{
		return INVALID_AMOUNT ;
	}
	return Ok;
}

EN_terminalError_t isBelowMaxAmount (ST_terminalData_t * termData)
{
	if(termData->maxTransAmount < termData->transAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	return Ok;
}

EN_terminalError_t setMaxAmount (ST_terminalData_t * termData)
{
	float maxTransaction;
	printf("Please Enter The Maximum Transaction Amount: ");
	scanf("%f",&maxTransaction);
	if(maxTransaction <= 0)
	{
		termData->maxTransAmount = 1;
		return INVALID_AMOUNT ;
	}
	termData->maxTransAmount = maxTransaction ;
	return Ok;
}
