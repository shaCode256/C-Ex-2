#include <stdio.h>
#include "myBank.h"
#define size 50
#define cell_size 2
#define min 901
#define max 950

double accounts[size][cell_size]; //decalring an account array.
int openAccounts=0; //counts how many open accounts there are, for further use

void Open(double amount){ //Opens a new account
	if(openAccounts==size){
		printf("There's no place for more accounts in this bank. it's already full (50 accounts are open).\n");
	}
	else	 if(amount<0){
					printf("Invalid amount\n");
				}
		else{
			int i; //can't put in for loop cuz the copmiler yells, since we use [i] outside the for loop
				for (i=0; i<size; i++){ //while you're in the account array range
					if(accounts[i][0]==-1){ //it's a closed account.
						break;
					}
				}			
		///you got to a closed account! (you have to, since openAccounts!=size)
		openAccounts++; //adds one to the num of open accounts	
		accounts[i][0]=1; //says it's open	
		accounts[i][1]=amount; //despositing the money in this account
		printf("New account number is: %d ",i+min);
		}
}

void Balance(int account_id){ //get the Balance (the amount of money that's in the account)
	if(min<=account_id&&account_id<=max&&accounts[account_id-min][0]==1){
				account_id=account_id-min;
				printf("The balance of account number %d is: %.2lf\n",account_id+min,accounts[account_id][1]);
			//	printf("Done printing this account's balance!\n");
			}
	else 	if(account_id<min||max<account_id){ //the account number is not in range
				printf("Invalid account number\n");
			}
	else  if(accounts[account_id-min][0]==-1){ //the account is closed
				printf("This account is closed\n");
			}
}

void Desposit(int account_id, double money){ //Desposit
	if(money<=0){
				printf("Cannot deposit a negative amount\n");
	}
	else{
			if(min<=account_id&&account_id<=max&&accounts[account_id-min][0]==1){
				account_id=account_id-min;
			//	printf("Adding %.2lf to already existed %.2lf in account numbered %d...\n",money,accounts[account_id][1],account_id+min);
				accounts[account_id][1]=accounts[account_id][1]+money;
				printf("The new balance is: %.2lf\n",accounts[account_id][1]);
		}
	else	if(account_id<min||max<account_id){ //the account number is not in range
				printf("Invalid account number\n");
			}
	else  if(accounts[account_id-min][0]==-1){ //the account is closed
				printf("This account is closed\n");
			}
		}
}

void Withdraw(int account_id, double money){ //Withdraw
	if(money<=0){
		printf("You can't withdraw an money which is <= 0. you can try to withdraw a positive money. please try again. \n");
	}
	else if(min<=account_id&&account_id<=max&&accounts[account_id-min][0]==1){ //it's an open account (and ofc in range)
			if(accounts[account_id-min][1] < money){
				printf("Cannot withdraw more than the balance\n");
			}
			else{ //you do have enough money for this
				accounts[account_id-min][1]= accounts[account_id-min][1]-money;
				printf("The new balance is: %.2lf\n",accounts[account_id-min][1]);
			}
		}
	else	if(account_id<min||max<account_id){ //the account number is not in range
				printf("Invalid account number\n");
			}
	else  if(accounts[account_id-min][0]==-1){ //the account is closed
					printf("This account is closed\n");
			}
}


void Close(int account_id){ //Close
	if(min<=account_id&&account_id<=max&&accounts[account_id-min][0]==1){
				account_id=account_id-min;
				accounts[account_id][0]=-1; //-1 as closed
				accounts[account_id][1]=0; //have 0 money
				printf(" Closed account number %d\n",account_id+min);
				openAccounts--;
			}
	else 	if(account_id<min||max<account_id){ //the account number is not in range
		printf("Invalid account number\n");
			}
	else  if(accounts[account_id-min][0]==-1){ //the account is closed
				printf(" This account is already closed");
			}
}			

void Interest_rate(int interest_rate){	//Update the interest_rate
	if(interest_rate<0){
		printf("Invalid interest rate\n");
	}
	else{
		for(int i=0; i<size; i++){
			if(accounts[i][0]==1){ // if the account is open
				//printf("Adding %.2lf to already existed %.2lf in account numbered %d...\n",money,accounts[account_id][1],account_id+min);
			//	printf("Account numbered %d that had amount of %.2lf has now:\n",i+min, accounts[i][1]);
				accounts[i][1]=accounts[i][1]*(((double)(100)+(double)(interest_rate))/(double)(100));
			//	printf(" %.2lf\n",accounts[i][1]);
				//Update it's amount with the interest rate.
				//By formula: update X%= (100+X/100)*original amount
			}
		}
	}				
}

void Print(){ //Print all of the open accounts
	if(openAccounts==0){
	//	printf("There's nothing to print, as there are no open accounts. sorry.\n");
	}
	else{
		for(int i=0; i<size; i++){
			if(accounts[i][0]==1){ //if this account is open
			printf("The balance of account number %d is: %.2lf\n",i+min,accounts[i][1]);
			}
		}
	}
}

void Exit(){ //Erase all of the open accounts and Exit
	if(openAccounts==0){
		//printf("There's nothing to close, as there are no open accounts right now. sorry.\n");
	}
	else{
		for(int i=0;i<size; i++){ //Initalize the array to how it was in the beginning.
				accounts[i][0]=-1; //a closed account X: [X][0] is -1.
				accounts[i][1]=0; //a closed account has no money. so 0 money.
		}
	}
}