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

#include <stdlib.h>

#include <platform.h>

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "curses_utils.h"

#include "cnucleotide.h"
#include "cnastrand.h"
#include "cdnapolymerase.h"

WINDOW* infowin;
WINDOW* contentwin;

int main()
{
    initscr();              /* Start curses mode */
    cbreak();               /* Dont wait for '\n'  from user*/
    noecho();               /* Dont echo user input */

    if (has_colors() == FALSE)
    {
        printw("Your terminal does not support color\n");
        refresh();
        return EXIT_FAILURE;
    }
    else
    {
        start_color();
    }

    infowin = newwin(8, getmaxx(stdscr), (getmaxy(stdscr)-8), 0);
    wborder(infowin, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, \
            ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
    wrefresh(infowin);

    contentwin = newwin(getmaxy(stdscr)-7, getmaxx(stdscr), 0, 0);
    wborder(contentwin, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, \
            ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
    wrefresh(contentwin);

    CNAStrand* strand = new CNAStrand(getmaxx(contentwin)/2, \
                                      getmaxy(contentwin)/2 - 1, UP, contentwin);
    CNAStrand* strand2 = new CNAStrand(getmaxx(contentwin)/2, \
                                       getmaxy(contentwin)/2 + 1, DOWN, contentwin);

    strand->add(ADE);
    strand->add(GUA);
    strand->add(CYT);
    strand->add(THY);

    strand->draw();

    CDNAPolymerase* polym = new CDNAPolymerase(getmaxx(contentwin)/2, \
                                               getmaxy(contentwin)/2, \
                                               strand, strand2, contentwin);

    while (polym->copy() == 0);

    wrefresh(contentwin);
    wrefresh(infowin);

    nocbreak();

    wbclear(infowin);
    mvwprintw(infowin, 1, 1, "DONE");
    wrefresh(infowin);
    wgetch(infowin);

    endwin();               /* End curses mode */

    return EXIT_SUCCESS;
}


