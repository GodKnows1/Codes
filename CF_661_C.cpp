#include <bits/stdc++.h>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int

// O(N*N)

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		vector<int> cnt(n+1);
		
		ff(i,0,n){
			cin>>v[i];
			cnt[v[i]]++;
		}
		int ans=0;
		for(int s=2;s<=2*n;s++){
			int curr=0;
			for(int i=1;i<(s+1)/2;i++){
				if(s-i>n)	continue;
				curr+=min(cnt[i],cnt[s-i]);
			}
			if(s%2==0)	curr+=cnt[s/2]/2;
			ans=max(curr,ans);
		}
		cout<<ans<<endl;
	}
}

//1
//7 2
//3 5 4 5 1 1 1

