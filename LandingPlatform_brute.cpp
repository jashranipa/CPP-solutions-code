// problem : https://www.codechef.com/problems/ACM14AM4
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef long double lld;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define endl  '\n'

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int m,n;

void solve()
{
    /*
    2 3
    
    ->n
    0 1 2
 m  2 3 1
    1 2 3
    3 2 1

    */
    // REM m*n to make all 1*1, 2*2, 3*3 --> O()  and all subsets and all subsequence
    // for <= , >=  feel of for,brute   // like recursion it does by itself
    // x,y diff. always be aware // always keep it as it was i.e  (0,0) ---------> x-axis(j variable (fix for all Q)) write in book
    cin>>m>>n;                                                      
    int a[m][n];                                                      
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int ele;cin>>ele;
            a[i][j]=ele;
        }
    }
    // below is brute force to generate all matrix of 2*2, 3*3, 4*4 ... out of m*n . 
    int mina = min(m,n);
    int ans1 = LLONG_MIN;
    for(int l=2;l<=mina;l++)
    {
        int s1= (n-l);
        int s2= (m-l);
        for(int i=0;i<=s2;i++)
        {
            for(int j=0;j<=s1;j++)
            {
                int ans=0;
                int y1=i;
                int x1=j;
                // l*l grid
                int x2 = j+l-1;
                int y2 = i;
                int count = l;
                while(count--)
                {
                    ans+=a[y1][x1];
                    x1++;y1++;
                } 
                count=l;
                while(count--)
                {
                    ans+=(a[y2][x2]);
                    x2--;y2++;
                }
                if(l%2!=0)
                {
                    int add = ((l-1)/2);
                    ans-=(a[i+add][j+add]);
                }
                ans1 = max(ans1,ans);
            }
        }
    }
    cout<<ans1<<endl;
    return;
}

int32_t main()
{
    fast_io();
    ll testcases=1;ll cse = 0;
    cin >> testcases;
    while (testcases--)
    {
        solve();
    }
    return 0;
}
