
#include<stdio.h>
#include<string.h>
#define N strlen(gen_poly)
char data[30];
char check_value[30];
char gen_poly[10];
int data_length,i,j;
void XOR(){
    for(j = 1;j < N; j++)
    check_value[j] = (( check_value[j] == gen_poly[j])?'0':'1');
}

void crc(){
    for(i=0;i<N;i++)
        check_value[i]=data[i];
    do{
        if(check_value[0]=='1')
            XOR();

        for(j=0;j<N-1;j++)
            check_value[j]=check_value[j+1];
        
        check_value[j]=data[i++];
    }while(i<=data_length+N-1);
}
void receiver(){
    printf("Enter the date received at receiver site: ");
    scanf("%s", data);
    printf("Data received: %s", data);
    crc();
    for(i=0;(i<N-1) && (check_value[i]!='1');i++);
        if(i<N-1){
            printf("\nCRC at receiver site is: %s",check_value);
            printf("\nError detected!\n\n");
        }
            
        else{
            printf("\nCRC at receiver site is: %s",check_value);
             printf("\nNo error detected\n\n");
        }
}
int main(){
    printf("\nEnter data to be transmitted: ");
    scanf("%s",data);
    printf("\nEnter the Generating polynomial: ");
    scanf("%s",gen_poly);

    data_length=strlen(data);
 
    for(i=data_length;i<data_length+N-1;i++)
        data[i]='0';
    printf("\nPadded Data: %s",data);
    crc();

    printf("\nCRC at sender site is: %s",check_value);
  
    for(i=data_length;i<data_length+N-1;i++)
        data[i]=check_value[i-data_length];
  printf("\nFinal data to be sent from sender site: %s\n",data);
   receiver();
    return 0;
}
