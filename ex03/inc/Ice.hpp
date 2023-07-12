/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:04:49 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 15:19:43 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_H__
# define __ICE_H__

# include	<string>
# include	<iostream>
# include	"AMateria.hpp"
// # include	"ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice( void );
		Ice( const Ice& ice );
		~Ice( void );
		Ice&		operator=( const Ice& ice );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif
