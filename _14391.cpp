#include <iostream>
#include <string>
using namespace std;

int n,m;
int paper[4][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	//숫자 string 입력 방법 
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			paper[i][j] = s[j]-'0';
		}
	}
	
	//0인 곳은 가로, 1인 곳은 세로 
	int ans = 0;
	//b:모든 경우의 수
	for(int b=0;b<(1<<(n*m));b++){
		int sum=0;
		
		//가로모양으로 자른 조각들만 계산 
		for(int i=0;i<n;i++){
			int now=0;
			for(int j=0;j<m;j++){
				//정사각형 종이 조각을 한줄로 이어 붙였을 때의 인덱스 
				int k = i*m+j;
				
				//k번째 자리값이 0(=가로로 자른다) (Idea)
				if((b&(1<<k))==0) //(b&(1<<k))==0 괄호 조심(==가 &보다 우선순위 높아)  
					now = now*10 + paper[i][j];
				else{
					sum+=now;
					now=0;	
				}				
			}					
			//한 행의 마지막점이 연속된 점의 끝일 때를 더해줘야 하므로  
			sum+=now; 
		}
	
		//세로 모양으로 자른 조각들 계산  
		for(int j=0;j<m;j++){
			int now = 0;
			for(int i=0;i<n;i++){
				//정사각형 종이 조각을 한줄로 이어 붙였을 때의 인덱스 
				int k = i*m+j;
				
				//k번째 자리값이 1(=세로 자른다) (Idea)
				if((b&(1<<k))!=0)
					now = now*10+paper[i][j]; // 10씩 곱하면 왼쪽으로 shift 
				else{
					sum+=now;
					now=0;
				}		
			}
			sum+=now;
		}
		if(ans<sum)
			ans = sum;
	}
	
	cout<<ans<<'\n';	
	return 0;
}
