#include <iostream.h>
#include <conio.h>

typedef enum
{
  true = 1,
  false = 0
} bool;

class Stack
{
	private:
		int topOfStack;
		int stackSize;
		int *stackArr;
	public:
		Stack()
		{

		}
		Stack(const int _size = 1)
		{
			topOfStack = 0;
			this->stackSize = _size;
			this->stackArr = new int[this->stackSize];
		}
		// adding copy constructor to solve Dynamic Area Problem
		Stack(Stack & s)
		{
			this->topOfStack = s.topOfStack;
			this->stackSize = s.stackSize;
			this->stackArr = new int[this->stackSize];
			// copying each element inside the original stack to the copy
			for (int i = 0; i < (this->topOfStack); i++)
			{
				(this->stackArr[i]) = s.stackArr[i];
			}
		}
		~Stack()
		{
			delete[] (this->stackArr);
			this->stackSize = 0;
			this->topOfStack = -1;
		}

		bool isStackEmpty()
		{
			return (topOfStack == 0 ? true : false);
		}
		bool isStackFull()
		{
			return (topOfStack == stackSize ? true : false);
		}
		bool push(const int _val)
		{
			if (this->isStackFull())
			{
				return false;
			}

			this->stackArr[topOfStack] = _val;
			topOfStack++;

			return true;
		}
		bool pop(int & _val)
		{
			if (this->isStackEmpty())
			{
				return false;
			}

			topOfStack--;
			_val = this->stackArr[topOfStack];
			return true;
		}
		int peak()
		{
			if (stackSize == 0)
				return 0;

			return stackArr[topOfStack - 1];
		}
		void printStack();

};


void Stack::printStack()
{
	if (isStackEmpty())
	{
		cout << "\[ \]"
			 << endl;
	}
	cout << "\[";
	for (int i = 0; i < topOfStack; i++)
	{
		cout << stackArr[i];
		if (i < (topOfStack - 1))
			cout << " ";
	}
	cout << "\]"
		 << endl;
}


void main()
{
	clrscr();
	int temp;
	Stack stackystacky(5);

	stackystacky.push(6);
	stackystacky.push(7);
	stackystacky.push(99);
	stackystacky.push(86);
	stackystacky.push(42);

	// printing stack after pushing 5 elements
	stackystacky.printStack();

	// peaking on top element
	cout << "Peaking on top element on stack: \n"
		 << stackystacky.peak()
		 << endl;

	cout << "Stack Before Popping: \n";
	stackystacky.printStack();
	cout << "After Popping: \n";
	stackystacky.pop(temp);
	stackystacky.printStack();

	return;
}