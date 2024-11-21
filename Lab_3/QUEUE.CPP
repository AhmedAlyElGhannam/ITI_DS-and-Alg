#include <iostream.h>
#include <conio.h>

typedef enum
{
  true = 1,
  false = 0
} bool;

class Queue
{
	private:
		int rear;
		int size;
		int *queue;
	public:
		Queue(const int _size = 10)
		{
			rear = 0;
			size = _size;
			queue = new int[size];
		}
		~Queue()
		{
			delete[] (queue);
			size = 0;
			rear = -1;
		}

		int isEmpty()
		{
			return (rear == 0);
		}
		int isFull()
		{
			return (rear == size);
		}
		int input(const int _val)
		{
			if (isFull())
			{
				return false;
			}

			queue[rear] = _val;
			rear++;

			return true;
		}
		bool output(int & _val)
		{
			if (isEmpty())
			{
				return false;
			}

			_val = queue[0];

			for (int i = 0; i < rear; i++)
				queue[i] = queue[i+1];

			rear--;
			return true;
		}
		int peak()
		{
			if (isEmpty())
				return 0;

			return queue[0];
		}
		void print();

};


void Queue::print()
{
	if (isEmpty())
	{
		cout << "\[ \]"
			 << endl;
	}
	cout << "\[ ";
	for (int i = 0; i < rear; i++)
	{
		cout << queue[i];
		if (i < rear)
			cout << " ";
	}
	cout << "\]"
		 << endl;
}


void main()
{
	clrscr();
	int temp;
	Queue Q(5);

	Q.input(6);
	Q.input(7);
	Q.input(99);
	Q.input(86);
	Q.input(42);

	// printing queue after pushing 5 elements
	Q.print();

	// peaking on first element in Q
	cout << "Peaking on first element in Q: \n"
		 << Q.peak()
		 << endl;

	cout << "Queue Before Outputing: \n";
	Q.print();
	cout << "After Outputing: \n";
	Q.output(temp);
	Q.print();

	return;
}