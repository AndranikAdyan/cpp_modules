#include "Account.hpp"
#include <iomanip>
#include <ctime>
#include <iostream>

int	Account::getNbAccounts( void ){};
int	Account::getTotalAmount( void ){};
int	Account::getNbDeposits( void ){};
int	Account::getNbWithdrawals( void ){};
void	Account::displayAccountsInfos( void ){};

Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
				<< this->_amount << ";created" << std::endl;
}

Account::~Account( void ){}

void	Account::makeDeposit( int deposit ) {};
bool	Account::makeWithdrawal( int withdrawal ) {}
int		Account::checkAmount( void ) const {}
void	Account::displayStatus( void ) const {}


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

Account::Account( void ){};

int main()
{
	Account acc(42);
	Account acc2(54);
	Account ac3(957);
}
