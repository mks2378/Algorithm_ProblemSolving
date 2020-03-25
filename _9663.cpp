#include <iostream>
#include <cmath>
using namespace std;

int N, result;
int col[15];

bool promising(int i){
	int k=1;
	bool flag = true;
	
	while(k<i && flag){
		// 서로 대각에 위치해 있을 때 판단 방법
		// : abs(col[i] - col[k]) == i-k
		if(col[i] == col[k] || abs(col[i] - col[k]) == i-k)
			flag = false;
		k++;
	}
	return flag;
}

void dfs(int cnt){
	if(promising(cnt)){
		if(cnt==N){
			++result;
			return;
		}
		else{
			for(int j=1;j<=N;j++){
				col[cnt+1] = j;
				dfs(cnt+1);	
			}
		}
	}
}

int main(){
	cin>>N;
	dfs(0);
	
	cout<<result;
	return 0;
}
