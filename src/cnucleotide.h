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
    ADE = COLOR_BLUE,
    THY = COLOR_YELLOW,
    GUA = COLOR_GREEN,
    CYT = COLOR_RED,
    URA = COLOR_MAGENTA,
    DEFAULT = -1
} e_nucleotide_type_t;


class CNucleotide : public CObject
{
public:
    CNucleotide(): type(DEFAULT) {}

    CNucleotide(e_nucleotide_type_t type, int x, int y, e_orientation_t orient):
    type(type)
    {
        CObject(x, y, orient);
    }

    virtual ~CNucleotide();

    int draw();

    e_nucleotide_type_t get_type(){return type;}
    void set_type(e_nucleotide_type_t type){this->type = type;}

    e_nucleotide_type_t type;
};

#endif // CNUCLEOTIDE_H
