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
	
	//���� string �Է� ��� 
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			paper[i][j] = s[j]-'0';
		}
	}
	
	//0�� ���� ����, 1�� ���� ���� 
	int ans = 0;
	//b:��� ����� ��
	for(int b=0;b<(1<<(n*m));b++){
		int sum=0;
		
		//���θ������ �ڸ� �����鸸 ��� 
		for(int i=0;i<n;i++){
			int now=0;
			for(int j=0;j<m;j++){
				//���簢�� ���� ������ ���ٷ� �̾� �ٿ��� ���� �ε��� 
				int k = i*m+j;
				
				//k��° �ڸ����� 0(=���η� �ڸ���) (Idea)
				if((b&(1<<k))==0) //(b&(1<<k))==0 ��ȣ ����(==�� &���� �켱���� ����)  
					now = now*10 + paper[i][j];
				else{
					sum+=now;
					now=0;	
				}				
			}					
			//�� ���� ���������� ���ӵ� ���� ���� ���� ������� �ϹǷ�  
			sum+=now; 
		}
	
		//���� ������� �ڸ� ������ ���  
		for(int j=0;j<m;j++){
			int now = 0;
			for(int i=0;i<n;i++){
				//���簢�� ���� ������ ���ٷ� �̾� �ٿ��� ���� �ε��� 
				int k = i*m+j;
				
				//k��° �ڸ����� 1(=���� �ڸ���) (Idea)
				if((b&(1<<k))!=0)
					now = now*10+paper[i][j]; // 10�� ���ϸ� �������� shift 
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
