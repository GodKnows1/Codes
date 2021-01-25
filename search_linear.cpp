#include<bits/stdc++.h>
using namespace std;

int linear_search(int *arr,int n,int x){
	
	for(int i=0;i<n;i++){
		if(arr[i]==x)	return i;
	}
	
	return -1; // not able to find
}

int binary_search(int *arr,int n,int x){
	int l=0,r=n-1;
	
	while(l<=r){
		
		int mid=l+(r-l)/2;
		if(arr[mid]==x){
			return mid;
		} else if(arr[mid]>x){
			r=mid-1;
		} else{
			l=mid+1;
		}
	}
	return -1;
}

int main(){
	int arr_size,ele_to_find;
	cin>>arr_size;
	
	int arr[arr_size];
	for(int i=0;i<arr_size;i++)	cin>>arr[i];
	
	cin>>ele_to_find;
	// linear search
	int ind;
	ind=linear_search(arr,arr_size,ele_to_find);
	int bin_ind=binary_search(arr,arr_size,ele_to_find);
	if(ind!=-1)
		cout<<"Linear Search "<<ind+1<<endl;  // from 1 to n
	else
		cout<<-1;
	
	if(bin_ind!=-1){
		cout<<"bin "<<bin_ind+1;
	} else{
		cout<<-1;
	}
	return 0;
}
