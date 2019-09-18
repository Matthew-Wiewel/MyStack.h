# MyStack.h
This repository contains code for a templated C++ array-based stack class in MyStack.h in addition to a driver for this class (MyStackTest.cpp) and a makefile to compile these two.

The template type is called DataT within the code.

# The public functions available to the MyStack class are

MyStack()
Default constructor. Will allocated an array with 50 indices.

MyStack(int)
Constructor taking an int parameter. Will allocate an array with the same size as the given int.

MyStack(const MyStack&)
Copy constructor. Will create a stack with the same array size and elements in the array as the copied stack.

~MyStack()
Destructor is present and will deallocate dynamic memory.

int getAllocated() const
Will return an integer that indicates how many spaces the underlying array has.

int getInUse() const
Will return an integer indicating how many spaces in the array are currently being used for the stack.

bool isEmpty() const
Will return whether or not the stack is empty.

void reset()
Will cause the stack to be empty. (Does not deallocate dynamic memory.)

void pop()
Will pop the stack.

void pop(DataT&)
Will pop the stack. Will also set the passed parameter equal to the top of the stack before the pop occurs. If called on empty stack, passed paraemeter will be set to a garbage value.

DataT top() const
Will return the top of the stack. If called on empty stack, will return a garbage value.

DataT bottom() const
Will return the bottom of the stack.

void push(const DataT&)
Will push the passed parameter onto the stack.

MyStack operator=(const MyStack&)
Assignment operator is overloaded for the MyStack class. 

void swap(MyStack&)
Will swap calling stack with passed stack.

void reverse()
Will reverse the contents of the stack. Previously bottom will be new top. Previous top will be new bottom. Ect.

void swap(MyStack&, MyStack&)
Not a member function. Will swap the two passed stacks.

# Private functions available to the MyStack class

DataT getArrayPos(int) const
Will return the given position of the stack's underlying array. Used in copy constructor and operator= to get contents of passed stack.

void destroy()
Used to deallocate dynamic memory.

void grow()
Used to double size of array and copy over elements to new array.

void swap(DataT&, DataT&)
Used to swap elements within MyStack class.

# Potential Functionality

void shrink()
This is a method that would shrink the array size by half when a pop causes the stack to only be using 1/4 or less of its allocated space. This method is currently commented out and not used by the MyStack class. If you wish to use this function, its definition is located in the private section and it is defined below the class definition. It is currently in place in the void pop() function in a commented out state. It is not present in the void pop(DataT&) function even in a commented out state. Note that this function has not been tested. 
