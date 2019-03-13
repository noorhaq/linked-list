// Stack1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node{
	int x;
	node *behind;
};
node *front = NULL, *back = NULL;
int length = 0;

void push(struct node *temp)
{
	int y;
	cout << "Please input the value : ";
	cin >> temp->x;
	if (front == NULL)
	{
		front = temp;
		back = temp;
		temp->behind = NULL;
		length++;
		return;
	}
	temp->behind = front;
	front = temp;
	length++;
	return;
}

void pop(struct node *temp)
{

	if (front == NULL){
		cout << "Queue is empty \n";
		return;
	}
	temp = front;
	cout << "The value being processed : " << front->x;
	front = front->behind;
	delete temp;
	length--;
	return;
}
//***************************************************************
//***********************************Dublicate Entries
//***************************************************************
void delete_duplicate()
{
	node *temp, *before, *after;
	temp = front;
	after = front;
	before = front;
	while (temp != NULL)
	{
		before = temp;
		after = temp->behind;
		while (after != NULL)
		{
			if (after->x == temp->x)
			{
				before->behind = after->behind;
				delete after;
				length--;
				after = before;
			}
			before = after;
			if (before != NULL)
			{
				after = after->behind;
			}
		}
		temp = temp->behind;
	}
}

void Traverse()
{
	node *temp;
	temp = front;
	while (temp != NULL)
	{
		cout << temp->x << "\t";
		temp = temp->behind;
		cout << endl;
	}
	return;
}

void choices()
{
	node *temp = new node;
	int choice = 0;
	cout << "1--Add \t 2--Delete \t 3--Duplicate \t 4--Exit \n Input your choice :";
	cin >> choice;
	//Traverse();
	switch (choice){
	case 1:
		push(temp);
		cout <<endl<< length << endl;
		choices();
	case 2:
		pop(temp);
		cout << endl << length << endl;
		choices();
	case 3:
		delete_duplicate();
		Traverse();
		cout << endl << length << endl;
		choices();
	case 4:
		break;
	default:
		cout << "Invalid Input. Select again. \n";
		choices();
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	choices();
	return 0;
}

