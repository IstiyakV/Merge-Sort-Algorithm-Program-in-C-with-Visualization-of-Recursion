#include<stdio.h>
int arr[10]={1,5,6,8,2,4,3,0,9,7};
int temp[10];

void printArray(int low,int high){

    for(int i=low;i<=high;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merging(int low,int mid,int high){

    printf("Before Marging : ");
    printArray(low,high);

    int left=low;
    int right=mid+1;
    int i=low;

    for(i=low;i<=mid && i<=high;i++){

        if(arr[left]<=arr[right]){
            temp[i] = arr[left];
            left++;
        }else{

            temp[i] = arr[right];
            right++;
        }
    }

    while(left<=mid){
        temp[i] = arr[left];
        i++;
        left++;
    }
     while(right<=high){
        temp[i] = arr[right];
        i++;
        right++;
    }

    for(i=low;i<=high;i++){
        arr[i]=temp[i];
    }
    printf("After Marging : ");
    printArray(low,high);
    printf("\n\n");

}

void partitioning(int low,int high){

    printArray(low,high);
    int mid = 0;

    if(low<high){
        mid = (low+high)/2;
        partitioning(low,mid);
        partitioning(mid+1,high);
        merging(low,mid,high);

    }else{

     printf("Returned\n\n");
        return;
    }
}


int main(){

    partitioning(0,9);

}
