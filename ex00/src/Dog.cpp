/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:44:50 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/10 13:23:27 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"

Dog::Dog( void ): Animal( "Dog" )
{
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog( const Dog& dog ): Animal( dog )
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& dog )
{
	std::cout << "Dog: Assignation operator called" << std::endl;
	if ( this != &dog )
		this->_type = dog._type;
	return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof Woof" << std::endl;
}

