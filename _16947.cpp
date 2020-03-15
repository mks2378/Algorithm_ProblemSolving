#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 3001
using namespace std;

int N;
bool Cycle;
bool visited[MAX];
bool Check_Cycle_Station[MAX];
vector<int> Station[MAX];

void DFS(int Cur, int Start, int line){
	if(Cur==Start && line>=2){
		Cycle = true;
		return;	
	}
	
	visited[Cur] = true;
	for(int i=0;i<Station[Cur].size();i++){
		int Next = Station[Cur][i];
		if(!visited[Next])
			DFS(Next, Start, line+1);
		else{
			if(Next == Start && line>=2)
				DFS(Next, Start, line);
		}
		
		if(Cycle == true) return;		
	}
}

int BFS(int a){
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, 0));
	visited[a] = true;
	
	while(!Q.empty()){
		int Cur = Q.front().first;
		int Cnt = Q.front().second;
		Q.pop();
		
		if(Check_Cycle_Station[Cur] == true)
			return Cnt;
			
		for(int i=0;i<Station[Cur].size();i++){
			int Next = Station[Cur][i];
			if(!visited[Next]){
				visited[Next] = true;
				Q.push(make_pair(Next, Cnt+1));
			}
		}		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	for(int i=0;i<N;i++){
		int a, b;
		cin>>a>>b;
		Station[a].push_back(b);
		Station[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++){
		memset(visited,false,sizeof(visited));
		Cycle = false;
		
		int Start_Station = i;
		DFS(i, Start_Station, 0);
		
		if(Cycle==true)
			Check_Cycle_Station[i] = true;	
	}
	
	vector<int> Answer;
	for(int i=1;i<=N;i++){
		if(Check_Cycle_Station[i] == true){
			Answer.push_back(0);
			continue;
		}
		Answer.push_back(BFS(i));
	}
	
	for(int i=0;i<Answer.size();i++)
		cout<<Answer[i]<<' ';
	
	return 0;
}

// cf)https://yabmoons.tistory.com/275
