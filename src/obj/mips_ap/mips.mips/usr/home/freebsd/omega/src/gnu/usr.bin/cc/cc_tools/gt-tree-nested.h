/* Type information for tree-nested.c.
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
gt_ggc_mx_nesting_info (void *x_p)
{
  struct nesting_info * x = (struct nesting_info *)x_p;
  struct nesting_info * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_12nesting_info ((*x).outer);
      gt_ggc_m_12nesting_info ((*x).inner);
      gt_ggc_m_12nesting_info ((*x).next);
      gt_ggc_m_P11var_map_elt4htab ((*x).field_map);
      gt_ggc_m_P11var_map_elt4htab ((*x).var_map);
      gt_ggc_m_15bitmap_head_def ((*x).suppress_expansion);
      gt_ggc_m_9tree_node ((*x).context);
      gt_ggc_m_9tree_node ((*x).new_local_var_chain);
      gt_ggc_m_9tree_node ((*x).debug_var_chain);
      gt_ggc_m_9tree_node ((*x).frame_type);
      gt_ggc_m_9tree_node ((*x).frame_decl);
      gt_ggc_m_9tree_node ((*x).chain_field);
      gt_ggc_m_9tree_node ((*x).chain_decl);
      gt_ggc_m_9tree_node ((*x).nl_goto_field);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_var_map_elt (void *x_p)
{
  struct var_map_elt * const x = (struct var_map_elt *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).old);
      gt_ggc_m_9tree_node ((*x).new);
    }
}

void
gt_ggc_m_P11var_map_elt4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_11var_map_elt ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_pch_nx_nesting_info (void *x_p)
{
  struct nesting_info * x = (struct nesting_info *)x_p;
  struct nesting_info * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_12nesting_info, gt_ggc_e_12nesting_info))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_12nesting_info ((*x).outer);
      gt_pch_n_12nesting_info ((*x).inner);
      gt_pch_n_12nesting_info ((*x).next);
      gt_pch_n_P11var_map_elt4htab ((*x).field_map);
      gt_pch_n_P11var_map_elt4htab ((*x).var_map);
      gt_pch_n_15bitmap_head_def ((*x).suppress_expansion);
      gt_pch_n_9tree_node ((*x).context);
      gt_pch_n_9tree_node ((*x).new_local_var_chain);
      gt_pch_n_9tree_node ((*x).debug_var_chain);
      gt_pch_n_9tree_node ((*x).frame_type);
      gt_pch_n_9tree_node ((*x).frame_decl);
      gt_pch_n_9tree_node ((*x).chain_field);
      gt_pch_n_9tree_node ((*x).chain_decl);
      gt_pch_n_9tree_node ((*x).nl_goto_field);
      x = ((*x).next);
    }
}

void
gt_pch_nx_var_map_elt (void *x_p)
{
  struct var_map_elt * const x = (struct var_map_elt *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_11var_map_elt, gt_ggc_e_11var_map_elt))
    {
      gt_pch_n_9tree_node ((*x).old);
      gt_pch_n_9tree_node ((*x).new);
    }
}

void
gt_pch_n_P11var_map_elt4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P11var_map_elt4htab, gt_e_P11var_map_elt4htab))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_11var_map_elt ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P11var_map_elt4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_p_12nesting_info (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct nesting_info * const x ATTRIBUTE_UNUSED = (struct nesting_info *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).outer), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).inner), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).field_map), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).var_map), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).suppress_expansion), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).context), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).new_local_var_chain), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).debug_var_chain), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).frame_type), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).frame_decl), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).chain_field), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).chain_decl), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).nl_goto_field), cookie);
}

void
gt_pch_p_11var_map_elt (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct var_map_elt * const x ATTRIBUTE_UNUSED = (struct var_map_elt *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).old), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).new), cookie);
}

void
gt_pch_p_P11var_map_elt4htab (ATTRIBUTE_UNUSED void *this_obj,
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

const struct ggc_root_tab gt_ggc_r_gt_tree_nested_h[] = {
  {
    &root,
    1,
    sizeof (root),
    &gt_ggc_mx_nesting_info,
    &gt_pch_nx_nesting_info
  },
  {
    &trampoline_type,
    1,
    sizeof (trampoline_type),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  LAST_GGC_ROOT_TAB
};

