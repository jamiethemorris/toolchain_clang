// Test the -fuse-ld options.
//
// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LD %s
// CHECK-LD: "{{.*}}ld{{(.exe)?}}"
//
// RUN: %clang -no-canonical-prefixes %s -### -o %t.o -fuse-ld=bfd 2>&1 \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LD-BFD %s
// CHECK-LD-BFD: "{{.*}}ld.bfd{{(.exe)?}}"
//
// RUN: %clang -no-canonical-prefixes %s -### -o %t.o -fuse-ld=gold 2>&1 \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LD-GOLD %s
// CHECK-LD-GOLD: "{{.*}}ld.gold{{(.exe)?}}"
//
// RUN: %clang -no-canonical-prefixes %s -### -o %t.o -fuse-ld=mcld 2>&1 \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LD-MCLD %s
// CHECK-LD-MCLD: "{{.*}}ld.mcld{{(.exe)?}}"
