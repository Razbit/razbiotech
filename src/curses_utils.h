/*
 * Utilities for doing stuff with curses.
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

#ifndef CURSES_UTILS
#define CURSES_UTILS

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

/* waddch with colors */
int fbwaddch(int fg, int bg, WINDOW* win, const chtype ch)
{
    int ret = 0;
    if (has_colors() == FALSE)
    {
        ret = waddch(win, ch);
    }
    else
    {
        init_pair(1, fg, bg);
        attron(COLOR_PAIR(1));
        ret = waddch(win, ch);
        attroff(COLOR_PAIR(1));
    }

    return ret;
}

int fwaddch(int fg, WINDOW* win, const chtype ch)
{
    short int bg = 0;
    pair_content(0, 0, &bg);
    return fbwaddch(fg, bg, win, ch);
}

int bwaddch(int bg, WINDOW* win, const chtype ch)
{
    short int fg = 0;
    pair_content(0, &fg, 0);
    return fbwaddch(fg, bg, win, ch);
}


/* addch with colors */
int fbaddch(int fg, int bg, const chtype ch)
{
    return fbwaddch(fg, bg, stdscr, ch);
}

int faddch(int fg, const chtype ch)
{
    return fwaddch(fg, stdscr, ch);
}

int baddch(int bg, const chtype ch)
{
    return bwaddch(bg, stdscr, ch);
}

/* mvwaddch with colors */
int fbmvwaddch(int fg, int bg, int y, int x, WINDOW* win, const chtype ch)
{
    wmove(win, y, x);
    return fbwaddch(fg, bg, win, ch);
}

int fmvwaddch(int fg, int y, int x, WINDOW* win, const chtype ch)
{
    wmove(win, y, x);
    return fwaddch(fg, win, ch);
}

int bmvwaddch(int bg, int y, int x, WINDOW* win, const chtype ch)
{
    wmove(win, y, x);
    return bwaddch(bg, win, ch);
}

/* mvaddch with colors */
int fbmvaddch(int fg, int bg, int y, int x, const chtype ch)
{
    return fbmvwaddch(fg, bg, y, x, stdscr, ch);
}

int fmvaddch(int fg, int y, int x, const chtype ch)
{
    return fmvwaddch(fg, y, x, stdscr, ch);
}

int bmvaddch(int bg, int y, int x, const chtype ch)
{
    return bmvwaddch(bg, y, x, stdscr, ch);
}

#endif // CURSES_UTILS

