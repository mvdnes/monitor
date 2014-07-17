#ifndef MONITOR_HOOKING_H
#define MONITOR_HOOKING_H

#include <stdint.h>
#include <windows.h>
#include "slist.h"

typedef struct _hook_info_t {
    uint32_t hook_count;
    uint32_t last_error;
    FARPROC handler;

    slist_t retaddr;
    slist_t eax;

    uint8_t *trampoline;
    uint8_t *guide;
    uint8_t *func_stub;
    uint8_t *clean;

    uint8_t *_mem;
} hook_info_t;

typedef struct _hook_t {
    const wchar_t *library;
    const char *funcname;
    FARPROC handler;
    FARPROC *orig;

    hook_info_t *hi;
} hook_t;

hook_info_t *hook_info();

int hook(const wchar_t *library, const char *funcname,
    FARPROC handler, FARPROC *orig);

int hook2(hook_t *h);

#endif
