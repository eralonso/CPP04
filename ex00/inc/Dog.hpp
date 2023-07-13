/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:55:06 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/13 19:00:43 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__

# include	"Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( const Dog& dog );
		~Dog( void );
		Dog&	operator=( const Dog& dog );
		void	makeSound( void ) const;
};

#endif
