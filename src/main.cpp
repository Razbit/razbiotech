/*
**/

/* Copyright (C) 2015  Eetu "Razbit" Pesonen
 *
 * This file is part of razbiotech.
 *
 * razbiotech is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * razbiotech is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with razbiotech.  If not, see <http://www.gnu.org/licenses/>.
**/

#include <iostream>

#include <platform.h>

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "cnucleotide.h"

using namespace std;

int main()
{
    initscr();              /* Start curses mode */
    if (has_colors() == FALSE)
        printw("Your terminal does not support color\n");
    else
        start_color();

    CNucleotide* nucl1 = new CNucleotide(ADE, 5, 5, UP);
    nucl1->draw();

    getch();                /* Wait for user input */
    endwin();               /* End curses mode */

    return 0;
}

