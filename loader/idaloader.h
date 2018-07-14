#ifndef __IDA_LOADER_H__
#define __IDA_LOADER_H__

#include <ida.hpp>
#include <fpro.h>
#include <idp.hpp>
#include <loader.hpp>
#include <name.hpp>
#include <bytes.hpp>
#include <offset.hpp>
#include <segment.hpp>
#include <segregs.hpp>
#include <fixup.hpp>
#include <entry.hpp>
#include <auto.hpp>
#include <diskio.hpp>
#include <kernwin.hpp>
#include <nalt.hpp>
#include <typeinf.hpp>

#define CLASS_CODE    "CODE"
#define NAME_CODE     ".text"

#define CLASS_DATA    "DATA"
#define NAME_DATA     ".data"

#define CLASS_BSS     "BSS"
#define NAME_BSS      ".bss"

#define CLASS_EXTERN  "XTRN"
#define NAME_EXTERN   ".ref"

/**
 * From documentation on loader_t::accept_file(...)
 * "This function may return a unique file format number instead of 1.
 * To get this unique number, please contact the author."
 */
#define LDR_ID        0xD07

#endif //#ifndef __IDA_LOADER_H__
