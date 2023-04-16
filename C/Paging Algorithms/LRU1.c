
// LRU page replacement.

// Replace a page which is not 
// in use for a long time.

#include <stdio.h>

void show(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int isPresent(int a[], int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == data)
        {
            return 1;
        }
    }
    return 0;
}

int getIndex(int f[], int n, int data){

    for(int i = 0; i < n; i++){
        if(f[i] == data){
            return i;
        }
    }
}

int main(){

    int pages[] = {3, 2, 1, 3, 4, 1, 6, 2, 4, 3, 4, 2, 1, 4, 5, 2, 1, 3, 4};
    int n = sizeof(pages) / sizeof(pages[0]);

    int hits = 0;
    int frames = 3;
    int f[frames];
    int ind = 0;
    int z = 0;
    for (int i = 0; i < frames; i++)
        f[i] = -1;
    
    // Fill the pages until frames are completely filled then perform replacement.
    
    while(ind != frames){
        
        if (isPresent(f, frames, pages[z]))
        {
            hits++;
        }
        else
        {
            f[ind] = pages[z];
            ind++;
        }
        z++;
    }
    // replace other pages and calculate hits..
    for(int i = z; i < n; i++){
        if (isPresent(f, frames, pages[i]))
        {
            hits++;
        }
        else
        {
            ind = getIndex(f, frames,pages[i - 3]);
            f[ind] = pages[i];
        }
    }
    printf("frames at end..\n");
    show(f, frames);
    printf("hits = %d\n", hits);

}