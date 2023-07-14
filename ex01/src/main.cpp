/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:11:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/14 19:20:18 by eralonso         ###   ########.fr       */
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
	int	fill;
	int	odd;
	int	size;

	size = msg.length() >= FILL ? msg.length() + 10 : FILL;
	fill = ( size - msg.length() ) / 2;
	odd = msg.length() < FILL ? msg.length() % 2 : 0;
	std::cout << clr_border;
	std::cout << "\n " << std::setfill( '_' ) << std::setw( size ) << "" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( fill + odd ) << "" << clr_text << msg << clr_border << std::setw( fill + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( '_' ) << std::setw( size + 2 ) << "|\n" << std::endl;
	std::cout << C_DEFAULT;
}

void	test_WrongAnimal( void )
{
	print_title( "Constructors", C_GREEN, C_YELLOW );
	std::cout << C_GREEN"const WrongAnimal* wrongAnimal"C_DEFAULT << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << std::endl;
	std::cout << C_GREEN"const WrongAnimal* wrongAnimalCat"C_DEFAULT << std::endl;
	const WrongAnimal* wrongAnimalCat = new WrongCat();
	std::cout << std::endl;
	std::cout << C_GREEN"const WrongCat* wrongCat"C_DEFAULT << std::endl;
	const WrongCat* wrongCat = new WrongCat();

	print_title( "Methods: getType", C_PURPLE, C_YELLOW );
	std::cout << "wrongAnimal -> " << wrongAnimal->getType() << " " << std::endl;
	std::cout << "wrongAnimalCat -> " << wrongAnimalCat->getType() << " " << std::endl;
	std::cout << "wrongCat -> " << wrongCat->getType() << " " << std::endl;

	print_title( "Methods: makeSound", C_PURPLE, C_YELLOW );
	std::cout << "wrongAnimal -> ";
	wrongAnimal->makeSound();
	std::cout << "wrongAnimalCat -> ";
	wrongAnimalCat->makeSound();
	std::cout << "wrongCat -> ";
	wrongCat->makeSound();

	print_title( "Destructors", C_RED, C_YELLOW );
	std::cout << C_RED"wrongAnimal"C_DEFAULT << std::endl;
	delete wrongAnimal;
	std::cout << std::endl;
	std::cout << C_RED"wrongAnimalCat"C_DEFAULT << std::endl;
	delete wrongAnimalCat;
	std::cout << std::endl;
	std::cout << C_RED"wrongCat"C_DEFAULT << std::endl;
	delete wrongCat;
}

void	test_Animal_v1( void )
{
	print_title( "Constructors", C_GREEN, C_YELLOW );
	std::cout << C_GREEN"const Animal* animal"C_DEFAULT << std::endl;
	const Animal* animal = new Animal();
	std::cout << std::endl;
	std::cout << C_GREEN"const Animal* animalDog"C_DEFAULT << std::endl;
	const Animal* animalDog = new Dog();
	std::cout << std::endl;
	std::cout << C_GREEN"const Animal* animalCat"C_DEFAULT << std::endl;
	const Animal* animalCat = new Cat();
	std::cout << std::endl;
	std::cout << C_GREEN"const Dog* dog"C_DEFAULT << std::endl;
	const Dog* dog = new Dog();
	std::cout << std::endl;
	std::cout << C_GREEN"const Cat* cat"C_DEFAULT << std::endl;
	const Cat* cat = new Cat();

	print_title( "Methods: getType", C_PURPLE, C_YELLOW );
	std::cout << "animal -> " << animal->getType() << " " << std::endl;
	std::cout << "animalDog -> " << animalDog->getType() << " " << std::endl;
	std::cout << "animalCat -> " << animalCat->getType() << " " << std::endl;
	std::cout << "dog -> " << dog->getType() << " " << std::endl;
	std::cout << "cat -> " << cat->getType() << " " << std::endl;

	print_title( "Methods: makeSound", C_PURPLE, C_YELLOW );
	std::cout << "animal -> ";
	animal->makeSound();	
	std::cout << "animalDog -> ";
	animalDog->makeSound();
	std::cout << "animalCat -> ";
	animalCat->makeSound();
	std::cout << "dog -> ";
	dog->makeSound();
	std::cout << "cat -> ";
	cat->makeSound();

	print_title( "Destructors", C_RED, C_YELLOW );
	std::cout << C_RED"animal"C_DEFAULT << std::endl;
	delete animal;
	std::cout << std::endl;
	std::cout << C_RED"animalDog"C_DEFAULT << std::endl;
	delete animalDog;
	std::cout << std::endl;
	std::cout << C_RED"animalCat"C_DEFAULT << std::endl;
	delete animalCat;
	std::cout << std::endl;
	std::cout << C_RED"dog"C_DEFAULT << std::endl;
	delete dog;
	std::cout << std::endl;
	std::cout << C_RED"cat"C_DEFAULT << std::endl;
	delete cat;
}

