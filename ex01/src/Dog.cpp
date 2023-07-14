/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:44:50 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 14:17:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"

Dog::Dog( void ): Animal( "Dog" )
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog& dog ): Animal( dog )
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->_brain = dog._brain ? new Brain( *dog._brain ) : new Brain();
}

Dog::~Dog( void )
{
	std::cout << "Dog: Destructor called" << std::endl;
	if ( this->_brain != NULL )
		delete this->_brain;
}

Dog&	Dog::operator=( const Dog& dog )
{
	std::cout << "Dog: Assignation operator called" << std::endl;
	if ( this != &dog )
	{
		if ( this->_brain != NULL )
			delete this->_brain;
		this->_brain = dog._brain ? new Brain( *dog._brain ) : new Brain();
		this->_type = dog._type;
	}
	return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof Woof" << std::endl;
}

void	Dog::addIdea( std::string idea )
{
	if ( this->_brain != NULL )
		this->_brain->b_addIdea( idea );
}

std::string	Dog::getIdea( unsigned int idx ) const
{
	if ( this->_brain != NULL )
		return ( this->_brain->b_getIdea( idx ) );
	return ( NULL );
}

std::string	Dog::getCurrentIdea( void ) const
{
	if ( this->_brain != NULL )
		return ( this->_brain->b_getCurrentIdea() );
	return ( NULL );
}

void	Dog::print_brain( std::ostream& out ) const
{
	out << this->_brain;
}

std::ostream&	operator<<( std::ostream& out, const Dog& dog )
{
	out << "Type: " << dog.getType() << " ";
	dog.print_brain( out );
	return ( out );
}

std::ostream&	operator<<( std::ostream& out, const Dog* dog )
{
	if ( dog != NULL )
	{
		out << "Type: " << dog->getType() << " ";
		dog->print_brain( out );
	}
	return ( out );
}
