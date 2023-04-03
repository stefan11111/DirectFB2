/*
   This file is part of DirectFB.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
*/

#include <core/core.h>
#include <directfb_result.h>

/**********************************************************************************************************************/

typedef void (*Func)( void );

static Func init_funcs[] = {
      DFBResult__init,
      Core_TLS__init,
};

static Func deinit_funcs[] = {
      Core_TLS__deinit,
      DFBResult__deinit,
};

/**********************************************************************************************************************/

__dfb_constructor__
void
__DFB_init_all( void )
{
     size_t i;

     for (i = 0; i < D_ARRAY_SIZE(init_funcs); i++)
          init_funcs[i]();
}

__dfb_destructor__
void
__DFB_deinit_all( void )
{
     size_t i;

     dfb_config_deinit();

     for (i = 0; i < D_ARRAY_SIZE(deinit_funcs); i++)
          deinit_funcs[i]();
}
