/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:52:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/10 13:19:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

# include	<iostream>
# include	<string>
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
