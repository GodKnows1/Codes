#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <cstring>
#include <climits>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int 

int main() {
	int m,n,bombs;
	cin>>m>>n>>bombs;
	set<llu> values;
	int rows[m];int cols[n];
	memset(rows,0,sizeof(rows));
	memset(cols,0,sizeof(cols));
	for(int i=0;i<bombs;i++){
		int v1,v2;
		cin>>v1>>v2;
		v1--; v2--;
		llu hash=v1*1000000001+v2;
		values.insert(hash);
		rows[v1]++; cols[v2]++;
	}
	
	vector<int> v;
	vector<int> vY;
	int max=INT_MIN;
	int maxY=INT_MIN;
	
	for(int i=0;i<m;i++)
		if(rows[i]>max)
			max=rows[i];
	
	for(int i=0;i<n;i++)
		if(cols[i]>maxY)
			maxY=cols[i];
		
	int ind=0;
	for(int i=0;i<m;i++){
		if(rows[i]==max){
			v.push_back(i);
		}
	}
	ind=0;
	for(int i=0;i<n;i++){
		if(cols[i]==maxY){
			vY.push_back(i);
		}
	}
	
	llu fin=max+maxY-1;
	int flag=1;
	for(int i:v){
		for(int j:vY){
			llu hash=i*1000000001+j;
			if(values.find(hash)==values.end()){
				fin++; flag=0;
				break;
			}
		}
		if(!flag)	break;
	}
	cout<<fin;
}

//1
//7 2
//3 5 4 5 1 1 1

