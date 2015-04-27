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

#ifndef CDNAPOLYMERASE_H
#define CDNAPOLYMERASE_H

#include <stdlib.h>

#include "cobject.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "cnastrand.h"
#include "cnapolymerase.h"

#define COLOR_DNAPOLYM 6

class CDNAPolymerase : public CNAPolymerase
{
public:
    CDNAPolymerase(int x, int y, CNAStrand* strand1, CNAStrand* strand2, WINDOW* win)
    {
        this->x = x;
        this->y = y;
        this->strand1 = strand1;
        this->strand2 = strand2;
        this->win = win;

        cur = 0;

        short bg = 0;
        pair_content(0, 0, &bg);

        init_pair(COLOR_DNAPOLYM, COLOR_CYAN, bg);
    }

    ~CDNAPolymerase();

    int draw();
    int copy();
    void move_strands();

    int cur;
};

#endif // CDNAPOLYMERASE_H
