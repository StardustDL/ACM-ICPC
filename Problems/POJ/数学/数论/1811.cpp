/*
Prime Test
题意：判断一个数是否为素数，若不是，输出其最小质因子
分析：数比较大，判断质数用MR，注意long long相乘不能直接乘，会爆
	  求最小质因子：pollard rho算法可求得一个质因子，多次求即可
	  Pollard Rho算法 ：
	  	Pollard rho算法的原理就是通过某种方法得到两个整数a和b，而待分解的大整数为n，计算p=gcd(a-b,n)，直到p不为1，或者a，b出现循环为止。然后再判断p是否为n，如果p=n成立，那么返回n是一个质数，否则返回p是n的一个因子，那么我们又可以递归的计算Pollard(p)和Pollard(n/p)，这样，我们就可以求出n的所有质因子。
    	具体操作中，我们通常使用函数x2=x1*x1+c来计算逐步迭代计算a和b的值，实践中，通常取c为1，即b=a*a+1，在下一次计算中，将b的值赋给a，再次使用上式来计算新的b的值，当a，b出现循环时，即可退出进行判断。
    	在实际计算中，a和b的值最终肯定一出现一个循环，而将这些值用光滑的曲线连接起来的话，可以近似的看成是一个ρ型的。
    	对于Pollard rho，它可以在O(sqrt(p))的时间复杂度内找到n的一个小因子p，可见效率还是可以的，但是对于一个因子很少、因子值很大的大整数n来说，Pollard rho算法的效率仍然不是很好，那么，我们还得寻找更加的方法了。 
	  证明：假定有两整数x1,x2,使得p|(x1-x2)且n不|(x1-x2), 则有p=gcd(x1-x2,n)：x1-x2=p*q,q不|n，这样gcd(x1-x2,n)既可以是1也可以是n的一个因数。 
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
            b--;//必须这么写，不要写快速幂的方法，这两个并不一样 
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
bool witness(LL a,LL n){//用a测试n是否为素数 
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
LL pollard_rho(LL n,int c){//寻找n的一个质因子  
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
void find(LL n,int c){//寻找n的最小质因子 
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

