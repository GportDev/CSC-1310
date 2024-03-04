# Pointers

A variable that holds an memory address (Datatype augment)

|Declaration    |Memory|Value|
|---------------|------|-----|
|int num = 6    |   øxf|    6|
|int* ptr = &num|   øx5|  øxf|

A pointer dereferenced is a value

A variable dereferenced is a memory address

A pointer hold the same kind of thing of an Array

# Classes and structs similarities

A class is like a struck in these ways:
- Allow bundling of related variables
- Syntax of declaration
- An object is an instance of a class in the same way that a variable can be an instance of a struct

### Classes

Classes is like a blueprint and objects are like houses built from it.
- Attributes: Data members
- Member functions: Methods or functions of a class
- Encapsulation: Combine data and attributes into an object
- Data hiding: Restricting access to certain members of an object (Direct access not allowed)

They are good for reusability.

`::` Informs the compiler that this functions is member of other types

#### ... function

Are functions that retrieve the value of members, but don't change it


#### Mutator functions

Are function that changes or mutates members (Setters)

#### Helper functions


## Namespaces

To prevent conflicts between classes' names, you can put all the class data inside a namespace

```cpp
namespace auditorium {
    class Seat {
        // Definitions
    }
}

// Instance of the seat
auditorium:: Seat;
```

### Operator overloading

<br/>
<br/>

# Templates

Function definition that have a special type parameter that may be used in place of types. They work like Typescript generics when the type of the variable will be defined depending on the data it get as argument.

```cpp
template<typename T>

T totalArrayElements(T myArr[], int size) {
    T total = 0;
    for (int x)...
}
```


## Makefiles

```cpp
target: prerequisite1 prerequisite2...
    command1
    command2
```