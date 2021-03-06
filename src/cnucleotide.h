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


#ifndef CNUCLEOTIDE_H
#define CNUCLEOTIDE_H

#include "cobject.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

typedef enum
{
    ADE = 1,
    THY = 2,
    GUA = 3,
    CYT = 4,
    URA = 5,
    DEFAULT = -1
} e_nucl_type_t;


class CNucleotide : public CObject
{
public:
    CNucleotide(): type(DEFAULT), next(NULL)
    {
        create_colors();
    }

    CNucleotide(e_nucl_type_t type, int x, int y, e_orientation_t orient,
                WINDOW* win): next(NULL)
    {
        set(type, x, y, orient, win);
        create_colors();
    }

    virtual ~CNucleotide();

    int draw();

    e_nucl_type_t get_type(){return type;}
    void set_type(e_nucl_type_t type){this->type = type;}

    void set(e_nucl_type_t type, int x, int y, e_orientation_t orient, WINDOW* win)
    {
        this->x = x;
        this->y = y;
        this->orient = orient;
        this->win = win;
        this->type = type;
    }

    void create_colors();

    e_nucl_type_t type;

    CNucleotide* next;
};

#endif // CNUCLEOTIDE_H
