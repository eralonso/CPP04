/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:52:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/13 19:00:40 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

# include	"Animal.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( const Cat& cat );
		~Cat( void );
		Cat&	operator=( const Cat& cat );
		void	makeSound( void ) const;
};

#endif
