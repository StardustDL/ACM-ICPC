/*
������
�������ж���û�г��ֹ���set��map 
*/ 
#include<cstdio>
#include<set>
using namespace std;
set<int> S;
int n,t;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		if(S.count(t)==0){
			S.insert(t);
			putchar('0');
		}else putchar('1');
	}
	return 0;
}

