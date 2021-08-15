#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
int N,M;
int cnt;
char current;
pair<int, int> Loc;
bool Is_Cycle;

char arr[MAX][MAX];
bool visited[MAX][MAX];

void dfs(pair<int, int> p){
	++cnt;
	visited[p.first][p.second] = true;
	
	if((make_pair(p.first+1,p.second)==Loc || make_pair(p.first-1,p.second)==Loc || 
	make_pair(p.first,p.second-1)==Loc || make_pair(p.first,p.second+1)==Loc) && cnt>3){
		Is_Cycle = true;
		visited[p.first][p.second] = false;
		--cnt;
		return;
	}
	
	if(p.first+1<N && arr[p.first+1][p.second]==current && !visited[p.first+1][p.second])
		dfs(make_pair(p.first+1,p.second));
	
	if(p.first-1>=0 && arr[p.first-1][p.second]==current && !visited[p.first-1][p.second])
		dfs(make_pair(p.first-1,p.second));
	
	if(p.second+1<M && arr[p.first][p.second+1]==current && !visited[p.first][p.second+1])
		dfs(make_pair(p.first,p.second+1));
		
	if(p.second-1>=0 && arr[p.first][p.second-1]==current && !visited[p.first][p.second-1])
		dfs(make_pair(p.first,p.second-1));
	
	visited[p.first][p.second] = false;
	--cnt;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>arr[i][j];
			
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			if(!Is_Cycle){
			current = arr[i][j];
			Loc = make_pair(i,j);
			dfs(make_pair(i,j));
			}
		}
		
	if(Is_Cycle)
		cout<<"Yes";
	else
		cout<<"No";
	
	return 0;
}
