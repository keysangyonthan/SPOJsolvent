
/*https://www.spoj.com/problems/PRIME1/  */
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll sieve[10000001],k;
//ll mrk[10000001];
void prime(ll n)
{
    ll i,j;
    k=0;
    ll mark[n];
    for(i=0;i<=n;i++)
    {
        mark[i]=1;
    }
    for(i=2;i<=n;i++)
    {
        if(mark[i])
        {
            sieve[k]=i;
            for(j=i;j<=n;j+=i)
            {
                mark[j]=0;
            }
            k++;
        }
    }
    /*for(i=0;i<sieve.size();i++)
    {
        cout<<sieve[i]<<" ";
    }*/
}
void segment(ll l,ll r)
{
    ll i,j,lower,n;;
    n=r-l+1;
    ll mrk[n];
    for(i=0;i<n;i++)
    {
        mrk[i]=1;
    }
    //cout<<k<<" ";
    for(i=0;i<k;i++)
    {
        //cout<<sieve[i]<<" ";
        lower=(floor(l/sieve[i]))*sieve[i];
        if(lower<l)
        {
            lower+=sieve[i];
        }
        if(lower==sieve[i])
        {
            lower+=sieve[i];
        }
        //cout<<lower<<" ";
        for(j=lower;j<=r;j+=sieve[i])
        {
            mrk[j-l]=0;
        }
    }
    ll count=0;
    for(i=l;i<=r;i++)
    {
        if(mrk[i-l] && i!=1)
        {
            cout<<i<<endl;
        }
    }
    cout<<endl;
}
int main()
{
    ll t,i,j,n,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        n=floor(sqrt(r))+1;
        prime(n);
        segment(l,r);
    }
} 