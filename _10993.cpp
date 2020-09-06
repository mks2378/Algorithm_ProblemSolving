#include <iostream>
#include <cmath>
using namespace std;

// �Է� �޴� N�� 10�����̹Ƿ� ���� �ִ� 1023 
const int MAX = 1024;

char starGraph[MAX][2*MAX];

void func(int y, int x, int height){
	if(height == 1){
		starGraph[y][x] = '*';
		return;	
	}
	
	int row = pow(2, height+1)-3;
	int col = pow(2, height)-1;
	
	// Ȧ���� ��  
	if(height%2){
		// '*'�� ��� ��µǴ� �� ���� ó��  
		for(int i=0;i<row;i++){
			starGraph[y+col-1][x+i] = '*';
		}
		
		// �� ���� �������鼭 �߰� �������� ��,�� 1ĭ�� �����鼭 �� ��� 
		for(int i=0;i<col-1;i++){
			starGraph[y+i][x+row/2-i] = '*';
			starGraph[y+i][x+row/2+i] = '*';
		}
		
		func(y+col/2, x+pow(2,height-1), height-1);
		
		return;
	}
	
	// ¦���� ��
	// ���� �� ������ ����� �� ���  
	for(int i=0;i<row;i++)
		starGraph[y][x+i] = '*';
	
	// �� ���� �� �� �ε����κ��� i��ŭ �鿩�����Ͽ� �� ��� 
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
	
	// ���� �� ���� ���̴� 2^(N+1) - 3
	// ���� �� ���̴� 2^N - 1
	int row = pow(2, N+1) - 3;
	int col = pow(2, N) - 1;
	
	// N=4, row=29, col=15 
	for(int i=0;i<col;i++){
		// ���� ���̸� �߰������κ��� 1�� �÷� ��� 
		if(N%2){ // Ȧ���� �� 
			for(int j=0;j<row-col+(i+1);j++){
				char c = starGraph[i][j] == '*'?'*':' ';
				cout<<c;
			}
			cout<<'\n';
			continue;
		}
		
		// ���� ���̸� �ִ밪���κ��� 1�� �ٿ� ��� 
		// ¦���� ��  
		for(int j=0;j<row-i;j++){
			char c = starGraph[i][j] == '*'?'*':' ';
			cout<<c;
		}
		cout<<'\n';
	}
	
	return 0;
}
