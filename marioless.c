#include <stdio.h>

int main(){
    while(1){
        int height=-1;
        printf("Enter the pyramids height : ");
        scanf("%d",&height);
        if(height>0){
        for(int i=0;i<height;i++){
            for(int j=height-1; j>i;j--){
                printf(" ");
            }
            for(int j=0;j<i+1;j++){
                printf("#");
            }
            printf("\n");
        }
       }
    else{
        break;
    }
    }
    return 0;
}