/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:52:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/11 15:05:16 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

# include	<iostream>
# include	<string>
# include	"AAnimal.hpp"
# include	"Brain.hpp"

class Cat: public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Cat( void );
		Cat( const Cat& cat );
		~Cat( void );
		Cat&		operator=( const Cat& cat );
		void		makeSound( void ) const;
		void		addIdea( std::string idea );
		std::string	getIdea( unsigned int idx ) const;
		std::string	getCurrentIdea( void ) const;
		void		print_brain( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Cat& cat );
std::ostream&	operator<<( std::ostream& out, Cat* cat );

#endif
