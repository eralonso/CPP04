/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:11:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 11:18:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
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

void	test_WrongAnimal( void )
{
	print_title( "Constructors", C_GREEN, C_YELLOW );
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	print_title( "Methods", C_GREEN, C_YELLOW );
	std::cout << "wrongCat -> " << wrongCat << " " << std::endl;
	std::cout << "wrongAnimal -> " << wrongAnimal << " " << std::endl;
	std::cout << "wrongCat -> ";
	wrongCat->makeSound();
	std::cout << "wrongAnimal -> ";
	wrongAnimal->makeSound();

	print_title( "Destructors", C_GREEN, C_YELLOW );
	delete wrongCat;
	delete wrongAnimal;
}

void	test_Animal_v1( void )
{
	print_title( "Constructors", C_GREEN, C_YELLOW );
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	Animal* cat = new Cat();

	print_title( "Method: getType", C_GREEN, C_YELLOW );
	std::cout << "dog -> " << dog << " " << std::endl;
	std::cout << "cat -> " << cat << " " << std::endl;
	std::cout << "animal -> " << animal << " " << std::endl;

	print_title( "Method: makeSound", C_GREEN, C_YELLOW );
	std::cout << "cat -> ";
	cat->makeSound();
	std::cout << "dog -> ";
	dog->makeSound();
	std::cout << "animal -> ";
	animal->makeSound();

	print_title( "Attribute: _brain", C_GREEN, C_YELLOW );
	static_cast<Cat *>(cat)->addIdea( "First idea" );
	std::cout << "cat -> " << static_cast<Cat *>(cat) << std::endl;

	print_title( "Destructors", C_GREEN, C_YELLOW );
	delete cat;
	delete dog;
	delete animal;
}

void	test_Animal_v2( int size )
{
	int		c_size;
	int		lower;

	c_size = size * 2;
	print_title( "Constructors", C_GREEN, C_YELLOW );
	Animal* animals[ c_size ];

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

	print_title( "Destructors", C_GREEN, C_YELLOW );
	for ( int i = 0; i < c_size; i++ )
		delete animals[ i ];
}

int	main( void )
{
	print_title( "Test: Animal V.1", C_YELLOW, C_PURPLE );
	test_Animal_v1();
	print_title( "Test: WrongAnimal", C_YELLOW, C_PURPLE );
	test_WrongAnimal();
	print_title( "Test: Animal V.2", C_YELLOW, C_PURPLE );
	test_Animal_v2( 5 );
	return ( 0 );
}
