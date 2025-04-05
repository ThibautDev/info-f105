double foo(int *x) {
  return 0.0;
}


int main() {
  int x, y, z;

  int *const t[] = {&x, &y, &z};

  int *const  p1 = t[2];
  int *const *p2 = &p1;
  int *const **i = &p2;
  
  double (*f)(int*) = &foo;

  return 0;    
}
