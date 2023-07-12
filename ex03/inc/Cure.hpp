/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:48:38 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 16:38:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_H__
# define __CURE_H__

# include	<iostream>
# include	<string>
# include	"AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure( void );
		Cure( const Cure& cure );
		~Cure( void );
		Cure&		operator=( const Cure& cure );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif
