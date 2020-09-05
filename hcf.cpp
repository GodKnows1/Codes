#include <bits/stdc++.h>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int
const int mod=1000000007;

// euclidean hcf

int hcfOrGCD(int x,int y){
	if(y==0){
		return x;
	}
	
	return hcfOrGCD(y,x%y);
}

void swap(int *x,int *y){
	int t=*x;
	*x=*y;
	*y=t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	if(b>a){
		swap(&a,&b);
	}
	cout<<hcfOrGCD(a,b);
	return 0;
}


//1
//7 2
//3 5 4 5 1 1 1

