// 1120KB, 0ms

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1005];

int main(){
    
    int n, ans = 0;
  
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);
    
    sort(arr, arr + n);
    
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= i; j ++)
            ans += arr[j];    
    
    printf("%d", ans);
    
    return 0;
}
