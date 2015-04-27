/*
 * CNAPolymerase is a class describing a NA polymerase entzyme
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

#ifndef CNAPOLYMERASE_H
#define CNAPOLYMERASE_H

#include <stdlib.h>

#include "cobject.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "cnastrand.h"

class CNAPolymerase : public CObject
{
public:
    CNAPolymerase(){}
    ~CNAPolymerase(){}

    CNAStrand* strand1;
    CNAStrand* strand2;

    virtual int copy() = 0;
    virtual int draw() = 0;
    int color;
};

#endif // CNAPOLYMERASE_H
