/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:39:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/17 11:19:16 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Character.hpp"

Character::Character( void ): _name( "Unnamed" ), _currIdx( 0 )
{
	std::cout << "Character: Default constructor called" << std::endl;
	for ( int i = 0; i < N_SLOTS; i++ )
		this->_inventory[ i ] = NULL;
	this->_floor = new Floor();
}

Character::Character( std::string name ): _name( name ), _currIdx( 0 )
{
	std::cout << "Character: Name constructor called" << std::endl;
	for ( int i = 0; i < N_SLOTS; i++ )
		this->_inventory[ i ] = NULL;
	this->_floor = new Floor();
}

Character::Character( const Character& character ): _name( character._name ), _currIdx( character._currIdx )
{
	std::cout << "Character: Copy constructor called" << std::endl;
	for ( int i = 0; i < N_SLOTS; i++ )
	{
		this->_inventory[ i ] = NULL;
		if ( character._inventory[ i ] != NULL )
			this->_inventory[ i ] = character._inventory[ i ]->clone();
	}
	this->_floor = new Floor( *character._floor );
}

Character::~Character( void )
{
	std::cout << "Character: Destructor called, memory address = " << this << std::endl;
	for ( int i = 0; i < N_SLOTS; i++ )
	{
		if ( this->_inventory[ i ] != NULL )
			delete this->_inventory[ i ];
	}
	if ( this->_floor != NULL )
		delete this->_floor;
}

Character&	Character::operator=( const Character& character )
{
	std::cout << "Character: Assignation operator called" << std::endl;
	if ( this != &character )
	{
		for ( int i = 0; i < N_SLOTS; i++ )
		{
			if ( this->_inventory[ i ] != NULL )
				delete this->_inventory[ i ];
			this->_inventory[ i ] = NULL;
			if ( character._inventory[ i ] != NULL )
				this->_inventory[ i ] = character._inventory[ i ]->clone();
		}
		this->_currIdx = character._currIdx;
		if ( this->_floor != NULL )
			delete this->_floor;
		if ( character._floor != NULL )
			this->_floor = new Floor( *character._floor );
	}
	return ( *this );
}

const std::string&	Character::getName( void ) const
{
	return ( this->_name );
}

void	Character::equip( AMateria* materia )
{
	std::cout << "Character: equip called with materia = " << materia << std::endl;
	if ( this->_currIdx == -1 )
	{
		if ( this->_floor != NULL )
			this->_floor->addNode( new AMateriaNode( materia ) );
		return ;
	}
	for ( int i = 0; i < N_SLOTS; i++ )
		if ( this->_inventory[ i ] == materia )
			return ;
	this->_inventory[ this->_currIdx ] = materia;
	for ( ; this->_currIdx < N_SLOTS; this->_currIdx++ )
		if ( this->_inventory[ this->_currIdx ] == NULL )
			break ;
	if ( this->_inventory[ this->_currIdx ] != NULL )
		this->_currIdx = -1;
	if ( this->_floor != NULL )
		this->_floor->unsetNode( materia );
}

void	Character::unequip( int idx )
{
	if ( idx < 0 || idx >= N_SLOTS || this->_inventory[ idx ] == NULL )
		return ;
	std::cout << "Character: unequip called with materia = " << this->_inventory[ idx ] << std::endl;
	this->_floor->addNode( new AMateriaNode( this->_inventory[ idx ] ) );
	this->_inventory[ idx ] = NULL;
	this->_currIdx = idx < this->_currIdx ? idx : this->_currIdx == -1 ? idx : this->_currIdx;
}

void	Character::use( int idx, ICharacter& target )
{
	if ( idx < 0 || idx >= N_SLOTS || this->_inventory[ idx ] == NULL )
		return ;
	this->_inventory[ idx ]->use( target );
}

void	Character::printMaterias( void )
{
	for ( int i = 0; i < N_SLOTS; i++ )
	{
		if ( this->_inventory[ i ] != NULL )
			std::cout << "invetory[ " << i << " ] = " << this->_inventory[ i ] << std::endl;
		else
			std::cout << "invetory[ " << i << " ] = " << "Empty" << std::endl;
	}
}

void	Character::printTrash( void )
{
	AMateriaNode*	tmp;
	int				i;

	if ( this->_floor != NULL )
	{
		i = 0;
		tmp = this->_floor->getFirst();
		while ( tmp != NULL )
		{
			std::cout << "Trash[ " << i << " ] = " << tmp->getContent() << std::endl;
			tmp = tmp->getNext();
			i++;
		}
	}
	else
		std::cout << "Empty" << std::endl;
}
