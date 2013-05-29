// RUN: %clang -target arm-linux-androideabi -### -c %s 2>&1 | FileCheck %s

// CHECK: "-arm-enable-ehabi"
// CHECK: "-arm-enable-ehabi-descriptors"
