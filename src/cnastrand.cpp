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

#include <stdlib.h>

#include "cnastrand.h"

#ifdef PLATFORM_WIN32
#include <pdcurses.h>
#else
#include <curses.h>
#endif

#include "curses_utils.h"

#include "cnucleotide.h"


CNAStrand::~CNAStrand()
{
    CNucleotide* ptr = ntides;
    CNucleotide* ptr2 = ntides;

    /* find the last element */
    while (ptr->next != NULL)
    {
        ptr2 = ptr->next;
        delete ptr;
        ptr = ptr2;
    }

    ntides = NULL;
}

int CNAStrand::draw()
{
    CNucleotide* ptr = ntides;
    while (ptr != NULL)
    {
        ptr->draw();

        if (ptr->next != NULL)
        {
            if (orient == UP)
                mvwaddch(this->win, this->y, ptr->x+1, '-');
            else
                mvwaddch(this->win, this->y+1, ptr->x+1, '-');
        }

        ptr = ptr->next;
    }

    wrefresh(this->win);

    return 0;
}

void CNAStrand::add(e_nucl_type_t type)
{

    /* If we already have an element in the list */
    if (ntides != NULL)
    {
        CNucleotide* ptr = ntides;

        /* find the last element */
        while (ptr->next != NULL)
            ptr = ptr->next;

        /* Add new nucleotide to the list */
        ptr->next = new CNucleotide(type, ptr->x+2, ptr->y, this->orient, this->win);
    }
    else
    {
        ntides = new CNucleotide(type, this->x, this->y, this->orient, this->win);
    }
}
