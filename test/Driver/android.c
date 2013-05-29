// Test Android Toolchain Detection

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o \
// RUN:     -target arm-linux-androideabi \
// RUN:     -gcc-toolchain %S/Inputs/basic_android_tree 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-ARM %s
// CHECK-ANDROID-ARM: "{{.*}}/Inputs/basic_android_tree/{{.*}}/arm-linux-androi
// CHECK-ANDROID-ARM: "{{.*}}/Inputs/basic_android_tree/{{.*}}/arm-linux-androi

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o \
// RUN:     -target mipsel-linux-android \
// RUN:     -gcc-toolchain %S/Inputs/basic_android_tree 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-MIPS %s
// CHECK-ANDROID-MIPS: "{{.*}}/Inputs/basic_android_tree/{{.*}}/mipsel-linux-an
// CHECK-ANDROID-MIPS: "{{.*}}/Inputs/basic_android_tree/{{.*}}/mipsel-linux-an

// RUN: %clang -no-canonical-prefixes %s -### -o %t.o \
// RUN:     -target i686-linux-android \
// RUN:     -gcc-toolchain %S/Inputs/basic_android_tree 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-X86 %s
// CHECK-ANDROID-X86: "{{.*}}/Inputs/basic_android_tree/{{.*}}/i686-linux-andro
