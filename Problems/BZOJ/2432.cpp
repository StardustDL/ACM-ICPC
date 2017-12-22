/*
[Noi2011]兔农
分析：F[n] = F[n - 1] + F[n - 2] if (n >= 3 && F[n] % G == 1) F[n]--;
		以k=7为例，考虑f[i]组成的序列: 
		1,1,2,3,5,0, 
		5,5,3,0, 
		3,3,6,2,0, 
		2,2,4,6,3,2,5,0,
		5,5,3,0, 
		3,3,6,2,0, 
		把减1得0的位置标出，并以这些0为界分段，可以发现：
		每段开头必为相同两数，它恰是上一段的最末一位非0数；由于总共只有k-1种余数，所以不超过k段就会出现循环（如果有的话），比如上面k=7时的第3,4段就是循环节。
		记斐波那契数列为fib[i]。假如某段段首数字为x，那么这一段内第i个数即为x×fib[i]。若记这一段长度为len，则有x×fib[len]≡1(modk)。
		现在我们试图找到整个数列的循环结构：根据上式，
		
		① 求x的逆元得到fib[len] 
		② 由fib[len]得知len 
		③ 用x×fib[len?1]算出下一段的段首，重复操作直到发现循环（或者发现这一段永远不终止）。
		
		至于具体实现：
		①扩欧或者欧拉定理
		②预处理indfib[y]数组，表示斐波那契数列中模k余y的数第一次出现的下标（开头的两个1不算）
		③预处理fib[i]模k的值。有一个结论：斐波那契数列模k后一定是0,1,1开头的纯循环，而且这个循环节的长度≤6k（证明http://vfleaking.blog.163.com/blog/static/174807634201341721051604/），所以只需暴力算fib数组并同时记录indfib[]，发现循环即停止。 
		注意，假如第①步不存在逆元，或者第②步不存在符合的len，那么这一段将永远不会终止（比如k=8时就是这样），那么整个数列就不存在循环了（可以视作最后一段的长度为无穷大）。
		接下来考虑如何用矩阵乘法计算f[n]%p。 
		两个重要矩乘：
			(a(i-1) ai 1)*(0 1 0,1 1 0,0 0 1)=(ai ai+a(i-1) 1)
			(a(i-1) ai 1)*(1 0 0,0 1 0,0 -1 1)=(a(i-1) ai-1 1)
		分别记这两个3×3矩阵为A,B。令初始矩阵为(1 0 1)，通过对其不断右乘A和B便能实现累加、减1两种操作。对于分出的每一段算出一个矩阵Alen×B，表示这一段的“效果”。
		接下来是喜闻乐见的分类讨论时间：假如整个数列是循环的，判断第n项是否在混循环的那部分里，若是则直接把前面几段乘起来，n所在这一段的零头直接用A的次幂算；若不是则先把混循环全部乘起来，然后把循环节全部乘起来，算出循环次数再快速幂，然后再像刚才一样算零头乘上去。若数列不循环倒方便些，也与上面类似，不多说了；如果长度无限，直接矩乘累加即可。
		
		一句话：斐波那契数列在mod k的意义下有循环节，长度在6*k之内
			我们要求的数列mod k之后是这样的1，1，2，3....a，0，1*a，1*a，2*a .... b，0，1*b 2*b ... 0
			1 a b...这个数列也是有循环节的（可以通过求逆元求出这个数列），这个循环节长度在k以内（可能没有循环，后面mod k都不为1），然后加上矩阵快速幂即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
typedef long long LL;
LL n,k,p;
LL fib[10000005],indfib[1000005]={0},inv[1000005];
LL exgcd(LL a,LL b,LL &lx,LL &ly){
    LL x=0,y=1,q,t;lx=1,ly=0;
    while(b){
        q=a/b;
        t=b;b=a%b;a=t;
        t=x;x=lx-q*x;lx=t;
        t=y;y=ly-q*y;ly=t;
    }
    return a;
}
void buildinv(){
    LL tmp1,tmp2;inv[1]=1;
    for (LL i=2;i<k;i++)
        if(exgcd(i,k,tmp1,tmp2)!=1)inv[i]=0;
        else inv[i]=tmp1<0?tmp1+k:tmp1;
}
LL ord[1000005];LL tot=0;
LL lensum[1000005];
LL vis[1000005]={0};
struct mat{LL a[3][3];void cl(){memset(a,0,sizeof(a));}void set1(){cl();a[0][0]=a[1][1]=a[2][2]=1;}};
mat mul(const mat &a,const mat &b){
    mat c;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++){
            c.a[i][j]=0;
            for (int k=0;k<3;k++)c.a[i][j]+=a.a[i][k]*b.a[k][j];
            c.a[i][j]%=p;
        }
    return c;
}
mat po(mat a,LL t){
    mat c;c.set1();
    while(t){
        if(t&1)c=mul(c,a);
        a=mul(a,a);
        t>>=1;
    }
    return c;
}
mat s[1000005],A,B;
int main()
{   
    cin>>n>>k>>p;
    fib[0]=0,fib[1]=fib[2]=1;
    for (LL i=3;;i++){ 
        fib[i]=fib[i-1]+fib[i-2];if(fib[i]>=k)fib[i]-=k;
        if(!indfib[fib[i]])indfib[fib[i]]=i;
        if(fib[i]==1 && fib[i-1]==1)break;
    }
    buildinv();
    LL cur=1;lensum[0]=0;
    A.cl();A.a[0][1]=A.a[1][0]=A.a[1][1]=A.a[2][2]=1;
    B.cl();B.a[0][0]=B.a[1][1]=B.a[2][2]=1;B.a[2][1]=-1;
    while(1){
        if(vis[cur])break;
        if(!inv[cur] || !indfib[inv[cur]])break;
        tot++;vis[ord[tot]=cur]=tot;
        lensum[tot]=lensum[tot-1]+indfib[inv[cur]];
        s[tot]=po(A,indfib[inv[cur]]);s[tot]=mul(s[tot],B);
        cur=1LL*cur*fib[indfib[inv[cur]]-1]%k;
    }   
    mat N;N.set1();
    if(vis[cur]){
        int pre=vis[cur]-1,i;mat M;
        for (i=1;i<=pre && n>=lensum[i];i++)N=mul(N,s[i]);
        if(i<=pre){
            M=po(A,n-lensum[i-1]);
            N=mul(N,M);
        }else{
            LL cylen=lensum[tot]-lensum[pre];
            n-=lensum[pre];
            mat C;C.set1();
            for (i=pre+1;i<=tot;i++)C=mul(C,s[i]);
            C=po(C,n/cylen);N=mul(N,C);n%=cylen;
            for (i=pre+1;n>=lensum[i]-lensum[pre];i++)N=mul(N,s[i]);
            M=po(A,n-(lensum[i-1]-lensum[pre]));
            N=mul(N,M);
        }
    }else{
        mat M;int i;
        for (i=1;i<=tot && n>=lensum[i];i++)N=mul(N,s[i]);
        M=po(A,n-lensum[i-1]);
        N=mul(N,M);
    }
    LL ans=(N.a[0][1]+N.a[2][1])%p;if(ans<0)ans+=p;
    printf("%lld\n",ans);
    return 0;
}

