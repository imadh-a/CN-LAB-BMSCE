#include <stdio.h>
int main() {
  int packet=0,bsize=0,rate=0;
  int capacity=0;
  char ans='y';
  
    printf("enter the bucket capacity: ");
    scanf("%d",&capacity);
    printf("enter the leaking rate: ");
    scanf("%d",&rate);
    while(ans=='y')
   {
        printf("\nenter the packet size: ");
        scanf("%d",&packet);
        
         if((bsize+packet) > capacity)
        {  
            printf("\nbuffer full at the moment ");
        }
        
        else if((bsize+packet) <= capacity)
        {
            bsize+=packet;
          
        }
        bsize-=rate;
        printf("\nremaining bucket capacity is %d",bsize);
        printf("\ndo you wish to keep adding packets? y/n: ");
        scanf("%s",&ans);
    
}
return 0;
}
