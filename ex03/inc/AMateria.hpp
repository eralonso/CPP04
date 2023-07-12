/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:29:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 15:35:16 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_H__
# define __AMATERIA_H__

# include	<iostream>
# include	<string>
# include	"ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	private:
		AMateria( void );
	public:
		AMateria( const std::string& type );
		AMateria( const AMateria& materia );
		virtual ~AMateria( void );
		AMateria&			operator=( const AMateria& materia );
		const std::string&	getType( void ) const;
		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
};

#endif
