/*
 * Syslink-IPC for TI OMAP Processors
 *
 * Copyright (C) 2009 Texas Instruments, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation version 2.1 of the License.
 *
 * This program is distributed .as is. WITHOUT ANY WARRANTY of any kind,
 * whether express or implied; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */
/** ============================================================================
 *  @file   MemoryOS.h
 *
 *  @brief      Memory abstraction APIs for local memory allocation.
 *
 *              This provides a direct access to local memory allocation, which
 *              does not require creation of a Heap.
 *  ============================================================================
 */


#ifndef MEMORYOS_H_0x97D2
#define MEMORYOS_H_0x97D2

/* OSAL and utils */
#include <MemoryDefs.h>

#if defined (__cplusplus)
extern "C" {
#endif

/*!
 *  @def    MEMORYOS_MODULEID
 *  @brief  Module ID for Memory OSAL module.
 */
#define MEMORYOS_MODULEID                 (UInt16) 0x97D2

/* =============================================================================
 *  All success and failure codes for the module
 * =============================================================================
 */
/*!
 * @def   MEMORYOS_STATUSCODEBASE
 * @brief Stauts code base for MEMORY module.
 */
#define MEMORYOS_STATUSCODEBASE            (MEMORYOS_MODULEID << 12u)

/*!
 * @def   MEMORYOS_MAKE_FAILURE
 * @brief Convert to failure code.
 */
#define MEMORYOS_MAKE_FAILURE(x)          ((Int) (0x80000000  \
                                           + (MEMORYOS_STATUSCODEBASE + (x))))
/*!
 * @def   MEMORYOS_MAKE_SUCCESS
 * @brief Convert to success code.
 */
#define MEMORYOS_MAKE_SUCCESS(x)            (MEMORYOS_STATUSCODEBASE + (x))

/*!
 * @def   MEMORYOS_E_MEMORY
 * @brief Indicates Memory alloc/free failure.
 */
#define MEMORYOS_E_MEMORY                   MEMORYOS_MAKE_FAILURE(1)

/*!
 * @def   MEMORYOS_E_INVALIDARG
 * @brief Invalid argument provided.
 */
#define MEMORYOS_E_INVALIDARG               MEMORYOS_MAKE_FAILURE(2)

/*!
 * @def   MEMORYOS_E_MAP
 * @brief Failed to map to host address space.
 */
#define MEMORYOS_E_MAP                      MEMORYOS_MAKE_FAILURE(3)

/*!
 * @def   MEMORYOS_E_UNMAP
 * @brief Failed to unmap from host address space.
 */
#define MEMORYOS_E_UNMAP                    MEMORYOS_MAKE_FAILURE(4)

/*!
 * @def   MEMORYOS_E_INVALIDSTATE
 * @brief Module is in invalidstate.
 */
#define MEMORYOS_E_INVALIDSTATE             MEMORYOS_MAKE_FAILURE(5)

/*!
 * @def   MEMORYOS_E_FAIL
 * @brief Genral failure.
 */
#define MEMORYOS_E_FAIL                     MEMORYOS_MAKE_FAILURE(6)

/*!
 * @def   MEMORYOS_SUCCESS
 * @brief Operation successfully completed
 */
#define MEMORYOS_SUCCESS                    MEMORYOS_MAKE_SUCCESS(0)

/*!
 * @def   MEMORYOS_S_ALREADYSETUP
 * @brief Module already initialized
 */
#define MEMORYOS_S_ALREADYSETUP             MEMORYOS_MAKE_SUCCESS(1)


/* =============================================================================
 *  Macros and types
 *  See MemoryDefs.h
 * =============================================================================
 */
/* =============================================================================
 *  APIs
 * =============================================================================
 */
/* Initialize the memory os module. */
Int32 MemoryOS_setup (void);

/* Finalize the memory os module. */
Int32 MemoryOS_destroy (void);

/* Allocates the specified number of bytes of type specified through flags. */
Ptr MemoryOS_alloc (UInt32 size, UInt32 align, UInt32 flags);

/* Allocates the specified number of bytes and memory is set to zero. */
Ptr MemoryOS_calloc (UInt32 size, UInt32 align, UInt32 flags);

/* Frees local memory */
Void MemoryOS_free (Ptr ptr, UInt32 size, UInt32 flags);

/* Maps a memory area into virtual space. */
Int MemoryOS_map (Memory_MapInfo * mapInfo);

/* UnMaps a memory area into virtual space. */
Int MemoryOS_unmap (Memory_UnmapInfo * unmapInfo);

/* Copies the data between memory areas. Returns the number of bytes copied. */
Ptr MemoryOS_copy (Ptr dst, Ptr src, UInt32 len);

/* Set the specified values to the allocated  memory area */
Ptr MemoryOS_set (Ptr buf, Int value, UInt32 len);

/* Translate API */
Ptr MemoryOS_translate (Ptr srcAddr, Memory_XltFlags flags);

/* TBD: Add APIs for Memory_move, Scatter-Gather & translateAddr. */


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* ifndef MEMORYOS_H_0x97D2 */
