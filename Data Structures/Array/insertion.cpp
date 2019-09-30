//Name : Kabir Nagpal
//Email ID : 21kabirnagpal@gmail.com

//program to insert an element to an array at any position

#include <iostream>
using namespace std;

//Global declartion of array for easy access. 
//Code can be modified to use it locally.
int a[50];

// a is the array in which elements are inserted
// n is the actual memory allocated to the array
// l is the size of array filled

int insert(int a[],int &n,int &l)
{
	if(l<n)
	{
	// if the size of array is smaller than allocated only then the element can be added
		
		int i,x;
		// variable i holds the position whereas x holds the value.


		cout<<"\nEnter number ";
		cin>>x;


		if(l==-1)
		{
			// for adding element at first position
			a[++l]=x;
		}
		
		else
		{
			cout<<"\nEnter location ";
			cin>>i;
			i--;
				// i here represents the index of array and is one less than the position hence decremented
				// if i is greater than the size of actual size the number cannot be added
				// this is due to the fact that arrays are continuous data structure	
		
			if(i>=0 && i<=l+1)
			{
				//if the element is to inserted in between the array all the later elemts needs to shift
				for(int j=l;j>=i;j--)
				{
					a[j+1]=a[j];
				}
				
				//element is added at desired location
				a[i]=x;
				l++;

			}
		}
	}
	
	//condition of overflow
	else
		cout<<"\nCannot enter more"<<endl;

return 0;
}

// function to display the array
int display(int a[],int l)
{
	for(int i=0;i<=l;i++)
		cout<<"\nelement "<<i+1<<" --> "<<a[i];
	return 0;
}


int main()
{
    int x=0,n=49,l=-1;;
	while(x!=3)
	{
		if (x==0)
		{
			cout<<"\nas array is empty we'll insert"<<endl;
			x=1;
		}

		else
		{
			cout<<"\nEnter choice \n1 to insert\n2 to display\n3 to exit";
			cin>>x;
		}

		switch(x)
		{

			
			case 1: insert(a,n,l);
					break;

			case 2: display(a,l);
					break;

			default: cout<<"\nWrong Command";
			         break;
		}
	}
}

//Time Complexity -
//Worst Case : O(n). 
//In the worst case, the element may be added at position 1 and hence rest all elements needs to be shifted.
//This will cause our loop to run for n elements

//Auxiliary Space Complexity : O(1). 