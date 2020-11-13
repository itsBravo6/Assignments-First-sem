#include <iostream>
using namespace std;
struct node
{
public:
	int data;
	node* next;
};



class ring
{
private:

	node* head, * temp, * temp1;

public:
	ring()
	{
		head = temp = temp1 = NULL;

	}

	void add()
	{
		if (head == NULL)

		{
			head = new node;
			cout << "Enter 1st Node's value:";
			cin >> head->data;
			head->next = head;
			return;
		}

		else
		{
			temp = head;
			do
			{
				if (temp->next == head)

				{
					temp1 = new node;

					cout << "Enter the data for node:";
					cin >> temp1->data;
					temp->next = temp1;
					temp1->next = head;
					return;
				}
				
				temp = temp->next;
			} while (temp!= head);
		}
		
	}




	void print()

	{
		

		if (head == NULL)
		{
			cout << "List is empty " << endl;

		}

		else
		{
			temp = head;
			do
			{


				
					cout << temp->data << " ";
					temp = temp->next;
					
				
			}while (temp != head);
		}
	}


	void del ()
	{
		
		if (head == NULL)
		{
			cout << "Nothing to Delete" << endl;
		}

		else {
			temp = head;
			int key;
			cout << "Enter Number to Check :";
			cin >> key;
			do
			{
				if (temp->next->data == key && temp->next == head)
				{
					head->next = temp;
					delete head;
					head = temp;
					return;
				}

				else if (temp->next->data == key && temp->next->next !=head)
				{
					temp->next = temp1;
					temp1->next=temp->next->next;
					
					temp->next = temp1->next;

					delete temp1;
					temp1 = NULL;
					return;




				}

				if (temp->next->data == key && temp->next->next == head)
				{
					temp->next = temp1;
					temp1->next = head;
					temp->next = temp1->next;
					delete temp1;
					temp1 = NULL;
					return;
				}
				temp = temp->next;
			}while (temp != head);
		}
	}
};


int main()
{
	ring A;

	A.add();
	A.add();
	A.add();

	A.print();

	A.del();

	cout << endl;

	A.print();
	
	system("pause");
}