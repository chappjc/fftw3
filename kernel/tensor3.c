/*
 * Copyright (c) 2002 Matteo Frigo
 * Copyright (c) 2002 Steven G. Johnson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* $Id: tensor3.c,v 1.2 2003-01-11 20:44:37 stevenj Exp $ */

#include "ifftw.h"

tensor *X(mktensor_rowmajor)(uint rnk, const uint *n,
			     const uint *niphys, const uint *nophys,
			     int is, int os)
{
     tensor *x = X(mktensor)(rnk);

     if (FINITE_RNK(rnk) && rnk > 0) {
          uint i;

          A(n && niphys && nophys);
          x->dims[rnk - 1].is = is;
          x->dims[rnk - 1].os = os;
          x->dims[rnk - 1].n = n[rnk - 1];
          for (i = rnk - 1; i > 0; --i) {
               x->dims[i - 1].is = x->dims[i].is * niphys[i];
               x->dims[i - 1].os = x->dims[i].os * nophys[i];
               x->dims[i - 1].n = n[i - 1];
          }
     }
     return x;
}

