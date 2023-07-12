/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:39:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 18:17:03 by eralonso         ###   ########.fr       */
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
	std::cout << "Character: Destructor called" << std::endl;
	for ( int i = 0; i < N_SLOTS; i++ )
	{
		if ( this->_inventory[ i ] != NULL )
			delete this->_inventory[ i ];
	}
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
	if ( this->_currIdx == -1 )
		return ;
	for ( int i = 0; i < N_SLOTS; i++ )
		if ( this->_inventory[ i ] == materia )
			return ;
	this->_inventory[ this->_currIdx ] = materia;
	for ( ; this->_currIdx < N_SLOTS; this->_currIdx++ )
		if ( this->_inventory[ this->_currIdx ] == NULL )
			break ;
	if ( this->_inventory[ this->_currIdx ] != NULL )
		this->_currIdx = -1;
}

void	Character::unequip( int idx )
{
	if ( idx < 0 || idx >= N_SLOTS || this->_inventory[ idx ] == NULL )
		return ;
	this->_floor->addNode( new AMateriaNode( this->_inventory[ idx ] ) );
	this->_currIdx = idx < this->_currIdx ? idx : this->_currIdx;
}

void	Character::use( int idx, ICharacter& target )
{
	if ( idx < 0 || idx >= N_SLOTS || this->_inventory[ idx ] == NULL )
		return ;
	this->_inventory[ idx ]->use( target );
}
