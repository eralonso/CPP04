/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:11:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/10 19:14:14 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	"Cat.hpp"
#include	"Dog.hpp"
#include	"WrongAnimal.hpp"
#include	"WrongCat.hpp"
#include	<iostream>
#include	<iomanip>

#define FILL	40

void    print_title( std::string msg )
{
        int     fill;
        int     odd;

        fill = ( FILL - msg.length() ) / 2;
        odd = msg.length() % 2;
        std::cout << "\n " << std::setfill('_') << std::setw(FILL - 1) << "" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw( fill + odd ) << "" << msg << std::setw( fill ) << "|" << std::endl;
        std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
        std::cout << "|" << std::setfill('_') << std::setw(FILL + 1) << "|\n" << std::endl;
}

void	test_WrongAnimal( void )
{
	print_title( "Constructors" );
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	print_title( "Methods" );
	std::cout << "wrongCat -> " << wrongCat << " " << std::endl;
	std::cout << "wrongAnimal -> " << wrongAnimal << " " << std::endl;
	std::cout << "wrongCat -> ";
	wrongCat->makeSound();
	std::cout << "wrongAnimal -> ";
	wrongAnimal->makeSound();

	print_title( "Destructors" );
	delete wrongCat;
	delete wrongAnimal;
}

void	test_Animal( void )
{
	print_title( "Constructors" );
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	Animal* cat = new Cat();

	print_title( "Method: getType" );
	std::cout << "dog -> " << dog << " " << std::endl;
	std::cout << "cat -> " << cat << " " << std::endl;
	std::cout << "animal -> " << animal << " " << std::endl;

	print_title( "Method: makeSound" );
	std::cout << "cat -> ";
	cat->makeSound();
	std::cout << "dog -> ";
	dog->makeSound();
	std::cout << "animal -> ";
	animal->makeSound();

	print_title( "Attribute: _brain" );
	static_cast<Cat *>(cat)->addIdea( "First idea" );
	std::cout << "cat -> " << static_cast<Cat *>(cat) << std::endl;

	print_title( "Destructors" );
	delete cat;
	delete dog;
	delete animal;
}

int	main( void )
{
	print_title( "Test: Animal" );
	test_Animal();
	// print_title( "Test: WrongAnimal" );
	// test_WrongAnimal();
	return ( 0 );
}
