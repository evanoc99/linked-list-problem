// linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string>

class node
{
private:
protected:
public:
	node * next;
	node * prev;
	std::string data = "r";
};

class list
{
private:
	node * head;
	node * tail;
	node * current;
	node * recent;
	node * temp;
public:
	list() {}
	list(unsigned int t)
	{
		createnodelist(t);
	}
	

	std::string getnode(const unsigned int &);
	void setnode(const unsigned int &, std::string);
	void createnodelist(unsigned int);
	unsigned int findnode(std::string);
	void addnode(unsigned int, std::string);
	void deletenode(unsigned int);
};

void list::createnodelist(unsigned int y)
{

	for (unsigned int i = 0; i < y; i++)
	{
		if (i == 0)
		{
			head = new node;
			head->data = "head";
			current = head;
			current->prev = NULL;
		}
		else if (i == (y - 1))
		{
			tail = new node;
			tail->data = "tail";
			tail->prev = current;
			tail->next = NULL;
			current->next = tail;
		}
		else
		{
			recent = new node;
			recent->prev = current;
			current->next = recent;
			current = recent;
		}
	}
}

std::string list::getnode(const unsigned int & y)
{
	bool check = true;
	current = head;
	for (unsigned int i = 0; i < y; i++)
	{
		if (current->next != NULL)
		{
			current = current->next;
		}
		else { std::cout << "outside of list" << std::endl; check = false; break; }
	}
	if (check == true) { return current->data; }
	else { return "The node was not in the list"; }
}

void list::setnode(const unsigned int & y, std::string k)
{
	bool check = true;
	current = head;
	for (unsigned int i = 0; i < y; i++)
	{
		if (current->next != NULL)
		{
			current = current->next;
		}
		else { std::cout << "outside list" << std::endl; check = false; break; }
		
	}
	if (check == true) { current->data = k; }
}

unsigned int list::findnode(std::string k)
{
	unsigned int i = 0;
	current = head;
	if (k == head->data)
	{
		return i;
	}
	while(current->next != NULL)
	{
		i++;
		current = current->next;
		if (current->data == k)
		{
			return i;
		}
	}
}

void list::addnode(unsigned int y, std::string k)
{
	current = new node;
	current->data = k;

	recent = head;
	for (unsigned int i = 0; i < y; i++)
	{
		if (recent->next != NULL)
		{
			recent = recent->next;
		}
		else { std::cout << "outside list" << std::endl; break; }
	}
	if (recent->next != NULL)
	{
		temp = recent->next;

		recent->next = current;
		current->prev = recent;

		temp->prev = current;
		current->next = temp;
	}
}

void list::deletenode(unsigned int y)
{
	bool check = true;
	current = head;
	for (unsigned int i = 0; i < y; i++)
	{
		if (current->next != NULL)
		{
			current = current->next;
		}
		else { std::cout << "outside list" << std::endl; check = false; break; }
	}
	if (check == true)
	{
		recent = current->prev;
		temp = current->next;

		recent->next = temp;
		temp->prev = current;

		delete current;
	}
}

int main(int argc, char * argv[])
{
	list e(20);
	e.setnode(10, "alpha");
	e.addnode(10, "new node");
	std::cout << e.findnode("tail") << std::endl;
	std::cout << e.getnode(11) << std::endl;
}