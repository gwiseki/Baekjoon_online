// 1504KB, 20ms

#include <cstdio>
#include <algorithm>

using namespace std;

bool little_end(int a, int b){
    return a > b;
}

int arr[100005];

int main(){
    
    int n, max = 0, sum;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);
    
    sort(arr, arr + n, little_end);
    
    for(int i = 1; i <= n; i ++){
        sum = i * arr[i - 1];
        
        if(max < sum)
            max = sum;
    }
    
    printf("%d", max);
    
    return 0;
    
}
