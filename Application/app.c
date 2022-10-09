/*
 * app.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */


#include "app.h"
#include "stdio.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"

ST_cardData_t myCard;
ST_terminalData_t myTerminal;
ST_transaction_t myTransaction;

void appStart(void)
{
	while ( setMaxAmount(&myTerminal) == INVALID_AMOUNT )
	{
		printf("INVALID_AMOUNT\n");
	}

	while ( getCardHolderName(&myCard) == WRONG_NAME )
	{
		printf("WRONG_NAME\n");
	}

	while ( getCardExpireDate(&myCard) == WRONG_EXP_DATE )
	{
		printf("WRONG_EXP_DATE\n");
	}

	while ( getCardPAN(&myCard) == WRONG_PAN )
	{
		printf("WRONG_PAN\n");
	}

	while ( getTransactionDate(&myTerminal) == WRONG_DATE )
	{
		printf("WRONG_DATE\n");
	}

	if( isCardExpried(myTerminal, myCard) == EXPIRED_CARD )
	{
		printf("DECLINED ---> Expired Card\n");
		return;
	}

	while ( getTransactionAmount(&myTerminal) == INVALID_AMOUNT )
	{
		printf("INVALID_AMOUNT\n");
	}

	if( isBelowMaxAmount(&myTerminal) == EXCEED_MAX_AMOUNT)
	{
		printf("DECLINED ---> Amount Exceeding Limit\n");
		return;
	}

	myTransaction.cardHolderData = myCard;
	myTransaction.terminalData = myTerminal;

	switch (recieveTransactionData(&myTransaction) )
	{

	case DECLINED_STOLEN_CARD :
		printf("DECLINED ---> Invalid Account\n");
		break;

	case INSUFFECIENT_FUND:
		printf("DECLINED ---> Insufficient Funds\n");
		break;

	case INTERNAL_SERVER_ERROR:
		printf("DECLINED ---> Saving Failed\n");
		break;

	default:
		printf("APPROVED\n");

	}

}
