/*
[��ɽ��ѡ2011]��ȫƽ����
���������ȶ��ִ𰸣���������ת�ɼ���С��x�ķ���ȫƽ���������ĸ���
	  �ݳ�ԭ��
	  	���ڡ�x���ڵ��������� x���ڵ���ƽ��������
		  =�������κ������ı�������������(��x)-������һ������ƽ����������������+��������������ƽ����������������-��������������ƽ����������������...
		���ϵ��������Ī����˹������
		��������ö��ÿһ������������������������ͬ�����ĳ˻�����ômuΪ����ż������muΪ��������muΪ��
		�ʴ𰸼���x/(i*i)*mu[i] ע��ƽ��������
		����˵���������Ͻ�ģ�Q(x)=6x/(pi^2) + O(sqrt(x)) Q(x)<=2x�����ǲ���֤�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],miu[MAXN+3],K;
vector<int> pris;
inline void init(int size){
	miu[1]=1;
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;miu[i]=-1;pris.push_back(i);}
		for(int j=0,k;j<pris.size()&&(k=pris[j]*i)<=size;j++){
			mindiv[k]=pris[j];
			if(pris[j]==mindiv[i]){miu[k]=0;break;}
			miu[k]=-miu[i];
		}
	}
}
int calc(int x){
	int m=(int)sqrt(x),ans=0;
	for(int i=1;i<=m;i++){
		ans+=miu[i]*(x/(i*i));
	}
	return ans;
}
int bitse(int l,int r){
	int ans=l;
	while(l<=r){
		int mid=(l>>1)+(r>>1)+(l&r&1);
		if(calc(mid)>=K)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	init(MAXN);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&K);
		printf("%d\n",bitse(1,K<<1|1));
	}
	return 0;
}

