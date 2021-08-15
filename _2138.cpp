#include <iostream>
#include <string>
#include <algorithm>
#include <climits> // 컴파일 에러 조심 (limits)으로 착각  
using namespace std;

int N, answer;
string s, copyS, result;

//스위치 누르는 함수  
void push(int idx){
	if(idx>0)
		copyS[idx-1] = (copyS[idx-1]=='0')?'1':'0';
	
	copyS[idx] = (copyS[idx]=='0')?'1':'0';
	
	if(idx<N-1)
		copyS[idx+1] = (copyS[idx+1]=='0')?'1':'0';
}


void simulation(int idx, int cnt){
	// idx 스위치가 idx-1 전구를 보고 누를지 말지 판단 
	// 마지막 전구는 그 다음 전구가 없으므로 
	// N-2 번째 전구를 판단할 때 같이 포함시킨다. 
	// N-1 번째 스위치가 N-2, N-1 전구를 모두 포함하므로 
	if(idx == N-1){
		//같은지 확인 
		bool flag = true;
		int len = copyS.length();
		for(int i=len-2;i<len;i++)
			if(copyS[i]!=result[i]){
				flag = false;
				break;			
			}
		
		if(flag)
			answer = min(answer,cnt);
		
		//스위치를 눌러보고 다시 확인 
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
	
	//스위치를 안 누른 상태 
	if(copyS[idx-1] == result[idx-1])
	 	simulation(idx+1, cnt);
		 
	//스위치를 누르고 
	push(idx);
	
	if(copyS[idx-1] == result[idx-1])
		simulation(idx+1, cnt+1);
		
	//원상복귀 
	push(idx);	
}

int main(){
	cin>>N>>s>>result;
	
	answer = INT_MAX;
	//0번째 스위치를 누르지 않은 상태에서 시작  
	copyS = s;
	simulation(1,0);
	
	//0번째 스위치를 누른 상태에서 시작  
	copyS = s;
	push(0);
	simulation(1,1);
	
	if(answer == INT_MAX)
		cout<<-1<<'\n';
	else
		cout<<answer<<'\n';
	
	return 0;
}
