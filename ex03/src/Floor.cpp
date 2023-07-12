/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:45:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 19:15:32 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Floor.hpp"

Floor::Floor( void )
{
	this->_size = 0;
	this->_first = NULL;
	this->_last = NULL;
}

Floor::Floor( const Floor& floor )
{
	short int		size;
	AMateriaNode	*tmp;

	size = floor.getSize();
	if ( size > 0 && floor._first != NULL )
	{
		tmp = floor._first;
		for ( int i = 0; i < size; i++ )
		{
			this->addNode( new AMateriaNode( *tmp ) );
			tmp = tmp->getNext();
		}
	}
}

Floor::~Floor( void )
{
	std::cout << "Floor: Destructor called" << std::endl;
	this->clean();
}

Floor&	Floor::operator=( const Floor& floor )
{
	
	short int		size;
	AMateriaNode	*tmp;

	if ( this != &floor )
	{
		this->clean();
		size = floor.getSize();
		if ( size > 0 && floor._first != NULL )
		{
			tmp = floor._first;
			while ( tmp )
			{
				this->addNode( new AMateriaNode( *tmp ) );
				tmp = tmp->getNext();
			}
		}
	}
	return ( *this );
}

void	Floor::addNode( AMateriaNode* node )
{
	if ( this->_size == 0 )
		this->_first = node;
	else
	{
		this->_last->setNext( node );
		node->setPrev( this->_last );
	}
	this->_last = node;
	this->_size++;
}

void	Floor::clean( void )
{
	AMateriaNode	*tmp;
	AMateriaNode	*tmp2;

	tmp = this->_first;
	while ( tmp )
	{
		tmp2 = tmp->getNext();
		if ( tmp != NULL )
			delete tmp;
		tmp = tmp2;
	}
}

AMateriaNode*	Floor::getFirst( void ) const
{
	return ( this->_first );
}

AMateriaNode*	Floor::getLast( void ) const
{
	return ( this->_last );
}

AMateriaNode*	Floor::getNode( unsigned short int idx ) const
{
	AMateriaNode*	tmp;

	tmp = NULL;
	if ( idx < this->_size )
	{
		tmp = this->_first;
		for ( ; idx < this->_size; idx++ )
			tmp = tmp->getNext();
	}
	return ( tmp );
}

unsigned short int	Floor::getSize( void ) const
{
	return ( this->_size );
}
