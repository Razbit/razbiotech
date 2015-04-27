/*
 * CNucleotide is a class describing a single nucleotide (e.g. amine)
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

#include "cobject.h"
#include "platform.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "cnucleotide.h"

CNucleotide::~CNucleotide()
{

}

int CNucleotide::draw()
{
    char ctype = 0;

    switch (type)
    {
    case ADE:
        ctype = 'A';
        break;
    case THY:
        ctype = 'T';
        break;
    case GUA:
        ctype = 'G';
        break;
    case CYT:
        ctype = 'C';
        break;
    case URA:
        ctype = 'U';
        break;
    case DEFAULT:
        break;
    }

    switch (orient)
    {
    case UP: // we're drawing the upper strand
        mvwaddch(this->win, this->y, this->x, ACS_TTEE);
        wattron(this->win, COLOR_PAIR(type));
        mvwaddch(this->win, this->y+1, this->x, ctype);
        wattroff(this->win, COLOR_PAIR(type));
        break;

    case DOWN: //lower strand
        mvwaddch(this->win, this->y+1, this->x, ACS_BTEE);
        wattron(this->win, COLOR_PAIR(type));
        mvwaddch(this->win, this->y, this->x, ctype);
        wattroff(this->win, COLOR_PAIR(type));
        break;

    default: // ???
        break;
    }


    wrefresh(this->win);

    return 0;
}

void CNucleotide::create_colors()
{
    short bg = 0;
    pair_content(0, 0, &bg);

    init_pair(ADE, COLOR_BLUE, bg);
    init_pair(THY, COLOR_YELLOW, bg);
    init_pair(GUA, COLOR_GREEN, bg);
    init_pair(CYT, COLOR_RED, bg);
    init_pair(URA, COLOR_MAGENTA, bg);
}
