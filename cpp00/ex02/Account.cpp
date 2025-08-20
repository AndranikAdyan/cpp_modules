#include "Account.hpp"
#include <iomanip>
#include <ctime>
#include <iostream>

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (this->_amount - withdrawal < 0) {
		std::cout	<< "index:" << this->_accountIndex
					<< ";p_amount:" << this->_amount
					<< ";withdrawal:refused" << std::endl;
		return false;
	}
	else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout	<< "index:" << this->_accountIndex
					<< ";p_amount:" << this->_amount + withdrawal
					<< ";withdrawal:" << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return true;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
	std::time_t t = std::time(0);

	std::tm *now = std::localtime(&t);

	std::cout << "["
				<< (now->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
				<< std::setw(2) << std::setfill('0') << now->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << now->tm_hour
				<< std::setw(2) << std::setfill('0') << now->tm_min
				<< std::setw(2) << std::setfill('0') << now->tm_sec
				<< "] ";
}

// int main()
// {
// 	Account acc(42);
// 	Account acc2(54);
// 	Account acc3(957);

// 	acc.makeDeposit(100);
// 	acc.makeDeposit(150);
// 	acc2.makeDeposit(150);
// }
