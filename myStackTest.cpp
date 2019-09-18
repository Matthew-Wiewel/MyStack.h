#include "myStack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void menu();
void constructorWithSize(); //tests the MyStack<type> object(int) constructor
// void copyConstructor(); this is tested implicity in other functions
// getAllocated, getInUse, isEmpty can all be done with the actual function calls
// same for top, getBack
void pop(MyStack<int>& test); //tests the pop(void) method that only pops
void pop2(MyStack<int>& test); //tests the pop(type&) method that also setstate
								//the parameter to the previous top
void push(MyStack<int>& test); //tests the push function
void swap(MyStack<int>& test); //tests the swap method
void swap2(MyStack<int>& test); //test the swap function 
void reverse(MyStack<int>& test); //tests the reverse function
void print(MyStack<int>& test); //prints the contents of the stack
MyStack<int> generateRandomStack(); //creates a random stack

enum selectionChoices { constructWithSizeTest=1, getAllocatedTest, getInUseTest,
isEmptyTest, topTest, bottomTest, popTest, pop2Test, pushTest, swapTest, 
swap2Test, reverseTest, quit };

int main(int argc, char* argv[])
{
	MyStack<int> test;
	int selection = 0;
	srand(time(0));
	
	do
	{
		menu(); //print out the menu options
		cout << "\nYour selection: ";
		cin >> selection;
		
		switch(selection)
		{
			case constructWithSizeTest:
			{
				constructorWithSize();
				break;
			}
			case getAllocatedTest:
			{
				cout << "\nHere is the currently allocated amount: " << 
				test.getAllocated();
				break;
			}
			case getInUseTest:
			{
				cout << "\nHere is the current amount in use: " << 
				test.getInUse();
				break;
			}
			case isEmptyTest:
			{
				if(test.isEmpty())
					cout << "\nThe stack is currently empty.";
				else
					cout << "\nThe stack is not currently empty.";
				
				break;
			}
			case topTest:
			{
				cout << "\nThe current top of the stack is: " << test.top();
				break;
			}
			case bottomTest:
			{
				cout << "\nThe current back of the stack is: " << 
					 test.bottom();
				break;
			}
			case popTest: 
			{
				pop(test);
				break;
			}
			case pop2Test:
			{
				pop2(test);
				break;
			}
			case pushTest: 
			{
				push(test);
				break;
			}
			case swapTest: 
			{
				swap(test);
				break;
			}
			case swap2Test:
			{
				swap2(test);
				break;
			}
			case reverseTest:
			{
				reverse(test);
				break;
			}
			case quit:
			{
				selection = -999; //give it a quitting value
				break;
			}
			default: 
			{
				cout << endl << selection << " is not a valid selection. Please "
				<< "enter a value from " << constructWithSizeTest << " to "
				<< quit << " to make a valid selection.";
			}
		}
			
	}while(selection != -999);
	
	return 0;
}

