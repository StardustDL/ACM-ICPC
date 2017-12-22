/*
Number Sequence
���⣺һ���������£�1121231234123451234561234567123456789123456789101234567891011...������е�nλ
������������Ƕ���kʹ��sigma{1..k}<=n�������õ���nλ����������10��11�ȶ�λ���Ĵ��ڣ��˷���Ч��
	  �����ǰi������ɵ����г��ȣ��ȼ�ȥһЩλ����Ȼ����ö�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<bitset>
using namespace std;
#define bit(x) ((int)(log10((double)x))+1)
const int INF=0x3f3f3f3f,MAXN=50000;
/*int solve(int k){
	int l=0,r=100000000;
	while(l<r){
		int mid=(l+r)>>1;
		if((1LL+mid)*mid/2LL<k)l=mid+1;
		else r=mid;
	}
	l--;
	int n=(1+l)*l/2;
	int ans=0;
	return k-n;
}
int main(){
	int T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		printf("%d\n",solve(x));
	}
	return 0;
}*/
int s[MAXN+3],n,t,ans;
int main(){
    s[0]=0;
    for(int i=1;i<MAXN;++i)s[i]=s[i-1]+bit(i);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int k=0,l=0;
        while(n >= s[k])n-=s[k++]; //ȥ������λ
        if(!n){printf("%d\n",(k-1)%10); continue;}
        for(k=1;l<n;++k)l+=bit(k);//�ճ���nλ����i�Ƕ��١�
        ans=(--k)/((int)pow(double(10),l-n)); //ȥ�������λ
		printf("%d\n",ans%10);
    }
    return 0;
}

