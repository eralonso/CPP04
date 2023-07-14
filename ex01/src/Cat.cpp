/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:32:26 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 14:18:12 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Cat.hpp"

Cat::Cat( void ): Animal( "Cat" )
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat( const Cat& cat ): Animal( cat )
{
	std::cout << "Cat: Copy constructor called" << std::endl;	
	this->_brain = cat._brain != NULL ? new Brain( *cat._brain ) : new Brain();
}

Cat::~Cat( void )
{
	std::cout << "Cat: Destructor called" << std::endl;
	if ( this->_brain != NULL )
		delete this->_brain;
}

Cat&	Cat::operator=( const Cat& cat )
{
	std::cout << "Cat: Assignation operator called" << std::endl;
	if ( this != &cat )
	{
		if ( this->_brain != NULL )
			delete this->_brain;
		this->_brain = cat._brain ? new Brain( *cat._brain ) : new Brain();
		this->_type = cat._type;
	}
	return ( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meeeeoooww" << std::endl;
}

void	Cat::addIdea( std::string idea )
{
	if ( this->_brain != NULL )
		this->_brain->b_addIdea( idea );
}

std::string	Cat::getIdea( unsigned int idx ) const
{
	if ( this->_brain != NULL )
		return ( this->_brain->b_getIdea( idx ) );
	return ( NULL );
}

std::string	Cat::getCurrentIdea( void ) const
{
	if ( this->_brain != NULL )
		return ( this->_brain->b_getCurrentIdea() );
	return ( NULL );
}

void	Cat::print_brain( std::ostream& out ) const
{
	out << this->_brain;
}

std::ostream&	operator<<( std::ostream& out, const Cat& cat )
{
	out << "Type: " << cat.getType() << " ";
	cat.print_brain( out );
	return ( out );
}

std::ostream&	operator<<( std::ostream& out, const Cat* cat )
{
	if ( cat != NULL )
	{
		out << "Type: " << cat->getType() << " ";
		cat->print_brain( out );
	}
	return ( out );
}
