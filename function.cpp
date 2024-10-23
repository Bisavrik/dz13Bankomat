#include "header.h"

ATM::ATM(int id, int minWithdrawAmount, int maxWithdrawAmount)
    : id(id), minWithdrawAmount(minWithdrawAmount), maxWithdrawAmount(maxWithdrawAmount), totalAmount(0) 
{
    for (int i = 0; i < 4; i++) 
    {
        counts[i] = 0;
    }
}

void ATM::loadCash(int denomination, int count) 
{
    bool found = false;
    for (int i = 0; i < 4; i++) 
    {
        if (denominations[i] == denomination)
        {
            counts[i] += count;
            totalAmount += denomination * count;
            cout << "Loaded " << count << " bills of " << denomination << " denomination" << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Invalid denomination: " << denomination << endl;
    }
}

bool ATM::withdrawCash(int amount) 
{
    if (amount < minWithdrawAmount || amount > maxWithdrawAmount)
    {
        cout << "Amount must be between " << minWithdrawAmount << " and " << maxWithdrawAmount << endl;
        return false;
    }
    if (amount > totalAmount)
    {
        cout << "Insufficient funds in the ATM" << endl;
        return false;
    }

    int remainingAmount = amount;
    int toGive[4] = { 0, 0, 0, 0 };

    for (int i = 3; i >= 0; i--) 
    {
        int neededBills = remainingAmount / denominations[i];
        if (neededBills > 0) 
        {
            int billsToGive = min(neededBills, counts[i]);
            toGive[i] = billsToGive;
            remainingAmount -= billsToGive * denominations[i];
        }
    }

    if (remainingAmount > 0) 
    {
        cout << "Cannot dispense the requested amount with available denominations" << endl;
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        counts[i] -= toGive[i];
        totalAmount -= toGive[i] * denominations[i];
    }

    cout << "Dispensed: " << amount << endl;
    return true;
}

void ATM::displayStatus() const 
{
    cout << "ATM balance: ";
    for (int i = 0; i < 4; i++) 
    {
        cout << denominations[i] << " denomination: " << counts[i] << " bills, ";
    }
    cout << "Total amount: " << totalAmount << " currency units." << endl;
}