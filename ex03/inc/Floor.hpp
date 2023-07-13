/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:38:48 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 17:55:32 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FLOOR_H__
# define __FLOOR_H__

# include	"AMateriaNode.hpp"

class Floor
{
	private:
		AMateriaNode*		_first;
		AMateriaNode*		_last;
		unsigned short int	_size;
	public:
		Floor( void );
		Floor( const Floor& floor );
		~Floor( void );
		Floor&				operator=( const Floor& floor );
		void				addNode( AMateriaNode* node );
		void				clean( void );
    void        unsetNode( AMateria* node);
		AMateriaNode		*getNode( unsigned short  int idx ) const;
		AMateriaNode		*getFirst( void ) const;
		AMateriaNode		*getLast( void ) const;
		unsigned short int	getSize( void ) const;
};

#endif
