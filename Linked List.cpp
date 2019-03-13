// Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;

struct node{
	int x;
	node *next;
};
class Linked_List
{
public:
	Linked_List(){
		start = NULL;
		end = NULL;
	};
	void Add(int y);
	void Delete(int y);
	int Length();
	void Traverse();
	void Create(int y);
	void fileinput();
	void fileoutput();

	~Linked_List(){};

private:
	node *start, *end;
	int length = 0;
};



void Linked_List::Traverse(){
	node *temp;
	temp = start;
	if (temp == NULL)
	{
		cout << "Linked List is empty \n";
		//return;
	}

	else{
		int i = 1;
		while (temp!=NULL)
		{
			cout << i << " : " << temp->x << endl;
			i += 1;
			temp=temp->next;
		}
	}
	delete temp;
	return;
}

//****************************************************************
//*****************************
//****************************************************************

void Linked_List::Delete(int y){
	node *temp,*temp_prev;
	temp = start;
	//IF LIST IS EMPTY
	if (temp == NULL){
		cout << "Nothing to delete Linker List is empty \n";

	}
	else
	{
		int found = 0;
		while (found == 0 && temp != NULL){
			if (temp->x == y)
				found = 1;
			else
			{
				temp_prev = temp;
				temp = temp->next;
			}
		}
		if (temp == NULL)
		{
			cout << "Value :" << y << "Not Present \n";

		}
		else
		{
			temp_prev->next = temp->next;
			length -= 1;
		}
	}
	delete temp;
	return;
}
//********************************************
//*********************
//*************************************************
int Linked_List::Length(){
	return length;
}
//********************************************
//*********************
//*************************************************

void Linked_List::Add(int y){
	node *temp;
	temp = new node;
	temp->x = y;
	temp->next = NULL;
	if (start == NULL){
		start = temp;
		end = temp;
	}
	else{
		end->next = temp;
		end = temp;

	}
	//******************IN CHROLOGICAL ORDER
	//******************
/*	if (start == NULL){
		start = temp;
	}
	else
	{
		node *before, *after;
		after = start;
		while (after->x < y && after != NULL){
			before = after;
			after=after->next;

		}
		if (after->x == y){
			cout << "Duplicate Value \n";
		}
		else
		{
			before->next = temp;
			temp->next = after;
		}
	}*/
	length += 1;
	return;
}

//********************************************
//*********************
//*************************************************
void Linked_List::Create(int y){
	node *temp; node *before;
	temp = new node;
	temp->x = y;
	temp->next = NULL;
	if (start == NULL){
		start = temp;
		end = temp;
	}
	else{
		before = start;
		start->next = temp;
		temp->next = before;

	}
	delete temp, before;
	length += 1;
	return;
}
//********************************************
//*********************
//*************************************************
void Linked_List::fileinput(){
	ifstream file;
	file.open("a.txt");
	if (file.fail()){
		cout << "File not present. \n";
		return;
	}
	int y;
	while (!file.eof())
	{
		file >> y;
		Add(y);
	}
	file.close();
	return;
}

void Linked_List::fileoutput(){
	ofstream file;
	file.open("a.txt");
	{
		node *temp;
		temp = start;
		int i = 1;
		while (temp != NULL)
		{
			file  << temp->x << endl;
			i += 1;
			temp = temp->next;
		}
	}
	file.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Linked_List list;
	int temp,i=0;
	list.fileinput();
	while (i != 5){

		cout << "What would you like to do next ? Options are \n";
		cout << "1) Add \t 2) Delete \t 3) Length \t 4) Traverse \t 5) End :";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "Enter the number :";
			cin >> temp;
			list.Add(temp);
			break;
		case 2:

			cout << "Enter the number :";
			cin >> temp;
			list.Delete(temp);
			break;
		case 3:
			cout << "Length :" << list.Length()<<endl;
			break;
		case 4:
			list.Traverse();
			list.fileoutput();
			break;
		case 5:
			cout << "OK. Thank you \n";
			return 0;
		default:
			cout << "Invalid Input \n";
			break;
		}
	}
	return 0;
}

