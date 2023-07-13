/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:55:06 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/13 19:10:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__

# include	"Animal.hpp"
# include	"Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		Dog( const Dog& dog );
		~Dog( void );
		Dog&		operator=( const Dog& dog );
		void		makeSound( void ) const;
		void		addIdea( std::string idea );
		std::string	getIdea( unsigned int idx ) const;
		std::string	getCurrentIdea( void ) const;
		void		print_brain( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Dog& dog );
std::ostream&	operator<<( std::ostream& out, Dog* dog );

#endif
