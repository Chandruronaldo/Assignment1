#include <iostream>
using namespace std;
//Creating the structure for node
struct node
{
	int data;//stores data of the node
	node *next;//stores address of the next element in the list
};

//class definition for carrying out operations on the list
class list
{
	private:
	node *head, *tail;//declaring head and tail of the list
	
	public:
	list()
	{
		head=NULL;
		tail=NULL;
	}
	
	void insert(int val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;//a single unliked node has been created
		if(tail==NULL)//case of an empty list
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	
	void insertAt(int pos,int val)
	{
		node *bfr=new node;
		node *aft=new node;
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;
		bfr=head;
		if(pos==1)
		{
			temp->next=head;
			head=temp;
			
		}//temp is made as the head
		else
		{
		for(int  i=1;i<pos-1;i++)
		{
			bfr=bfr->next;
			
			
		}
		aft=bfr->next;
		
		temp->next=aft;
		bfr->next=temp;
	}/*a node has been inserted by breaking the previous link between BFR and AFT
	  and a new link created between BFR and TEMP and between TEMPand AFT*/
	}
	
	
void deleteend()
{
	node *temp=new node;
	temp=head;
	while(temp->next!=tail)
	{
		temp=temp->next;
	}
	
            temp->next=NULL;
	tail=temp;
}//temp is made as the tail

void deleteAt(int pos)
{
		node *bfr=new node;
		node *aft=new node;
		node *temp=new node;
		int m=countitems();
	            bfr=head;
		if(pos==1)
		{
			
			head=head->next;
			
		}
		
		else
		{
		for(int  i=1;i<pos-1;i++)
		{
			bfr=bfr->next;
			
			
		}
		temp=bfr->next;
	            aft=temp->next;
	            bfr->next=aft;
	            temp->next=NULL;
	            delete temp;}/*the previous link between BFR and TEMP is broken 
	                           BFR is linked to AFT and the link between TEMP and AFT is broken
	                           TEMP is deleted*/
}
	void display()
	{
		node *temp=new node;
		temp=head;
		while(temp->next!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
					}
		cout<<temp->data<<"->NULL";
	}


int countitems()
{	
	int i=0;
	node *temp=new node;
	temp=head;
	while(temp->next!=NULL)
	{i=i+1;
	temp=temp->next;}
	return i+1;//since the tail element is not counted, i is incremented by 1
}
};
int main() {
		list a;
	int n=0,m=0,i1=0,pos=0,data=0;
	cout<<"\n Do you have the initial list? \nif yes press 1\nif not press 2";
	cin>>i1;
	switch(i1)
	{
	case 1:
	cout<<"\n enter the no of elements in list ";
	cin>>m;
	cout<<"\n enter the elements";
	 for(int i=1;i<=m;i++)
	{
		cin>>n;
		a.insert(n);
	}
	break;
	
	case 2:
	break;
	}
	
	cout<<"\n the linked list is \n";
	a.display();

	
	cout<<"\nDo you want to insert a node?\n If yes press 1 \n If no press 2";
	cin>>i1;
	switch(i1)
	{
		case 1:
		cout<<"enter the position to enter and the data";
		cin>>pos>>data;
		a.insertAt(pos,data);
			break;
		
		case 2:
		break;
	}
	a.display();
	cout<<"\nDo you want to delete a node?\n If yes press 1 \n If no press 2";
	cin>>i1;
	switch(i1)
	{
		case 1:
		cout<<"\n the position to delete";
		cin>>pos;
		if(pos==a.countitems())
		a.deleteend();
		else
		a.deleteAt(pos);
		
		case 2:
		break;
	}
	a.display();
	return 0;
}