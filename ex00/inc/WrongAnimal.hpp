/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:47:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 11:46:58 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__

# include	<iostream>
# include	<string>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( const WrongAnimal& wrongAnimal );
		~WrongAnimal( void );
		WrongAnimal&	operator=( const WrongAnimal& wrongAnimal );
		std::string		getType( void ) const;
		void			makeSound( void ) const;
};

std::ostream&	operator<<( std::ostream& out, const WrongAnimal& wrongAnimal );
std::ostream&	operator<<( std::ostream& out, const WrongAnimal* wrongAnimal );

#endif
