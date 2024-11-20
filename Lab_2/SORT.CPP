#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
  true = 1,
  false = 0
} bool;

class Complex
{
	private:
		float real;
		float img;
		static int counter;
	public:
		Complex()
		{
			//counter++;
			this->real = 0;
			this->img = 0;
			/*cout << "\nCounter = "
				 << counter
				 << endl;*/
		}
		Complex(float _real, float _img)
		{
			//counter++;
			real = _real;
			img = _img;
			/*cout << "\nCounter = "
				 << counter
				 << endl;  */
		}
		Complex(Complex & c)
		{
		   //	counter++;
			this->real = c.real;
			this->img = c.img;
		   /*	cout << "\nCounter = "
				 << counter
				 << endl;*/
		}
		float getReal()
		{
			return (this->real);
		}
		float getImg()
		{
			return ((*this).img);
		}
		void setValue(float _real)
		{
			this->real = _real;
		}
		void setValue(float _real, float _img)
		{
			this->real = _real;
			this->img = _img;
		}
		void addComplexValue(Complex c1)
		{
			(this->real) += c1.real;
			(this->img) += c1.img;
		}
		void subComplexValue(Complex c1)
		{
			(this->real) -= c1.real;
			(this->img) -= c1.img;
		}
	   /*	int getCounter()
		{
			return counter;
		} */
		friend void viewContent(Complex & c);

		~Complex()
		{
			/*counter--;
			cout << "\nCounter = "
				 << counter
				 << endl;*/
		}
		/***********************************/
		// haha, Operator Overloading go brrr!

		// c + c
		Complex operator + (Complex & c)
		{
			Complex c1((this->real + c.img), (this->img + c.img));
			return c1;
		}

		// c + f
		Complex operator + (float f)
		{
			Complex c1((this->real + f), (this->img));
			return c1;
		}

		// c - c
		Complex operator - (Complex & c)
		{
			Complex c1((this->real - c.real), (this->img - c.img));
			return c1;
		}

		// c - f
		Complex operator - (float f)
		{
			Complex c1((this->real - f), (this->img));
			return c1;
		}

		// c * c
		Complex operator * (Complex & c)
		{
			// (x + yi)*(a + bi) = (x*a - y*b) + (x*b + a*y)i
			Complex c1( (this->real * c.real) - (this->img * c.img),
						(this->real * c.img) + (this->img * c.real) );
			return c1;
		}

		// c * f
		Complex operator * (float f)
		{
			// (x + yi) * f = f*x + f*yi
			Complex c1((this->real * f), (this->img * f));
			return c1;
		}

		// c < c && c > c
		int operator < (Complex & c)
		{
			return ((this->real < c.real) && (this->img < c.img));
		}
		int operator > (Complex & c)
		{
			return ((this->real > c.real) && (this->img > c.img));
		}

		// c = c
		Complex & operator = (Complex & c)
		{
			this->real = c.real;
			this->img = c.img;
			return (*this);
		}

		// c++ && ++c
		Complex & operator ++ () // prefix
		{
			(this->real)++;
			(this->img)++;
			return (*this);
		}
		Complex operator ++ (int dumdum) // postfix
		{
			Complex temp(*this);
			(this->real)++;
			(this->img)++;
			return temp;
		}

		// c-- && --c
		Complex & operator -- () // prefix
		{
			(this->real)--;
			(this->img)--;
			return (*this);
		}
		Complex operator -- (int dumdum) // postfix
		{
			Complex temp(*this);
			(this->real)--;
			(this->img)--;
			return temp;
		}

		// c == c
		int operator == (Complex & c)
		{
			return ((this->real == c.real) && (this->img == c.img));
		}

		// c += c
		Complex & operator += (Complex & c)
		{
			this->real += c.real;
			this->img += c.img;
			return (*this);
		}

		// c -= c
		Complex & operator -= (Complex & c)
		{
			this->real -= c.real;
			this->img -= c.img;
			return (*this);
		}

		// (float)c
		operator float ()
		{
			return (float)sqrt((this->real * this->real) + (this->img * this->img));
		}


		// << && >> with i/o stream
		friend istream & operator >> (istream & in, Complex & c);
		friend ostream & operator << (ostream & out, Complex & c);
};


Complex addComplex(Complex & x, Complex & y)
{
	static Complex c3(x.getReal() + y.getReal(), x.getImg() + y.getImg());

	return c3;
}

Complex subComplex(Complex & x, Complex & y)
{
	static Complex c3(x.getReal() - y.getReal(), x.getImg() - y.getImg());

	return c3;
}

void viewContent(Complex & c)
{
	if (c.img == 1)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '+'
			 << " "
			 << "j\n";
	}
	else if (c.img == -1)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '-'
			 << " "
			 << "j\n";
	}
	else if (c.img == 0)
	{
		cout << "\nNumber = "
			 << c.real
			 << "\n";
	}
	else if (c.img < 0)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '-'
			 << " "
			 << -1 * c.img
			 << "j\n";
	}
	else if (c.img > 0)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '+'
			 << " "
			 << c.img
			 << "j\n";
	}
}

