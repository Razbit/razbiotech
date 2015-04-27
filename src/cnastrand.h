/*
 * CNAStrand is a class describing a single strand of a nucleic acid,
 * i.e. a DNA or RNA strand
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

#ifndef CNASTRAND_H
#define CNASTRAND_H

#include <stdlib.h>

#include "cobject.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "curses_utils.h"

#include "cnucleotide.h"

class CNAStrand : public CObject
{
public:
    CNAStrand(): ntides(NULL) {}

    CNAStrand(int x, int y, e_orientation_t orient, WINDOW* win): ntides(NULL)
    {
        set(x, y, orient, win);
    }

    ~CNAStrand();

    int draw();

    void add(e_nucl_type_t type);

    void set(int x, int y, e_orientation_t orient, WINDOW* win)
    {
        this->x = x;
        this->y = y;
        this->orient = orient;
        this->win = win;
    }

    CNucleotide* ntides; /* A list of all nucleotides in the strand. */
};

#endif // CNASTRAND_H
