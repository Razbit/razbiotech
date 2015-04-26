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

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "curses_utils.h"

#include "cnucleotide.h"

CNucleotide::~CNucleotide()
{

}

int CNucleotide::draw()
{
    char tmp[2] = {0, 0};
    char ctype = 0;
    int color = COLOR_WHITE;

    switch (type)
    {
    case ADE:
        ctype = 'A';
        color = ADE;
        break;
    case THY:
        ctype = 'T';
        color = THY;
        break;
    case GUA:
        ctype = 'G';
        color = GUA;
        break;
    case CYT:
        ctype = 'C';
        color = CYT;
        break;
    case URA:
        ctype = 'U';
        color = URA;
        break;
    }

    switch (orient)
    {
    case UP: // we're drawing the upper strand
        mvaddch(this->y, this->x, '+');
        fmvaddch(color, this->y+1, this->x, ctype);
        break;

    case DOWN: //lower strand
        mvaddch(this->y+1, this->x, '+');
        fmvaddch(color, this->y, this->x, ctype);
        break;

    default: // ???
        break;
    }


    refresh();

    return 0;
}

