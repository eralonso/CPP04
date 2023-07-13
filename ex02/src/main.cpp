/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:11:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/13 14:29:55 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AAnimal.hpp"
#include	"Cat.hpp"
#include	"Dog.hpp"
#include	"WrongAnimal.hpp"
#include	"WrongCat.hpp"
#include	<iostream>
#include	<iomanip>

#define FILL		40
#define C_DEFAULT	"\033[0m"
#define C_RED		"\033[1;91m"
#define C_GREEN		"\033[1;92m"
#define C_YELLOW	"\033[1;93m"
#define C_BLUE		"\033[1;94m"
#define C_PINK		"\033[1;95m"
#define C_CYAN		"\033[1;96m"
#define C_WHITE		"\033[1;97m"
#define C_PURPLE	"\033[1;38;2;150;25;250m"

void    print_title( std::string msg, std::string clr_text, std::string clr_border )
{
        int     fill;
        int     odd;

        fill = ( FILL - msg.length() ) / 2;
        odd = msg.length() % 2;
		std::cout << clr_border;
        std::cout << "\n " << std::setfill('_') << std::setw(FILL - 1) << "" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw( fill + odd ) << "" << clr_text << msg << clr_border << std::setw( fill ) << "|" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
        std::cout << "|" << std::setfill('_') << std::setw(FILL + 1) << "|\n" << std::endl;
		std::cout << C_DEFAULT;
}

void	test_Animal_v2( int size )
{
	int		c_size;
	int		lower;
	// Discomment to check that AAnimal is an abstract class and generate a compile error.
	// AAnimal	animal;
	// AAnimal	*animal_ptr = new AAnimal();

	c_size = size * 2;
	print_title( "Constructors", C_GREEN, C_YELLOW );
	AAnimal* animals[ c_size ];

	for ( int i = 0; i < c_size; i++ )
	{
		lower = i < size;
		switch ( lower )
		{
			case 1:
				animals[ i ] = new Cat();
				dynamic_cast<Cat *>(animals[ i ])->addIdea( "Exploding Kittens" );
				break ;
			default:
				animals[ i ] = new Dog();
				dynamic_cast<Dog *>(animals[ i ])->addIdea( "Exploding Puppies" );
				break ;
		}
	}

	print_title( "Method: getType", C_GREEN, C_YELLOW );
	for ( int i = 0; i < c_size; i++ )
	{
		lower = i < size;
		switch ( lower )
		{
			case 1:
				std::cout << dynamic_cast<Cat *>(animals[ i ])->getType() << " -> ";
				std::cout << dynamic_cast<Cat *>(animals[ i ])->getIdea( 0 ) << std::endl;
				break ;
			default:
				std::cout << dynamic_cast<Dog *>(animals[ i ])->getType() << " -> ";
				std::cout << dynamic_cast<Dog *>(animals[ i ])->getIdea( 0 ) << std::endl;			
				break ;
		}
	}

	print_title( "Destructors", C_RED, C_YELLOW );
	for ( int i = 0; i < c_size; i++ )
		delete animals[ i ];
}

int	main( void )
{
	print_title( "Test: Animal V.2", C_YELLOW, C_PURPLE );
	test_Animal_v2( 5 );
	return ( 0 );
}
