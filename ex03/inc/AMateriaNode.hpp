/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaNode.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:31:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 19:33:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIANODE_H__
# define __AMATERIANODE_H__

# include	"AMateria.hpp"

class AMateriaNode
{
	private:
		AMateriaNode*	_prev;
		AMateriaNode*	_next;
		AMateria*		_content;
	public:
		AMateriaNode( void );
		AMateriaNode( AMateria* materia );
		AMateriaNode( const AMateriaNode& node );
		~AMateriaNode( void );
		AMateriaNode&	operator=( const AMateriaNode& node );
		AMateriaNode*	getPrev( void ) const;
		AMateriaNode*	getNext( void ) const;
		AMateria*		getContent( void ) const;
		void			setPrev( AMateriaNode* node );
		void			setNext( AMateriaNode* node );
};

#endif
