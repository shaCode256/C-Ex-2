#define _MYBANK_H_

void Open(double amount); //Open
void Balance(int account_id); //Balance
void Desposit(int account_id, double amount); //Desposit
void Withdraw(int account_id, double amount); //Withdraw
void Close(int account_id); //Close
void Interest(int interest_rate); //Intreste_rate
void Print(); //Print
void Exit(); //Exit