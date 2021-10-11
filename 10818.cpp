// 5016KB, 244ms

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000005];

int main(){
    
    int n, min, max;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);
    
    sort(arr, arr + n);
    
    min = arr[0];
    max = arr[n - 1];
    
    printf("%d %d", min, max);
    
    return 0;
}
