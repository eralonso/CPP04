/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:16:44 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/17 11:19:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

# include	<string>
# include	<iostream>
# include	"IMateriaSource.hpp"

# define N_MATERIAS	4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_materias[ N_MATERIAS ];
		short int	_currIdx;
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& materiaSource );
		~MateriaSource( void );
		MateriaSource&	operator=( const MateriaSource& materiaSource );
		void			learnMateria( AMateria* materia );
		AMateria*		createMateria( const std::string& type );
};

#endif
