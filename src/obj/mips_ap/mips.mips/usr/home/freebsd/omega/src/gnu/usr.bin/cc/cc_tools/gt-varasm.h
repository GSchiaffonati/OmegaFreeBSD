/* Type information for varasm.c.
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
gt_ggc_mx_VEC_alias_pair_gc (void *x_p)
{
  struct VEC_alias_pair_gc * const x = (struct VEC_alias_pair_gc *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x).base).num); i0++) {
          gt_ggc_m_9tree_node ((*x).base.vec[i0].decl);
          gt_ggc_m_9tree_node ((*x).base.vec[i0].target);
        }
      }
    }
}

void
gt_ggc_mx_constant_descriptor_tree (void *x_p)
{
  struct constant_descriptor_tree * const x = (struct constant_descriptor_tree *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_7rtx_def ((*x).rtl);
      gt_ggc_m_9tree_node ((*x).value);
    }
}

void
gt_ggc_mx_rtx_constant_pool (void *x_p)
{
  struct rtx_constant_pool * const x = (struct rtx_constant_pool *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_23constant_descriptor_rtx ((*x).first);
      gt_ggc_m_23constant_descriptor_rtx ((*x).last);
      gt_ggc_m_P23constant_descriptor_rtx4htab ((*x).const_rtx_htab);
    }
}

void
gt_ggc_mx_varasm_status (void *x_p)
{
  struct varasm_status * const x = (struct varasm_status *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_17rtx_constant_pool ((*x).pool);
    }
}

void
gt_ggc_mx_constant_descriptor_rtx (void *x_p)
{
  struct constant_descriptor_rtx * x = (struct constant_descriptor_rtx *)x_p;
  struct constant_descriptor_rtx * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_23constant_descriptor_rtx ((*x).next);
      gt_ggc_m_7rtx_def ((*x).mem);
      gt_ggc_m_7rtx_def ((*x).sym);
      gt_ggc_m_7rtx_def ((*x).constant);
      x = ((*x).next);
    }
}

void
gt_ggc_m_P23constant_descriptor_rtx4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_23constant_descriptor_rtx ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_ggc_m_P24constant_descriptor_tree4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_24constant_descriptor_tree ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_pch_nx_VEC_alias_pair_gc (void *x_p)
{
  struct VEC_alias_pair_gc * const x = (struct VEC_alias_pair_gc *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_17VEC_alias_pair_gc, gt_ggc_e_17VEC_alias_pair_gc))
    {
      {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x).base).num); i0++) {
          gt_pch_n_9tree_node ((*x).base.vec[i0].decl);
          gt_pch_n_9tree_node ((*x).base.vec[i0].target);
        }
      }
    }
}

void
gt_pch_nx_constant_descriptor_tree (void *x_p)
{
  struct constant_descriptor_tree * const x = (struct constant_descriptor_tree *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_24constant_descriptor_tree, gt_ggc_e_24constant_descriptor_tree))
    {
      gt_pch_n_7rtx_def ((*x).rtl);
      gt_pch_n_9tree_node ((*x).value);
    }
}

void
gt_pch_nx_rtx_constant_pool (void *x_p)
{
  struct rtx_constant_pool * const x = (struct rtx_constant_pool *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_17rtx_constant_pool, gt_ggc_e_17rtx_constant_pool))
    {
      gt_pch_n_23constant_descriptor_rtx ((*x).first);
      gt_pch_n_23constant_descriptor_rtx ((*x).last);
      gt_pch_n_P23constant_descriptor_rtx4htab ((*x).const_rtx_htab);
    }
}

void
gt_pch_nx_varasm_status (void *x_p)
{
  struct varasm_status * const x = (struct varasm_status *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_13varasm_status, gt_ggc_e_13varasm_status))
    {
      gt_pch_n_17rtx_constant_pool ((*x).pool);
    }
}

void
gt_pch_nx_constant_descriptor_rtx (void *x_p)
{
  struct constant_descriptor_rtx * x = (struct constant_descriptor_rtx *)x_p;
  struct constant_descriptor_rtx * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_23constant_descriptor_rtx, gt_ggc_e_23constant_descriptor_rtx))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_23constant_descriptor_rtx ((*x).next);
      gt_pch_n_7rtx_def ((*x).mem);
      gt_pch_n_7rtx_def ((*x).sym);
      gt_pch_n_7rtx_def ((*x).constant);
      x = ((*x).next);
    }
}

void
gt_pch_n_P23constant_descriptor_rtx4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P23constant_descriptor_rtx4htab, gt_e_P23constant_descriptor_rtx4htab))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_23constant_descriptor_rtx ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P23constant_descriptor_rtx4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_n_P24constant_descriptor_tree4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P24constant_descriptor_tree4htab, gt_e_P24constant_descriptor_tree4htab))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_24constant_descriptor_tree ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P24constant_descriptor_tree4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_p_17VEC_alias_pair_gc (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct VEC_alias_pair_gc * const x ATTRIBUTE_UNUSED = (struct VEC_alias_pair_gc *)x_p;
  {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(((*x).base).num); i0++) {
      if ((void *)(x) == this_obj)
        op (&((*x).base.vec[i0].decl), cookie);
      if ((void *)(x) == this_obj)
        op (&((*x).base.vec[i0].target), cookie);
    }
  }
}

void
gt_pch_p_24constant_descriptor_tree (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct constant_descriptor_tree * const x ATTRIBUTE_UNUSED = (struct constant_descriptor_tree *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).rtl), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).value), cookie);
}

void
gt_pch_p_17rtx_constant_pool (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct rtx_constant_pool * const x ATTRIBUTE_UNUSED = (struct rtx_constant_pool *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).first), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).last), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).const_rtx_htab), cookie);
}

void
gt_pch_p_13varasm_status (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct varasm_status * const x ATTRIBUTE_UNUSED = (struct varasm_status *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).pool), cookie);
}

void
gt_pch_p_23constant_descriptor_rtx (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct constant_descriptor_rtx * const x ATTRIBUTE_UNUSED = (struct constant_descriptor_rtx *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).next), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).mem), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).sym), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).constant), cookie);
}

void
gt_pch_p_P23constant_descriptor_rtx4htab (ATTRIBUTE_UNUSED void *this_obj,
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
gt_pch_p_P24constant_descriptor_tree4htab (ATTRIBUTE_UNUSED void *this_obj,
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

const struct ggc_root_tab gt_ggc_r_gt_varasm_h[] = {
  {
    &alias_pairs,
    1,
    sizeof (alias_pairs),
    &gt_ggc_mx_VEC_alias_pair_gc,
    &gt_pch_nx_VEC_alias_pair_gc
  },
  {
    &weakref_targets,
    1,
    sizeof (weakref_targets),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &weak_decls,
    1,
    sizeof (weak_decls),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &const_desc_htab,
    1,
    sizeof (const_desc_htab),
    &gt_ggc_m_P24constant_descriptor_tree4htab,
    &gt_pch_n_P24constant_descriptor_tree4htab
  },
  {
    &initial_trampoline,
    1,
    sizeof (initial_trampoline),
    &gt_ggc_mx_rtx_def,
    &gt_pch_nx_rtx_def
  },
  {
    &pending_assemble_externals,
    1,
    sizeof (pending_assemble_externals),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &shared_constant_pool,
    1,
    sizeof (shared_constant_pool),
    &gt_ggc_mx_rtx_constant_pool,
    &gt_pch_nx_rtx_constant_pool
  },
  {
    &object_block_htab,
    1,
    sizeof (object_block_htab),
    &gt_ggc_m_P12object_block4htab,
    &gt_pch_n_P12object_block4htab
  },
  {
    &section_htab,
    1,
    sizeof (section_htab),
    &gt_ggc_m_P7section4htab,
    &gt_pch_n_P7section4htab
  },
  {
    &unnamed_sections,
    1,
    sizeof (unnamed_sections),
    &gt_ggc_mx_section,
    &gt_pch_nx_section
  },
  {
    &weak_global_object_name,
    1, 
    sizeof (weak_global_object_name),
    &gt_ggc_m_S,
    (gt_pointer_walker) &gt_pch_n_S
  },
  {
    &first_global_object_name,
    1, 
    sizeof (first_global_object_name),
    &gt_ggc_m_S,
    (gt_pointer_walker) &gt_pch_n_S
  },
  LAST_GGC_ROOT_TAB
};

const struct ggc_root_tab gt_pch_rs_gt_varasm_h[] = {
  { &anchor_labelno, 1, sizeof (anchor_labelno), NULL, NULL },
  { &const_labelno, 1, sizeof (const_labelno), NULL, NULL },
  LAST_GGC_ROOT_TAB
};

