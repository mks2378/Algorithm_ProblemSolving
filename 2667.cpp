#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

const int MAX = 26;
bool visited[MAX][MAX];
bool arr[MAX][MAX];
vector<int> v;

int cnt;
int N;

void bfs(int idx_y, int idx_x){
	queue<pair<int,int> > q;
	q.push(make_pair(idx_y,idx_x));
	visited[idx_y][idx_x] = true;
	
	while(!q.empty()){		
		auto p = q.front();
		q.pop();
		
		if(arr[p.first][p.second]){
			cnt++;
			visited[p.first][p.second] = true;
		}
		
		if(p.first-1>=1 && !visited[p.first-1][p.second] && arr[p.first-1][p.second]!=0){
			visited[p.first-1][p.second] = true;
			q.push(make_pair(p.first-1,p.second));
		}
		if(p.first+1<=N && !visited[p.first+1][p.second] && arr[p.first+1][p.second]!=0){
			visited[p.first+1][p.second] = true;
			q.push(make_pair(p.first+1,p.second));
		}
		if(p.second-1>=1 && !visited[p.first][p.second-1] && arr[p.first][p.second-1]!=0){
			visited[p.first][p.second-1] = true;
			q.push(make_pair(p.first,p.second-1));
		}
		if(p.second+1<=N && !visited[p.first][p.second+1] && arr[p.first][p.second+1]!=0){
			visited[p.first][p.second+1] = true;
			q.push(make_pair(p.first,p.second+1));
		}
	}
	
	v.push_back(cnt);
	cnt=0;	
}

int main(){
	string str;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>str;
		for(int j=0;j<N;j++){
			arr[i+1][j+1] = str[j] - '0';		
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(!visited[i][j] && arr[i][j]==1)
				bfs(i,j);						
		}
	}
	
	sort(v.begin(), v.end());
	
	cout<<v.size()<<'\n';
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<'\n';
	
	return 0;
}
