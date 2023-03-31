#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) 
{
  ArrayList *l = (ArrayList*) malloc (sizeof(ArrayList));
  l->data = (void**) malloc (2*sizeof(void*));
  if(l == NULL || l->data == NULL) exit(1);

//data es como se recorre
  
  l->capacity = 2;
  l->size = 0;
  
  return l;
}

void append(ArrayList * l, void * data)
{
  if (l == NULL) return exit(1);

  if (l->size == l->capacity) 
  {
    l->data = realloc(l->data, sizeof(4*sizeof(void*)));
    l->size++;
    
    l->data[l->size] = data;
    
  }
  else
  {
    l->size++;
    
    l->data[l->size] = data;
  }
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
