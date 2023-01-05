#include <stdio.h>
int main() {
  int capacity=0,packet=0,bsize=0,rate=0;
    char ans='y';
     printf("enter the bucket size : ");
    scanf("%d",&capacity);
    printf("enter the leaking rate : ");
    scanf("%d",&rate);
      while(ans=='y')
 {
        printf("\nenter the packet size : ");
        scanf("%d",&packet);
         if((bsize+packet) > capacity)
        {
            printf("\n buffer full at the moment ");
        }
        
        else if((bsize+packet) <= capacity)
        {
            bsize+=packet;
        }
        bsize-=rate;
        printf("remaining bucket capacity is %d",bsize);
        printf("\ndo you wish to keep adding packets? y/n : ");
        scanf("%s",&ans);
    
}
}