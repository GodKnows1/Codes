#include<bits/stdc++.h>
#define llu long long int
using namespace std;

int main(){
	int m,n,targets;
	cin>>m>>n>>targets;
	
	set<llu> values; // to store hash
	int rows[m],cols[n];
	memset(rows,0,sizeof(rows));
	memset(cols,0,sizeof(cols));
	
	
	for(int i=0;i<targets;i++){
		int v1,v2;
		cin>>v1>>v2;
		llu hash=v1*1000000000+v2; // hash created
		values.insert(hash);
		rows[v1]++;	// to find that which row has how many targets
		cols[v2]++; // to find that which row has how many targets
	}
	
	// now we will find the maxTarget value
	int maxX=INT_MIN,maxY=INT_MIN;
	//maxX
	for(int i=0;i<m;i++){
		maxX=max(maxX,rows[i]);
	}
	//maxY
	for(int i=0;i<n;i++){
		maxY=max(maxY,cols[i]);
	}
	
	// now we will have candidate rows and cols which can be destroyed
	vector<int> candX; vector<int> candY; int ind=0;
	
	for(int i=0;i<m;i++){
		if(rows[i]==maxX){
			candX.push_back(i);
		}
	}
	ind=0;
	for(int i=0;i<n;i++){
		if(cols[i]==maxY){
			candY.push_back(i);
		}
	}
	
	// in the above two loops we are having our candidates rows and cols;
	
	int ans=maxX+maxY-1,flag=0;
	for(int cx:candX){
		for(int cy:candY){
			llu hash=cx*1000000000+cy;
			if(values.find(hash)==values.end()){
				ans++;
				flag=1; // if target is not here we add one and break from this and outer loop
				break;
			}
		}
		if(flag==1)	break;
	}
	
	cout<<ans;
	return 0;
}
