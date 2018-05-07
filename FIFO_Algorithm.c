#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 
struct Page
{
int pageID=-1;
char* accessType;
int accessTime=-1;
};
 
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
void sort ( Page *array, int size)
{
  int n=size;
  int i;
  int j;
  for (i = 0; i < n; ++i)
        {
        for (j = i + 1; j < n; ++j)
            {
                if (array[i].accessTime > array[j].accessTime)
                {
                    Page a =  array[i];
                    array[i] = array[j];
                    array[j] = a;
                }
 
            }
 
        }
 
 
}
void printPages(Page* array,int size)
{
printf("\n");
printf("The values of the page IDs in the queue are : ");
printf("\n");
for(int i=0;i<size;i++){
if(array[i].pageID!=-1)
{printf("%d",array[i].pageID);
printf("\n");}
}
}
int emptyplace (Page *array, int size)
{
  int n=size;
  int i;
  for (i = 0; i < n; ++i)
        {
       if (array[i].pageID==-1)
                {
                    return i;
                }
 
        }
return -1;
}
 
int pageexists(Page *array, int id,int size)
{
  int n=size;
  int i;
  for (i = 0; i < n; ++i)
        {
       if (array[i].pageID==id)
                {
                    return i;
                }
 
        }
return -1;
}
 
main(){
 
FILE *myFile;
myFile = fopen("pages.txt", "r");
 
 
struct Page pages[1000];
struct Page frame[5];
int j = 0;
 
int counter=20;
 
FILE* stream = fopen("pages.txt", "r");
 
    char line[1024];
    while (fgets(line, 1024, stream))
    {
       if(line != NULL )
     j++;
      for (int i=1;i<4;i++){
	char* tmp = strdup(line);
	char* x= (char *)(getfield(tmp, i));
	if(x != NULL && i==1){
           pages[j].accessTime = atoi(x);
	}
	if(x != NULL && i==2){
           pages[j].pageID = atoi(x);
 
	}
	if(x != NULL && i==3){
           pages[j].accessType = x;
	 }
	free(tmp);
 
}
 
   }
printf("The first page in the csv is : ");
printf("%d",pages[0].pageID);
 
for(int i=0;i<43;++i)
{
    if(pages[i].accessTime>=counter)
    {
        printf("\n");
        printf("Interrupt caused by quantum is taking place at time : ");
        printf("%d",counter);
        printf("\n");
        counter+=20;
    }
    sort(frame,5);
    int pageexistance=pageexists(frame,pages[i].pageID,5);
    int empty=emptyplace(frame,5);
 
    if(pageexistance==-1)
    {
        printf("\n");
        printf("Page fault : ");
        printf("%d",pages[i].pageID);
        printf(" at time : ");
        printf("%d",pages[i].accessTime);
        printf("\n");
 
        if(empty!=-1)
        {
            frame[empty]=pages[i];
        }
        else
        {
            printf("\n");
            printf("The page ID that will be removed from the queue and will get added to disk is : ");
            printf("%d",frame[0].pageID);
            printf("\n");
            sort(frame,5);
            frame[0]=pages[i];
        }
    }
    sort(frame,5);
        printPages(frame,5);
 
}
 
return 0;
}
