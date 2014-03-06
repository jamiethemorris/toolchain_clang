// RUN: %clang_cc1 -verify -fopenmp=libiomp5 -ast-print %s | FileCheck %s
// RUN: %clang_cc1 -fopenmp=libiomp5 -x c++ -std=c++11 -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp=libiomp5 -std=c++11 -include-pch %t -fsyntax-only -verify %s -ast-print | FileCheck %s
// expected-no-diagnostics

#ifndef HEADER
#define HEADER

void foo() {}

template <class T>
struct S {
  operator T() {return T();}
};

template <typename T, int C>
T tmain(T argc, T *argv) {
  T b = argc, c, d, e, f, g;
  static T a;
  S<T> s;
#pragma omp parallel
  a=2;
#pragma omp parallel default(none), private(argc,b) firstprivate(argv) shared (d) if (argc > 0) num_threads(C)
  foo();
#pragma omp parallel if (C) num_threads(s)
  foo();
  return 0;
}
// CHECK: template <typename T = int, int C = 5> int tmain(int argc, int *argv) {
// CHECK-NEXT: int b = argc, c, d, e, f, g;
// CHECK-NEXT: static int a;
// CHECK-NEXT: S<int> s;
// CHECK-NEXT: #pragma omp parallel
// CHECK-NEXT: a = 2;
// CHECK-NEXT: #pragma omp parallel default(none) private(argc,b) firstprivate(argv) shared(d) if(argc > 0) num_threads(5)
// CHECK-NEXT: foo()
// CHECK-NEXT: #pragma omp parallel if(5) num_threads(s)
// CHECK-NEXT: foo()
// CHECK: template <typename T = long, int C = 1> long tmain(long argc, long *argv) {
// CHECK-NEXT: long b = argc, c, d, e, f, g;
// CHECK-NEXT: static long a;
// CHECK-NEXT: S<long> s;
// CHECK-NEXT: #pragma omp parallel
// CHECK-NEXT: a = 2;
// CHECK-NEXT: #pragma omp parallel default(none) private(argc,b) firstprivate(argv) shared(d) if(argc > 0) num_threads(1)
// CHECK-NEXT: foo()
// CHECK-NEXT: #pragma omp parallel if(1) num_threads(s)
// CHECK-NEXT: foo()
// CHECK: template <typename T, int C> T tmain(T argc, T *argv) {
// CHECK-NEXT: T b = argc, c, d, e, f, g;
// CHECK-NEXT: static T a;
// CHECK-NEXT: S<T> s;
// CHECK-NEXT: #pragma omp parallel
// CHECK-NEXT: a = 2;
// CHECK-NEXT: #pragma omp parallel default(none) private(argc,b) firstprivate(argv) shared(d) if(argc > 0) num_threads(C)
// CHECK-NEXT: foo()
// CHECK-NEXT: #pragma omp parallel if(C) num_threads(s)
// CHECK-NEXT: foo()

enum Enum { };

int main (int argc, char **argv) {
  long x;
  int b = argc, c, d, e, f, g;
  static int a;
  Enum ee;
// CHECK: Enum ee;
#pragma omp parallel
// CHECK-NEXT: #pragma omp parallel
  a=2;
// CHECK-NEXT: a = 2;
#pragma omp parallel default(none), private(argc,b) firstprivate(argv) if (argc > 0) num_threads(ee)
// CHECK-NEXT: #pragma omp parallel default(none) private(argc,b) firstprivate(argv) if(argc > 0) num_threads(ee)
  foo();
// CHECK-NEXT: foo();
  return tmain<int, 5>(b, &b) + tmain<long, 1>(x, &x);
}

#endif
