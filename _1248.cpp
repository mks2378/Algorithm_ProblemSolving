#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool Find;
char S[10][10];
int Select[10];


// Idea: cnt를 index로 하여 선택된 값을 저장해 가면, 
// 거꾸로 더해가서 sum값을 통해 S[i][cnt](i:0~cnt) 확인 가능  
bool Check(int idx){
	int Sum=0;
	for(int i=idx;i>=0;i--){
		Sum+=Select[i];
		if(S[i][idx]=='+' && Sum<=0) return false;
		if(S[i][idx]=='-' && Sum>=0) return false;
		if(S[i][idx]=='0' && Sum!=0) return false;
	}
	return true;
}

void dfs(int cnt){	
	if(cnt==N){
		for(int i=0;i<N;i++)
			cout<<Select[i]<<' ';
		exit(0); // 정상 강제 종료  
	}
	
	for(int i=-10;i<=10;i++){
		Select[cnt] = i;
		if(Check(cnt)==true)
			dfs(cnt+1);
	}
}

int main(){
	cin>>N;
	
	for(int i=0;i<N;i++)
		for(int j=i;j<N;j++)
			cin>>S[i][j];
			
	dfs(0);
	return 0;
}

/* 처음에 잘못 푼 코드(시간초과)  
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool Find;
char s[10][10];

bool visited[21];
vector<int> v;

bool Check(){
	for(int i=0;i<N;i++){
		int sum = v[i];
		for(int j=i+1;j<N;j++){			
			sum+=v[j];
			
			if(s[i][j]=='+'&&sum>0)
				continue;
			else if(s[i][j]=='-'&&sum<0)
				continue;
			else if(s[i][j]=='0'&&sum==0)
				continue;
			else return false;					
		}
	}
	return true;
}

void dfs(int cnt){	
	if(Find==true)
		return;
	
	if(cnt==N){
		if(Check()==true){
			Find = true;
			for(int i=0;i<N;i++)
				cout<<v[i]<<' ';
		}
		return;
	}
	
	if(s[cnt][cnt]=='-'){
		for(int i=-10;i<0;i++){
			if(!visited[i+10]){
				visited[i+10] = true;
				v.push_back(i);
				dfs(cnt+1);
				v.pop_back();
				visited[i+10] = false;
			}
		}
	}
	else if(s[cnt][cnt]=='+'){
		for(int i=1;i<=10;i++){
			if(!visited[i+10]){
				visited[i+10] = true;
				v.push_back(i);
				dfs(cnt+1);
				v.pop_back();
				visited[i+10] = false;
			}
		}
	}
	else if(s[cnt][cnt]=='0'){
		if(!visited[10]){
			visited[10] = true;
			v.push_back(0);
			dfs(cnt+1);
			v.pop_back();
			visited[10] = false;
		}
	}	
}

int main(){
	cin>>N;
	
	for(int i=0;i<N;i++)
		for(int j=i;j<N;j++)
			cin>>s[i][j];
			
	dfs(0);
	
	return 0;
}
*/
