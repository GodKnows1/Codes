#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int 

int m,n;

int main() {
	cin>>m>>n;
	char maze[m][n];
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	sx--;
	sy--;
	ex--;
	ey--;
	int distance[m][n];
	ff(i,0,m){
		ff(j,0,n){
			cin>>maze[i][j];
			distance[i][j]=1e7;
		}
	}
	//memset(distance,INT_MAX,sizeof(distance));
	deque<int> queX;
	deque<int> queY;
	
	distance[sx][sy]=0;
	queX.push_front(sx);
	queY.push_front(sy);
	int dx[]={-1,1,0,0}; int dy[]={0,0,1,-1};
	while(!queX.empty()){
		int curX=queX.front();
		queX.pop_front();
		int curY=queY.front();
		queY.pop_front();	
		
		for(int sh=0;sh<4;sh++){
			int nx=curX+dx[sh];
			int ny=curY+dy[sh];
			if(nx< 0 || ny<0 || nx>=m || ny>=n || maze[nx][ny]=='#'){
				continue;
			}
			if(distance[nx][ny]>distance[curX][curY]){
				distance[nx][ny]=distance[curX][curY];
				queX.push_front(nx);
				queY.push_front(ny);
			}
		}
		
		for(int xh=curX-2;xh<=curX+2;xh++){
			for(int yh=curY-2;yh<=curY+2;yh++){
				if(xh< 0 || yh<0 || xh>=m || yh>=n || maze[xh][yh]=='#'){
					continue;
				}
				if(distance[xh][yh]>distance[curX][curY]+1){
					distance[xh][yh]=distance[curX][curY]+1;
					queX.push_back(xh);
					queY.push_back(yh);
				}
			}
		}
		
	}
	
	if(distance[ex][ey]>=1e7){
		cout<<-1;
	} else{
		cout<<distance[ex][ey];
	}
	
}

//1
//7 2
//3 5 4 5 1 1 1

