// RUN: %clang_cc1 -mllvm -disable-global-ctor-const-promotion \
// RUN:     -emit-llvm -O2 -o - %s \
// RUN:   | FileCheck %s

class Boolean {
private:
  bool val;
public:
  Boolean(bool b): val(b) { }
};

extern const Boolean TRUE;
extern const Boolean FALSE;

const Boolean TRUE(true);
const Boolean FALSE(false);

// CHECK:     @TRUE = global %class.Boolean { i8 1 }, align 1
// CHECK-NOT: @TRUE = constant %class.Boolean { i8 1 }, align 1
// CHECK:     @FALSE = global %class.Boolean zeroinitializer, align 1
// CHECK-NOT: @FALSE = constant %class.Boolean zeroinitializer, align 1
