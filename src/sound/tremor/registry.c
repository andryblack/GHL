/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis 'TREMOR' CODEC SOURCE CODE.   *
 *                                                                  *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis 'TREMOR' SOURCE CODE IS (C) COPYRIGHT 1994-2002    *
 * BY THE Xiph.Org FOUNDATION http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: registry for floor, res backends and channel mappings

 ********************************************************************/

#include "ivorbiscodec.h"
#include "codec_internal.h"
#include "registry.h"
#include "misc.h"


/* seems like major overkill now; the backend numbers will grow into
   the infrastructure soon enough */

extern vorbis_func_floor     ifloor0_exportbundle;
extern vorbis_func_floor     ifloor1_exportbundle;
extern vorbis_func_residue   iresidue0_exportbundle;
extern vorbis_func_residue   iresidue1_exportbundle;
extern vorbis_func_residue   iresidue2_exportbundle;
extern vorbis_func_mapping   imapping0_exportbundle;

vorbis_func_floor     *_ifloor_P[]={
  &ifloor0_exportbundle,
  &ifloor1_exportbundle,
};

vorbis_func_residue   *_iresidue_P[]={
  &iresidue0_exportbundle,
  &iresidue1_exportbundle,
  &iresidue2_exportbundle,
};

vorbis_func_mapping   *_imapping_P[]={
  &imapping0_exportbundle,
};



