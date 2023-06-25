#include <stdio.h>
#include <math.h>
int size,start;
void FCFS(int arr[],int head)
{
	int seek_count = 0;
	int cur_track, distance;
	for(int i=0;i<size;i++)
	{
		cur_track = arr[i];
		distance = fabs(head - cur_track);
		seek_count += distance;
		head = cur_track;
	}
	printf("Total number of Head Movements: %d\n",seek_count);
	printf("Seek Sequence is\n");
	printf("%d",start);
	for (int i = 0; i < size; i++) {
		printf("->%d",arr[i]);
	}
}
int main()
{
    int i,req[20],head;
    printf("Enter the no.of requests\n");
    scanf("%d",&size);
    printf("Enter the requests:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
	start=head;
	FCFS(req,head);
	return 0;
}