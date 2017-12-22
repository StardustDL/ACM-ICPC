#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int> q;
int n;
int main(){
	cin>>n;
	while(n--){
		char c;int x;
		cin>>c;
		switch(c){
			case 'A':cin>>x;q.push(x);break;
			case 'T':printf("%d\n",q.top());q.pop();break;
		}
	}
	return 0;
}	