/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:04:35 by youhan            #+#    #+#             */
/*   Updated: 2022/11/04 21:20:53 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

static int Account::_nbAccounts = 0;
static int Account::_totalAmount = 0;
static int Account::_totalNbDeposits = 0;
static int Account::_totalNbWithdrawals = 0;


static int	Account::getNbAccounts( void )
{
	return (this->_totalAmount);
}
static int	Account::getTotalAmount( void )
{
	return (this->_totalAmount);
}
static int	Account::getNbDeposits( void )
{
	return (this->_totalAmount);
}
static int	Account::getNbWithdrawals( void )
{
	return (this->_totalAmount);
}
void	Account::displayAccountsInfos( void )
{
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbAccounts += 1;
	this->_totalAmount += 1;
	std::cout << "[time] index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
}

void	Account::makeDeposit( int deposit )
{

}
bool	Account::makeWithdrawal( int withdrawal )
{
return (1);
}
int		Account::checkAmount( void ) const
{
	return (0);
}
void	Account::displayStatus( void ) const
{
	
}

static void	_displayTimestamp( void )
{
	
}

Account::Account( void )
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
