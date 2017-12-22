/*
Prime Test
���⣺�ж�һ�����Ƿ�Ϊ�����������ǣ��������С������
���������Ƚϴ��ж�������MR��ע��long long��˲���ֱ�ӳˣ��ᱬ
	  ����С�����ӣ�pollard rho�㷨�����һ�������ӣ�����󼴿�
	  Pollard Rho�㷨 ��
	  	Pollard rho�㷨��ԭ�����ͨ��ĳ�ַ����õ���������a��b�������ֽ�Ĵ�����Ϊn������p=gcd(a-b,n)��ֱ��p��Ϊ1������a��b����ѭ��Ϊֹ��Ȼ�����ж�p�Ƿ�Ϊn�����p=n��������ô����n��һ�����������򷵻�p��n��һ�����ӣ���ô�����ֿ��Եݹ�ļ���Pollard(p)��Pollard(n/p)�����������ǾͿ������n�����������ӡ�
    	��������У�����ͨ��ʹ�ú���x2=x1*x1+c�������𲽵�������a��b��ֵ��ʵ���У�ͨ��ȡcΪ1����b=a*a+1������һ�μ����У���b��ֵ����a���ٴ�ʹ����ʽ�������µ�b��ֵ����a��b����ѭ��ʱ�������˳������жϡ�
    	��ʵ�ʼ����У�a��b��ֵ���տ϶�һ����һ��ѭ����������Щֵ�ù⻬���������������Ļ������Խ��ƵĿ�����һ�����͵ġ�
    	����Pollard rho����������O(sqrt(p))��ʱ�临�Ӷ����ҵ�n��һ��С����p���ɼ�Ч�ʻ��ǿ��Եģ����Ƕ���һ�����Ӻ��١�����ֵ�ܴ�Ĵ�����n��˵��Pollard rho�㷨��Ч����Ȼ���Ǻܺã���ô�����ǻ���Ѱ�Ҹ��ӵķ����ˡ� 
	  ֤�����ٶ���������x1,x2,ʹ��p|(x1-x2)��n��|(x1-x2), ����p=gcd(x1-x2,n)��x1-x2=p*q,q��|n������gcd(x1-x2,n)�ȿ�����1Ҳ������n��һ�������� 
*/
#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#include<map>  
#include<cstdlib>  
using namespace std;  
#define Times 10
typedef long long LL;
//map<LL,int>m;
LL mi;  
LL random(LL n){
    return ((double)rand()/RAND_MAX*n+0.5);
}
LL multi(LL a,LL b,LL mod){  
    LL ans=0;
    while(b){
        if(b&1){
            b--;//������ôд����Ҫд�����ݵķ���������������һ�� 
            ans=(ans+a)%mod;
        }  
        else{  
            b>>=1;
            a=(a<<1)%mod;
        }  
    }  
    return ans;  
}  
LL Pow(LL a,LL b,LL mod){  
    LL ans=1;
    while(b){
        if(b&1)ans=multi(ans,a,mod);  
        b>>=1;
        a=multi(a,a,mod);
    }
    return ans;
}
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}
bool witness(LL a,LL n){//��a����n�Ƿ�Ϊ���� 
	LL d=n-1;
    while(!(d&1))d>>=1;
    LL t=Pow(a,d,n);
    while(d!=n-1 && t!=1 && t!=n-1){
        t=multi(t,t,n);
        d<<=1;
    }
    return t==n-1 || d&1;
}  
bool miller_rabin(LL n){  
    if(n==2)return true;  
    if(n<2||!(n&1))return false;  
    for(int i=1;i<=Times;i++){
        if(!witness((random(n-2)+1),n))return false;
    }
    return true;
}
LL pollard_rho(LL n,int c){//Ѱ��n��һ��������  
    LL x,y,d,i=1,k=2;
    x=random(n-2)+1;
    y=x; 
    while(i++){
        x=(multi(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if(1<d&&d<n)return d;
        if(y==x)return n;
        if(i==k){
            y=x;
            k<<=1;
        }
    }  
}  
void find(LL n,int c){//Ѱ��n����С������ 
    if(n==1)return;  
    if(miller_rabin(n)){
        mi=min(mi,n);
        return;
    }
    LL p=n;
    while(p>=n)p=pollard_rho(p,c--);
    find(p,c);
    find(n/p,c);
}
int main(){  
    int t;scanf("%d",&t);
    while(t--){  
        LL n;scanf("%lld",&n);
        mi=n;  
        if(miller_rabin(n))puts("Prime");
        else{
            find(n,12312);
            printf("%d\n",mi);
        }
    }  
    return 0;  
}  

