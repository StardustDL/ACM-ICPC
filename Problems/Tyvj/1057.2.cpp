/*
������Ԥ�㷽��
����2���µ�ת�Ʒ��� 
����ͨ�� 
*/
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=32000,MAXM=60;
struct thi{
	int v,p,q,ch1,ch2,w;
	thi(){
		v=p=q=ch1=ch2=w=0;
	}
}th[MAXM+3];
int n,m,opt[MAXN+3];
void read(){
	ios::sync_with_stdio(false);
	int e;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>th[i].v>>th[i].p>>th[i].q;
		th[i].w=th[i].v*th[i].p;
		e=th[i].q;
		if(e!=0){//��¼ÿ�������ĺ��� 
			if(th[e].ch1==0)th[e].ch1=i;
			else th[e].ch2=i;
		}
	}
}
int solve(){
	int tt=0;
	for(int i=1;i<=m;i++){
		if(th[i].q!=0)continue;
		thi &t=th[i];
		for(int j=n;j>=t.v;j--){
			int &a=opt[j];
			//����ת�ƣ�ע��Ҫ��֤�����װ�� 
			a=(tt=j-t.v)>=0?max(a,opt[tt]+t.w):a;
			a=(tt=j-t.v-th[t.ch1].v)>=0?max(a,opt[tt]+t.w+th[t.ch1].w):a;
			a=(tt=j-t.v-th[t.ch2].v)>=0?max(a,opt[tt]+t.w+th[t.ch2].w):a;
			a=(tt=j-t.v-th[t.ch1].v-th[t.ch2].v)>=0?max(a,opt[tt]+t.w+th[t.ch1].w+th[t.ch2].w):a;
		}
	}
	return opt[n];
}
int main(){
	read();
	/*for(int i=1;i<=m;i++){
		cout<<th[i].v<<" "<<th[i].p<<" "<<th[i].q<<" "<<th[i].w<<" "<<th[i].ch1<<" "<<th[i].ch2<<endl;
	}*/
	cout<<solve();
	return 0;
}
