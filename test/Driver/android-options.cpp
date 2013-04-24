// This file checks Android-specific toolchain options.

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     -target arm-linux-androideabi \
// RUN:   | FileCheck %s --check-prefix=CHECK-DEFAULT-MISSING-RETURN
// CHECK-DEFAULT-MISSING-RETURN: {{.*}}clang{{.*}}" "-cc1"
// CHECK-DEFAULT-MISSING-RETURN: "-fno-cxx-missing-return-semantics"

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     -fno-cxx-missing-return-semantics \
// RUN:     -target arm-linux-androideabi \
// RUN:   | FileCheck %s --check-prefix=CHECK-DISABLE-MISSING-RETURN
// CHECK-DISABLE-MISSING-RETURN: {{.*}}clang{{.*}}" "-cc1"
// CHECK-DISABLE-MISSING-RETURN: "-fno-cxx-missing-return-semantics"

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     -fcxx-missing-return-semantics \
// RUN:     -target arm-linux-androideabi \
// RUN:   | FileCheck %s --check-prefix=CHECK-ENABLE-MISSING-RETURN
// CHECK-ENABLE-MISSING-RETURN: {{.*}}clang{{.*}}" "-cc1"
// CHECK-ENABLE-MISSING-RETURN: "-fcxx-missing-return-semantics"

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     -target arm-linux-androideabi \
// RUN:   | FileCheck %s --check-prefix=CHECK-DEFAULT-GLOBAL-CTOR
// CHECK-DEFAULT-GLOBAL-CTOR: {{.*}}clang{{.*}}" "-cc1"
// CHECK-DEFAULT-GLOBAL-CTOR: "-mllvm"
// CHECK-DEFAULT-GLOBAL-CTOR: "-disable-global-ctor-const-promotion"

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     -fglobal-ctor-const-promotion \
// RUN:     -target arm-linux-androideabi \
// RUN:   | FileCheck %s --check-prefix=CHECK-ENABLE-GLOBAL-CTOR
// CHECK-ENABLE-GLOBAL-CTOR: {{.*}}clang{{.*}}" "-cc1"
// CHECK-ENABLE-GLOBAL-CTOR-NOT: "-disable-global-ctor-const-promotion"

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
// RUN:     -fno-global-ctor-const-promotion \
// RUN:     -target arm-linux-androideabi \
// RUN:   | FileCheck %s --check-prefix=CHECK-DISABLE-GLOBAL-CTOR
// CHECK-DISABLE-GLOBAL-CTOR: {{.*}}clang{{.*}}" "-cc1"
// CHECK-DISABLE-GLOBAL-CTOR: "-mllvm"
// CHECK-DISABLE-GLOBAL-CTOR: "-disable-global-ctor-const-promotion"
