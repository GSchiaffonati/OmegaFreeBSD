/* Type information for ipa-inline.c.
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

/* GC roots.  */

static void gt_ggc_ma_order (void *);
static void
gt_ggc_ma_order (ATTRIBUTE_UNUSED void *x_p)
{
  if (order != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(nnodes); i0++) {
      gt_ggc_m_11cgraph_node (order[i0]);
    }
    ggc_mark (order);
  }
}

static void gt_pch_pa_order
    (void *, void *, gt_pointer_operator, void *);
static void gt_pch_pa_order (ATTRIBUTE_UNUSED void *this_obj,
      ATTRIBUTE_UNUSED void *x_p,
      ATTRIBUTE_UNUSED gt_pointer_operator op,
      ATTRIBUTE_UNUSED void * cookie)
{
  if (order != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(nnodes); i0++) {
      if ((void *)(order) == this_obj)
        op (&(order[i0]), cookie);
    }
    if ((void *)(&order) == this_obj)
      op (&(order), cookie);
  }
}

static void gt_pch_na_order (void *);
static void
gt_pch_na_order (ATTRIBUTE_UNUSED void *x_p)
{
  if (order != NULL) {
    size_t i1;
    for (i1 = 0; i1 != (size_t)(nnodes); i1++) {
      gt_pch_n_11cgraph_node (order[i1]);
    }
    gt_pch_note_object (order, &order, gt_pch_pa_order, gt_types_enum_last);
  }
}

const struct ggc_root_tab gt_ggc_r_gt_ipa_inline_h[] = {
  {
    &order,
    1,
    sizeof (order),
    &gt_ggc_ma_order,
    &gt_pch_na_order
  },
  LAST_GGC_ROOT_TAB
};

