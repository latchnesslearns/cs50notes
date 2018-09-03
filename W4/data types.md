# CS50 Notes - Week 4

## Structures

### Definition

```c
struct car
{
    int year;
    char model[10];
    float engine;
};
```

### Declaration

- to instantiate struct onto the call stack

```c
struct car myCar;
```

- to dynamically allocate memory for structure onto the heap

```c
struct car *myCar = malloc(sizeof(struct car));
```

### Access

- use a dot operator to access elements of initalised structs on the stack

```c
myCar.year = 2011;
```

- use pointer dereference to access elements of a struct on the heap

```c
(*myCar).year = 2011;
```

- OR use arrow operator which
    1. Dereferences
    2. Accesses element

```c
myCar->year = 2011;
```

### Example Program

structs1.c

## Custom Types

### Definition

```c
//typdef <old name> <new name>;
typedef char* string;
```

- structs can be typedef'ed to avoid having to always call them with struct

```c
typedef struct car
{
    int year;
    char model[10];
}

typedef struct car car_t;
// struct_t by convention to specify type
```

## Singly Linked Lists

### Definition

- comprised of nodes, which themselves have two fields
    1. Data
    2. Pointer to node of same type as node

```c
typedef struct sllNodetemp
// temporary name is required as definition is self referential
{
    int data;
    struct sllNode* next;
}
sllNode;
```

- Useful things to do with linked lists;
    1. Create one from scratch
    2. Search one to find something
    3. Insert new node
    4. Delete single element
    5. Delete entire list

### sample program
sll1.c