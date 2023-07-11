/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/11 18:58:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Cure.hpp"

Cure::Cure( void ): AMateria( "cure" )
{
	std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure( const AMateria& materia ): AMateria( "cure" )
{
	std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "Cure: Destructor called" << std::endl;
}

Cure&	Cure::operator=( const Cure& cure )
{
	std::cout << "Cure: Assignation operator called" << std::endl;
	return ( *this );
}

AMateria*	clone( void ) const
{
	return ( new Cure() );
}

void	use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
