 #include<bits/stdc++.h>
using namespace std;

struct node
{
    int dob;
    string name;
    struct node* prev;
    struct node* next;
};
void Add(node** head,int a, string first_name, string last_name)
	{
     struct node* temp=*head;
     while(temp!=NULL)
		{
         if(temp->dob==a)
		   {
             cout<<"ID already exists";
            return;
           }
        temp=temp->next;
    	}
    	
    node* newnode = new node;
    newnode -> dob=a;
    newnode -> name = first_name + " " + last_name;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if(*head==NULL)
		{
        *head=newnode;
        return;
    	}
    else
		{
         if((*head)->dob>newnode->dob)
			{
            	newnode->next=*head;
            	newnode->next->prev=newnode;
            	*head=newnode;
        	}
    		else
				{
            	 struct node* current=*head;
            
            	 while(current->next!=NULL && current->next->dob<newnode->dob)
					{
                	 current=current->next;
            		}
            	
            	 newnode->next=current->next;
            
            	 if(current->next!=NULL)
                	 newnode->next->prev=newnode;
            		 current->next=newnode;
            		 newnode->prev=current;
        		}
    	}
	}

int Delete(struct node** head,int a)
	{
     if(*head == NULL)
		{
        	cout << "The linked list is empty.";
        	return -1;
    	}
     if((*head)->dob==a)
		{
        	*head = (*head) -> next;
        	return 1;
    	}
    struct node* current=*head;
    while(current -> dob!=a && current -> next!=NULL)
		{
        	current = current -> next;
    	}
    if(current -> dob!=a)
		{
        	return 0;
    	}
    if(current -> next!=NULL)
		{
        	current -> next -> prev = current -> prev;
    	}
    if(current -> prev!=NULL)
		{
        	current -> prev -> next = current -> next;
    	}
    return 1;
	}

void display(struct node* head)
	{
     while(head!=NULL)
		{
        	cout << "Name: "  << head -> name;
			cout << " -- ID Num: "<< head -> dob;
			cout << endl;
        	head = head -> next;
    	}
	}

int Search(struct node* head, int a)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        if(head->dob==a)
        {
            cout << "The node with ID " << a << ": " << endl << endl;
            cout << "Name: " << head -> name;
			cout << " -- ID: "   << head -> dob << endl;
            return count;
        }
        head=head->next;
    } 
    return -1;
}

void Modify(struct node** head,int s,int f, string first_name, string last_name)
{ 
    struct node* current=*head;
    if(Search(current,s)==-1)
    {
        cout << "The ID you want to modify doesn't exist.";
        return;
    }
    while(current!=NULL)
    {
        if(current -> dob==f)
        {
            cout << "The ID you want to change to already exists.";
            return;
        }
        current=current->next;
    }
    cout << "The ID before the change was: " << s << endl;
    Delete(head,s);
    Add(head,f, first_name, last_name);
    cout << "The ID after the change is: " << f << endl;
    cout << "The ID has been modified.";
}

void purge(struct node** head)
	{
     struct node* current=*head;
     struct node* next;
     while(current!=NULL)
		{
        	next=current->next;
        	delete current;
        	current=next;
    	}
    *head=NULL;
	}

int main()
{
    struct node* head=NULL;
    int choice;
    cout << "Main Menu:" << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Create a Linked List" << endl
         << "2. Add a node" << endl
         << "3. Delete a node" << endl
         << "4. Display entire list" << endl
         << "5. Modify a node" << endl
         << "6. Purge the entire list" << endl
         << "7. Search for a node" << endl
         << "8. Exit the program" << endl;
    cout << "--------------------------------" << endl;

    do
      {

        cout << endl << "Choose an action: " << endl;
        cin  >> choice;
        cout <<"--------------------------------" << endl;

        if(choice==1)
        {
            head = NULL;
            cout << "Linked List has been created.";
        }
        else if(choice==2)
        {  
            int a;
            string first_name, last_name;
            cout << "Enter an ID Number: ";
            cin  >> a;
            cout << "Enter the first name: ";
            cin  >> first_name;
            cout << "Enter the last name: ";
            cin  >> last_name;
            Add(&head,a, first_name, last_name);
        }
        else if(choice==3)
         {  
            int a;
            cout << "What would you like to delete: ";
            cin  >> a;
            a=Delete(&head,a);
            if(a==1)
              {
                cout << "Node has been deleted from the linked list.";
              }   
            else
              {
                cout << "Node not found.";
              }
         }
        else if(choice==4)
        {
          
            if(head==NULL)
              {
                cout << "End of linked list.";
              }
            else
              {
                display(head);
              }
          }
       else if(choice==5)
        {
        	int s,f;
        	string first_name, last_name;
        	cout << "What ID would you like to change: ";
        	cin  >> s;
        	cout << "What would you like to change it to: ";
        	cin  >> f;
        	cout << "Enter the first name: ";
        	cin  >> first_name;
        	cout << "Enter the last name: ";
        	cin  >> last_name;
        	Modify(&head,s,f, first_name, last_name);
        }
    else if(choice==6)
        {
        	char ch;
        	cout << "Are you sure you want to delete entire list(y/n): ";
        	cin  >> ch;
        	if(ch=='y')
            purge(&head);
            cout << "Entire List is deleted.";
         }
    
    else if(choice==7)
      {
        	int a;
        	cout << "What number would you like to search: ";
        	cin  >> a;
        	a=Search(head,a);
         if(a!=-1)
             cout << "ID found at position: "<<a;
        
        else
         {
            cout << "ID not found.";
         }
      }  
    
    else if(choice==8)
       {
        cout << "QUIT";
       }
    else
       {
        cout << "INVALID CHOICE";
       }  
     }
      while(choice!=8);
      return 0;
  }
