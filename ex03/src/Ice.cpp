/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:18:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/11 18:57:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Ice.hpp"

Ice::Ice( void ): AMateria( "ice" )
{
	std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice( const Ice& ice ): AMateria( "ice" )
{
	std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "Ice: Destructor called" << std::endl;
}

Ice&	Ice::operator=( const Ice& ice )
{
	std::cout << "Ice: Assignation operator called" << std::endl;
	return ( *this );
}

AMateria*	Ice::clone( void ) const
{
	return ( new Ice() );
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at" << target.getName() << "*" << std::endl;
}
