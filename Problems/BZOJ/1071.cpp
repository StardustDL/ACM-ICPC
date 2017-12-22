/*
[SCOI2007]组队
分析：A * ( height – minH ) + B * ( speed – minV ) <= C可以化为 A*height+B*speed-C <= A*minh + B*minv 
	  先给sum = A * h + B * s排序，再给h排序，然后枚举h和s的最小值。(h -- Height, s -- Speed)
	  然后维护两个 数组的指针。非常的神奇 
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=5000;
struct data{
    int s,h,sum;
}x[MAXN+3], y[MAXN+3];
inline bool cmp1(const data &a, const data &b){
    return a.h < b.h;
}
inline bool cmp2(const data &a, const data &b){
    return a.sum < b.sum;
}
int n,Maxs,Mins,l,r,cnt,ans;
int A,B,C;
inline bool check1(int p){
    return y[p].s <= Maxs && y[p].s >= Mins;
}
inline bool check2(int p){
    return x[p].s <= Maxs && x[p].s >= Mins;
}
int main(){
    scanf("%d", &n);
    scanf("%d%d%d", &A, &B, &C);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", &x[i].h, &x[i].s);    
        x[i].sum = A * x[i].h + B * x[i].s;
        y[i] = x[i];
    }
    sort(x + 1, x + n + 1, cmp1);//按h 
    sort(y + 1, y + n + 1, cmp2);//按sum 
    for (int i = 1; i <= n; ++i){//枚举最小的speed 
        Mins = x[i].s, Maxs = Mins + C / B; 
        //要有这个上界，大于这个上界意味着：下面的第一个不等式：A*h<A*minh，这是不合法的，但不合法却不会被第二个循环检查出来，因为l单调增，会忽略前面的h，如果没有上界，那么l前面的就会重复计数 
        l = 0, r = 0, cnt = 0;
        for (int j = 1; j <= n; ++j){//枚举最小的height
            while (r < n && y[r + 1].sum <= A * x[j].h + B * x[i].s + C)//两步处理，第一次只保证sum正确 
                ++r, cnt += check1(r);
            while (l < n && x[l + 1].h < x[j].h)//第二次检查高度不满足，同时又被上一步错加进去的 
                ++l, cnt -= check2(l);
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", ans);
    return 0;
}
