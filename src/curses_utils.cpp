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

#include "curses_utils.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

void wbclear(WINDOW* win)
{
    int h, w;
    getmaxyx(win, h, w);
    h--;
    w--;

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
            mvwaddch(win, i, j, ' ');
    }
}

/* Draw a box at x,y of size h,w with border */
void wmvbox(WINDOW* win, int y, int x, int h, int w)
{
    wmvbox(win, y, x, h, w, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, \
           ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
}

/* Draw a box at x,y of size h,w with border
 * ls, rs, ts, bs,
 * tl, tr, bl, br */
void wmvbox(WINDOW* win, int y, int x, int h, int w,    \
            chtype ls, chtype rs, chtype ts, chtype bs, \
            chtype tl, chtype tr, chtype bl, chtype br)
{
    // left
    for (int i = y + 1; i < y + h; i++)
        mvwaddch(win, i, x, ls);
    // right
    for (int i = y + 1; i < y + h; i++)
        mvwaddch(win, i, x + w, rs);
    // top
    for (int i = x + 1; i < x + w; i++)
        mvwaddch(win, y, i, ts);
    // bottom
    for (int i = x + 1; i < x + w; i++)
        mvwaddch(win, y + h, i, bs);
    // tl
    mvwaddch(win, y, x, tl);
    // tr
    mvwaddch(win, y, x + w, tr);
    // bl
    mvwaddch(win, y + h, x, bl);
    // br
    mvwaddch(win, y + h, x + w, br);
}



