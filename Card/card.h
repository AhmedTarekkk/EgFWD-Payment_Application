/*
 * card.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Ahmed
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

typedef struct ST_cardData_t
{
	char cardHolderName[25];
	char primaryAccountNumber[20];
	char cardExpirationDate[6];

}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK,
	WRONG_NAME,
	WRONG_EXP_DATE,
	WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpireDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);

#endif /* CARD_CARD_H_ */
