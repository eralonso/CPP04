/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:57:25 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 13:14:24 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"

Animal::Animal( void ): _type( "Animal" )
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal( std::string type ): _type( type )
{
	std::cout << "Animal: Type constructor called" << std::endl;
}

Animal::Animal( const Animal& animal ): _type( animal._type )
{
	std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal: Destructor called" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return ( this->_type );
}

void	Animal::makeSound( void ) const
{
	std::cout << "(animal sound)" << std::endl ;
}

Animal&	Animal::operator=( const Animal& animal )
{
	std::cout << "Animal: Assignation operator called" << std::endl;
	this->_type = animal._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& out, const Animal& animal )
{
	out << "Type: " << animal.getType();
	return ( out );
}

std::ostream&	operator<<( std::ostream& out, const Animal* animal )
{
	if ( animal != NULL )
		out << "Type: " << animal->getType();
	return ( out );
}
