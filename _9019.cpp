#include<iostream>
#include<cstring>
#include<string>
#include<queue>

#define MAX 10000
using namespace std;

int Start, End;
bool visited[MAX];

void Initialize(){
	memset(visited, false, sizeof(visited));
}

string BFS(int a){
	queue<pair<int, string>> Q;
	Q.push({a,""});
	visited[a] = true;
	
	while(!Q.empty()){
		int x = Q.front().first;
		string s = Q.front().second;
		Q.pop();	
		
		if(x==End) return s;
		
		int nx = x*2;
		if(nx>9999) nx = nx%10000;
		if(visited[nx] == false){
			visited[nx] = true;
			Q.push({nx,s+"D"});
		}
		
		nx = x-1;
		if(nx<0) nx = 9999;
		if(visited[nx] == false){
			visited[nx] = true;
			Q.push({nx,s+"S"});
		}
		
		nx = (x%1000)*10 + (x/1000);
		if(visited[nx] == false){
			visited[nx] = true;
			Q.push({nx,s+"L"});
		}
		
		nx = (x%10)*1000 + (x/10);
		if(visited[nx] == false){
			visited[nx] = true;
			Q.push({nx, s+"R"});
		}
	}	
}

int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		Initialize();
		cin>>Start>>End;
		
		string Answer = BFS(Start);
		cout<<Answer<<'\n';	
	}
	
	return 0;
}

// 메모리 초과(vector<char>타입의 벡터 자체를 저장하여 메모리 초과) 
/*
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int T;
int A,B;
char ch[4] = {'D','S','L','R'};

int LenOfNum(int a){
	int len = 0;
	while(a/10!=0){
		++len;
		a = a/10;	
	}
	++len;
	return len;
}

// pow 함수는 return 값의 type이 double 
int Order(int n, int i){
	if(i==0){//D
		n = n*2;
		if(n>9999){
			return n%10000;
		}
		return n;
	}
	else if(i==1){//S
		n = n-1;
		if(n==-1)
			return 9999;
		return n;
	}
	else if(i==2){//L
		int len = LenOfNum(n);
		int sur = n/int(pow(10,len-1));
		n = (n%int(pow(10,len-1)))*10;
		n = n + sur;
		return n;
	}
	else if(i==3){//R
		int len = LenOfNum(n);
		int sur = n%10;
		n = n/10;
		n = n + sur*int(pow(10,len-1));
		return n;
	}
}

vector<char> BFS(int x,int y){
	queue<pair<int,vector<char>>> q;
	vector<char> v;
	q.push({x,v});
	
	while(!q.empty()){
		int num = q.front().first;
		vector<char> str = q.front().second;
		q.pop();
		
		if(num==y)
			return str;
		
		for(int i=0;i<4;i++){
			int new_num = Order(num, i);
			str.push_back(ch[i]);
			q.push({new_num,str});
			str.pop_back();		
		}		
	}	
}

int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		vector<char> s;
		cin>>A>>B;
		s = BFS(A,B);
		
		for(int i=0;i<s.size();i++)
			cout<<s[i];
		cout<<'\n';
	}	
	
	return 0;
}
*/
