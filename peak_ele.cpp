#include<bits/stdc++.h>
using namespace std;

int peak_ele(int *arr,int l,int r,int n){
	int mid=l+(r-l)/2;
	
	if((mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid+1]<arr[mid])){
		return mid;
	}
	else if(mid>0 && arr[mid-1]>arr[mid]){
		return peak_ele(arr,l,mid-1,n);
	}
	else{
		return peak_ele(arr,mid+1,r,n);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ind=peak_ele(arr,0,n-1,n);
	cout<<ind;
	return 0;
}
