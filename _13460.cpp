#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 10

int N, M;
int Answer = 987654321;
char MAP[MAX][MAX];
pair<int, int> Red, Blue;

// 2차원에서 상, 하, 좌, 우 움직임 -> 배열 이용 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 단방향 이동이므로 x 또는 y로의 움직임을 동시에 계산 가능  
int Move_Dist(int x, int y, int xx, int yy){
	return abs(x-xx) + abs(y-yy);
}

int Inverse_Direction(int Cur_D){
	if(Cur_D == 0) return 1;
	else if(Cur_D == 1) return 0;
	else if(Cur_D == 2) return 3;
	else if(Cur_D == 3) return 2;
}

/*
1. 공이 움직인다 
2. 두 공 중 하나가 구멍에 빠졌을 때, 결과값 출력
3. 두 공 모두 빠지지 않았을 때, 두 공이 겹치지 않게 위치 좌표 조정 
4. 현재 이동했던 방향의 수직이 되는 방향 중 한 방향으로 다음에 이동  
*/

// 이동 횟수와 방향을 같이 표현  
void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir){
	if(Cnt>=Answer) return;
	if(Cnt>10) return;
	
	bool Red_Flag = false;
	bool Blue_Flag = false;
	
	int nRx = Rx + dx[dir];
	int nRy = Ry + dy[dir];
	while(1){
		if(MAP[nRx][nRy] == '#') break;
		if(MAP[nRx][nRy] == 'O'){
			Red_Flag = true;
			break;
		}
		// 위 두 가지 경우가 아닐 경우, 같은 방향으로 계속 이동  
		nRx = nRx + dx[dir];
		nRy = nRy + dy[dir];
	}
	// 마지막 위치가 '#'이므로, 이동했던 방향의 반대 방향으로 한 칸 이동 
	nRx = nRx - dx[dir];
	nRy = nRy - dy[dir];
	
	int nBx = Bx + dx[dir];
	int nBy = By + dy[dir];
	while(1){
		if(MAP[nBx][nBy] == '#') break;
		if(MAP[nBx][nBy] == 'O'){
			Blue_Flag = true;
			break;
		}
		// 위 두 가지 경우가 아닐 경우, 같은 방향으로 계속 이동 
		nBx = nBx + dx[dir];
		nBy = nBy + dy[dir];
	}
	// 마지막 위치가 '#'이므로, 이동했던 방향의 반대 방향으로 한 칸 이동 
	nBx = nBx - dx[dir];
	nBy = nBy - dy[dir];
	
	if(Blue_Flag == true) return;
	else{
		if(Red_Flag == true){
			Answer = min(Answer, Cnt);
			return;
		}
	}
	
	// 이동 후에 어느 공도 구멍에 빠지지 않았을 때,
	// 두 공이 겹치는 것을 방지 
	// 아이디어: 이동 거리가 많은 공이 뒤에서 출발한 공  
	if(nRx == nBx && nRy == nBy){
		int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy);
		int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);
		
		if(Red_Dist>Blue_Dist){
			nRx = nRx - dx[dir];
			nRy = nRy - dy[dir];
		}
		else{
			nBx = nBx - dx[dir];
			nBy = nBy - dy[dir];	
		}
	}
	
	//현재 움직인 방향과 같은 방향으로 움직일 필요가 없다. 
	// 같은 방향으로는 더 이상 갈 곳이 없기 때문에 의미가 없다.   
	// 현재 움직인 방향의 반대 방향으로 움직일 필요가 없다. 
	// 다시 제자리로 돌아가는 움직임이기 때문에 의미가 없다. 
	// 즉, 현재 움직인 방향의 수직이 되는 두 가지 방향으로 이동한다.  
	for(int i=0;i<4;i++){
		if(i == dir) continue;
		if(i == Inverse_Direction(dir)) continue; 
		
		Move(nRx, nRy, nBx, nBy, Cnt+1, i);	
	}	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>MAP[i][j];
			if(MAP[i][j] == 'R'){
				Red.first = i;
				Red.second = j;
				MAP[i][j] = '.';
			}
			else if(MAP[i][j] == 'B'){
				Blue.first = i;
				Blue.second = j;
				MAP[i][j] = '.';	
			}
		}		
	}
	
	for(int i=0;i<4;i++){
		int x = Red.first;
		int y = Red.second;
		int xx = Blue.first;
		int yy = Blue.second;
		
		Move(x, y, xx, yy, 1, i);
	}
	
	if(Answer>10 || Answer==987654321) 
		Answer = -1;
	cout<<Answer;
	return 0;
}
