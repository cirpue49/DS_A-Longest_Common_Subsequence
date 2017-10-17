//
//  main.cpp
//  longest_common_subsequence
//
//  Created by 村上候助 on 2017/10/17.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char X[1005];
char Y[1005];

void lcs(){
    size_t m = strlen(X);
    size_t n = strlen(Y);
    int c[m+1][n+1];
    c[0][0] = 0;
    for (int i = 1; i <= m; i++) c[i][0] = 0;
    for (int j = 1; j <= n; j++) c[0][j] = 0;
    for (int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (X[i] == Y[j]){
                c[i][j] = c[i-1][j-1]+1;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
            }
            else{
                c[i][j] = c[i][j-1];
            }
        }
    }
    cout << c[m][n] << endl;
}

int main(int argc, const char * argv[]) {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%s", X);
        scanf("%s", Y);
        lcs();
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
