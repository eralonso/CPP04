/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:46:35 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/11 18:47:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"AMateria.hpp"

AMateria::AMateria( void )
{
	std::cout << "AMateria: Default constructor called" << std::endl;	
}

AMateria::AMateria( const std::string& type ): _type( type )
{
	std::cout << "AMateria: Type constructor called" << std::endl;
}

AMateria::AMateria( const AMateria& materia ): _type( materia._type )
{
	std::cout << "AMateria: Copy constructor called" << std::endl;	
}

AMateria::~AMateria( const std::string& type )
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& materia ): _type( materia._type )
{
	std::cout << "AMateria: Assignation operator called" << std::endl;
	return ( *this );
}

const std::string& AMateria::getType( void ) const;
{
	return ( this->_type );
}
