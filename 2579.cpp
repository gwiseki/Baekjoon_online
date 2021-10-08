// 1116KB, 0ms

#include <cstdio>

using namespace std;

typedef struct _double_int{
    int val1;
    int val2;
} double_int;

double_int answer[305];
int stairs[305];

int minimum(double_int a){
    return a.val1 > a.val2 ? a.val1 : a.val2;
}

int main(){    
    
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i ++){
        answer[i].val1 = 0;
        answer[i].val2 = 0;
    }
    
    for(int i = 1; i <= n; i ++)
        scanf("%d", &stairs[i]);
        
    answer[1].val1 = stairs[1];
    answer[2].val1 = answer[1].val1 + stairs[2];
    answer[2].val2 = stairs[2];
    
    for(int i = 3; i <= n; i ++){
        answer[i].val1 = answer[i - 1].val2 + stairs[i];
        answer[i].val2 = minimum(answer[i - 2]) + stairs[i];        
    }
    printf("%d\n", minimum(answer[n]));
    
    
    return 0;
}
