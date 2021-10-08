// 1116KB, 0ms

#include <cstdio>

using namespace std;

int main(){
    
    int T, n, ans;
    int coin[3] = {1, 2, 3};
    int memo[10];
    
    scanf("%d", &T);
    
    for(int tc = 0; tc < T; tc ++){
        
        for(int i = 3; i <= 10; i ++ )
            memo[i] = 0;

        scanf("%d", &n);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 4;
        for(int i = 4; i <= n; i ++)
            for(int j = 0; j < 3; j ++)
                if(i >= coin[j])
                    memo[i] += memo[i - coin[j]];
        
        printf("%d\n", memo[n]);
    }
    
    
}
