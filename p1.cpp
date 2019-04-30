#include<iostream>
using namespace std;
int comparison;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int bubblesort(int arr[],int N)
{
	
	for(int i=0;i<N-1;++i)
	{
		
		for(int j=0;j<N-i-1;++j)
		{
		
			if(arr[j]>arr[j+1])
			{
				comparison++;
				swap(&arr[j],&arr[j+1]);
			}
		
		}
	
	}
	return comparison;
}

int selection(int arr[],int N)
{
	for(int i=0;i<N-1;++i)
	{
		int min_index=i;
		for(int j=i+1;j<N;++j)
		if(arr[j]<arr[min_index])
		{
			comparison++;
			min_index=j;
		}
		
		swap(arr[min_index],arr[i]);
	}
	return comparison;
}
int insertion(int arr[],int N)
{
	int key,j;
	for(int i=0;i<N;++i)
	{
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key)
		{   
		comparison=comparison+1;
			arr[j+1]=arr[j];
			j=j-1;
			
		}
		arr[j+1]=key;
	}
	return comparison;
}

void printarray(int arr[],int N)
{
	for(int i=0;i<N;++i)
	{
		cout<<"\n"<<arr[i]<<" ";
	}
}
int main()
{    int c;
	int arr[5]={2,5,1,4,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	c=bubblesort(arr,n);
	cout<<"\n New array is ";
	printarray(arr,n);
	cout<<"\nTotal number of comparison: "<<c;
	c=selection(arr,n);
	cout<<"\n New array is ";
	printarray(arr,n);
	cout<<"\nTotal number of comparison: "<<c;
	c=insertion(arr,n);
	cout<<"\n New array is ";
	printarray(arr,n);
	cout<<"\nTotal number of comparison: "<<c;
	return 0;
}
