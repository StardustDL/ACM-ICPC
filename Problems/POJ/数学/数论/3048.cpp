/*
Max Factor
题意：n个数中，找具有最大素数因子的那个数 
*/
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
const int MAXN=5001,MAXM=20001;
bitset<MAXM+3> isp;
int ans[MAXN];
vector<int> pris;
void init_prime(){
    isp=0;isp[1]=1;
    for(int i=2;i<=MAXM;++i)
        if(!isp[i]){pris.push_back(i);for(int j=i*i;j<=MAXM;j+=i)isp[j]=1;}
}
int main(){
    init_prime();
    int t,mx,n,result;
    while(scanf("%d",&n)==1){
        mx=-1;
        for(int i=0;i<n;i++){
            scanf("%d",&ans[i]);
            t=1;
            for(int j=0;j<pris.size();j++){
                if(pris[j]>ans[i])break;
                if(ans[i]%pris[j]==0)t=j;
            }
            if(mx<pris[t]){
                mx=pris[t];
                result=ans[i];
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
