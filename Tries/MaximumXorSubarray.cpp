/*
				PROBLEM STATEMENT
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7


the idea is to use prefix xor array.
for example--1,2,8,7
prefix_xor=1,1^2,1^2^8,1^2^8^7.

now create the trie of it first.
then find xorsubarray using prefix_xor array.



*/





#include<bits/stdc++.h>
using namespace std;


class trieNode{
	public:
		trieNode *left;
		trieNode *right;
};


//insert all element in the trie first
//it takes Nlog(n) time. N*31

void insertNode(trieNode * head,int n)
{
	trieNode * curr=head;
	

	
	for(int i=31;i>=0;i--)
	{
		
		int bit=(n>>i)&1;
		
		
		//if bit is 0,then insert at left otherwise right.
		if(bit==0)
		{
			if(curr->left)
			{
				curr=curr->left;
			}
			else
			{
				curr->left=new trieNode();
				curr=curr->left;
			}
			
			
		}else
		{
			if(!curr->right)
			{
				curr->right=new trieNode();
			}
			
			curr=curr->right;
		}
	}
	
}


//all the elements are inserted.now find maxXor pair for each.
//in worst case it will traverse through itself---means xor will be zero for tht case.


int findMaxXorsubarray(trieNode * head,int *arr,int size)
{
	int max_xor=INT_MIN;
	

	
	for(int i=0;i<size;i++)
	{
		trieNode * curr=head;
		int v=arr[i];
		int curr_xor=0;
		
		//start from msb,bcoz we have to maximize our ans.
		for(int j=31;j>=0;j--)
		{
			int bit=(v>>j)&1;
			
			
			//if bit is zero,then move to "one" (opposite)side i.e right side,bcoz 0^1=1
			//otherwise we have no option,we have to move bit side only.
			if(bit==0)
			{
				if(curr->right)
				{
					curr_xor+=pow(2,j);
					curr=curr->right;
				}
				else
				{
					curr=curr->left;
					
				}
				
			}
			else
			{
				if(curr->left)
				{
					curr_xor+=pow(2,j);
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
				
			}
		}
		
	//	cout<<curr_xor<<endl;
		
		if(curr_xor>max_xor)
		{
			max_xor=curr_xor;
		}
	}
	
	return max_xor;
}



int main()
{
	
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	trieNode *head=new trieNode();
	
	
	int prefix_xor[n]; 
	int curr_xor=0;
	for(int i=0;i<n;i++)
	{
		curr_xor^=arr[i];
		prefix_xor[i]=curr_xor;
		insertNode(head,curr_xor);
	}
	
	
	
	cout<<findMaxXorsubarray(head,prefix_xor,n);
	
	
}
