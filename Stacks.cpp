#include <iostream>

using namespace std;

#define SIZE 10

void push(int stack[], int& top, int item);
void pop(int stack[], int& top);
void top_function(int stack[], int top);
void purge(int stack[],int& top);
bool isEmpty(int top);
bool isFull(int top);
bool ispurge(int top);
void displayStack(int stack[], int top);
 
int main()
{
	int stack[SIZE], top, option, item;
	char repeat = 'y'; 

while(repeat == 'y')
{
	top = 0;

do
 {
	 cout << "MENU" << endl;
	 cout << "1. Push an integer" << endl;
	 cout << "2. Pop an integer" << endl;
	 cout << "3. Display the top element" << endl;
	 cout << "4. Check if stack is empty" << endl;
	 cout << "5. Purge the Stack" << endl;
	 cout << "6. Exit" << endl;
	 cout << endl << "Enter your choice(1-6): ";
	 cin  >> option;

	if(option == 1)
	{
		if(isFull(top)) 
		 cout << "Stack is full, overflow error" << endl;
		 cout << "Enter an integer between 0 and 99: ";
		 cin  >> item;

		if (item >=0 && item <= 99)
		{
		 push(stack, top, item); 
		 displayStack(stack, top); 
		}

		if (item <0 || item >99)
		{
		 cout << "Error, enter a postive integer between 0 and 99";
		 displayStack(stack, top); 
		}
	}

	else if(option == 2)
	{
		if (isEmpty(top)) 
		 cout << "Stack is empty, underflow error" << endl;

		else pop(stack, top); 
		 displayStack(stack, top); 
	}

	else if(option == 3)
	{
		if (isEmpty(top)) 
		 cout << "Stack is empty, underflow error" << endl;

		 else top_function(stack, top); 
		 displayStack(stack, top); 
	}

	else if(option == 4)
	 {
		if(isEmpty(top)) 
		 cout << "Stack is empty" << endl;
		 
		else 
		 cout << "Stack is not empty" << endl;
		 displayStack(stack, top); 
	 }

	else if(option == 5)
	 {
		purge(stack, top); 
		displayStack(stack, top); 
	 }
	
	else if(option != 6) 
		cout << "Invalid choice";
		cout << endl;		
 }
	
while(option != 6);
		cout << "Enter 'y' to run the program again: ";
		cin  >> repeat;
}

return 0;
}

void push(int stack[], int& top, int item)
 {
	if(isFull(top)) 
	 cout << "Stack is full, overflow error" << endl;

	else 
	{
	 stack[top] = item;
	 top++; 
	}
 }

void pop(int stack[], int& top)
 {
	if(isEmpty(top)) 
	 cout << "Stack is empty, underflow error" << endl;

	else 
	{
	 top--; 
	 cout << endl << stack[top] << " has been removed"  << endl;
	}
 }

void purge(int stack[], int& top)
 { 
	top =-1; 
	cout << "Stack has been purged " << endl;
 }

void top_function(int stack[], int top)
 {
	if(isEmpty(top)) 
	 cout << "Stack is empty, underflow error" << endl;

	else 
	 cout << "Top element: " << stack[top-1] << endl;
 }

bool isEmpty(int top)
 {
	return top == 0;
 }

bool isFull(int top)
 {
	return top == SIZE;
 }

bool ispurge(int top)
 {
	return top =-1;
 }

void displayStack(int stack[], int top)
 {
	cout << endl << "Stack elements: " << endl;
	
	if(isEmpty(top)) 
	 cout << "Stack is empty" << endl;
	
	else
	{
	 for(int i=top-1;i>=0;i--)
	 cout << stack[i] << endl;
	}	
 }