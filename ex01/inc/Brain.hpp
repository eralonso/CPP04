/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:19:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/13 18:57:25 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
# define __BRAIN_H__

# include	<string>
# include	<iostream>

# define MAX_IDEAS	100

class Brain
{
	private:
		std::string		_ideas[ MAX_IDEAS ];
		unsigned int	_idx;
	public:
		Brain( void );
		Brain( std::string idea );
		Brain( const Brain& brain );
		~Brain( void );
		Brain&		operator=( const Brain& brain );
		void		b_addIdea( std::string idea );
		std::string	b_getIdea( unsigned int idx ) const;
		std::string	b_getCurrentIdea( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Brain& brain );
std::ostream&	operator<<( std::ostream& out, Brain* brain );

#endif
