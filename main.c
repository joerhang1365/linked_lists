#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  void *next;
  int data;
} node;

node *head = NULL;

// add a node to the list
node *node_add(int data)
{
  node *new = NULL;
  // two cases

  // if the list is empty
  if(head == NULL)
  {
    new = malloc(sizeof(node));
    if(new == NULL)
    {
      return NULL;
    }
    new->data = data;
    head = new;
    new->next = NULL;
  }
  else
  {
    new = malloc(sizeof(node));
    if(new == NULL)
    {
      return NULL;
    }
    new->data = data;
    new->next = head;
    head = new;
  }

  return new;
}

// remove a node from the list
int node_remove(int data)
{
  node *current = head;
  node *prev = head;
  while(current != NULL)
  {
    if(current->data == data)
    {
      // if current is the list head
      if(current == head)
      {
        head = current->next;
      }
      else
      {
        prev->next = current->next;
        free(current);
        current = NULL;
      }

      return 1;
    }
    prev = current;
    current = current->next;
  }
  return 0;
}

// insert a node into position in the list
node *node_insert(int data, int position)
{
  node *current = head;
  while(current != NULL && position != 0)
  {
    position--;
  }

  if(position != 0)
  {
    printf("requested position too far into list\n");
    return NULL;
  }

  node *new = malloc(sizeof(node));
  if(new == NULL)
  {
    return NULL;
  }

  new->data = data;
  new->next = current->next;
  current->next = new;

  return new;
}

// print operation
void print_list()
{
  node *current = head;
  while(current != NULL)
  {
    printf("%d->", current->data);
    current = current->next;
  }

  printf("\n");
  return;
}

void print_menu()
{
  printf("You have the following options:\n");
  printf("\t1 add a node to the list\n");
  printf("\t2 remove a node from the list\n");
  printf("\t3 insert a node to the list\n");
  printf("\t4 print list\n");
  printf("\t5 quit\n");
}

int main(int argc, char **argv)
{
  int option = -1;
  int input = 0;
  int input2 = 0;
  while(option != 5)
  {
    print_menu();
    int num_received = scanf("%d", &option);
    if(num_received == 1 && option > 0 && option <= 5)
    {
      switch(option)
      {
        case 1:
          // add operation
          printf("what data to insert?\n");
          scanf("%d", &input);
          node *new = node_add(input);
          break;
        case 2:
          // remove operation
          printf("whata data to remove?\n");
          scanf("%d", &input);
          int success = node_remove(input);
          if(!success)
          {
            printf("element not found\n");
          }
          break;
        case 3:
          // insert operation
          printf("what data to insert?\n");
          scanf("%d", &input);;
          printf("what position?\n");
          scanf("%d", &input2);
          node *n = node_insert(input, input2);
          if(n == NULL)
          {
            printf("failed to insert into list\n");
          }
          break;
        case 4:
          // print list
          print_list();
          break;
        case 5:
            break;
      }
    }
  }

  return 0;
}
