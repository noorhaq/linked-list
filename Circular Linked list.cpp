// Circular Linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node{
	int y;
	node *cw, *acw;
};

node *start = NULL;
int length = 0;
void traverse(){
	node *temp;
	temp = start;
	if (start == NULL){
		cout << "List is empty. \n";
		return;
	}
	do{
		cout << temp->y<<endl;
		temp = temp->cw;
	} while (temp!=start);

	do{
		cout << temp->y << endl;
		temp = temp->acw;
	} while (temp != start);
	return;
}

void add(int y)
{
	node *b = new node;
	b->y = y;
	if (start == NULL){
		start = b;
		b->cw = start;
		b->acw = start;
		length++;
		return;
	}
	node *temp = start;

		if (temp->y == y)
		{
			cout << "Value alrady present. \n";
			return;
		}
		if (temp->y > y)
		{
			start = b;
			b->cw = temp;
			b->acw = temp->acw;
			temp->acw = b;
			temp = b->acw;
			temp->cw = b;
			length++;
			return;
		}

		if (temp->y < y)
		{
			node *after;
			node *before=new node;
			after = start;
		//	while ((after->y) < y)
			{
				before = after;
				after = after->cw;
			}
			before->cw = b;
			b->acw = before;
			b->cw= after;
			after->acw = b;
			return;
		} 

		if (temp->y < y)
		{
			b->cw = start;
			b->acw = start->acw;
			start->acw = b;
			temp = b->acw;
			temp->cw = b;
			length++;
			return;
		}
}

void search(int x){
	node *temp_cw,*temp_acw;
	temp_cw = start->cw;
	temp_acw = start;
	if (start == NULL){
		cout << "List is empty. \n";
		return;
	}
	static int i = 0;
Here:
	i++;
	if (temp_acw->y == x)
	{
		cout << "X found 1:" << endl;
		cout << i;
		return;
	}
	if (temp_cw->y == x)
	{
		cout << "X found 2:" << endl;
		cout << i;
		return;
	}
	if (temp_acw == temp_cw)
	{
		cout << "Value not found. ";
		cout << i;
		return;
	}
	temp_acw=temp_acw->acw;
	temp_cw = temp_cw->cw;
	goto Here;
}

int _tmain(int argc, _TCHAR* argv[])
{
	add(7);
	add(3);
	add(4);
	add(6);
	add(1);
	add(9);
	search(10);
	cout << endl;
	traverse();
	return 0;
}

