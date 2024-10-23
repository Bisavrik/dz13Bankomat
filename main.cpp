#include "header.h"

int main() 
{
    ATM atm(1, 100, 10000);
    atm.loadCash(100, 50);
    atm.loadCash(500, 30);
    atm.loadCash(1000, 20);

    atm.displayStatus();

    atm.withdrawCash(1500);
    atm.displayStatus();

    atm.withdrawCash(20000);

    return 0;
}