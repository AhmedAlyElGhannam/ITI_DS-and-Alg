#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <string.h>

typedef enum
{
  true = 1,
  false = 0
};

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
		friend int sequentialSearchComplex(const Complex *compArr, unsigned int size, Complex & key);
		friend int binarySearchComplex(const Complex *compArr, unsigned int size, Complex & key);
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

int sequentialSearchComplex(Complex *compArr, unsigned int size, Complex & key)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (compArr[i] == key)
		{
			index = i;
			break;
		}
	}

	return index;
}

int binarySearchComplex(Complex *compArr, unsigned int size, Complex & key)
{
	int index = -1;
	int start = 0;
	int end = size - 1;
	int mid;
	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (compArr[mid] == key)
		{
			index = mid;
			break;
		}
		else if (compArr[mid] > key)
		{
			end = mid - 1;
		}
		else if (compArr[mid] < key)
		{
			start = mid + 1;
		}
	}

	return index;
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

int sequentialSearchByID(Employee *empArr, unsigned int size, Employee & key)
{
	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (key.getID() == empArr[i].getID())
		{
			index = i;
			break;
		}
	}

	return index;
}

int binarySearchByID(Employee *empArr, unsigned int size, Employee & key)
{
	int index = -1;
	int start = 0;
	int end = size - 1;
	int mid;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (empArr[mid].getID() == key.getID())
		{
			index = mid;
			break;
		}
		else if (empArr[mid].getID() > key.getID())
		{
			end = mid - 1;
		}
		else if (empArr[mid].getID() < key.getID())
		{
			start = mid + 1;
		}
	}

	return index;
}

int sequentialSearchByName(Employee *empArr, unsigned int size, Employee & key)
{
	int index = -1;
	int cmp;
	for (int i = 0; i < size; i++)
	{
		cmp = strcmp(empArr[i].getName(), key.getName());

		if (!cmp)
		{
			index = i;
			break;
		}
	}

	return index;
}

int binarySearchByName(Employee *empArr, unsigned int size, Employee & key)
{
	int index = -1;
	int start = 0;
	int end = size - 1;
	int mid;
	int cmp;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		cmp = strcmp(empArr[mid].getName(), key.getName());

		if (!cmp)
		{
			index = mid;
			break;
		}
		else if (cmp > 0)
		{
			end = mid - 1;
		}
		else if (cmp < 0)
		{
			start = mid + 1;
		}
	}

	return index;

}

int sequential_search(int *arr, unsigned int size, int elem)
{
	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == elem)
		{
			index = i;
			break;
		}
	}

	return index;
}


void main()
{
	clrscr();

	int arr[78] = {0};

	for (int i = 0; i < 78; i++)
	{
		arr[i] = i;
	}

	cout << "Testing Sequential Search on Array of int: \n"
		 << sequential_search(arr, 78, 70)
		 << endl;

	Complex compArr[12] = { Complex(1,2), Complex(2,3), Complex(3,4),
							Complex(4,5), Complex(5,6), Complex(6,7),
							Complex(7,8), Complex(8,9), Complex(9,10),
							Complex(10,11), Complex(11,12), Complex(12,13)
						  };

	Complex key(5,6);
	cout << "Testing Sequential Search on Array of Complex: \n"
		 << sequentialSearchComplex(compArr, 12, key)
		 << endl;

	cout << "Testing Binary Search on Array of Complex: \n"
		 << binarySearchComplex(compArr, 12, key)
		 << endl;

	Employee empArr[5] = { Employee("Ehsan", 123), Employee("Medhat", 234), Employee("Mohsen", 345),
						   Employee("Sehs", 456), Employee("Sultan", 567)
						 };


	Employee empKey("Sehs", 456);

	cout << "Testing Sequential Search on Array of Employee (By ID): \n"
		 << sequentialSearchByID(empArr, 9, empKey)
		 << endl;

	cout << "Testing Sequential Search on Array of Employee (By Name): \n"
		 << sequentialSearchByName(empArr, 9, empKey)
		 << endl;

	cout << "Testing Binary Search on Array of Employee (By ID): \n"
		 << binarySearchByID(empArr, 9, empKey)
		 << endl;

	cout << "Testing Binary Search on Array of Employee (By Name): \n"
		 << binarySearchByName(empArr, 9, empKey)
		 << endl;

	return;

}

