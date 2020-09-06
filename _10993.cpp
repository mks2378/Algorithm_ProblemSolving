#include <iostream>
#include <cmath>
using namespace std;

// 입력 받는 N이 10까지이므로 높이 최대 1023 
const int MAX = 1024;

char starGraph[MAX][2*MAX];

void func(int y, int x, int height){
	if(height == 1){
		starGraph[y][x] = '*';
		return;	
	}
	
	int row = pow(2, height+1)-3;
	int col = pow(2, height)-1;
	
	// 홀수일 때  
	if(height%2){
		// '*'이 모두 출력되는 행 먼저 처리  
		for(int i=0;i<row;i++){
			starGraph[y+col-1][x+i] = '*';
		}
		
		// 한 열씩 내려가면서 중간 기준으로 좌,우 1칸씩 넓히면서 별 찍기 
		for(int i=0;i<col-1;i++){
			starGraph[y+i][x+row/2-i] = '*';
			starGraph[y+i][x+row/2+i] = '*';
		}
		
		func(y+col/2, x+pow(2,height-1), height-1);
		
		return;
	}
	
	// 짝수일 때
	// 별이 다 찍히는 행부터 별 찍기  
	for(int i=0;i<row;i++)
		starGraph[y][x+i] = '*';
	
	// 각 행의 맨 끝 인덱스로부터 i만큼 들여쓰기하여 별 찍기 
	for(int i=1;i<col;i++){
		starGraph[y+i][x+i] = '*';
		starGraph[y+i][x+row-(i+1)] = '*';
	}
	
	func(y+1, x+pow(2, height-1), height-1);
	
	return;
}

int main(){
	int N;
	cin>>N;
	
	func(0, 0, N);
	
	// 제일 긴 가로 길이는 2^(N+1) - 3
	// 제일 긴 높이는 2^N - 1
	int row = pow(2, N+1) - 3;
	int col = pow(2, N) - 1;
	
	// N=4, row=29, col=15 
	for(int i=0;i<col;i++){
		// 행의 길이를 중간값으로부터 1씩 늘려 출력 
		if(N%2){ // 홀수일 때 
			for(int j=0;j<row-col+(i+1);j++){
				char c = starGraph[i][j] == '*'?'*':' ';
				cout<<c;
			}
			cout<<'\n';
			continue;
		}
		
		// 행의 길이를 최대값으로부터 1씩 줄여 출력 
		// 짝수일 때  
		for(int j=0;j<row-i;j++){
			char c = starGraph[i][j] == '*'?'*':' ';
			cout<<c;
		}
		cout<<'\n';
	}
	
	return 0;
}
