#define _GNU_SOURCE 
#include <stdio.h>
#include<stdlib.h> 
#include<ctype.h> 
#include "myBank.h"
#include "myBank.c"

///////////////////////////////the main function/////////////////////////////////
int main(){
	//size=50 for 50 accounts. 2 for two "cells" for every account.
	//////accounts [50][i]:
	////// i==0: isThisAcoountOpen: 1- OPEN. -1: CLOSE.
	////// i==1; amountOfMoneyInThisAccount. 
	//can use for in main funcs only.
	for(int i=0;i<size; i++){ //Intiate the accounts 2-d array
		accounts[i][0]=-1; //at first, initallize all accounts to be closed
		accounts[i][1]=0; ////at first, initallize all accounts to have no money
	}	
	int account_id=0; //just initallizing
	double money=0; //just initallizing
	char transaction_type='J'; //just to make sure it is initalied with a char which isn't E.
	int interest_rate=0; //just initallizing

		while(transaction_type!='E'){ //while the user don't type E, keep on	
			printf("\n");
			printf("Please choose a transaction type:\n");
			printf(" O-Open Account\n");
			printf(" B-Balance Inquiry\n");
			printf(" D-Deposit\n");
			printf(" W-Withdrawal\n");
			printf(" C-Close Account\n");
			printf(" I-Interest\n");
			printf(" P-Print\n");	
			printf(" E-Exit\n");
			scanf(" %c",&transaction_type);	
		//fflush(stdin); 
		if(transaction_type!='O'&&transaction_type!='B'&&transaction_type!='D'&&transaction_type!='W'&&transaction_type!='C'&&transaction_type!='I'&&transaction_type!='P'&&transaction_type!='E'){
		//	printf("Oops! You typed a char %c which doesn't represent any option. please try again.\n",transaction_type);
			printf("Invalid transaction type\n");
		}	//if it's none of the transaction_types
		else if(transaction_type=='O'){
					//printf("You chose to Open a new account!\n");
					printf("Please enter amount for deposit: ");
				if(	scanf(" %lf",&money)!=1){
					//fflush(stdin); 
					printf("Failed to read the amount\n");
				//	fflush(transaction_type); 
					}
					else{
						Open(money);
					}
			}
		else	if(transaction_type=='B'){
				//	printf("You chose to get the Balance (the amount of money that's in the account)!\n");			
					printf("Please enter account number: ");
					if( scanf(" %d",&account_id)==1){
					//fflush(stdin); 
						Balance(account_id);
					}
					else{
						printf("Failed to read the account number\n");
					}			
				}
		else	if(transaction_type=='D'){
				//	printf("You chose to Desposit!\n");
					printf("Please enter account number: ");
					if( scanf(" %d",&account_id)==1){
						if(account_id<min||max<account_id){ //the account number is not in range
							printf("Invalid account number\n");
						}
						else if(accounts[account_id-min][0]==-1){ //the account is closed
							printf("This account is closed\n");
						}
						else {
							printf("Please enter the amount to deposit: ");
						if(	scanf(" %lf",&money)==1){
							//fflush(stdin); 
							Desposit(account_id,money);
						}
						else{
							printf("Failed to read the amount");
						//	break;
						}
						}
					}
					else{
						printf("Failed to read the account number\n");
					//	break;
					}			
					//fflush(stdin);
					//fflush(stdin); 
				}
		else	if(transaction_type=='W'){
				//	printf("You chose to Withdraw!\n");
					printf("Please enter account number: ");
					if (scanf(" %d",&account_id)==1){
						if(account_id<min||max<account_id){ //the account number is not in range
							printf("Invalid account number\n");
						}
						else  if(accounts[account_id-min][0]==-1){ //the account is closed
							printf("This account is closed\n");
						}
						//fflush(stdin); 
						else{
						printf("Please enter the amount to withdraw: ");
						if(scanf(" %lf",&money)==1){
						//fflush(stdin); 
						Withdraw(account_id,money);
						}
						else{
						printf("Invalid amount\n");
						}
						}
						
					//	break;
					}
					else{
						printf("Failed to read the account number\n");
					//	break;
					}
				}
		else	if(transaction_type=='C'){
				//	printf("You chose to Close an account!\n");
					printf("Please enter account number:");
					if (scanf(" %d",&account_id)==1){
					//fflush(stdin); 
					Close(account_id);
				//	break;
					}
					else{
						printf(" Failed to read the account number\n");
					//	break;
					}		
				}
		else	if(transaction_type=='I'){
				//	printf("You chose to update the Interest rate!\n");
					printf("Please enter interest rate: ");
					if( scanf(" %d",&interest_rate)==1){
					//fflush(stdin); 
						Interest_rate(interest_rate);
					//	break;
					}
					else{
						printf("Failed to read the interest rate\n");
					//	break;
					}
				}
		else	if (transaction_type=='P'){
				//	printf("You chose to Print all open accounts numbers and balance!\n");
				//	printf("Printing all the accounts and their balance...\n");
					Print();
					//break;
				}		
		} //end of getting option inputs, except for Exit.
		
		if(transaction_type=='E'){ /////exit option, always (should be) last
		//	printf("you chose to Erase all of the open accounts and Exit!\n");
		//	printf("Closing all accounts and Exiting the program...\n");
			Exit();
		}	
	
	return 0; //defult returning as saying the program ran OK.
}