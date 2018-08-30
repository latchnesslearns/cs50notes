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

