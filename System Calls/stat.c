#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
void main()
{
 struct  stat s;
 stat("hello.txt",&s);
 printf("Mode and type of file:%o",s.st_mode);
}