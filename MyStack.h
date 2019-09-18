#ifndef MY_STACK_WIEWEL
#define MY_STACK_WIEWEL

//this class is for use with classes that have many data members
//for built-in datatypes or classes with few members, use MyBuiltInStack
template <typename DataT>
class MyStack
{
private:
	
	DataT* array; //used to store stack
	int inUse; //used to denote how many positions are currently in use in arr
	int allocated; //denotes how many spaces array has
	
	//private inline functions
	
	DataT getArrayPos(int p) const //takes in a position and return that spot
	{ return this->array[p]; }
	void destroy() //used for deleting dynamic memory
	{
		delete[] this->array;
		this->inUse = 0;
		this->allocated = 0;
	}
	
	//private function defined in .cpp
	
	void grow(); //used to grow array when it is not large enough
	void shrink(); //used to shrink array when it has lots of unused spaces
	void swap(DataT& a, DataT& b); //because this is need for swap within
	
public: 

	//constructors and destructor
	
	MyStack() //default constructor with 50 spaces in array
		:array(new DataT[50]), inUse(0), allocated(50) {}
	MyStack(int a) //constructor with user determining 'a' initial size of arr
		:array(new DataT[a]), inUse(0), allocated(a) {}
	MyStack(const MyStack& b) //copy constructor
		:array(new DataT[b.getAllocated()]), inUse(b.getInUse()), 
		allocated(b.getAllocated())
	{
		for(int i = 0; i < this->inUse; i++) //copy elements over
			this->array[i] = b.getArrayPos(i);
	}
	~MyStack() //destructor calls destroy function to deallocate memory
	{ this->destroy(); }
	
	//public inline functions
	
	int getAllocated() const //get function for allocated variable
	{ return this->allocated; }
	int getInUse() const //get function for inUse variable
	{ return this->inUse; }
	bool isEmpty() const//check if stack is empty. 
	{ return this->inUse <= 0; }
	void reset() //resets stack by putting inUse to 0. No need to deallocate
	{ this->inUse = 0; }
	void pop() //pops top element off the stack	
	{ (this->inUse)--; } //there is an untested version below that will
						//also shrink the array size if it is using 1/4 
						//or less of the allocated space
	void pop(DataT& elem)//pops top element and sets elem equal to previous top
	{
		elem = top(); //set elem to the current top
		(this->inUse)--;
	}
	
	//public functions defined in cpp
	
	DataT top() const; //returns top of stack
	DataT bottom() const;//returns the bottom of a stack
	void push(const DataT& datum); //function to push by constant reference
	MyStack operator=(const MyStack& b); //operator = overloading for MyStack
	void swap(MyStack& b);
	void reverse(); //I'm thinking of something like
	/*there was also somewhere saying it could be done recursively, 
	but I think that'd require another stack and was meant for 
	a link-list based stack as opposed to array-based. */
	

};

//private function to grow array 
template <typename DataT>
void MyStack<DataT>::grow()
{
	DataT* temp = this->array; //have temp point to array
	this->allocated *= 2; //double array's size
	this->array = new DataT[this->allocated]; //allocated new space
	
	//copy contents over
	for(int i = 0; i < this->inUse; i++)
	{
		this->array[i] = temp[i];
	}
	
	delete[] temp; //free space
}
//function not currently used and is therefore commented out
//you will need to uncomment shrink() to use the shrink portion
//of the pop(void)
//private function to shrink array
/*
template <typename DataT>
void MyStack<DataT>::shrink()
{
	DataT* temp = this->array; //temp points to array
	this->allocated /= 2; //only allocate half the space
	this->array = new DataT[this->allocated]; //allocate new space
	
	//copy contents over
	for(int i = 0; i < this->inUse; i++)
	{
		this->array[i] = temp[i];
	}
	
	delete[] temp; //free old space
}
*/
template <typename DataT>
void MyStack<DataT>::swap(DataT& a, DataT& b)
{
	DataT c = a;
	a = b;
	b = c;
}
//public copy constructor
/*
template <typename DataT>
MyStack<DataT>::MyStack(const MyStack<DataT>& b)
{		
		//set members equal to b's 
		this->inUse = b.getInUse();
		this->allocated = b.getAllocated();
		this->array = new DataT[this->allocated];
		
		//copy contents
		for(int i = 0; i < this->inUse; i++)
		{
			this->array[i] = b.getArrayPos(i);
		}
}
*/
//public top function
template <typename DataT>
DataT MyStack<DataT>::top() const
{
	if(this->isEmpty())
	{
		//trying to access invalid place. give back garbage value;
		static DataT garbage;
		return garbage;
	}
	else
	{
		return this->array[this->inUse - 1];
	}
}
template <typename DataT>
DataT MyStack<DataT>::bottom() const
{
	if(this->isEmpty())
	{
		//trying to access invalid location
		static DataT garbage;
		return garbage;
	}
	else
	{
		//valid bottom, return it
		return this->array[0];
	}
}
/* pop has been moved to defined in .h
this version has been kept here as legacy code for easy implementation
if you desire a pop that also uses the shrink method
this version has not been tested
//public pop function
template <typename DataT>
void MyStack<DataT>::pop()
{
	//if only 1/4 of stack is in use and it's being poppped, shrink the array
	if(this->inUse < (this->allocated / 4) && this->allocated > 4)
		this->shrink();
	
	//move inUse down one 
	(this->inUse)--;
} */
//public push function
template <typename DataT>
void MyStack<DataT>::push(const DataT& datum)
{
	//if stack full, grow it
	if(this->inUse == this->allocated)
		this->grow();
	
	//popping has the potential to have made inUse less than 0
	//here we fix that so that if the stacked has been popped while empty
	//it will start at a reasonable value
	if(this->inUse < 0)
		this->inUse = 0;
	
	//put datum onto the stack and update inUse
	this->array[inUse] = datum;
	(this->inUse)++;
}
//public operator =
template <typename DataT>
MyStack<DataT> MyStack<DataT>::operator=(const MyStack<DataT>& b)
{
	//make sure not equalling self
	if(this != &b)
	{
		//clear any previous contents
		this->destroy();
		
		//set members equal to b's 
		this->inUse = b.getInUse();
		this->allocated = b.getAllocated();
		this->array = new DataT[this->allocated];
		
		//copy contents
		for(int i = 0; i < this->inUse; i++)
		{
			this->array[i] = b.getArrayPos(i);
		}
	}
	
	return *this;
}	
//public swap function
template <typename DataT>
void MyStack<DataT>::swap(MyStack<DataT>& b)
{
	//standard swap procedure
	MyStack<DataT> a = b;
	b = *this;
	*this = a;
}
//public reverse function
template <typename DataT>
void MyStack<DataT>::reverse()
{
	//set a front variable equal to the position of the top element
	int front = this->inUse - 1;
	
	//use a for loop to swap the elements
	for(int back = 0; back < (this->inUse / 2); back++)
	{
		//back keeps getting updated so that they keep swapping
		swap(this->array[back], this->array[front]);
		
		//move front down one position into the stack
		front--;
	}
	
	/*
	works this way
	1 2 3 4 5
	5 2 3 4 1
	5 4 3 2 1 
	*/
}

//associated functions not part of class

template <typename DataT>
void swap(MyStack<DataT>& a, MyStack<DataT>& b)
{
	MyStack<DataT> c = a;
	a = b;
	b = c;
}

#endif

