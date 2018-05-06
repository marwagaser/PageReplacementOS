#include <stdbool.h>
#include <stdio.h>
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


bool exists(int pageID, struct page n [3],int Mbit){
for (int i=0;i<3;++i){
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

main (){
struct page n [3];
struct page pages [15];

pages[0].pageID=0;
pages[0].Rbit=1;
pages[0].Mbit=0;
pages[0].Atime=0;

pages[1].pageID=1;
pages[1].Atime=1;
pages[1].Rbit=1;
pages[1].Mbit=0;


pages[2].pageID=1;
pages[2].Atime=2;
pages[2].Rbit=1;
pages[2].Mbit=1;


pages[3].pageID=2;
pages[3].Atime=4;
pages[3].Rbit=1;
pages[3].Mbit=0;


pages[4].pageID=3;
pages[4].Atime=5;
pages[4].Rbit=1;
pages[4].Mbit=0;

pages[5].pageID=4;
pages[5].Atime=7;
pages[5].Rbit=1;
pages[5].Mbit=0;

pages[6].pageID=0;
pages[6].Atime=8;
pages[6].Rbit=1;
pages[6].Mbit=0;

pages[7].pageID=0;
pages[7].Atime=9;
pages[7].Rbit=1;
pages[7].Mbit=0;

pages[8].pageID=6;
pages[8].Atime=10;
pages[8].Rbit=1;
pages[8].Mbit=0;

pages[9].pageID=6;
pages[9].Atime=11;
pages[9].Rbit=1;
pages[9].Mbit=1;

pages[10].pageID=3;
pages[10].Atime=12;
pages[10].Rbit=1;
pages[10].Mbit=0;

pages[11].pageID=4;
pages[11].Atime=15;
pages[11].Rbit=1;
pages[11].Mbit=0;

pages[12].pageID=6;
pages[12].Atime=20;
pages[12].Rbit=1;
pages[12].Mbit=0;

pages[13].pageID=2;
pages[13].Atime=24;
pages[13].Rbit=1;
pages[13].Mbit=0;

pages[14].pageID=2;
pages[14].Atime=25;
pages[14].Rbit=1;
pages[14].Mbit=1;
bool flagMR = false;
bool flagpass2 =true;
bool flagifexists=false;

int counter =0;

n[counter].pageID=pages[0].pageID;
n[counter].Rbit=pages[0].Rbit;
n[counter].Mbit=pages [0].Mbit;
n[counter].Atime=pages[0].Atime;
counter++;
printf("page fault: ");
printf("%d",pages[0].pageID);
printf("\n");

for (int i=1;i<15;i++){
if (counter==3){
break;
}
if (exists(pages[i].pageID,n,pages[i].Mbit)){
continue;
}
else{
n[counter].pageID=pages[i].pageID;
n[counter].Rbit=pages[i].Rbit;
n[counter].Mbit=pages [i].Mbit;
n[counter].Atime=pages[i].Atime;
counter++;
printf("page fault: ");
printf("%d",pages[i].pageID);
printf("\n");
}
}
bool repeat = false;
for (int j=3;j<15;j++){
 flagifexists=false;
 flagMR = false;
 flagpass2 =true;
bool w = exists(pages[j].pageID,n,pages[j].Mbit);
if (w){
flagifexists=true;
//printf("%s\n","5 here");
}

if(flagifexists==false){
//printf("%s\n","hi");
for (int h=0;h<3;h++){
if (n[h].Rbit==0&&n[h].Mbit==0&&flagMR==false){
//printf("%d\n",pages[j].pageID);
int u =n[h].pageID;
n[h].pageID=pages[j].pageID;
n[h].Rbit =pages[j].Rbit;
n[h].Mbit = pages[j].Mbit;
n[h].Atime= pages[j].Atime;
qsort(n, 3, sizeof(struct page), compare);
flagMR=true;
flagpass2=false;
qsort(n, 3, sizeof(struct page), compare);
printf("page fault: ");
printf("%d",pages[j].pageID);
printf(" removes ");
printf("%d",u);
printf("\n");

}
}
}
if (flagifexists==false&&flagMR==false){
for (int q=0;q<3;q++){
if (n[q].Rbit==0&&flagpass2==true){

int u=n[q].pageID;
n[q].pageID=pages[j].pageID;
n[q].Rbit =pages[j].Rbit;
n[q].Mbit = pages[j].Mbit;
n[q].Atime= pages[j].Atime;
flagpass2 =false;

qsort(n, 3, sizeof(struct page), compare);

printf("page fault: ");
printf("%d",pages[j].pageID);
printf(" removes ");
printf("%d",u);
printf("\n");
}
else {
n[q].Rbit=0;
}
}
if (flagpass2==true){
if (pages[j].pageID==6){
printf("marwa");
}
j=j-1;

}
}
}
qsort(n, 3, sizeof(struct page), compare);
for (int p1=0;p1<3;p1++){
printf("%d\n",n[p1].pageID);
}

}

