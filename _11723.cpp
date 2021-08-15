#include <iostream>
#include <string>
using namespace std;

bool visited[21];
int M, num;
string s;

void Calculate(){
	if(s=="add"){
		cin>>num;
		visited[num] = true;
		return;
	}
		
	else if(s=="remove"){
		cin>>num;
		visited[num] = false;
		return;
	}
	else if(s=="check"){
		cin>>num;
		if(visited[num]){
			cout<<1<<'\n';
			return;	
		}
		else{
			cout<<0<<'\n';
			return;
		}			
	}
	else if(s=="toggle"){
		cin>>num;
		if(visited[num]){
			visited[num] = false;
			return;
		}
		else{
			visited[num] = true;
			return;	
		}
	}
	else if(s=="all"){
		for(int i=1;i<=20;i++)
			visited[i] = true;
		return;
	}
	else if(s=="empty"){
		for(int i=1;i<=20;i++)
			visited[i] = false;
		return;
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>M;

	for(int i=0;i<M;i++){
		cin>>s;
		Calculate();
	}

	return 0;
}
