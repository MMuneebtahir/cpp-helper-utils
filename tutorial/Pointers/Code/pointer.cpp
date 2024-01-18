#include <iostream>
#include <vector>
int sumofElement(int A[]);
int sumofElement_ref(int *A, int size);
void Double(int *A, int size);
void local_function_increment(int a);
void call_by_reference(int *p);
int main()
{
	int check = 0;
	std::cout<<"Enter a section number you want to run"<<std::endl;
	std::cin>>check;

	if (check == 0)
	{
		/******************************************
		******************************************
			Introduction to pointers in C/C++
		******************************************
		******************************************/
		int a;												 // creating a variable of type int
		int *p;												 // creating a pointer of type int
		p = &a;												 // assigning  p the address of a
		std::cout << "initial value:	" << a << std::endl; // garbage value in a
		a = 5;												 // assigning  a value 5
		std::cout << "pointer:	" << p << std::endl;
		std::cout << "address to value: " << &a << std::endl;
		std::cout << "address to pointer: " << &p << std::endl;
		std::cout << "pointer to value:	" << *p << std::endl;
		*p = 8; // accessing a through pointer p
		std::cout << "value changed via pointer:	" << a << std::endl;
		int b = 100;
		*p = b;
		std::cout << "value of a change with pointer:	" << a << std::endl;
	}
	else if (check == 1)
	{
		/******************************************
		******************************************
				Working with pointers
		******************************************
		******************************************/
		int a = 10;
		int *p;
		p = &a;
		std::cout << "pointer:		" << p << std::endl;
		std::cout << "pointer increment:	" << p + 1 << std::endl; // difference of p+1 and p is 4 as p is of type int
		std::cout << "step increment:		" << sizeof(a) << std::endl;
		std::cout << "value at *(p+1):		" << *(p + 1) << std::endl; // some garbage value
	}
	else if (check == 2)
	{
		/*****************************************************
		******************************************************
		Pointer Types, Pointer Arithmetic , void pointer
		******************************************************
		******************************************************/
		int a = 1025;
		int *p = &a;
		std::cout << "size of integer:	" << sizeof(int) << " bytes" << std::endl;
		std::cout << "address pointing to a  :	" << p << "	value of pointer:	" << *p << std::endl;
		std::cout << "address pointing to p+1:	" << p + 1 << "	value of pointer:	" << *(p + 1) << std::endl;
		// this increment is equal to 4 bytes as p stores sizeof(int) bytes p+1 address would be p's address + 4bytes
		char *p0;
		p0 = (char *)p; // type cast
		std::cout << "size of char " << sizeof(char) << std::endl;
		std::cout << "Address of p0:	" << (void *)p0 << " value of p0:	" << (void *)(*p0) << std::endl;
		std::cout << "Address of p0:	" << (void *)p0 + 1 << " value of p0+1:	" << (void *)(*(p0 + 1)) << std::endl;
		// base address of pointer to integer is shored in P0 so P0 point first byte of p that is 1
		// p0 +1 would point to second byte of p that is 4
		//   1025 = 00000000 00000000 00001000 0000001
		//   1025 =		0		0		 4		 1
		//  generic pointer type
		/*
		void pointer type  is not mapped to a particular data type,
		we cannot dereference this particular pointer  variable.
		So, if you try to print *P0 will give you  an error we are
		getting a compilation error,
		*/
		void *P0;
		P0 = p;
		// std::cout << "Address of p0:	" << (void*)P0 << " value of P0:	" <<(void*)(*P0) << std::endl; //compilation error
		std::cout << "Address of p0  :	" << (void *)P0 << std::endl;	  // we only print the address
		std::cout << "Address of p0+1:	" << (void *)P0 + 1 << std::endl; // we only print the address
	}
	else if (check == 3)
	{
		/******************************************
		******************************************
				pointer to pointer
		******************************************
		******************************************/
		int x = 5;
		int *p = &x;
		std::cout << std::hex << "value of p			" << p << std::endl;
		std::cout << std::hex << "address of p			" << &p << std::endl;
		std::cout << std::hex << "pointer value p			" << *p << std::endl;
		*p = 6;
		std::cout << "Updating x though its pointer p" << std::endl;
		std::cout << std::hex << "pointer value p			" << *p << std::endl;
		std::cout << std::hex << "value of x			" << x << std::endl;
		int **q = &p;
		std::cout << std::hex << "value of p			" << p << std::endl;
		std::cout << std::hex << "pointer value of q		" << *q << std::endl;

		std::cout << std::hex << "pointer value of p		" << *p << std::endl;
		std::cout << std::hex << "pointer to pointer  of q	" << **q << std::endl;
	}
	else if (check == 4)
	{
		/****************************************************
		****************************************************
		Pointers as function arguments - call by reference
		****************************************************
		****************************************************/
		int a = 5;
		std::cout << std::hex << "address of a:				" << &a << std::endl;
		local_function_increment(a);
		std::cout << std::hex << "value of a: " << a << std::endl;
		call_by_reference(&a);
		std::cout << std::hex << "value of a: " << a << std::endl;
	}
	else if (check == 5)
	{
		/******************************************
		******************************************
				pointer and Array
		******************************************
		******************************************/
		int A[5] = {2, 4, 5, 8, 1};
		int *p = &A[0];
		std::cout << "address of A			" << &A << std::endl;
		std::cout << "Value of P (address of A[0])	" << p << std::endl;
		/* base address of A array) is same as address of A[0]*/
		std::cout << "pointer value p		" << *p << std::endl;
		std::cout << "value of A[0]		" << *A << std::endl;
		std::cout << "pointer value p+1	" << *(p + 1) << std::endl;
		std::cout << "value of A[1]		" << *(A + 1) << std::endl;
		std::cout << "pointer value p+2	" << *(p + 2) << std::endl;
		std::cout << "value of A[2]		" << *(A + 2) << std::endl;
		std::cout << "pointer value p+3	" << *(p + 3) << std::endl;
		std::cout << "value of A[3]		" << *(A + 3) << std::endl;
		// A++   ==> would give us error
		// after assigning address to pointer we can do p++
	}
	else if (check == 6)
	{
		/******************************************
		******************************************
				Array as function argument
		******************************************
		******************************************/
		int A[] = {1, 2, 3, 4, 5};
		int size = sizeof(A) / sizeof(A[0]);
		std::cout << "size of A inside main " << size << std::endl;
		int total = sumofElement(A);
		std::cout << "sum of element:	" << total << std::endl;
		int total_ref = sumofElement_ref(&A[0], size);
		std::cout << "sum of A ref:	" << total_ref << std::endl;
		Double(A,size);
		for (int i = 0; i < size; i++){
			std::cout<<A[i]<<"	";
		}
		std::cout<<std::endl;
	}
	return 0;
}
int sumofElement(int A[])
{
	/*
	when is called it does not copy the whole array
	it just create a pointer to array
	int A[]  ==> int *A  (both are same here )
	array are always passed as reference to function
	if we dont pass it by reference we cannot
	calculate the correct size of array

	one advantage is that every time we call the function we don't want to
	copy the whole big array
	*/
	int sum = 0;
	int size = sizeof(A) / sizeof(A[0]);
	std::cout << "size of A inside function " << size << std::endl;

	for (int i = 0; i < size; i++)
	{
		sum += A[i];
	}
	return sum;
}
int sumofElement_ref(int *A, int size)
{
	int sum = 0;
	std::cout << "size of A ref function " << size << std::endl;
	for (int i = 0; i < size; i++)
	{
		sum += A[i];
	}
	return sum;
}
void Double(int *A, int size)
{
	for (int i = 0; i < size; i++)
	{
		A[i]=2*A[i];
	}
	
}
void local_function_increment(int x)
{ // call by value function
	/*
	when function is called new variable is declared
	& value id copied to that variable
	when a function end it clears the stack frame that was located
	for  increment the local variable
	and main method resumes again
	lifetime of a local variable is
	till the time the function is executing.
	*/
	x = x + 1;
	std::cout << std::hex << "address of a local_function_increment :	" << &x << std::endl;
}
void call_by_reference(int *p)
{
	/*
	when you this line execute
		*p=&a
	*/
	*p = (*p) + 1;
}