#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  long long int ans=0;
  long long int pow=5; 
  while(n/pow>0){
    ans+=floor(n/pow);
    pow*=5;
  }
  cout<<ans;
}