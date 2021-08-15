#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	int count, num;
	queue<int> q;
	string order;
	
	cin>>count;
	while(count--){
		cin>>order;
		
		if(order=="push"){
			cin>>num;
			q.push(num);
		}
		else if(order=="pop"){
			if(!q.empty()){ // pop() �̿�ÿ��� empty Ȯ��  
				cout<<q.front()<<'\n';
				q.pop(); // pop() �� ���� ��ȯ ���ϹǷ� front �̿� 
			}
			else
				cout<<-1<<'\n'; 
		}
		else if(order=="front"){
			if(!q.empty())
				cout<<q.front()<<'\n';
			else
				cout<<-1<<'\n';
		}
		else if(order=="back"){
//			if(!q.empty()){
//				int curSize = q.size();
//				
//				for(int j=0;j<curSize-1;j++){
//					int num = q.front();
//					q.pop();
//					q.push(num);
//				}
//				
//				num = q.front();
//				q.pop();
//				cout<<num<<'\n';
//				q.push(num);							
//			}
			if(!q.empty()){
				cout<<q.back()<<'\n';
			}
			else
				cout<<-1<<'\n';
		}
		else if(order=="size"){
			cout<<q.size()<<'\n';
		}
		else if(order=="empty"){
			cout<<q.empty()<<'\n';
		}
	}
	
	return 0;
}
