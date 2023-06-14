#include <stdio.h>
#define MAXN 1001

long long A[MAXN][MAXN];

int N;
int M;
int sr, sc, er, ec;

void init()
{
    scanf("%d", &N);
    long long val;
    for (int i = 1; i <=N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%lld", &val);
            A[i][j] = val + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }
}

long long query()
{
    scanf("%d %d %d %d", &sr, &sc, &er, &ec);

    return A[er][ec] - A[sr - 1][ec] - A[er][sc - 1] + A[sr - 1][sc - 1];
}

int main()
{
    init();
    
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
        printf("%lld\n", query());

    return 0;
}