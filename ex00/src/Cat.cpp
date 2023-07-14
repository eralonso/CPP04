/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:32:26 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 11:32:56 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Cat.hpp"

Cat::Cat( void ): Animal( "Cat" )
{
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat( const Cat& cat ): Animal( cat )
{
	std::cout << "Cat: Copy constructor called" << std::endl;	
}

Cat::~Cat( void )
{
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& cat )
{
	std::cout << "Cat: Assignation operator called" << std::endl;
	this->_type = cat._type;
	return ( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meeeeoooww" << std::endl;
}
