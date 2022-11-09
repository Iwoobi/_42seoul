/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:04:35 by youhan            #+#    #+#             */
/*   Updated: 2022/11/09 18:34:33 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::__1::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	time_t tt = std::chrono::system_clock::to_time_t(now);
	std::cout << std::put_time(localtime(&tt), "[%Y%m%d_%H%M%S]");
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbAccounts += 1;
	this->_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this-> _amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this-> _amount;
	std::cout << ";withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		std::cout << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else
		std::cout << "refused" << std::endl;
	return (1);
}
int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account( void )
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
