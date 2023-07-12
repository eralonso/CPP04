/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:27:41 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 18:48:37 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_H__
# define __ICHARACTER_H__

# include	<string>
# include	<iostream>
# include	"AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter( void ) {}
		virtual const std::string&	getName( void ) const = 0;
		virtual void				equip( AMateria* materia ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, ICharacter& target ) = 0;
		virtual void				printMaterias( void ) = 0;
		virtual void				printTrash( void ) = 0;

};

#endif
