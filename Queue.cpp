// QUEUE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node{
	int x;
	node *behind;
};

node *front=NULL, *back=NULL;
int length=0;

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
	back->behind = temp;
	back = temp;
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

void _Duplicate(struct node *temp){
	if (front == NULL)
	{
		return;
	}

	int y=0;
	temp = front;
	while (temp != NULL)
	{
		node *temp_prev;
		y = temp->x;
		while (temp->x != y && temp != NULL){
			temp_prev = temp;
			temp = temp->behind;
		}
		if (temp->x == y)
		{
			temp_prev->behind = temp->behind;
			length--;
			delete temp;
			temp = temp_prev;
		}
		temp = temp->behind;
	}

}
void Traverse()
{
	node *tmp;
	tmp = front;
	while (tmp!= NULL)
	{
		cout << tmp->x<< "\t";
		tmp = tmp->behind;

		cout << tmp->x;
		cout << endl;
	}
	return;
}

void choices()
{
	node *temp=new node;
	int choice = 0;
		cout << "1--Add \t 2--Delete \t 3--Duplicate \t 4--Exit \n Input your choice :";
		cin >> choice;
		switch (choice){
		case 1:
			push(temp);
			cout << length <<endl;
			choices();
		case 2:
			pop(temp);
			cout << "\n" << length<<endl ;
			choices();
		case 3:
			_Duplicate(temp);
			Traverse();
			choices();
		case 4:
			return;
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

