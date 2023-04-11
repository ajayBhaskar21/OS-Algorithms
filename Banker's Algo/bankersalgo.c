/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, r;
    n = 5; // Number of processes
    r = 3; // Number of resources
    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
 
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4
 
    int avail[3] = { 3, 3, 2 }; // Available Resources    
    
    // Need Matrix
    int need[5][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            need[i][j] = abs(alloc[i][j] - max[i][j]);
            printf("%d ", need[i][j]);
        }
        printf("\n");
        
    }
    int exec[n], ans[n];
    for(int i = 0; i < n; i++)
        exec[i]=0;
    int exe = 0;
    int flag = 0;
    int z = 0;
    // exe is no. of processes executed.
    while(exe < n){
        // loop runs n process times.
        for(int i = 0; i < n; i++){
            flag = 0;
            // checks whether process i is already executed.
            if(exec[i] == 0){
                // runs Resources no. of times
                for(int j = 0; j < r; j++){
                    // atleast one resource is unavailable then we should break
                    if(avail[j] < need[i][j]){
                        flag = 0;
                        break;
                    }
                    flag = 1;
                }
                if(flag == 1){
                    exe++;
                    exec[i] = exe;
                    for(int k = 0; k < r; k++){
                        avail[k] = avail[k] + alloc[i][k];
                    }
                    
                }
                if(flag == 0){
                    continue;
                }
                // stores optimal sequence of processes 
                ans[z++] = i;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        printf("P%d ", ans[i]);
    
    
    
    
    return 0;
}

