/* libsas - library for Structured Additive Synthesis
   Copyright (C) 1999-2001 Sylvain Marchand
   Copyright (C) 2001-2002 SCRIME, universit� Bordeaux 1

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef __SAS_FILE_H__
#define __SAS_FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sas_frame.h"

/* Abstract data type for handles on open SAS files. */
typedef void * sas_file_t;

/* Opens a SAS file.  Maintains a cache of open SAS files.  Increments
   the number of accesses to the file.  Returns an opaque handle on
   the file, or NULL on failure. */
extern sas_file_t sas_file_open (const char * filename);

/* Closes a SAS file.  Decrements the number of accesses to the file.
   The handle is deleted from memory if the number of accesses drops
   to 0. */
extern void sas_file_close (sas_file_t f);

/* Returns the number of SAS frames that can be extracted from a SAS
   file.  This number corresponds to a normal rate of 1 frame every
   SAS_SAMPLES audio samples (see sas_synthesizer.h).  */
extern int sas_file_number_of_frames (sas_file_t f);

/* Fills dest with the n-th frame of the file.  Returns dest on
   success, NULL on failure. */
extern sas_frame_t sas_file_get_frame (sas_file_t f,
				       sas_frame_t dest,
				       int n);

#ifdef __cplusplus
}
#endif

#endif
