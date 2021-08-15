#include <iostream>
using namespace std;

#define MAX 5

int Select[MAX];
int Arr[MAX] = {1,2,3,4,5};


//combination with repetition
void dfs(int cnt, int idx){
	if(cnt==2){
		for(int i=0;i<cnt;i++)
			cout<<Select[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=idx;i<MAX;i++){
		Select[cnt] = Arr[i];
		dfs(cnt+1, i);
	}
}

int main(){
	dfs(0,0);

	return 0;
}
