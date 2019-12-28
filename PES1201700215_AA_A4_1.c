#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ll long long

bool iseven(ll n)
{
    if(n%2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ll modular(ll a, ll b, ll p)
{
    ll r = 1;
    a = a%p;
    while(b>0)
    {
        if(b & 1)
        {
            r = (r*a)%p;
        }
       
        b = b/2;
        a = (a*a)%p;
    }
    return r;
}

bool miller(ll x, ll n)
{
    ll a = 2 + rand() % (n-4);
    ll res = modular(a,x,n);
    if(res == 1 || res == n-1)
    {
        return true;
    }
    while(x != n-1)
    {
        res = (res*res)%n;
        x = x*2;
        if(res == 1)
        {
            return false;
        }
        if(res == n-1)
        {
            return true;
        }
    }
    return false;
}

bool isprime(ll n, ll c)
{
    if(n<=1 || n==4) return false;
    if(n<=3)return true;
    ll x = n-1;
    while(x%2 == 0)
    {
        x = x/2;
    }
    for(ll i = 0; i<c; i++)
    {
        if(!miller(x,n))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll i;
        ll iterations = 4;
        if(iseven(n))
        {
            n = n+1;
            i = 0;
            while(true)
            {
                if(isprime(n+i,iterations))
                {
                    break;
                }
                else
                {
                    i = i+2;
                }
            }
        }
        else
        {
            i = 2;
            while(true)
            {
                if(isprime(n+i,iterations))
                {
                    break;
                }
                else
                {
                    i = i+2;
                }
            }

        }
        printf("%lld\n",n+i);
    }
    return 0;
}
