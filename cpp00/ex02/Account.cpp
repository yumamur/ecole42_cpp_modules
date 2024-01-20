#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ostream>
#include <sstream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    std::ostringstream oss;

    this->_amount = initial_deposit;
    this->_accountIndex = Account::_nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    oss << "index:"     << this->_accountIndex  << ";"
        << "amount:"    << initial_deposit      << ";"
        << "created";

    std::cout << oss.str() << std::endl;
    oss.clear();
}
Account::~Account( void ) {
    std::ostringstream oss;

    _displayTimestamp();
    oss << "index:"     << this->_accountIndex  << ";"
        << "amount:"    << this->_amount        << ";"
        << "closed";

    std::cout << oss.str() << std::endl;
    oss.clear();
}

int	Account::getNbAccounts( void ) {
    int ret = Account::_nbAccounts;
    return (ret);
}

int	Account::getTotalAmount( void ) {
    int ret = Account::_totalAmount;
    return (ret);
}

int	Account::getNbDeposits( void ) {
    int ret = Account::_totalNbDeposits;
    return (ret);
}

int	Account::getNbWithdrawals( void ) {
    int ret = Account::_totalNbWithdrawals;
    return (ret);
}

void	Account::displayAccountsInfos( void ) {
    std::ostringstream oss;

    _displayTimestamp();
    oss << "accounts:"      << _nbAccounts          << ";"
        << "total:"         << _totalAmount         << ";"
        << "deposits:"      << _totalNbDeposits     << ";"
        << "withdrawals:"   << _totalNbWithdrawals;

    std::cout << oss.str() << std::endl;
    oss.clear();
}

void	Account::makeDeposit( int deposit ) {
    std::ostringstream oss;

    _displayTimestamp();
    oss << "index:"     << this->_accountIndex  << ";"
        << "p_amount:"  << this->_amount        << ";"
        << "deposit:"   << deposit              << ";";

    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;

    oss << "amount:"        << this->_amount        << ";"
        << "nb_deposits:"   << this->_nbDeposits;

    std::cout << oss.str() << std::endl;
    oss.clear();
}

bool	Account::makeWithdrawal( int withdrawal ) {
    std::ostringstream oss;

    _displayTimestamp();
    oss << "index:"     << this->_accountIndex  << ";"
        << "p_amount:"  << this->_amount        << ";"
        << "withdrawal:";

    if (withdrawal <= this->_amount) {
        oss << withdrawal;
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;

        oss << ";amount:"            << this->_amount        << ";"
            << "nb_withdrawals:"    << this->_nbWithdrawals;

        std::cout << oss.str() << std::endl;

        return (true);
    } else {
        oss << "refused";

        std::cout << oss.str() << std::endl;

        return (false);
    }
}

int	Account::checkAmount( void ) const {
    return this->_amount;
}

void	Account::displayStatus( void ) const {
    std::ostringstream oss;

    _displayTimestamp();
    oss << "index:"         << this->_accountIndex  << ";"
        << "amount:"        << this->_amount        << ";"
        << "deposits:"      << this->_nbDeposits    << ";"
        << "withdrawals:"   << this->_nbWithdrawals;

    std::cout << oss.str() << std::endl;
    oss.clear();
}


void	Account::_displayTimestamp( void ) {
    std::time_t cur = std::time(NULL);
    std::tm *time = std::localtime(&cur);

    char buf[20];
    std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", time);
    std::cout << buf << " ";
}
