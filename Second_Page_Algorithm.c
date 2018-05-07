#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//THE FINAL SUBMISSION ONE



///OUR CODE FIRST SEARCHES FOR (0,0) AND AS YOU SEARCH CHNAGE EVERY R BIT YOU ENCOUNTER FROM 0 TO 1 IF NOT FOUND, LOOP AGAIN TO try FIND 0,O IF NOT FOUND THEN FOLLLOW FIFO METHOD

int countlines(char *filename) //get size of big array
{
  // count the number of lines in the file called filename
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL)
  return 0;

  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
    lines++;
    }
  fclose(fp);
  return lines-1; /// METHOD READS EXTRA LINE SO I SUBTRACTED ONE
}


struct page {
int pageID;
int Rbit;
int Mbit;
int Atime;
};

int compare(const void *s1, const void *s2)
{
  struct page *p1 = (struct page *)s1;
  struct page *p2 = (struct page *)s2;
return p1->Atime - p2->Atime;
}


bool exists(int pageID, struct page n [5],int Mbit,int size){
for (int i=0;i<size;i++){
if (n[i].pageID==pageID){
n[i].Rbit=1;
if (Mbit==1){
n[i].Mbit=1;
}
return true;
}
}
return false;
}



int main()
{
int lines =countlines("/home/marwa/Desktop/pages.txt");
struct page n [5];
struct page pages [lines];
int k=0;
int at;
int pid;
char t;
 FILE* stream = fopen("/home/marwa/Desktop/pages.txt", "r");
if (stream==NULL){
printf("null");
}
else{
int s = fscanf(stream, "%d,%d,%c",&at,&pid,&t);
while(s!=EOF){
struct page p1;
p1.Atime=at;
p1.pageID=pid;
if(t=='R'){
p1.Rbit=1;
p1.Mbit=0;
}
else{
p1.Mbit=1;
p1.Rbit=0;
}
pages[k].pageID=p1.pageID;
pages[k].Atime=p1.Atime;
pages[k].Mbit=p1.Mbit;
pages[k].Rbit=p1.Rbit;
k++;
s = fscanf(stream, "%d,%d,%c",&at,&pid,&t);
}
}


int time=-1;
bool flagMR = false;
bool flagifexists=false;
bool fr=false;
int counter =0;
int start;
int size=0;
n[0].pageID=pages[0].pageID;
n[0].Rbit=pages[0].Rbit;
n[0].Mbit=pages [0].Mbit;
n[0].Atime=pages[0].Atime;
size++;
printf("PAGE FAULT: ");
printf("%d",pages[0].pageID);
printf(", at time: ");
printf("%d",pages[0].Atime);
printf("\n");
counter=1;
for (int i=1;i<lines;i++){
if (counter==5){
start=i;
break;
}
bool t = exists(pages[i].pageID,n,pages[i].Mbit,size);
if (t==0){
n[counter].pageID=pages[i].pageID;
n[counter].Rbit=pages[i].Rbit;
n[counter].Mbit=pages [i].Mbit;
n[counter].Atime=pages[i].Atime;
counter++;
size++;
printf("PAGE FAULT: ");
printf("%d",pages[i].pageID);
printf(", at time: ");
printf("%d",pages[i].Atime);
printf("\n");
}
}
for (int j=start;j<lines;j++){
time=time+1;
if(time%20==0&&time>0){
printf("Clock Interrupt at Time: ");
printf("%d",time);
printf("\n");
for(int e=0;e<5;e++){ //quantum =20 reset all R bits
n[e].Rbit=0;
}
}
if (pages[j].Atime==time){ //if the time = access time execute
 flagifexists=false;
 flagMR = false;
 bool w = exists(pages[j].pageID,n,pages[j].Mbit,5);
 if(w==1){
 flagifexists=true;
 exists(pages[j].pageID,n,pages[j].Mbit,5);
 }
 else{
for (int h=0;h<5;h++){
if (n[h].Rbit==0&&n[h].Mbit==0&&flagMR==false){
int u =n[h].pageID;
int m = n[h].Mbit;
n[h].pageID=pages[j].pageID;
n[h].Rbit =pages[j].Rbit;
n[h].Mbit = pages[j].Mbit;
n[h].Atime= pages[j].Atime;
qsort(n, 5, sizeof(struct page), compare);
flagMR=true;
printf("PAGE FAULT HERE, Page ");
printf("%d",pages[j].pageID);
printf(" removes page ");
printf("%d",u);
printf(", at time ");
printf("%d",pages[j].Atime);
printf("\n");
if (m==1){
printf("Page ");
printf("%d",u);
printf(" is written back to the disk");
printf("\n");
}
}
else {
if (flagMR==false&&!(n[h].Mbit==0&&n[h].Rbit==0)){
n[h].Rbit =0;
}
}
}
if(flagMR==false){
for (int q=0;q<5;q++){
if (n[q].Rbit==0&&n[q].Mbit==0&&flagMR==false){//&&flagpass2==true)
int u=n[q].pageID;
int m = n[q].Mbit;
n[q].pageID=pages[j].pageID;
n[q].Rbit =pages[j].Rbit;
n[q].Mbit = pages[j].Mbit;
n[q].Atime= pages[j].Atime;
flagMR=true;
qsort(n, 5, sizeof(struct page), compare);
printf("PAGE FAULT HERE, Page ");
printf("%d",pages[j].pageID);
printf(" removes page ");
printf("%d",u);
printf(", at time ");
printf("%d",pages[j].Atime);
printf("\n");
if (m==1){
printf("Page ");
printf("%d",u);
printf(" is written back to the disk");
printf("\n");
}
}
}

if(flagMR==false){ //still no 0,0 remove ba2a awl haga
int u=n[0].pageID;
int m=n[0].Mbit;
n[0].pageID=pages[j].pageID;
n[0].Rbit =pages[j].Rbit;
n[0].Mbit = pages[j].Mbit;
n[0].Atime= pages[j].Atime;
flagMR=true;
qsort(n, 5, sizeof(struct page), compare);
printf("PAGE FAULT HERE, Page ");
printf("%d",pages[j].pageID);
printf(" removes page ");
printf("%d",u);
printf(", at time ");
printf("%d",pages[j].Atime);
printf("\n");
if (m==1){
printf("Page ");
printf("%d",u);
printf(" is written back to the disk");
printf("\n");
}
}

}
 }
}
else{
j=j-1;
}
}
printf("The pages in the page frame are: ");
for (int p1=0;p1<5;p1++){
printf("%d",n[p1].pageID);
printf(", ");
}
printf("----DONE----");
}

