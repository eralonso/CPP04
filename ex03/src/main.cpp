/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:11:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 18:23:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <string>
#include    <iostream>
#include    <iomanip>
#include	"IMateriaSource.hpp"
#include	"ICharacter.hpp"
#include	"AMateria.hpp"
#include	"MateriaSource.hpp"
#include	"Character.hpp"
#include	"Ice.hpp"
#include	"Cure.hpp"

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

void    test_Materia( void )
{
    IMateriaSource	*src = new MateriaSource();
    ICharacter		*me = new Character("me");
    ICharacter		*bob = new Character("bob");
    AMateria		*tmp;

    src->learnMateria( new Ice() );
    src->learnMateria( new Cure() );

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

int	main( void )
{
	print_title( "Test: Materia", C_YELLOW, C_PURPLE );
	test_Materia();
	return ( 0 );
}
