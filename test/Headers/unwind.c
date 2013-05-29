// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
// RUN: %clang_cc1 -triple mips-unknown-linux -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
// RUN: %clang_cc1 -triple i686-unknown-linux -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
// RUN: %clang_cc1 -triple x86_64-unknown-linux -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s

// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
// RUN: %clang_cc1 -triple mips-unknown-linux -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
// RUN: %clang_cc1 -triple i686-unknown-linux -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
// RUN: %clang_cc1 -triple x86_64-unknown-linux -Wall -Werror \
// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s

#include "unwind.h"

uintptr_t test_unwind_get_ip(struct _Unwind_Context *context) {
  return _Unwind_GetIP(context);
}
