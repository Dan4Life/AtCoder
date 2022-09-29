/*
Solved with help (https://cp-algorithms.com/algebra/all-submasks.html#enumerating-all-submasks-of-a-given-mask)
The crux of the problem is finding out how to enumerate all submasks quickly. 
Turns out it's standard and can be done in O(3^n)
*/

#include <bits/stdc++.h>
using namespace std;
int n, a[1<<18];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n; int prev = 0;
    for(int i = 0; i < (1<<n); i++) cin >> a[i];
    for (int m=1; m<(1<<n); m++){
        int x=-1, y=-1;
        for (int s=m; ; s=(s-1)&m){ //The two loops run in amortized complexity: O(3^n)
            if(x<y) swap(x,y);
            if(x==-1) x=a[s];
            else if(y==-1) y=a[s];
            else if(x>=a[s] and a[s]>=y) y=a[s];
            else if(x<=a[s]) y=x, x=a[s];
            if(s==0) break;
        }
        cout << max(prev, x+y) << "\n"; prev = max(prev,x+y);
    }
}