/*
 * CNAPolymerase is a class describing a DNA polymerase entzyme
 * Makes a copy of strand1 to strand2.
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
#include <ctype.h>
#include <string.h>

#include "cobject.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "curses_utils.h"

#include "cnastrand.h"
#include "cnapolymerase.h"

#include "cdnapolymerase.h"

extern WINDOW* infowin;
extern WINDOW* contentwin;

CDNAPolymerase::~CDNAPolymerase()
{

}

int CDNAPolymerase::draw()
{
    wbclear(this->win);
    wrefresh(this->win);
    strand1->draw();
    strand2->draw();



    return 0;
}

/* Ask a nucleotide from user */
int CDNAPolymerase::copy()
{
    CNucleotide* ptr = strand1->ntides;

    for (int i = 0; i < cur; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
        return -1;

    e_nucl_type_t type;
    switch(ptr->type)
    {
    case ADE:
        type = THY;
        break;
    case THY:
        type = ADE;
        break;
    case GUA:
        type = CYT;
        break;
    case CYT:
        type = GUA;
        break;
    case DEFAULT: /* fall-through */
    default:
        break;
    }

    wmove(infowin, 1, 1);
    wprintw(infowin, "Which nucleotide (A, T, G, C or U)? ");
    int cur_y, cur_x;
    getyx(infowin, cur_y, cur_x);

    wrefresh(infowin);

    e_nucl_type_t input = DEFAULT;
    int first = 0;

    do {
        if (first != 0)
        {
            mvwprintw(infowin, 2, 1, "Try again!");
            wmove(infowin, cur_y, cur_x);
            wrefresh(infowin);
        }
        char tmp = wgetch(infowin);
        switch (toupper(tmp))
        {
        case 'A':
            input = ADE;
            break;
        case 'T':
            input = THY;
            break;
        case 'G':
            input = GUA;
            break;
        case 'C':
            input = CYT;
            break;
        default:
            break;
        }
        first = 1;
    } while (input != type);
    mvwprintw(infowin, 2, 1, "          ");
    wmove(infowin, cur_y, cur_x);
    wrefresh(infowin);

    strand2->add(type);

    cur++;
    draw();
    move_strands();

    return 0;
}

void CDNAPolymerase::move_strands()
{
    strand1->move(strand1->getx()-2, strand1->gety());
    strand2->move(strand2->getx()-2, strand2->gety());
}
