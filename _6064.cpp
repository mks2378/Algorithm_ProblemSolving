#include <iostream>
#include <algorithm>
using namespace std;

/*
- ���̵��: ���� �⵵��� ���� M,N���� ������ �� 
�������� x,y��� �ϹǷ� x�� M�� �� ���� ������ �� N���� ���� �������� 
y�� �Ǹ� ���� �⵵ ����. M,N�� �ִ������� �Ѿ�� �Ұ�(-1)  

- gcd, lcm ���ϱ� => ��Ŭ���� ȣ����(�ݺ���, ��� �Լ�)

- ������ x�� ���(N)���� ������ ��, 0�� �ƴ� �ڽ� ���� ������ �ϱ� ���� 
(x-1)%N+1 
*/ 

int M,N,x,y;

//�ִ����� 
int GCD(int a, int b){
	if(a%b==0)
		return b;
		
	return GCD(b, a%b);
}

//�ּҰ����  
int LCM(int a, int b){
	return (a*b)/GCD(a,b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin>>tc;
	
	for(int t=0;t<tc;t++){
		cin>>M>>N>>x>>y;
		
		int maxYear = LCM(M,N);
		
		while(true){
			if(x>maxYear||(x-1)%N+1==y)
				break;
				
			x += M;		
		}
		
		if(x>maxYear)
			cout<<-1<<'\n';
		else
			cout<<x<<'\n';
	}
	
	return 0;
}
