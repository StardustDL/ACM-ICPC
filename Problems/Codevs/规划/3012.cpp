/*
�߶θ��� 4
������������ǰ�����߶θ���������ͬ���߶������ڵ�����
	  ����״̬�����߶����Ͳ�̫�����ˣ���Ϊ
	  opt[i]��ʾ����i��λ�õ����Ž⣬
	  �Ȱ��Ҷ˵�����
	  ת����΢����һ�㣺
	  ���ȶ���opt[i]��Ҫ��֤����opt[j|j<i]��Ϊ���Ž⣬����Ҫ�ȼ��
	  Ȼ��ת�ƣ�opt[����i���Ҷ˵�]=max{opt[����i����˵�]+����i�ļ�ֵ}
	  ���ʱ����Ҫ��֤���Ž����ʣ������ټ��һ�� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000000;
typedef long long LL; 
struct block{
	int x,y,w;
	bool operator < (const block &t)const{
		return y<t.y||(y==t.y&&x<t.x);
	}
}bs[MAXN+3];
LL n,opt[MAXN+3],ans=0,cur=1;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>bs[i].x>>bs[i].y>>bs[i].w;
	sort(bs+1,bs+n+1);
	for(int i=1;i<=n;i++){
		while(cur<=bs[i].x){
			opt[cur]=max(opt[cur],opt[cur-1]);cur++;
		}
		opt[bs[i].y]=max(opt[bs[i].x]+bs[i].w,opt[bs[i].y]);
	}
	while(cur<=bs[n].y){
		opt[cur]=max(opt[cur],opt[cur-1]);cur++;
	}
	cout<<opt[bs[n].y];
	return 0;
} 
