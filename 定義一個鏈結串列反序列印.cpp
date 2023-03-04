#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

struct Node{
	
	int data;
	struct Node *next;
	
};
int main()	
	{
	Node *head,*ptr;
	head = NULL;
	int value ;
	
	while(1)
	{
	 cin >> value;
	 if (value == -1)
	 {
	 	break;	
	 }
	 if(head==NULL)
	 {
	 	head =(Node*)malloc(sizeof(Node));	
	 	head->next = NULL;
	 }
	 else
	 {
	 head =(Node*)malloc(sizeof(Node));	
	 head->next =ptr;
	 }
	 head->data = value;
	 ptr = head;
	}
	ptr = head;
	while(ptr!=NULL){ 
		cout << ptr->data << " "; 
		ptr=ptr->next;		
	}
	return 0;
}