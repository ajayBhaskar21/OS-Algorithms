
// Optimal page replacement.
// Replace the page which will not be
// used in the near future.

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

int setCounts(int pages[], int n, int data, int start){
    if(start > n){
        return -10;
    }
    int steps = 0;
    for(int i = start; i < n; i++){
        steps++;
        if(pages[i] == data)
            return steps;
    }
    return steps;
}

int findMax(int steps[], int frames){
    int max = 0;
    for(int i = 0; i < frames; i++){
        if(max < steps[i]){
            max = steps[i];
        }

    }
    return max;
}

int main(){

    int pages[] = {3, 2, 1, 3, 4, 1, 6, 2, 4, 3, 4, 2, 1, 4, 5, 2, 1, 3, 4};
    int n = sizeof(pages) / sizeof(pages[0]);

    int hits = 0;
    int frames = 3;
    int f[frames];
    int steps[frames];

    int ind = 0;
    int z = 0;
    for (int i = 0; i < frames; i++){
        f[i] = -1;
        steps[i] = 0;
    }
        

    // Fill the pages until frames are completely filled then perform replacement.

    while (ind != frames)
    {

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
    for (int i = z; i < n; i++)
    {
        if (isPresent(f, frames, pages[i]))
        {
            hits++;
        }
        else
        {
            for(int j = 0; j < frames; j++){
                steps[j] = setCounts(pages, n, f[j], i + 1);
            }
            int max = findMax(steps, frames);
            for(int j = 0; j < frames; j++){
                if(steps[j] == max){
                    ind = j;
                    break;
                }
            }
            
            show(steps, frames);

            for(int j = 0; j < frames; j++) steps[j] = 0;

            f[ind] = pages[i];
        }
    }
    
    printf("hits = %d\n", hits);
}