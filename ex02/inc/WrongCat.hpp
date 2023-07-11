/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:52:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/10 13:04:56 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

# include	<iostream>
# include	<string>
# include	"WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( const WrongCat& wrongCat );
		~WrongCat( void );
		WrongCat&	operator=( const WrongCat& wrongCat );
		void		makeSound( void );
};

#endif
