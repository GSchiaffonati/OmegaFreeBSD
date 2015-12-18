/* Type information for tree.c.
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
gt_ggc_mx_tree_int_map (void *x_p)
{
  struct tree_int_map * const x = (struct tree_int_map *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).from);
    }
}

void
gt_ggc_mx_type_hash (void *x_p)
{
  struct type_hash * const x = (struct type_hash *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).type);
    }
}

void
gt_ggc_m_P12tree_int_map4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_12tree_int_map ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_ggc_m_P9type_hash4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_9type_hash ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_pch_nx_tree_int_map (void *x_p)
{
  struct tree_int_map * const x = (struct tree_int_map *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_12tree_int_map, gt_ggc_e_12tree_int_map))
    {
      gt_pch_n_9tree_node ((*x).from);
    }
}

void
gt_pch_nx_type_hash (void *x_p)
{
  struct type_hash * const x = (struct type_hash *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_9type_hash, gt_ggc_e_9type_hash))
    {
      gt_pch_n_9tree_node ((*x).type);
    }
}

void
gt_pch_n_P12tree_int_map4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P12tree_int_map4htab, gt_e_P12tree_int_map4htab))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_12tree_int_map ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P12tree_int_map4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_n_P9type_hash4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P9type_hash4htab, gt_e_P9type_hash4htab))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_9type_hash ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P9type_hash4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_p_12tree_int_map (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct tree_int_map * const x ATTRIBUTE_UNUSED = (struct tree_int_map *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).from), cookie);
}

void
gt_pch_p_9type_hash (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct type_hash * const x ATTRIBUTE_UNUSED = (struct type_hash *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).type), cookie);
}

void
gt_pch_p_P12tree_int_map4htab (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct htab * const x ATTRIBUTE_UNUSED = (struct htab *)x_p;
  if ((*x).entries != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
      if ((void *)((*x).entries) == this_obj)
        op (&((*x).entries[i0]), cookie);
    }
    if ((void *)(x) == this_obj)
      op (&((*x).entries), cookie);
  }
}

void
gt_pch_p_P9type_hash4htab (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct htab * const x ATTRIBUTE_UNUSED = (struct htab *)x_p;
  if ((*x).entries != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
      if ((void *)((*x).entries) == this_obj)
        op (&((*x).entries[i0]), cookie);
    }
    if ((void *)(x) == this_obj)
      op (&((*x).entries), cookie);
  }
}

/* GC roots.  */

const struct ggc_root_tab gt_ggc_r_gt_tree_h[] = {
  {
    &last_annotated_node,
    1,
    sizeof (last_annotated_node),
    &gt_ggc_mx_location_s,
    &gt_pch_nx_location_s
  },
  {
    &int_cst_node,
    1,
    sizeof (int_cst_node),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  LAST_GGC_ROOT_TAB
};

const struct ggc_cache_tab gt_ggc_rc_gt_tree_h[] = {
  {
    &restrict_base_for_decl,
    1,
    sizeof (restrict_base_for_decl),
    &gt_ggc_mx_tree_map,
    &gt_pch_nx_tree_map,
    &tree_map_marked_p
  },
  {
    &init_priority_for_decl,
    1,
    sizeof (init_priority_for_decl),
    &gt_ggc_mx_tree_int_map,
    &gt_pch_nx_tree_int_map,
    &tree_int_map_marked_p
  },
  {
    &value_expr_for_decl,
    1,
    sizeof (value_expr_for_decl),
    &gt_ggc_mx_tree_map,
    &gt_pch_nx_tree_map,
    &tree_map_marked_p
  },
  {
    &debug_expr_for_decl,
    1,
    sizeof (debug_expr_for_decl),
    &gt_ggc_mx_tree_map,
    &gt_pch_nx_tree_map,
    &tree_map_marked_p
  },
  {
    &int_cst_hash_table,
    1,
    sizeof (int_cst_hash_table),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node,
    &ggc_marked_p
  },
  {
    &type_hash_table,
    1,
    sizeof (type_hash_table),
    &gt_ggc_mx_type_hash,
    &gt_pch_nx_type_hash,
    &type_hash_marked_p
  },
  LAST_GGC_CACHE_TAB
};

const struct ggc_root_tab gt_pch_rc_gt_tree_h[] = {
  {
    &restrict_base_for_decl,
    1,
    sizeof (restrict_base_for_decl),
    &gt_ggc_m_P8tree_map4htab,
    &gt_pch_n_P8tree_map4htab
  },
  {
    &init_priority_for_decl,
    1,
    sizeof (init_priority_for_decl),
    &gt_ggc_m_P12tree_int_map4htab,
    &gt_pch_n_P12tree_int_map4htab
  },
  {
    &value_expr_for_decl,
    1,
    sizeof (value_expr_for_decl),
    &gt_ggc_m_P8tree_map4htab,
    &gt_pch_n_P8tree_map4htab
  },
  {
    &debug_expr_for_decl,
    1,
    sizeof (debug_expr_for_decl),
    &gt_ggc_m_P8tree_map4htab,
    &gt_pch_n_P8tree_map4htab
  },
  {
    &int_cst_hash_table,
    1,
    sizeof (int_cst_hash_table),
    &gt_ggc_m_P9tree_node4htab,
    &gt_pch_n_P9tree_node4htab
  },
  {
    &type_hash_table,
    1,
    sizeof (type_hash_table),
    &gt_ggc_m_P9type_hash4htab,
    &gt_pch_n_P9type_hash4htab
  },
  LAST_GGC_ROOT_TAB
};

const struct ggc_root_tab gt_pch_rs_gt_tree_h[] = {
  { &next_type_uid, 1, sizeof (next_type_uid), NULL, NULL },
  { &next_decl_uid, 1, sizeof (next_decl_uid), NULL, NULL },
  LAST_GGC_ROOT_TAB
};

