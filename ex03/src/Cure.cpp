/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 15:01:10 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Cure.hpp"

Cure::Cure( void ): AMateria( "cure" )
{
	std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure( const Cure& cure ): AMateria( "cure" )
{
	std::cout << "Cure: Copy constructor called" << std::endl;
	this->_type = cure._type;
}

Cure::~Cure( void )
{
	std::cout << "Cure: Destructor called, memory address = " << this << std::endl;
}

Cure&	Cure::operator=( const Cure& cure )
{
	std::cout << "Cure: Assignation operator called" << std::endl;
	this->_type = cure._type;
	return ( *this );
}

AMateria*	Cure::clone( void ) const
{
	return ( new Cure( *this ) );
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
