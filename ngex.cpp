#include<bits/stdc++.h>
using namespace std;

int sumOfN(int n){
	return (n*(n+1))/2;			// can overflow
}

int func_helper(int x){
	int l=1, r=x;
	int mid=l+(r-l)/2;
	int res;
	
	while(l<=r){
		mid=l+(r-l)/2;
		if(sumOfN(mid)>=x){
			r=mid-1;
			res=mid;
		} else{
			l=mid+1;	
		}
	}
	return res;
}

int main(){
	int x;
	cin>>x;
	
	int n=func_helper(x);
	cout<<n;
	return 0;
}
