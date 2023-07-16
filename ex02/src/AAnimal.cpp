/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:57:25 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 13:14:24 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AAnimal.hpp"

AAnimal::AAnimal( void ): _type( "Animal" )
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ): _type( type )
{
	std::cout << "AAnimal: Type constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& animal ): _type( animal._type )
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return ( this->_type );
}

AAnimal&	AAnimal::operator=( const AAnimal& animal )
{
	std::cout << "AAnimal: Assignation operator called" << std::endl;
	this->_type = animal._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& out, const AAnimal& animal )
{
	out << "Type: " << animal.getType();
	return ( out );
}

std::ostream&	operator<<( std::ostream& out, const AAnimal* animal )
{
	if ( animal != NULL )
		out << "Type: " << animal->getType();
	return ( out );
}
