/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:32:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/17 11:19:18 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include	<string>
# include	<iostream>
# include	"ICharacter.hpp"
# include	"Floor.hpp"

# define N_SLOTS	4

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[ N_SLOTS ];
		int			_currIdx;
		Floor*		_floor;
	public:
		Character( void );
		Character( std::string name );
		Character( const Character& character );
		~Character( void );
		Character&	operator=( const Character& character );
		const std::string&	getName( void ) const;
		void				equip( AMateria* materia );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );
		void				printMaterias( void );
		void				printTrash( void );
};

#endif
