/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:44:50 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/11 15:06:01 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"

Dog::Dog( void ): AAnimal( "Dog" )
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog& dog ): AAnimal( dog )
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->_brain = dog._brain ? new Brain( *dog._brain ) : new Brain();
}

Dog::~Dog( void )
{
	std::cout << "Dog: Destructor called" << std::endl;
	if ( this->_brain )
		delete this->_brain;
}

Dog&	Dog::operator=( const Dog& dog )
{
	std::cout << "Dog: Assignation operator called" << std::endl;
	if ( this != &dog )
	{
		if ( this->_brain )
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
	if ( this->_brain )
		this->_brain->b_addIdea( idea );
}

std::string	Dog::getIdea( unsigned int idx ) const
{
	if ( this->_brain )
		return ( this->_brain->b_getIdea( idx ) );
	return ( NULL );
}

std::string	Dog::getCurrentIdea( void ) const
{
	if ( this->_brain )
		return ( this->_brain->b_getCurrentIdea() );
	return ( NULL );
}

void	Dog::print_brain( void ) const
{
	std::cout << this->_brain;
}

std::ostream&	operator<<( std::ostream& out, Dog& dog )
{
	out << "Type: " << dog.getType() << " ";
	dog.print_brain();
	return ( out );
}

std::ostream&	operator<<( std::ostream& out, Dog* dog )
{
	if ( dog )
	{
		out << "Type: " << dog->getType() << " ";
		dog->print_brain();
	}
	return ( out );
}
