/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:52:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 18:53:46 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

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
		Cat&			operator=( const Cat& cat );
		void			makeSound( void ) const;
		void			addIdea( std::string idea );
		std::string		getIdea( unsigned int idx ) const;
		std::string		getCurrentIdea( void ) const;
		unsigned int	getIndex( void ) const;
		void			printBrain( std::ostream& out ) const;
};

std::ostream&	operator<<( std::ostream& out, const Cat& cat );
std::ostream&	operator<<( std::ostream& out, const Cat* cat );

#endif
