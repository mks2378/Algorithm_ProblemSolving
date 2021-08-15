#include <iostream>
#include <algorithm>
using namespace std;

/*
- 아이디어: 같은 년도라면 각각 M,N으로 나눴을 때 
나머지가 x,y어야 하므로 x에 M을 한 번씩 더했을 때 N으로 나눈 나머지가 
y가 되면 같은 년도 가능. M,N의 최대공약수를 넘어가면 불가(-1)  

- gcd, lcm 구하기 => 유클리드 호제법(반복문, 재귀 함수)

- 임의의 x를 배수(N)으로 나눴을 때, 0이 아닌 자신 값이 나오게 하기 위해 
(x-1)%N+1 
*/ 

int M,N,x,y;

//최대공약수 
int GCD(int a, int b){
	if(a%b==0)
		return b;
		
	return GCD(b, a%b);
}

//최소공배수  
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
