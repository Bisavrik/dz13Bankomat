#ifndef ATM_H
#define ATM_H

#include <iostream>

using namespace std;

class ATM 
{
private:
    int id;
    int denominations[4] = { 100, 200, 500, 1000 };
    int counts[4];
    int totalAmount;
    int minWithdrawAmount;
    int maxWithdrawAmount;

public:
    ATM(int id, int minWithdrawAmount, int maxWithdrawAmount);

    void loadCash(int denomination, int count);
    bool withdrawCash(int amount);
    void displayStatus() const;
};

#endif
