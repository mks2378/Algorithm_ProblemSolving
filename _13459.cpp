#include <iostream>
#include <string>
using namespace std;

#define MAX 10

int N,M;
char MAP[MAX][MAX];

bool Completed;
pair<int, int> Red, Blue;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int Inverse_dir(int dir){
	if(dir==0) return 1;
	else if(dir==1) return 0;
	else if(dir==2) return 3;
	else if(dir==3) return 2;
}

int Distance(int dir, int y, int x, int ny, int nx){
	return abs(ny-y) + abs(nx-x);
}

void Move(int Cnt, int dir, int Ry, int Rx, int By, int Bx){
	if(Completed) return;
	if(Cnt>10) return;
	
	// 전역 변수로 선언하여 실패 오류 
	// ex) 경로의 경우의 수 중 파란 공이 구멍에 빠진 경우 있다고 하면
	// Blue_hole = true가 계속 유지되고, 후에 다른 경우의 수 중 10번 이하에 
	// 빨간공만 구멍에 빠지는 경우는 Blue_hole의 조건문 때문에 답이 되지 못한다. 
	// 그래서 Red_hole, Blue_hole을 지역변수로 선언해야 문제 해결 가능하다  
	bool Red_hole = false;
	bool Blue_hole = false;
	
	int nRy = Ry + dy[dir];
	int nRx = Rx + dx[dir];
	while(MAP[nRy][nRx]!='#'){
		if(MAP[nRy][nRx]=='O'){
			Red_hole = true;
			break;	
		}
		nRy = nRy + dy[dir];
		nRx = nRx + dx[dir];
	}
	nRy = nRy - dy[dir];
	nRx = nRx - dx[dir];
	
	int nBy = By + dy[dir];
	int nBx = Bx + dx[dir];
	while(MAP[nBy][nBx]!='#'){
		if(MAP[nBy][nBx]=='O'){
			Blue_hole = true;
			break;	
		}
		nBy = nBy + dy[dir];
		nBx = nBx + dx[dir];
	}
	nBy = nBy - dy[dir];
	nBx = nBx - dx[dir];
	
	if(Blue_hole)
		return;
	else{
		if(Red_hole){
			Completed = true;
			return;
		}
	}
	
	if(nRx == nBx && nRy == nBy){
		if(Distance(dir, Ry, Rx, nRy, nRx)>Distance(dir, By, Bx, nBy, nBx)){
			nRy = nRy - dy[dir];
			nRx = nRx - dx[dir];
		}
		else{
			nBy = nBy - dy[dir];
			nBx = nBx - dx[dir];	
		}
	}
	
	for(int i=0;i<4;i++){
		if(i == dir) continue;
		if(i == Inverse_dir(dir)) continue;
		Move(Cnt+1, i, nRy, nRx, nBy, nBx);
	}
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<M;j++){
			if(s[j] == 'R'){
				Red = make_pair(i,j);
				MAP[i][j] = '.';	
			}
			else if(s[j] == 'B'){
				Blue = make_pair(i,j);
				MAP[i][j] = '.';	
			}
			else
				MAP[i][j] = s[j];	
		}	
	}
	
	for(int i=0;i<4;i++){
		int Red_y = Red.first;
		int Red_x = Red.second;
		int Blue_y = Blue.first;
		int Blue_x = Blue.second;
		Move(1, i, Red_y, Red_x, Blue_y, Blue_x);
	}
	
	cout<<Completed;
	return 0;
}
