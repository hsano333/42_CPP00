
#include "Account.hpp"
#include <string>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::setfill;
using std::setw;
using std::to_string;


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

string get_timestamp(void)
{
    std::stringstream ss;
    time_t now = time(NULL);
    struct tm *pnow = localtime(&now);

    ss << "[";
    ss << setw(4) << setfill('0') << to_string(pnow->tm_year+1900);
    ss << setw(2) << setfill('0') << to_string(pnow->tm_mon + 1);
    ss << setw(2) << setfill('0') << to_string(pnow->tm_mday);
    ss << "_";
    ss << setw(2) << setfill('0') << to_string(pnow->tm_hour);
    ss << setw(2) << setfill('0') << to_string(pnow->tm_min);
    ss << setw(2) << setfill('0') << to_string(pnow->tm_sec);
    ss << "] ";
    return (ss.str());
}

Account::Account(int initial_deposit)
{
    if (initial_deposit < 0)
    {
        cout << "error: invalid deposit" << endl;
        return ;
    }

    _displayTimestamp();
    //cout << get_timestamp();
    cout << "index:" << Account::getNbAccounts() << ";";
    cout << "amount:" << initial_deposit << ";";
    cout << "created";
    cout << endl;
    this->_accountIndex = Account::getNbAccounts();
    this->_nbDeposits = initial_deposit;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    //_totalNbDeposits += initial_deposit;
}

Account::~Account()
{
    //cout << get_timestamp();
    _displayTimestamp();
    //cout << get_timestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "closed";
    cout << endl;
}


int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    //cout << "displayAccountsInfos" << endl;
    _displayTimestamp();
    //cout << get_timestamp();
    cout << "accounts:" << getNbAccounts() << ";";
    cout << "total:" << getTotalAmount() << ";";
    cout << "deposits:" << getNbDeposits() << ";";
    cout << "withdrawals:" << getNbWithdrawals();
    cout << endl;
}

void Account::makeDeposit(int deposit)
{
    int tmp_amount = _amount + deposit;
    int old_amount = _amount;
    if (deposit < 0 || tmp_amount < _amount)
    {
        cout << "error: invalid deposit" << endl;
        return ;
    }
    _totalAmount += deposit;
    _amount = tmp_amount;
    _nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();
    //cout << get_timestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "p_amount:" << old_amount << ";";
    cout << "deposit:" << deposit << ";";
    cout << "amount:" << _amount << ";";
    cout << "nb_deposits:" << _nbDeposits;
    cout << endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int tmp_amount = _amount - withdrawal;
    int old_amount = _amount;

    if (withdrawal < 0 || tmp_amount < 0)
    {
        _displayTimestamp();
        //cout << get_timestamp();
        cout << "index:" << _accountIndex << ";";
        cout << "p_amount:" << old_amount << ";";
        cout << "withdrawal:refused";
        cout << endl;
        return (false);
    }
    _totalAmount -= withdrawal;
    _amount = tmp_amount;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    _displayTimestamp();
    //cout << get_timestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "p_amount:" << old_amount << ";";
    cout << "withdrawal:" << withdrawal << ";";
    cout << "amount:" << _amount << ";";
    cout << "nb_withdrawals:" << _nbDeposits;
    cout << endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    //cout << get_timestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "deposits:" << _nbDeposits << ";";
    cout << "withdrawals:" << _nbWithdrawals;
    cout << endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(NULL);
    struct tm *pnow = localtime(&now);

    cout << "[";
    cout << setw(4) << setfill('0') << to_string(pnow->tm_year+1900);
    cout << setw(2) << setfill('0') << to_string(pnow->tm_mon + 1);
    cout << setw(2) << setfill('0') << to_string(pnow->tm_mday);
    cout << "_";
    cout << setw(2) << setfill('0') << to_string(pnow->tm_hour);
    cout << setw(2) << setfill('0') << to_string(pnow->tm_min);
    cout << setw(2) << setfill('0') << to_string(pnow->tm_sec);
    cout << "] ";
    //cout << get_timestamp();
}
