#include <iostream>
using namespace std;
class Node{
	public:
		Node* prev;
		int data;
		Node* next;
		
		Node(){}
		
};
void print(Node* head)
{
	while(head)
	{
		if(head->next == NULL)
		{
			cout<<"["<<head->data<<"]";
		}
		else
		{
			cout<<"["<<head->data<<"]->";
			
		}
		head=head->next;
	}
	cout<<endl<<endl;
}
//insert at the front
void push(Node** head_ref, int new_data)
{
	//allocate the node
	Node* new_node = new Node();
	
	//assign the data
	new_node->data = new_data;
	
	//make the next of the new node as head and the previous is NULL
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	
	//set the prev of head node to new node
	if((*head_ref) != NULL)
	{
		(*head_ref)->prev = new_node;
	}
	(*head_ref) = new_node;
}

//insertion before a specific node
void insertbefore(Node* next_node, int new_data)
{
	//check if the given node is null
	if(next_node ==NULL)
	{
		cout<<"The given next node can not be NULL";
		return;
	}
	
	//allocate the node
	Node* new_node = new Node();
	
	//assign the data
	new_node->data = new_data;
	
	//set the prev of the new node to the prev of the next node
	new_node->prev=next_node->prev;
	
	//set the prev of next_node as next node
	next_node->prev=new_node;
	
	//set the next of new node as next node
	new_node->next=next_node;
	
	//change next of new_node's previous node
	if(new_node->prev != NULL)
	{
		new_node->prev->next = new_node;
	}
	else
	{
		next_node = new_node;
	}
	
}
//insertion at the end
void insertend(Node** head_ref, int new_data)
{
	
	//check if the given node is NULL
	if(head_ref == NULL)
	{
		cout<<"the given next node can not be NULL";
		return;
	}
	//allocate the node
	Node* new_node = new Node;
	
	Node* last = *head_ref;
	
	//assign the data
	new_node->data = new_data;
	
	//set the next of the newly created node to NULL
	new_node->next = NULL;
	
	//check id the list is empty
	if(*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	
	//else traverse till the last node of list
	while(last->next != NULL)
	{
		last= last->next;
	}
	//point the next of last node to the newly created node
	last->next = new_node;
	return;
}
//delete first node
void deletefirst(Node** head_ref)
{
	//check if the list is empty
	if(*head_ref == NULL)
	{
		cout<<"list is empty"<<endl;
		return;
	}
	
	//save the reference to the head node
	Node* temp = *head_ref;
	
	//move the head to the next node
	*head_ref = (*head_ref)->next;
	
	//if the new head is not NULL, update its previous pointer to NULL
	if(*head_ref != NULL)
	{
		(*head_ref)->prev = NULL;
	}
	
	//free the memory of the original head node
	delete temp;
	
}
//delete specific node
void deletethis(Node** head_ref, int value) {
    // Check if the list is empty
    if (*head_ref == NULL) {
        cout << "List is empty." <<endl;
        return;
    }

    // Traverse the list and delete nodes with the specified value
    Node* current = *head_ref;
    Node* next_node;

    while (current != NULL) {
        next_node = current->next;

        // If the current node has the specified value
        if (current->data == value) {
            // If the current node is the head
            if (current == *head_ref) {
                *head_ref = next_node; // Update the head to the next node
                if (next_node != NULL) {
                    next_node->prev = NULL; // Update the next node's previous pointer
                }
                delete current; // Free the memory of the deleted node
            } else {
                current->prev->next = next_node; // Update the previous node's next pointer
                if (next_node != NULL) {
                    next_node->prev = current->prev; // Update the next node's previous pointer
                }
                delete current; // Free the memory of the deleted node
            }
        }

        current = next_node;
    }
}
//delete last element
//void deletelast()
int main() {
	
	Node* head = NULL;
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head,0);
	
	print(head);
	
	//insert end
	insertend(&head,5);
	print(head);
	//delete first node
	deletefirst(&head);
	print(head);
	
	print(head);
	
	//delete this
	deletethis(&head,3);
	print(head);
	return 0; }

