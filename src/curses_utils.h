/*
 * Utilities for curses
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

#ifndef CURSES_UTILS_H
#define CURSES_UTILS_H

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif


/* Clear everything but the border */
void wbclear(WINDOW* win);

/* Draw a box at x,y of size h,w with border */
void wmvbox(WINDOW* win, int y, int x, int h, int w);
/* ls, rs, ts, bs,
 * tl, tr, bl, br */
void wmvbox(WINDOW* win, int y, int x, int h, int w,    \
            chtype ls, chtype rs, chtype ts, chtype bs, \
            chtype tl, chtype tr, chtype bl, chtype br);

#endif // CURSES_UTILS_H
