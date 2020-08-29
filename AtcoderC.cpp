#include <bits/stdc++.h>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu unsigned long long int

int minimumChar(string S1, string S2) 
{ 
    // Get the sizes of both strings 
    int n = S1.size(), m = S2.size(); 
  
    int ans = INT_MAX; 
  
    // Traverse the string S2 
    for (int i = 0; i < m - n + 1; i++) { 
        int minRemovedChar = 0; 
  
        // From every index in S2, check the number of 
        // mis-matching characters in substring of 
        // length of S1 
        for (int j = 0; j < n; j++) { 
            if (S1[j] != S2[i + j]) { 
                minRemovedChar++; 
            } 
        } 
  
        // Take minimum of prev and current mis-match 
        ans = min(minRemovedChar, ans); 
    } 
  
    // return answer 
    return ans; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t;
	cin>>s>>t;
	cout << minimumChar(t, s); 
}

//1
//7 2
//3 5 4 5 1 1 1

