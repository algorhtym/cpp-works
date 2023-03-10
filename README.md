A series of C++ classes illustrating various important advanced cpp concepts studied at the *Programming Concepts with C++* course. Except for the ones specifically mentioned, STL was not used in the implementations for better exercise of programming concepts.

*Check the overview section for description and illustrated C++ concepts of each practice.*

# Table of Contents 
- [Table of Contents](#table-of-contents)
- [Overview](#overview)
  - [Array Template Class](#array-template-class)
  - [BigInteger Class](#biginteger-class)
  - [Pieces Class](#pieces-class)
  - [DoubleLinkedList Class](#doublelinkedlist-class)
  - [Graph Classes (directed/undirected)](#graph-classes-directedundirected)
  - [Mapping Class](#mapping-class)
  - [Relation and MappingRelation Template Classes](#relation-and-mappingrelation-template-classes)
  - [RandomGenerator Class](#randomgenerator-class)
  - [streams class](#streams-class)
- [Author](#author)

# Overview 
An explanation of each subfolder's classes, concepts introduced and objectives:

## Array Template Class 
A dynamic array template class with desired range of indexes for any type of elements

Illustrated concepts in C++:
- *Templates*
- *Dynamic memory allocation* 

## BigInteger Class 
A class for the concept of an integer number in a particular base. The number could contain any number of digits in a specified base. This was part of a lab practice focusing on *operator overloading* in C++.

Illustrated concepts in C++ :
- *Operator overloading*
- *Constructors and destructors*
- *Dynamic memory*
- *Pointers*

## Pieces Class
A set of classes purposed to simulate the moves of chess pieces. This was asked in a final exam and implemented under a time limitation. The purpose of the exercise was to successfully illustrate the concept of *inheritance and polymorphism* in C++ by designing an abstract class called *Piece*, that has a method called *move*, then creating a class for each chess piece (bishop, king, knight, pawn, queen, rook) that inherits the *Piece* class and overrides the *move* method for its respective rule, as well as implement validity checking methods (for color, position, and moves) through the use of virtual functions and polymorphism.

Illustrated concepts in C++:
- *Inheritance*
- *Polymorphism*
- *Abstract classes and purely virtual methods*

## DoubleLinkedList Class 
A C++ double linked list implementation without a dummy node. Supports primitive functions of: *add_to_front*, *add_to_back*, *insert_item*, *remove_item*, *remove_from_front*, *remove_from_back*, as well as an overloaded indexing operator for better debugging. Friend classes are also practiced in this exercise. 

Illustrated concepts in C++:
- *Linked lists*
- *Pointers to objects*
- *Friend classes*

## Graph Classes (directed/undirected) 
Graph implementation classes illustrating a directed and undirected graph using *adjacency lists*. The structure of both classes are in the form of "linked list of headers of linked lists". Adding edge, removing edge, getting the degree of a vertex, vertex addition/decrement operators, as well as depth-first-search and breadth-first-search traversal is implemented. 

Illustrated concepts in C++:
- *Linked lists*
- *Directed and undirected graphs using adjacency lists*
- *DFS, BFS*
- Dynamic memory and pointers

## Mapping Class
A mapping class that uses the C++ Standard Template Library (STL) for implementing a mapping that maps *a set of any type* to *a set of any type*. This was part of a lab exercise where map and set libraries of STL were put to use, with a template structure that allows generic classes. 

Illustrated concepts in C++:
- *C++ Standard Template Library (STL)*
- *Mapping*
- *Templates*

## Relation and MappingRelation Template Classes
Two relation class designs for the concept of illustrating *relations of any type*. One class (Relation_Template) allows a relation for one generic type (defined on AxA), and the other class (MappingRelation) allows a relation between any type (defined on AxB). Both classes make use of the *vector* and *set* data structures defined on STL. This was part of an assignment exercise studying the concept of templates. 

Illustrated concepts in C++:
- *STL vector and set*
- *Template classes*
- *Operator overloading*
- *Friend classes*
- *Structs*

## RandomGenerator Class
A random generator class implemented using dynamic memory allocation. It adopts the use of two *seeds* with *s* digits and generating the next random number by multiplying the two first seeds and conserving the *s* digits in the middle, adding leading 0's if the result is less then 2*s* digits. This was part of a lab exercise studying dynamic memory and operator overloading in C++. 

Illustrated concepts in C++:
- *Random generation*
- *Operator overloading*
- *Dynamic memory*

## streams class
A class that works on the main function without creating an object oriented style, purposed to reads all data from a binary file (.info extension) that holds some given student information in a certain format, organize the data, make some mark and letter grade calculations, and write them into a new binary file (.info extension) for each student. 

Illustrated concepts in C++:
- *Filestreams*
- *Reading and writing into files*
- *STL vectors*
- *Structural programming in main*



# Author
Kemal Kilic - [Github](https://github.com/algorhtym)

