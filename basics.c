#include <stdio.h>
#include <stdlib.h>

void static_int_alloc();
void dynamic_int_alloc();

void static_int_arr_alloc(int);
void dynamic_int_arr_alloc(int);

void static_struct_alloc();
void dynamic_struct_alloc();

typedef struct pair{
  int first;
  int second;
} pair_t;

typedef enum BOOL { True = 1, False = 0 } bool_t;

int main(int argc, char **argv){
  static_int_alloc();
  dynamic_int_alloc();

  static_int_arr_alloc(10);
  dynamic_int_arr_alloc(10);

  static_struct_alloc();
  dynamic_struct_alloc();
  
  bool_t b = True;

  if(b){ printf("b is true\n"); }
  return 0;
}


void static_int_alloc(){
  int p;
  p = 5;

  printf("The value of p is %d\n", p);

  return;
}


void dynamic_int_alloc(){
  int* p = malloc( sizeof(int) );
  *p = 5;
  printf("The value of p is %d\n", *p);
  printf("The location of p is %p\n", p);

  free(p);
  return ;
}


void static_int_arr_alloc(int i){
  int arr[i];

  for(int x = 0; x < i; ++x){
    arr[x] = x;
  }

  for(int x = 0; x < i; ++x){
    printf("%d\n", arr[x]);
  }

  return;
}


void dynamic_int_arr_alloc(int i){
  int* arr;

  arr = malloc( sizeof(int) * i );

  for(int x = 0; x < i; ++x){
    arr[x] = x;
  }

  for(int x = 0; x < i; ++x){
    printf("%d\n", arr[x]);
  }
  
  free(arr);
  return;
}


void static_struct_alloc(){
  pair_t p1;
  p1.first = 0;
  p1.second = 5;

  printf("The value of p.first is %d\n", p1.first);
  printf("The value of p.second is %d\n", p1.second);

  return;
}


void dynamic_struct_alloc(){
  struct pair* pp = malloc( sizeof(pair_t) );

  (*pp).first = 5;
  pp->second = 3;

  printf("The value of pp.first is %d\n", (*pp).first);
  printf("The value of pp.second is %d\n", pp->second);

  free(pp);
  return;
}
