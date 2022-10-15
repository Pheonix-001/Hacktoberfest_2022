#include<stdio.h>
int main()
{
    int n1,n2;
    printf("Enter length of set 1-->");
    scanf("%d",&n1);
    printf("Enter length of set 2-->");
    scanf("%d",&n2);
    int a[n1],b[n2];
    printf("Enter elements in set 1-->");
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter elements in set 2-->");
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    int c[10],k=0;
    printf("The difference of set1-set2 is-->");
    for(int i=0;i<n1;i++){
        int count=0;
        for(int j=0;j<n2;j++){
            if(a[i]!=b[j]){
                count++;
            }
        }
        if(count==n2){
            c[k]=a[i];
            printf("%d ",a[i]);
            k++;
        }
    }
    printf("\nThe difference of set2-set1 is-->");
    for(int j=0;j<n2;j++){
        int count=0;
        for(int i=0;i<n1;i++){
            if(b[j]!=a[i]){
                count++;
            }
        }
        if(count==n1){
            c[k]=b[j];
            printf("%d ",b[j]);
            k++;
        }
    }
    printf("\nThe symmetric difference is-->");
    for(int i=0;i<k;i++){
        printf("%d ",c[i]);
    }

return 0;
}