void menu()
{
	cout << "\n\nHere are your selection options.";
	cout << endl << constructWithSizeTest << ": Construct a stack with a"
		 << " specified initial array size.";
	cout << endl << getAllocatedTest << ": See how much space is allocated "
		 << "for the stack.";
	cout << endl << getInUseTest << ": See how much space is in use in the "
		 << "stack.";
	cout << endl << isEmptyTest << ": See if the stack is empty.";
	cout << endl << topTest << ": Get the top of the stack.";
	cout << endl << bottomTest << ": Get the bottom of the stack.";
	cout << endl << popTest << ": Pop an item from the stack.";
	cout << endl << pop2Test << ": Pop an item from the stack and "
		 << "simultaneously set a parameter equal to the previous top.";
	cout << endl << pushTest << ": Push an item onto the stack.";
	cout << endl << swapTest << ": Swap two stacks using the MyStack method.";
	cout << endl << swap2Test << ": Swap two stacks using a function from the "
		 << "MyStack.h file";
	cout << endl << reverseTest << ": Reverse the contents of the stack.";
	cout << endl << quit << ": Quit.";
	
}
void constructorWithSize()
{
	int size;
	cout << "\nNote that this stack will not be used beyond this test.";
	cout << "\nWhat size would you like the stack's underlying array to have? ";
	cin >> size;
	
	MyStack<int> test(size);
	cout << "\nHere is the size of the stack you created: " 
		 << test.getAllocated();
}
void pop(MyStack<int>& test)
{
	char willWePop = 'y';
	
	cout << "\nIn this test we will use the pop(void) method.";
	cout << "\nWe will show the before and after of the stack.";
	
	while(willWePop == 'y' || willWePop == 'Y' )
	{
		//show the stack's top and size before popping
		cout << "\nHere is the top of the stack before popping: " 
			 << test.top();
		cout << "\nHere is the inUse of the stack before popping: " 
			 << test.getInUse();
		
		//pop the stack
		test.pop();
		
		//show the after-effects
		cout << "\nHere is the top of the stack after popping: " 
			 << test.top();
		cout << "\nHere is the inUse of the stack after popping: " 
			 << test.getInUse();
		
		cout << "\nWould you like to pop again? (y/n)  ";
		cin >> willWePop;
	}
}
void pop2(MyStack<int>& test)
{
	char willWePop = 'y';
	
	cout << "\nIn this test we will use the pop(type) method.";
	cout << "\nThe value of elem (defaults to -999) should become the "
		 << "same as the value of the top before popping.";
	
	while(willWePop == 'y' || willWePop == 'Y' )
	{
		int elem = -999; //default to value that will be recognized as wrong
		
		//show the stack's top and size before popping
		cout << "\nHere is the top of the stack before popping: " 
			 << test.top();
		cout << "\nHere is the inUse of the stack before popping: " 
			 << test.getInUse();
		cout << "\nHere is the value of elem before popping: " << elem;
		
		//pop the stack
		test.pop(elem);
		
		//show the after-effects
		cout << "\nHere is the top of the stack after popping: " 
			 << test.top();
		cout << "\nHere is the inUse of the stack after popping: " 
			 << test.getInUse();
		cout << "\nHere is the value of elem after popping: " << elem;
		
		cout << "\nWould you like to pop again? (y/n)  ";
		cin >> willWePop;
	}
}
void push(MyStack<int>& test)
{
	char selection;
	int value;
	
	cout << "\nIn this test we will push values onto the stack.";
	
	do
	{
		cout << "\nWould you like to enter values manually or push random values?";
		cout << "\n(random values will range from 0 to 100)";
		cout << "\nEnter 'm' for manual or 'r' for random.";
		cin >> selection;
		selection = tolower(selection);
		
		switch(selection)
		{
			case 'm':
			{
				cout << "\nWhich value would you like to push? ";
				cin >> value;
				
				cout << "\nHere is the top of the stack before pushing: "
					 << test.top();
				cout << "\nHere is the inUse of the stack before pushing: "
					 << test.getInUse();
				cout << "\nHere is the allocated of the stack before pushing: "
					 << test.getAllocated();
				
				test.push(value);
				
				cout << "\nHere is the top of the stack after pushing: "
					 << test.top();
				cout << "\nHere is the inUse of the stack after pushing: "
					 << test.getInUse();
				cout << "\nHere is the allocated of the stack after pushing: "
					 << test.getAllocated();
					 
				break;
			}
			case 'r':
			{
				int numValues = 0;
				cout << "\nHow many random values would you like to push? ";
				cin >> numValues;
				
				cout << "\nHere are the value of: "
					 << "\ttop \tinUse \tallocated.";
				cout << "\nBefore pushing: \t" << test.top() << '\t' 
					 << test.getInUse() << '\t' << test.getAllocated();
				
				for(int i = 0; i < numValues; i++)
				{
					value = rand() % 100;
					test.push(value);
					
					cout << "\nAfter push " << i + 1 << ":\t\t" << test.top() 
						 << '\t' << test.getInUse() << '\t' 
						 << test.getAllocated();
				}
				break;
			}
			default:
			{
				cout << endl << selection << " is not a valid value. "
					 << "Please enter 'm' or 'r' next time.";
			}
		}
		
		cout << "\nWould you like to continue pushing? (y/n) ";
		cin >> selection;
	}while(selection == 'y' || selection == 'Y');
}
void swap(MyStack<int>& test)
{
	MyStack<int> swapWith = generateRandomStack();
	
	cout << "\nStack A before swap: ";
	print(test);
	cout << "\nStack B before swap: ";
	print(swapWith);
	
	test.swap(swapWith);
	
	cout << "\nStack A after swap: ";
	print(test);
	cout << "\nStack B after swap: ";
	print(swapWith);
}
void swap2(MyStack<int>& test)
{
	MyStack<int> swapWith = generateRandomStack();
	
	cout << "\nStack A before swap: ";
	print(test);
	cout << "\nStack B before swap: ";
	print(swapWith);
	
	swap(test, swapWith);
	
	cout << "\nStack A after swap: ";
	print(test);
	cout << "\nStack B after swap: ";
	print(swapWith);
}
void reverse(MyStack<int>& test)
{
	//show what stack is before reversal
	cout << "\nBefore reversal: ";
	print(test);
	
	//reverse the stack
	test.reverse();
	
	//show what the stack is now
	cout << "\nAfter reversal: ";
	print(test);
}
void print(MyStack<int>& test)
{
	MyStack<int> printThis(test); //create a copy of test to print
	
	//print from top to bottom until the copied stack is empty
	while(!printThis.isEmpty())
	{
		cout << printThis.top() << " ";
		printThis.pop();
	}
}
MyStack<int> generateRandomStack()
{
	//set number of values for stack and its size
	//I have chosen to mod by 50 arbitrarily
	int numValues = rand() % 50 + 1;
	MyStack<int> randomStack(numValues); //only allocate as much as needed
	
	//push random values into the stack
	for(int i = 0; i < numValues; i++)
	{
		randomStack.push(rand() % 50);
	}
	
	//return the stack
	return randomStack;
}
