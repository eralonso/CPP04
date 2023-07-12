/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:11:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/12 14:13:08 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <string>
#include    <iostream>
#include    <iomanip>

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

int	main( void )
{
	print_title( "Test: Materia", C_YELLOW, C_PURPLE );
	// test_Materia();
	return ( 0 );
}
