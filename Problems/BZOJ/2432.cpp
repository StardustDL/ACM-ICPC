/*
[Noi2011]��ũ
������F[n] = F[n - 1] + F[n - 2] if (n >= 3 && F[n] % G == 1) F[n]--;
		��k=7Ϊ��������f[i]��ɵ�����: 
		1,1,2,3,5,0, 
		5,5,3,0, 
		3,3,6,2,0, 
		2,2,4,6,3,2,5,0,
		5,5,3,0, 
		3,3,6,2,0, 
		�Ѽ�1��0��λ�ñ����������Щ0Ϊ��ֶΣ����Է��֣�
		ÿ�ο�ͷ��Ϊ��ͬ��������ǡ����һ�ε���ĩһλ��0���������ܹ�ֻ��k-1�����������Բ�����k�ξͻ����ѭ��������еĻ�������������k=7ʱ�ĵ�3,4�ξ���ѭ���ڡ�
		��쳲���������Ϊfib[i]������ĳ�ζ�������Ϊx����ô��һ���ڵ�i������Ϊx��fib[i]��������һ�γ���Ϊlen������x��fib[len]��1(modk)��
		����������ͼ�ҵ��������е�ѭ���ṹ��������ʽ��
		
		�� ��x����Ԫ�õ�fib[len] 
		�� ��fib[len]��֪len 
		�� ��x��fib[len?1]�����һ�εĶ��ף��ظ�����ֱ������ѭ�������߷�����һ����Զ����ֹ����
		
		���ھ���ʵ�֣�
		����ŷ����ŷ������
		��Ԥ����indfib[y]���飬��ʾ쳲�����������ģk��y������һ�γ��ֵ��±꣨��ͷ������1���㣩
		��Ԥ����fib[i]ģk��ֵ����һ�����ۣ�쳲���������ģk��һ����0,1,1��ͷ�Ĵ�ѭ�����������ѭ���ڵĳ��ȡ�6k��֤��http://vfleaking.blog.163.com/blog/static/174807634201341721051604/��������ֻ�豩����fib���鲢ͬʱ��¼indfib[]������ѭ����ֹͣ�� 
		ע�⣬����ڢٲ���������Ԫ�����ߵڢڲ������ڷ��ϵ�len����ô��һ�ν���Զ������ֹ������k=8ʱ��������������ô�������оͲ�����ѭ���ˣ������������һ�εĳ���Ϊ����󣩡�
		��������������þ���˷�����f[n]%p�� 
		������Ҫ�سˣ�
			(a(i-1) ai 1)*(0 1 0,1 1 0,0 0 1)=(ai ai+a(i-1) 1)
			(a(i-1) ai 1)*(1 0 0,0 1 0,0 -1 1)=(a(i-1) ai-1 1)
		�ֱ��������3��3����ΪA,B�����ʼ����Ϊ(1 0 1)��ͨ�����䲻���ҳ�A��B����ʵ���ۼӡ���1���ֲ��������ڷֳ���ÿһ�����һ������Alen��B����ʾ��һ�εġ�Ч������
		��������ϲ���ּ��ķ�������ʱ�䣺��������������ѭ���ģ��жϵ�n���Ƿ��ڻ�ѭ�����ǲ����������ֱ�Ӱ�ǰ�漸�γ�������n������һ�ε���ͷֱ����A�Ĵ����㣻���������Ȱѻ�ѭ��ȫ����������Ȼ���ѭ����ȫ�������������ѭ�������ٿ����ݣ�Ȼ������ղ�һ������ͷ����ȥ�������в�ѭ��������Щ��Ҳ���������ƣ�����˵�ˣ�����������ޣ�ֱ�Ӿس��ۼӼ��ɡ�
		
		һ�仰��쳲�����������mod k����������ѭ���ڣ�������6*k֮��
			����Ҫ�������mod k֮����������1��1��2��3....a��0��1*a��1*a��2*a .... b��0��1*b 2*b ... 0
			1 a b...�������Ҳ����ѭ���ڵģ�����ͨ������Ԫ���������У������ѭ���ڳ�����k���ڣ�����û��ѭ��������mod k����Ϊ1����Ȼ����Ͼ�������ݼ��� 
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

