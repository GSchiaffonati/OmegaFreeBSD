/* Type information for c-parser.c.
   Copyright (C) 2004 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

/* This file is machine generated.  Do not edit.  */

void
gt_ggc_mx_c_parser (void *x_p)
{
  struct c_parser * const x = (struct c_parser *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(2); i0++) {
          gt_ggc_m_9tree_node ((*x).tokens[i0].value);
        }
      }
    }
}

void
gt_pch_nx_c_parser (void *x_p)
{
  struct c_parser * const x = (struct c_parser *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_8c_parser, gt_ggc_e_8c_parser))
    {
      {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(2); i0++) {
          gt_pch_n_9tree_node ((*x).tokens[i0].value);
          gt_pch_n_S ((*x).tokens[i0].location.file);
        }
      }
    }
}

void
gt_pch_p_8c_parser (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct c_parser * const x ATTRIBUTE_UNUSED = (struct c_parser *)x_p;
  {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(2); i0++) {
      if ((void *)(x) == this_obj)
        op (&((*x).tokens[i0].value), cookie);
      if ((void *)(x) == this_obj)
        op (&((*x).tokens[i0].location.file), cookie);
    }
  }
}

/* GC roots.  */

const struct ggc_root_tab gt_ggc_r_gt_c_parser_h[] = {
  {
    &the_parser,
    1,
    sizeof (the_parser),
    &gt_ggc_mx_c_parser,
    &gt_pch_nx_c_parser
  },
  LAST_GGC_ROOT_TAB
};

