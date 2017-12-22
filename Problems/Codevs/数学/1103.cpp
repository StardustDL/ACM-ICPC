/*
循环
分析：从最低位开始讨论，每个位置上的循环长度乘起来即可，这要用高精度，为什么自己测是对的，交上去RE 
	  后k个数循环的长度是后k-1个数循环长度的倍数
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
struct bign{
	int v[MAXN+3],len;
	
	bign(){init();}
	
	bign(int t){
		init();
		*this=t;
	}
	
	void init(){
		memset(v,0,sizeof(v));
		len=0;
	}
	
	void clear(){
		while(!v[len-1] && len>1)len--;
	}
	
	bign operator = (const bign &t){
		memcpy(v,t.v,(t.len+5)*sizeof(int));
		len=t.len;
		return *this;
	}
	
	bign operator = (int val){
		init();
		if(val==0)len=1;
		while(val){
			v[len++]=val%10;
			val/=10;
		}
		return *this;
	}
	
	bign operator ++ (){
		v[0]++;
		simply();
		return *this;
	}
	
	bign operator ++ (int){
		v[0]++;
		simply();
		return *this;
	}
	
	bign operator + (const bign &t)const{
		bign ans;ans.len=max(len,t.len);
		int lm=min(len,t.len);
		for(int i=0;i<lm;i++)ans.v[i]=v[i]+t.v[i];
		const int *s=(len<t.len?t.v:v);
		for(int i=lm;i<ans.len;i++){
			ans.v[i]=s[i];
		}
		ans.simply();
		return ans;
	}
	
	bign operator -- (){
		if(v[0]){v[0]--;clear();}
		else{
			bign t;t=1;
			*this=*this-t;
		}
		return *this;
	}
	
	bign operator -- (int){
		if(v[0]){v[0]--;clear();}
		else{
			bign t;t=1;
			*this=*this-t;
		}
		return *this;
	}
	
	bign operator - (const bign &t)const{//要求大减小 
		bign ans=*this;
		for(int i=0;i<t.len;i++){
			if(ans.v[i]-t.v[i]<0){
				ans.v[i+1]--;
				ans.v[i]+=10;
			}
			ans.v[i]-=t.v[i];
		}
		ans.clear();
		return ans;
	}
	
	bign operator * (const bign &t)const{
		bign ans;ans.len=len+t.len;
		for(int i=0;i<len;i++){
			for(int j=0;j<t.len;j++){
				if(i+j<=MAXN)ans.v[i+j]+=v[i]*t.v[j];
			}
		}
		ans.simply();
		ans.clear();
		return ans;
	}
	
	void input(){
		char c[MAXN+3];
		init();
		scanf("%s",c);
		input(c,0,strlen(c)-1);
	}
	
	void add10(int e){
		v[e]+=1;
		len=max(len,e+1);
	}
	
	void mutiply10(int e){
		len+=e;
		for(int i=len-1;i>=e;i--){
			v[i]=v[i-e];
		}
		for(int i=0;i<e;i++)v[i]=0;
	}
	
	void simply(){
		len=min(len,MAXN);
		v[len+1]=0;
		for(int i=0;i<len;i++){
			if(v[i]>=10){
				v[i+1]+=v[i]/10;
				v[i]%=10;
			}
		}
		if(v[len])len++;
		len=min(len,MAXN);
	}
	
	void input(char *s,int l,int r){
		init();
		while(r>=l){
			v[len++]=s[r--]-'0';
		}
	}
	
	void debug(){
		for(int i=len-1;i>=0;i--)cout<<v[i]<<" ";puts("");
	}
	
	void output(){
		for(int i=len-1;i>=0;i--)putchar(v[i]+'0');
	}
};
int k,cnt;
bign base,ans,a,b,tmp,n;
int main(){
	n.input();cin>>k;
	ans=1;base=n;a=base;
	for(int i=0,t;i<k;i++){
		b=base;t=b.v[i];cnt=0;
		do{
			b=b*a;
			cnt++;
			//b.output();cout<<endl;
		}while(cnt<=10&&b.v[i]!=t);
		//cout<<cnt<<endl;
		ans=ans*cnt;
		if(b.v[i]!=t){
			ans=-1;break;
		}
		tmp=1;
		while(cnt--)tmp=tmp*a;
		//tmp.output();cout<<endl;
		a=tmp;
	}
	if(ans.v[0]==-1)cout<<-1<<endl;
	else ans.output();
	return 0;
}
/*AC C Code
#include <stdio.h>
#include <string.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define read(a) read_(&a)
#define output(a) output_(&a)
#define mul(a, b) mul_(&a, &b)
#define mulnum(a, b) mulnum_(&a, b)
#define copy(a, b) memcpy((a), (b), sizeof(numtype) * ((b)->len) + sizeof(int))
#define give(a, b) give_(&a, b)
#define getnum(a, i) (a.num[i])
#define MAX 201
const int used = 10;
typedef char numtype;
typedef struct bignum{
    int len;
    numtype num[MAX];
}bignum;
bignum std, x, num, num1, ans;
int k;

void read_(bignum *a)
{
    char tmp[101];
    int i;
    scanf("%s", tmp);
    a->len = strlen(tmp);
    i = a->len - 1;
    while(i >= 0){
        a->num[i] = tmp[a->len - 1 - i] - '0';
        i--;
    }
}

void output_(bignum *a)
{
    int i;
    numtype *num = a->num;
    for(i = a->len - 1; i >= 0; i--){
        printf("%d", num[i]);
    }
    printf("\n");
}

void give_(bignum *a, int n)
{
    int i;
    for(i = 0; n != 0; i++){
        a->num[i] = n % used;
        n /= used;
    }
    a->len = i;
}

void mul_(bignum *a, bignum *b)
{
    static bignum tmp;
    int len = a->len + b->len - 1;
    int i, j;
    numtype re;
    memset(&tmp, 0, sizeof(bignum));
    for(i = 0; i < a->len; i++){
        re = 0;
        for(j = 0; j < b->len; j++){
            tmp.num[i + j] += a->num[i] * b->num[j] + re;
                //是+=
            re = tmp.num[i + j] / used;
            if(re > 0){
                tmp.num[i + j] %= used;
            }
        }
        if(re > 0){
            tmp.num[i + j] = re;
            len = max(i + j + 1, len);
        }
    }
    if(len > k){
        len = k;
    }
    tmp.len = len;
    copy(a, &tmp);
}

void mulnum_(bignum *a, int n)
{
    int i;
    numtype re = 0;
    for(i = 0; i < a->len; i++){
        a->num[i] = a->num[i] * n + re;
        re = a->num[i] / used;
        if(re > 0){
            a->num[i] %= used;
        }
    }
    if(re > 0){
        a->num[i] = re;
        a->len++;
    }              
}

int main(void)
{
    int i, j;
    int a, b;
    read(std);
    give(ans, 1);
    copy(&x, &std);
    give(ans, 1);
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        copy(&num, &std);
        give(num1, 1);
        b = getnum(std, i);
        for(j = 1; j <= 10; j++){
            mul(num1, x);
            mul(num, x);
            a = getnum(num, i);
            if(a == b){
                copy(&x, &num1);
                mulnum(ans, j);
                break;
            }
        }
        if(j > 10){
            printf("-1\n");
            return 0;
        }
    }
    output(ans);
    return 0;
}
*/

