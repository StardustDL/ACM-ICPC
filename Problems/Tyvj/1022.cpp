/*
����ת��
��������������ǹؼ� 
*/
#include<iostream>
using namespace std;
const int MAXN=40;
int w[MAXN+1],wn=0,n,r;
void to(int n,int r){
	int cur=MAXN+1;
	if(n==0)w[--cur]=0;
	while(n!=0){
		w[--cur]=n%r;
		if(w[cur]<0){//�����λС��0����ôҪ����һ��r 
			w[cur]-=r;n=n/r+1;
		}else n/=r;
	}
	wn=cur;
}
void output(){
	for(int i=wn;i<=MAXN;i++){
		if(w[i]<10)cout<<w[i];
		else cout<<(char)('A'+w[i]-10);
	}
}
int main(){
	cin>>n;to(n,-2);output(); 
	return 0;
}
