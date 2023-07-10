/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:32:26 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/10 13:24:09 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal( "WrongCat" )
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& wrongCat ): WrongAnimal( wrongCat )
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;	
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& wrongCat )
{
	std::cout << "WrongCat: Assignation operator called" << std::endl;
	if ( this != &wrongCat )
		this->_type = wrongCat._type;
	return ( *this );
}

void	WrongCat::makeSound( void )
{
	std::cout << "Meeeeoooww" << std::endl;
}
