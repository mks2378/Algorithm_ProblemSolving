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

/* ó���� �߸�§ �ڵ�  
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<int, int>> Coin;
bool wall[20][20];
int least_move = 987654321;

typedef struct move{
	int y,x;
}Move;

Move move_pos[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

bool Promising(vector<pair<int, int>> &v){
	if((Coin[0].first>=N||Coin[0].first<0||Coin[0].second>=M||Coin[0].second<0)
	&& (Coin[1].first<N && Coin[1].first>=0 && Coin[1].second<M && Coin[1].second>=0))
		return true;
	else if((Coin[1].first>=N||Coin[1].first<0||Coin[1].second>=M||Coin[1].second<0)
	&& (Coin[0].first<N && Coin[0].first>=0 && Coin[0].second<M && Coin[0].second>=0))
		return true;
	else
		false;
}

void dfs(int cnt, vector<pair<int, int>> &Coin){
	if(least_move==-1)
		return;
	
	if(cnt>10){
		least_move = -1;
		return;
	}
	
	if(Promising(Coin)){
		least_move = min(least_move, cnt);
		return;
	}
	
	vector<pair<int, int>> C;
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
			if(!wall[Coin[j].first+move_pos[i].x][Coin[j].second+move_pos[i].y])
				C.push_back(make_pair(Coin[j].first+move_pos[i].y, Coin[j].first+move_pos[i].x));
		}
		dfs(cnt+1, C);
	}
}

int main(){	
	cin>>N>>M;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<M;j++){
			if(s[j]=='#')
				wall[i][j] = true;
			if(s[j]=='o')
				Coin.push_back(make_pair(i,j));
		}
	}
	
	dfs(0, Coin);
	cout<<least_move;
	return 0;
}
*/