void	test_Cat( Cat *cat, unsigned int first_getIdea_idx, unsigned int second_getIdea_idx, std::ostream& out, std::string stream )
{
	out << "getType(): " << cat->getType();
	out << " | getIdea( 0 ): " << cat->getIdea( first_getIdea_idx );
	out << " | getIdea( 1 ): " << cat->getIdea( second_getIdea_idx );
	out << " | getIndex(): " << cat->getIndex();
	out << " | getCurrentIdea(): " << cat->getCurrentIdea() << std::endl;
	out << " | printBrain( " << stream << " ): ";
	cat->printBrain( out );
	out << std::endl;
}

void	test_Dog( Dog *dog, unsigned int first_getIdea_idx, unsigned int second_getIdea_idx, std::ostream& out, std::string stream )
{
	out << "getType(): " << dog->getType();
	out << " | getIdea( 0 ): " << dog->getIdea( first_getIdea_idx );
	out << " | getIdea( 1 ): " << dog->getIdea( second_getIdea_idx );
	out << " | getIndex(): " << dog->getIndex();
	out << " | getCurrentIdea(): " << dog->getCurrentIdea() << std::endl;
	out << " | printBrain( " << stream << " ): ";
	dog->printBrain( out );
	out << std::endl;
}

void	test_Animal_basic_v2( Animal* animals[], unsigned short int size, unsigned int c_size, unsigned short int (*cmp)( unsigned int , unsigned int ) )
{
	unsigned short int lower;

	print_title( "Methods: getType() && getIdea( 0 ) && getIdea( 1 ) && getIndex() && getCurrentIdea() && printBrain( std::cout )", C_PURPLE, C_YELLOW );
	for ( unsigned int i = 0; i < c_size; i++ )
	{
		lower = cmp( i, size );
		std::cout << C_PURPLE"Animal* animals[ "C_WHITE << i << C_PURPLE" ]"C_WHITE << std::endl;
		switch ( lower )
		{
			case 1:
				test_Cat( dynamic_cast<Cat *>( animals[ i ] ), 0, 1, std::cout, "std::cout" );
				break ;
			default:
				test_Dog( dynamic_cast<Dog *>( animals[ i ] ), 0, 1, std::cout, "std::cout" );
				break ;
		}
		std::cout << std::endl;
	}
}

void	test_Animal_advanced_v2( Animal* animals[], unsigned short int size, unsigned int c_size, unsigned short int (*cmp)( unsigned int , unsigned int ) )
{
	( void )size;
	( void )c_size;
	( void )animals;
	( void )cmp;
	return ;
}

unsigned short int	lower_than( unsigned int num1, unsigned int num2 )
{
	if ( num1 < num2 )
		return ( 1 );
	return ( 0 );
}

void	test_Animal_v2( unsigned short int size )
{
	unsigned int		c_size;
	unsigned short int	lower;

	c_size = size * 2;
	print_title( "Constructors", C_GREEN, C_YELLOW );
	std::cout << C_GREEN"Animal* animals[ "C_WHITE << c_size << C_GREEN" ]"C_DEFAULT << std::endl;
	Animal* animals[ c_size ];
	std::cout << std::endl;

	for ( unsigned int i = 0; i < c_size; i++ )
	{
		lower = i < size;
		switch ( lower )
		{
			case 1:
				std::cout << C_GREEN"Animal* animals[ "C_WHITE << i << C_GREEN" ] = new Cat()"C_DEFAULT << std::endl;
				animals[ i ] = new Cat();
				dynamic_cast<Cat *>(animals[ i ])->addIdea( "Exploding Kittens" );
				break ;
			default:
				std::cout << C_GREEN"Animal* animals[ "C_WHITE << i << C_GREEN" ] = new Dog()"C_DEFAULT << std::endl;
				animals[ i ] = new Dog();
				dynamic_cast<Dog *>(animals[ i ])->addIdea( "Exploding Puppies" );
				break ;
		}
		std::cout << std::endl;
	}

	test_Animal_basic_v2( animals, size, c_size, lower_than );
	test_Animal_advanced_v2( animals, size, c_size, lower_than );

	print_title( "Destructors", C_RED, C_YELLOW );
	for ( unsigned int i = 0; i < c_size; i++ )
	{
		std::cout << C_RED"animals[ "C_WHITE << i << C_RED" ]"C_DEFAULT << std::endl;
		delete animals[ i ];
		std::cout << std::endl;
	}
}

int	main( void )
{
	print_title( "Test: Animal V.1", C_BLUE, C_YELLOW );
	test_Animal_v1();
	print_title( "Test: WrongAnimal", C_BLUE, C_YELLOW );
	test_WrongAnimal();
	print_title( "Test: Animal V.2", C_BLUE, C_YELLOW );
	test_Animal_v2( 5 );
	return ( 0 );
}
