#include <iostream>
#include <string>
#include <algorithm>
#include <climits> // ������ ���� ���� (limits)���� ����  
using namespace std;

int N, answer;
string s, copyS, result;

//����ġ ������ �Լ�  
void push(int idx){
	if(idx>0)
		copyS[idx-1] = (copyS[idx-1]=='0')?'1':'0';
	
	copyS[idx] = (copyS[idx]=='0')?'1':'0';
	
	if(idx<N-1)
		copyS[idx+1] = (copyS[idx+1]=='0')?'1':'0';
}


void simulation(int idx, int cnt){
	// idx ����ġ�� idx-1 ������ ���� ������ ���� �Ǵ� 
	// ������ ������ �� ���� ������ �����Ƿ� 
	// N-2 ��° ������ �Ǵ��� �� ���� ���Խ�Ų��. 
	// N-1 ��° ����ġ�� N-2, N-1 ������ ��� �����ϹǷ� 
	if(idx == N-1){
		//������ Ȯ�� 
		bool flag = true;
		int len = copyS.length();
		for(int i=len-2;i<len;i++)
			if(copyS[i]!=result[i]){
				flag = false;
				break;			
			}
		
		if(flag)
			answer = min(answer,cnt);
		
		//����ġ�� �������� �ٽ� Ȯ�� 
		push(idx);
		flag = true; 
		for(int i=len-2;i<len;i++)
			if(copyS[i]!=result[i]){
				flag = false;
				break;
			}
		
		if(flag)
			answer = min(answer, cnt+1);
			
		return;
	}
	
	//����ġ�� �� ���� ���� 
	if(copyS[idx-1] == result[idx-1])
	 	simulation(idx+1, cnt);
		 
	//����ġ�� ������ 
	push(idx);
	
	if(copyS[idx-1] == result[idx-1])
		simulation(idx+1, cnt+1);
		
	//���󺹱� 
	push(idx);	
}

int main(){
	cin>>N>>s>>result;
	
	answer = INT_MAX;
	//0��° ����ġ�� ������ ���� ���¿��� ����  
	copyS = s;
	simulation(1,0);
	
	//0��° ����ġ�� ���� ���¿��� ����  
	copyS = s;
	push(0);
	simulation(1,1);
	
	if(answer == INT_MAX)
		cout<<-1<<'\n';
	else
		cout<<answer<<'\n';
	
	return 0;
}
