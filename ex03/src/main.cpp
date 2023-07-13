/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2023/07/12 19:21:04 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Output:
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
*/

#include <iostream>
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main( void )
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }


int main( void )
{
	std::cout << "1. Creating MateriaSource" << std::endl; 
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;
		//src->printMaterias();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "2. \"src\" learning 5 materias" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		std::cout << std::endl;
		Ice	*mat = new Ice();
		src->learnMateria(mat);
		// delete	mat;

		// std::cout << std::endl;
		// src->printMaterias();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "3. Creating Character \"vilma\" and \"oktorok\"" << std::endl;
		Character* vilma = new Character("vilma");
		vilma->printMaterias();
		std::cout << std::endl;

		Character* oktorok = new Character("oktorok");
		oktorok->printMaterias();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia" << std::endl;
		vilma->equip(NULL);
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		tmp = src->createMateria("cure");
		vilma->equip(tmp);
		tmp = src->createMateria("cure");
		vilma->equip(tmp);
		tmp = src->createMateria("ice");
		vilma->equip(tmp);

		std::cout << std::endl;
		vilma->printMaterias();

		std::cout << std::endl;
		tmp = src->createMateria("ice"); //esto lo pongo yo
		oktorok->equip(tmp);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "5. Testing Character Assignation overload \"vilma = oktorok\" for deep copy and changed vilma afterwards" << std::endl;	
		*oktorok = *vilma;
		
		vilma->unequip(0);
		std::cout << "VILMA" << std::endl;
		vilma->printMaterias();
		std::cout << std::endl;

		std::cout << "OKTOROK" << std::endl;
		oktorok->printMaterias();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "6. Testing character copy constructor for deep copy \"stardust = Character(vilma)\" and changed vilma afterwards" << std::endl;
		
		vilma->printMaterias();
		Character* stardust = new Character(*vilma);
    stardust->printMaterias();

		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		std::cout << "VILMA" << std::endl;
		vilma->printMaterias();
		std::cout << std::endl;

		std::cout << "STARDUST" << std::endl;
    stardust->printMaterias();


	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	
	std::cout << "7. \"vilma\" using all equiped materias on \"oktorok\" " << std::endl;
		vilma->use(0, *oktorok);
		vilma->use(1, *oktorok);
		vilma->use(2, *oktorok);
		vilma->use(3, *oktorok);
		vilma->use(10, *oktorok);
		vilma->use(-1, *oktorok);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "8. \"vilma\" trying to use unequiped materias on \"oktorok\" " << std::endl;
		vilma->unequip(0);
		vilma->use(0, *oktorok);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "9. New character \"lucifer\" equipping and unequipping materias" << std::endl;
		ICharacter* lucifer = new Character("lucifer");
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;

		lucifer->equip(cure);
		lucifer->equip(ice);
		lucifer->equip(cure);
		lucifer->equip(ice);
		lucifer->unequip(0);
		lucifer->unequip(1);
		lucifer->unequip(2);
		lucifer->unequip(3);
		lucifer->equip(cure);
		lucifer->equip(ice);

		lucifer->printMaterias();
		lucifer->printTrash();

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

  std::cout << "10. Testing if unequiped materia is freed" << std::endl;

	ICharacter* test = new Character("test");
		
	 	tmp = src->createMateria("ice");
	 	test->equip(tmp);
   	test->unequip(0);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	std::cout << "11. Deleting \"vilma\", \"oktorok\", \"stardust\" and \"lucifer\"" << std::endl;

  std::cout << "TEST" << std::endl;
	delete test;
  std::cout << std::endl;
  std::cout << "LUCIFER" << std::endl;
	delete lucifer;
  std::cout << std::endl;
  std::cout << "STARDUST" << std::endl;
  stardust->printMaterias();
  stardust->printTrash();
  delete stardust;
  std::cout << std::endl;
  std::cout << "OKTOROK" << std::endl;
  oktorok->printMaterias();
  oktorok->printTrash();
	delete oktorok;
  std::cout << std::endl;
  std::cout << "VILMA" << std::endl;
  vilma->printMaterias();
  vilma->printTrash();
  delete vilma;
  std::cout << std::endl;
  std::cout << "SRC" << std::endl;
	delete src;

	return (0);
}
