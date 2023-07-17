/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:47:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/17 11:19:48 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_H__
# define __AANIMAL_H__

# include	<iostream>
# include	<string>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( const AAnimal& animal );
		virtual ~AAnimal( void );
		AAnimal&		operator=( const AAnimal& animal );
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
};

std::ostream&	operator<<( std::ostream& out, const AAnimal& animal );
std::ostream&	operator<<( std::ostream& out, const AAnimal* animal );

#endif
