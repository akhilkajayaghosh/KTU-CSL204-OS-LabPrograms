#include <stdio.h>
int main() {
    int n, i, j, k, page_faults = 0,page_hits=0,frame_pointer = 0,MAX_FRAMES;
  printf("Enter no of frames:");
  scanf("%d",&MAX_FRAMES);
    int frames[MAX_FRAMES];
    int recent[MAX_FRAMES]; // Array to store the recentness of frames
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference sequence:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < MAX_FRAMES; ++i) {
        frames[i] = -1; // Initialize frames with an invalid page number
        recent[i] = 0; // Initialize recentness to 0
        }
    printf("Pages\t");
    for(i=1;i<=MAX_FRAMES;i++)
        printf("F%d\t",i);
    printf("\n");
    for (i = 0; i < n; ++i) {
        int flag = 0;
        for (j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == pages[i]) { // Check if page already exists in frames
                flag = 1;
                printf("%d\t",pages[i]);
                for(k=0;k<MAX_FRAMES;k++)
                {
                if (frames[k]==-1)
                {
                    printf("-\t");
                }
                else
                  printf("%d\t",frames[k]);
                }
                printf("Page Hit\t");
                ++page_hits;
                recent[j] = i + 1; // Update recentness
                break;
            }
        }
        if (flag == 0) { // Page fault
            int least_recent = 0;
            for (j = 1; j < MAX_FRAMES; ++j) {
                if (recent[j] < recent[least_recent]) {
                    least_recent = j; // Find the least recently used frame
                }
            }
            frames[least_recent] = pages[i];
            recent[least_recent] = i + 1; // Update recentness
            ++page_faults;
            printf("%d\t",pages[i]);
            for(k=0;k<MAX_FRAMES;k++)
            {
                if (frames[k]==-1)
                {
                    printf("-\t");
                }
                else{
                printf("%d\t",frames[k]);
                }
            }
           printf("Page Fault\t"); 
        }

        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
    printf("Total page Hit: %d\n", page_hits);
    return 0;
}