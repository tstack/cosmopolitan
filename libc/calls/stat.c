/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=8 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/calls/struct/stat.h"
#include "libc/sysv/consts/at.h"

/**
 * Returns information about thing.
 *
 * @param st is where result is stored
 * @see S_ISDIR(st.st_mode), S_ISREG(), etc.
 * @raise EACCES if denied access to component in path prefix
 * @raise EIO if i/o error occurred while reading from filesystem
 * @raise ELOOP if a symbolic link loop exists in `path`
 * @raise ENAMETOOLONG if a component in `path` exceeds `NAME_MAX`
 * @raise ENOENT on empty string or if component in path doesn't exist
 * @raise ENOTDIR if a parent component existed that wasn't a directory
 * @raise EOVERFLOW shouldn't be possible on 64-bit systems
 * @raise ELOOP may ahappen if `SYMLOOP_MAX` symlinks were dereferenced
 * @raise ENAMETOOLONG may happen if `path` exceeded `PATH_MAX`
 * @asyncsignalsafe
 */
int stat(const char *path, struct stat *st) {
  return fstatat(AT_FDCWD, path, st, 0);
}

__strong_reference(stat, stat64);
