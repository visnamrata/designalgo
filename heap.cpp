#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(int arr[],int k,int N)
{
	int l,r,largest;
	l=2*k;
	r=2*k+1;
	
	if(l<N && arr[l]>arr[k])
	largest=l;
	else
	largest=k;
	
	if(r<N && arr[r]>arr[largest])
	largest=r;
	
	if(largest!=k)
	{
		swap(arr[k],arr[largest]);
		max_heapify(arr,largest,N);
		
	}
	
}

void heapsort(int arr[],int N)
{
	for(int i=N/2-1; i>=0; i--)
	{
		max_heapify(arr,i,N);
	}	
		for(int i=N-1;i>=0;i--)
		{
			swap(arr[0],arr[i]);
			max_heapify(arr,0,i);
		}
	
}

void printarray(int arr[],int N)
{
		for(int i=0;i<N;++i)
	{
		cout<<arr[i]<<"-> ";
	}
	cout<<"\n";
}
int main()
{
	int arr[]={1,6,4,9,2,7};
	int N=sizeof(arr)/sizeof(arr[0]);
	heapsort(arr,N);
	cout<<"Sorted array is \n";
	printarray(arr,N);
	return 0;
}
