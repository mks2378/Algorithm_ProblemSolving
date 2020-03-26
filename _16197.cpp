#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 20

int N,M;
int Answer = 987654321;
char MAP[MAX][MAX];
vector<pair<int, int>> Coin;

// 2���� map���� �̵��� �����ϴ� ���  
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// ������ MAP ������ �������� ����  
bool Range_Over(int a, int b){
	if(a<0||b<0||a>=N||b>=M)
		return true;
	return false;
}

void Move(int x, int y, int xx, int yy, int Cnt, int dir){
	// ������ Ƚ������ �� ���� ��ư�� �����ٸ�, �� �̻� �غ� �ʿ䰡 ����. 
	// �ּڰ��� �ƴϱ� ������   
	if(Answer<Cnt)
		return;
	
	// ������ Ƚ���� ���ؼ� ���� ���Ÿ� �����ְ� �״�� ����  
	if(Cnt>10){
		Answer = min(Answer, Cnt);
		return;
	}
	
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int nxx = xx + dx[dir];
	int nyy = yy + dy[dir];
	
	//MAP ������ ������ ��  
	if(Range_Over(nx,ny) == true && Range_Over(nxx,nyy) == true)
		return;
		
	//�ϳ��� MAP ������ ������ ��  
	else if(Range_Over(nx,ny) == true && Range_Over(nxx,nyy) == false){
		Answer = min(Answer,Cnt);
		return;
	}
	else if(Range_Over(nx,ny) == false && Range_Over(nxx,nyy) == true){
		Answer = min(Answer,Cnt);
		return;
	}
	
	// �� �� ������ �ʾ�����, �̵��� ��ġ�� ���� �� 
	if(MAP[nx][ny] == '#'){
		nx = x;
		ny = y;
	}
	if(MAP[nxx][nyy] == '#'){
		nxx = xx;
		nyy = yy;
	}
	
	// �־��� ���⿡ ���� ������ �̵�  
	for(int i=0;i<4;i++)
		Move(nx,ny,nxx,nyy,Cnt+1,i);	
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>MAP[i][j];
			if(MAP[i][j] == 'o')
				Coin.push_back(make_pair(i,j));
		}
	
	for(int i=0;i<4;i++){
		int x = Coin[0].first;
		int y = Coin[0].second;
		int xx = Coin[1].first;
		int yy = Coin[1].second;
		
		Move(x,y,xx,yy,1,i);
	}
	
	if(Answer>10)
		Answer = -1;
	cout<<Answer;	
	
	return 0;
}
