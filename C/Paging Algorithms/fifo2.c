#include<stdio.h>


void show(int a[], int n){

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

}

int isPresent(int a[], int n, int data){
    for(int i = 0; i < n; i++){
        if(a[i] == data){
            return 1;
        }
    }
    return 0;

}


int main(){

    
    int pages[] = {3, 2, 1, 3, 4, 1, 6, 2, 4, 3, 4, 2, 1, 4, 5, 2, 1, 3, 4};
    int n = sizeof(pages)/sizeof(pages[0]);

    int hits = 0;
    int frames = 3;
    int f[frames];
    int ind = 0;
    for(int i = 0; i < frames; i++) f[i] = -1;

    // Push first page into the frame. 
    f[ind] = pages[0];
    ind++;
    for(int i = 1; i < n; i++){
        if(ind == frames){
            ind = 0;
        }
        if (isPresent(f, frames, pages[i])){
            hits++;
        }
        else{
            f[ind] = pages[i];
            ind++;
        }
    }
    printf("frames at end..\n");
    show(f, frames);
    printf("hits = %d\n", hits);
}