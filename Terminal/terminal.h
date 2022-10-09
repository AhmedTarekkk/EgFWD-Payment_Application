/*
 * terminal.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#ifndef TERMINAL_TERMINAL_H_
#define TERMINAL_TERMINAL_H_

#include "../Card/card.h"

typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	char transactionDate[11];

}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	Ok,
	WRONG_DATE,
	EXPIRED_CARD,
	INVALID_CARD,
	INVALID_AMOUNT,
	EXCEED_MAX_AMOUNT,
	INVALUD_MAX_AMOUNT
}EN_terminalError_t;

EN_terminalError_t getTransactionDate (ST_terminalData_t * termData);

EN_terminalError_t isCardExpried (ST_terminalData_t termData ,ST_cardData_t cardData);

EN_terminalError_t isValidCardPAN (ST_cardData_t * cardData);

EN_terminalError_t getTransactionAmount (ST_terminalData_t * termData);

EN_terminalError_t isBelowMaxAmount (ST_terminalData_t * termData);

EN_terminalError_t setMaxAmount (ST_terminalData_t * termData);

#endif /* TERMINAL_TERMINAL_H_ */
