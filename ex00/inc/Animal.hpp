/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:47:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/10 13:31:58 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include	<iostream>
# include	<string>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& animal );
		virtual ~Animal( void );
		Animal&			operator=( const Animal& animal );
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
};

std::ostream&	operator<<( std::ostream& out, const Animal& animal );
std::ostream&	operator<<( std::ostream& out, const Animal* animal );

#endif
