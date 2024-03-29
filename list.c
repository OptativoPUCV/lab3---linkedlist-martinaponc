#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List *list = (List*)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;

  return list;
}

void * firstList(List * list) 
{
  list->current = list->head;
  if (list->current) 
  {
    list->current = list->head;
    return list->current->data;
  }
  return NULL;
}

void * nextList(List * list)
{

  if(list->current != NULL)
  {
    list->current = list->current->next;
  }
  if(list->current != NULL)
  {
    return list->current->data;
  }
  return NULL;

}

void * lastList(List * list) 
{
  if (list->head == NULL)
  {
    return NULL;
  }
    while(list->current->next != NULL)
      {
        list->current = list->current->next;
      }
  return list->current->data;
}

void * prevList(List * list) 
{
  if (list->head == NULL || list->current ==list->head)
  {
    return NULL;
  }
  Node *nodoPrev = list->head;

  if (list->current == NULL)return NULL;

  while(nodoPrev->next != list->current)
  {
    nodoPrev = nodoPrev->next;
  }
  list->current = nodoPrev;
  return nodoPrev->data;

}

void pushFront(List * list, void * data) 
{
  Node *newNodo = (Node *)malloc(sizeof(Node));
  newNodo->prev = NULL;
  newNodo->data = data;
  newNodo->next = list->head;
  if(list->head != NULL)
  {
    list->head->prev = newNodo;  
  }
  list->head = newNodo;
  if(list->tail == NULL)
  {
    list->tail = newNodo;
  }
}

void pushBack(List * list, void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  if(list->current == NULL)
    {
      return NULL;
    }
    Node *nodoEliminar = list->current;
    void *datos = nodoEliminar->data;
    if(nodoEliminar == list->head && nodoEliminar == list->tail)
    {
      list->head = list->tail = NULL;
    }
    else if(nodoEliminar == list->head)
    {
      list->head = list->head->next;
      list->head->prev = NULL;
    }
    else if(nodoEliminar == list->tail)
    {
      list->tail = list->tail->prev;
      list->tail->next = NULL;
    }
    else
    {
     nodoEliminar->prev->next = nodoEliminar->next;
     nodoEliminar->next->prev = nodoEliminar->prev; 
    }

    free(nodoEliminar);
    list->current = NULL;
    return datos;

  }
}

void * popFront(List * list) 
{
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) 
{
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}