/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaNode.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:34:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 19:33:18 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AMateriaNode.hpp"

AMateriaNode::AMateriaNode( void )
{
	this->_prev = NULL;
	this->_next = NULL;
	this->_content = NULL;
}

AMateriaNode::AMateriaNode( AMateria* materia )
{
	this->_prev = NULL;
	this->_next = NULL;
	this->_content = materia;
}

AMateriaNode::AMateriaNode( const AMateriaNode& node )
{
	this->_prev = node._prev;
	this->_next = node._next;
	this->_content = node._content->clone();
}

AMateriaNode::~AMateriaNode( void )
{
	std::cout << "AMateriaNode: Destructor called" << std::endl;
	if ( this->_content != NULL )
		delete this->_content;
}

AMateriaNode&	AMateriaNode::operator=( const AMateriaNode& node )
{
	if ( this != &node )
	{
		this->_prev = node._prev;
		this->_next = node._next;
		this->_content = node._content->clone();
	}
	return ( *this );
}

AMateriaNode*	AMateriaNode::getPrev( void ) const
{
	return ( this->_prev );
}

AMateriaNode*	AMateriaNode::getNext( void ) const
{
	return ( this->_next );
}

AMateria*	AMateriaNode::getContent( void ) const
{
	return ( this->_content );
}

void	AMateriaNode::setPrev( AMateriaNode* node )
{
	this->_prev = node;
}

void	AMateriaNode::setNext( AMateriaNode* node )
{
	this->_next = node;
}