istream & operator >> (istream & in, Complex & c)
{
	cout << "Enter Real Part: ";
	in >> c.real;
	cout << "Enter Imaginary Part: ";
	in >> c.img;
	return in;
}

ostream & operator << (ostream & out, Complex & c)
{
	if ((int)c.img == 1)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '+'
			<< " "
			<< "j\n";
	}
	else if ((int)c.img == -1)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '-'
			<< " "
			<< "j\n";
	}
	else if ((int)c.img == 0)
	{
		out << "\nNumber = "
			<< c.real
			<< "\n";
	}
	else if ((int)c.img < 0)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '-'
			<< " "
			<< -1 * c.img
			<< "j\n";
	}
	else if ((int)c.img > 0)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '+'
			<< " "
			<< c.img
			<< "j\n";
	}

	return out;
}

class Employee
{
	private:
		char name[20];
		int id;
	public:
		Employee()
		{

		}
		Employee(char *_name, int _id)
		{
			id = _id;

			for (int i = 0; i < 20; i++)
			{
				name[i] = _name[i];
			}
		}
		char* getName()
		{
			return name;
		}
		int getID()
		{
			return id;
		}
		friend int sequentialSearchByID(Employee *empArr, unsigned int size, Employee & key);
		friend int sequentialSearchByName(Employee *empArr, unsigned int size, Employee & key);
		friend int binarySearchByID(Employee *empArr, unsigned int size, Employee & key);
		friend int binarySearchByName(Employee *empArr, unsigned int size, Employee & key);
};

template <class T>
void swap(T & t1, T & t2)
{
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}

template <class T>
void selectionSort(T arr[], int size)
{
	int index = 0;

	for (int i = 0; i < (size - 1); i++, index = i)
	{
		for (int j = (i + 1); j < size; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}

		swap(arr[index], arr[i]);
	}
}

template <class T>
void bubbleSort(T arr[], int size)
{
	int swapped;
	for (int i = 0; i < size; i++)
	{
		swapped = false;
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

	}

	return;
}

template <class T>
void merge(T *ptr, T *left, T *right, int leftCount, int rightCount)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while ((i < leftCount) && (j < rightCount))
	{
		if (left[i] < right[j])
			ptr[k++] = left[i++];
		else if (left[i] >= right[j])
			ptr[k++] = right[j++];
	}

	while (i < leftCount)
		ptr[k++] = left[i++];

	while (j < rightCount)
		ptr[k++] = right[j++];


}

template <class T>
void mergeSort(T *ptr, int size)
{
	int mid;
	int i;
	T *left;
	T *right;

	// base case
	if (size < 2)
		return;

	// middle index
	mid = size / 2;

	// allocating memory for left piece
	left = new T[mid];

	// allocating memory for right piece
	right = new T[size - mid];

	// copying elements to left piece
	for (i = 0; i < mid; i++)
		left[i] = ptr[i];

	// copying elements to right piece
	for (i = mid; i < size; i++)
		right[i - mid] = ptr[i];

	// recursion 100
	mergeSort(left, mid); // divide and sort left piece
	mergeSort(right, size - mid); // divide and sort right piece

	// merge left and right pieces
	merge(ptr, left, right, mid, size-mid);

	delete[] left;
	delete[] right;
}

void selectionSortStr(char **arr, int size)
{
	int index = 0;

	for (int i = 0; i < (size - 1); i++, index = i)
	{
		for (int j = (i + 1); j < size; j++)
		{
			if (strcmp(arr[index], arr[j]) > 0)
			{
				index = j;
			}
		}

		swap(arr[index], arr[i]);
	}
}


void main()
{
	clrscr();

	Complex compArr1[3] = { Complex(1,6), Complex(5,3), Complex(-3,-4)};
	Complex compArr2[3] = { Complex(1,6), Complex(5,3), Complex(-3,-4)};
	Complex compArr3[3] = { Complex(1,6), Complex(5,3), Complex(-3,-4)};

	selectionSort(compArr1, 3);
	bubbleSort(compArr2, 3);
	mergeSort(compArr3, 3);

	cout << "Selection Sort Output on Complex Array 1: \n";
	for (int i = 0; i < 3; i++)
	{
		cout << compArr1[i]
			 << " ";
	}
	cout << endl;


	cout << "Bubble Sort Output on Complex Array 2: \n";
	for (int j = 0; j < 3; j++)
	{
		cout << compArr2[j]
			 << " ";
	}
	cout << endl;

	cout << "Merge Sort Output on Complex Array 3: \n";
	for (int k = 0; k < 3; k++)
	{
		cout << compArr3[k]
			 << " ";
	}
	cout << endl;

	char *strArr[] = {"Thunder", "Cross", "Split", "Attack!"};

	selectionSortStr(strArr, 4);

	cout << "Selection Sort Output on String Array: \n";
	for (int p = 0; p < 4; p++)
	{
		cout << strArr[p]
			 << " ";
	}

	return;

}

