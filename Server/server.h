/*
 * server.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include "../Card/card.h"
#include "../Terminal/terminal.h"

typedef enum EN_transState_t
{
	APPROVED,
	DECLINED,
	INSUFFECIENT_FUND,
	DECLINED_STOLEN_CARD,
	INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError_t
{
	ok,
	SAVING_FAILED,
	TRANSACTION_NOT_FOUND,
	ACCOUNT_NOT_FOUND,
	LOW_BALANCE
}EN_serverError_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	unsigned long int transactionSequenceNumber;
}ST_transaction_t;

typedef struct ST_accountsDB_t
{
	float balance;
	char primaryAccountNumber[20];
}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction_t *transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
EN_serverError_t saveTransaction(ST_transaction_t *transData);
EN_serverError_t getTransaction(unsigned long int transactionSequenceNumber, ST_transaction_t *transData);

#endif /* SERVER_SERVER_H_ */
