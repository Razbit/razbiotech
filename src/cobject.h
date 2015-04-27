/*
 * CObject is a virtual class containing basic info on all renderable objects
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

#ifndef COBJECT_H
#define COBJECT_H

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} e_orientation_t;

class CObject
{
public:
    CObject(int x, int y, e_orientation_t orient, WINDOW* win):
        x(x), y(y), orient(orient), win(win) {}

    CObject(): x(0), y(0), orient(UP), win(stdscr) {}

    virtual ~CObject(){}

    virtual int draw(){return 0;}

    int getx(){return x;}
    int gety(){return y;}
    void getxy(int* x, int* y){*x = this->x; *y = this->y;}

    void move(int x, int y){this->x = x; this->y = y;}

    e_orientation_t get_orient(){return orient;}
    void rotate(e_orientation_t orient){this->orient = orient;}

    int x, y; /* Top-left of bounding box */
    e_orientation_t orient; /* Orientation */

    /* Window to draw this object in */
    WINDOW* win;
};

#endif // COBJECT_H
