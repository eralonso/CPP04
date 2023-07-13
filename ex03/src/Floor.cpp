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
  this->_size = 0;
  this->_first = NULL;
  this->_last = NULL;
	if ( size > 0 && floor._first != NULL )
  {
		tmp = floor._first;
		for ( ; this->_size < size; this->_size++ )
		{
      if ( tmp != NULL )
        this->addNode( new AMateriaNode( *tmp ) );
			tmp = tmp->getNext();
		}
  }
}

Floor::~Floor( void )
{
	std::cout << "Floor: Destructor called, memory address = " << this << std::endl;
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
    this->_size = size;
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

  if ( this->_size > 0 && this->_first != NULL )
  {
    tmp = this->_first;
	  while ( tmp != NULL )
  	{
  		tmp2 = tmp->getNext();
  		delete tmp;
	  	tmp = tmp2;
    }
    this->_size = 0;
    this->_first = NULL;
    this->_last = NULL;
	}
}

void  Floor::unsetNode( AMateria* materia )
{
  AMateriaNode*  tmp;

  tmp = this->_first;
  while ( tmp != NULL && tmp->getContent() != materia )
    tmp = tmp->getNext();
  if ( tmp != NULL )
  {
    if ( tmp->getPrev() != NULL )
      tmp->getPrev()->setNext( tmp->getNext() );
    if ( tmp->getNext() != NULL )
      tmp->getNext()->setPrev( tmp->getPrev() );
    if ( this->_first == tmp )
      this->_first = tmp->getNext();
    if ( this->_last == tmp )
      this->_last = tmp->getPrev();
    tmp->setDelete( false );
    delete tmp;
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
		for ( int i = 0; idx > i; i++ )
			tmp = tmp->getNext();
	}
	return ( tmp );
}

unsigned short int	Floor::getSize( void ) const
{
	return ( this->_size );
}
