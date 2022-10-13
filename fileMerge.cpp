// fileMerge.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
using std::ifstream;

using namespace std;

struct node
{
	string data;
	node* next;
};

class linked_list
{
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	node* head;
	node* tail;

public:
	node* create(string n)
	{

		node* tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
		return head;
	}
	void display(node* head)
	{
		node* q;
		q = head;
		while (q != NULL)
		{
			cout << q->data <<endl;
			q = q->next;

		}
	}
	void writeFile(node* head)
	{
		ofstream RT_File("RT.txt");
		node* q;
		q = head;
		while (q != NULL)
		{
			RT_File << q->data << endl;
			q = q->next;
		}
	}
	node* merge(node* head1l1, node* head2l2,int len_pwd)
	{
		linked_list l;
		node* dummy = nullptr;
		node* head = nullptr;
		dummy = l.create("A");
		head = l.create("A");

		int flag = 0;

		node* p, * q;
		p = head1l1;
		q = head2l2;

		if (p == NULL && q == NULL)
			return NULL;
		else if (p == NULL)
			return q;
		else if (q == NULL)
			return p;


		while (p != NULL && q != NULL)
		{
			if (p->data.substr(len_pwd+1,len_pwd) < q->data.substr(len_pwd + 1, len_pwd)) {
				if (flag == 0) {
					head = p;
					dummy = head;
				}
				else {
					dummy->next = p;
					dummy = dummy->next;
				}
				p = p->next;
			}
			else {
				if (flag == 0) {
					head = q;
					dummy = head;
				}
				else {
					dummy->next = q;
					dummy = dummy->next;
				}
				q = q->next;
			}
			flag = 1;
		}

		while (p != NULL) {
			dummy->next = p;
			dummy = dummy->next;
			p = p->next;
		}
		while (q != NULL) {
			dummy->next = q;
			dummy = dummy->next;
			q = q->next;
		}
		return head;

	}

};


int main()
{
	linked_list l;
	linked_list l2;
	node *head = nullptr;
	node *head2 = nullptr;

    ifstream indata("example1.txt"); 
    ifstream indata2("example2.txt");

	string line,line2;


	while (std::getline(indata, line)) 
	{
		head = l.create(line);
	}

	while (std::getline(indata2, line2))
	{
		head2 = l2.create(line2);
	}

	l.display(head);
    cout << "--" << endl; 
	l2.display(head2);
	cout << "--" << endl;
	head = l.merge(head, head2,4);
	l.display(head);
	l.writeFile(head);
}

