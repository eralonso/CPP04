/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:13:16 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 14:37:48 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_H__
# define __IMATERIASOURCE_H__

# include	<string>
# include	<iostream>
# include	"AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource( void ) {}
		virtual void		learnMateria( AMateria* materia ) = 0;
		virtual AMateria*	createMateria( const std::string& type ) = 0;
};

#endif
