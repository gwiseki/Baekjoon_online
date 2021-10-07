// 1988KB, 0ms  

#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int len, halflen;
    string str;
    bool ispal;
    
    while(10){
        cin >> str;
        
        if(str == "0")
            break;
        
        len = str.length();
        halflen = len / 2;
        
        ispal = true;
        for(int i = 0; i < halflen; i ++)
            if(str[i] != str[len - 1 - i]){
                ispal = false;
                break;
            }
        if(ispal)
            printf("yes\n");
        else
            printf("no\n");
        
    }
    
    
    
    return 0;
}
