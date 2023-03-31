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
    l->capacity *= 2;
    
    l->data[l->size-1] = data;
    
  }
  else
  {
    l->size++;
    l->data[l->size-1] = data;
  }
}

void push(ArrayList * l, void * data, int i)
{
  if (l == NULL) return exit(1);

  if (i < 0 || i > l->size) 
  {
    printf("Error: Invalid index\n");
    return;
  }
    
  if (l->size == l->capacity) 
  {
    l->capacity *= 2;
    l->data = realloc(l->data, l->capacity * sizeof(int)); 
  }

  for (int j = l->size - 1; j >= i; j--) 
  {
    l->data[j+1] = l->data[j];
  }
  
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i)
{
  if (i < 0 || i >= l->size) 
  {
    return 0;
  }

  void* eliminado = l->data[i];
  for (int j = i; j < l->size - 1; j++) 
  {
    l->data[j] = l->data[j+1];
  }
  
  l->size--;
  return eliminado;
  
}

void* get(ArrayList * l, int i)
{
  if (i < 0 || i >= l->size) 
  {
    return 0;
  }
  
  return l->data[i];
}

int get_size(ArrayList * l)
{
    return l->size;
}

//remove elements
void clean(ArrayList * l)
{
  l->capacity = 2;
  l->size = 0;
}
