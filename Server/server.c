/*
 * server.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#include "server.h"
#include "../Terminal/terminal.h"
#include "string.h"

ST_accountsDB_t g_accounts[255] = {
		{35200,"324879324987423134"},
		{10000,"239498773726478832"},
		{12000,"715974764873268732"},
		{15000,"932764873268427632"}
};

ST_transaction_t g_transcations[255] = {
		0
};

short int g_counter = 0 ;
ST_accountsDB_t mainAccount ;

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	EN_transState_t status = APPROVED;
	if( isValidAccount(&(transData->cardHolderData)) == ACCOUNT_NOT_FOUND )
	{
		status = DECLINED_STOLEN_CARD;
	}
	else if( isAmountAvailable(&(transData->terminalData)) == LOW_BALANCE )
	{
		status = INSUFFECIENT_FUND;
	}
	else if(saveTransaction(transData) == SAVING_FAILED)
	{
		status = INTERNAL_SERVER_ERROR;
	}
	transData->transState = status ;
	return status;
}

EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
	EN_serverError_t status = ACCOUNT_NOT_FOUND;
	for(g_counter = 0 ; g_counter < 255 ; g_counter++ )
	{
		if(strcmp(g_accounts[g_counter].primaryAccountNumber, cardData->primaryAccountNumber) == 0)
		{
			mainAccount = g_accounts[g_counter];
			status = ok;
		}
	}
	return status;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{
	EN_serverError_t status = LOW_BALANCE;
	if(mainAccount.balance >= termData->transAmount)
	{
		status = ok;
	}
	return status;
}

EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	EN_serverError_t status = SAVING_FAILED;
	/* the sequence number of the transaction is its offset in the array */
	static unsigned long int sequence = 0;
	if(sequence < 255)
	{
		g_transcations[sequence] = *transData ;
		g_transcations[sequence].transactionSequenceNumber = sequence ;
		sequence ++;
		status = ok;
	}
	return status;
}

EN_serverError_t getTransaction(unsigned long int transactionSequenceNumber, ST_transaction_t *transData)
{
	EN_serverError_t status = TRANSACTION_NOT_FOUND;
	for(unsigned char i = 0 ; i < 255 ; i++)
	{
		if(transactionSequenceNumber == g_transcations[i].transactionSequenceNumber)
		{
			*transData = g_transcations[i];
			status = ok;
		}
	}
	return status;
}
