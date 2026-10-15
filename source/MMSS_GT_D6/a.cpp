#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

int memo[1000005];


int g(int n)
{
    if (n <= 1)
        return 0; 
    if (memo[n] != -1)
        return memo[n];

    vector<bool> seen(n + 2, false);
    for (int i = 1; i <= n; i++)
    {             
        int v = g(i - 1) ^ g(n - i);
        seen[v] = true;
    }
    int m = 0;
    while (seen[m])
        m++;
    return memo[n] = m;
}

int main()
{
    int N;
    scanf("%d", &N);
    memset(memo, -1, sizeof memo);
    vector<int> ps = {};
    for (int n = 0; n <= N; n++) {
        printf("P_%-4d  g=%-3d  %c\n", n, g(n), g(n) ? 'N' : 'P');
        if(!g(n)){
            ps.push_back(n);
        }
    }
    for(int i : ps){
        printf("%d\n", i);
    }
}