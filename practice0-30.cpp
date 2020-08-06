#include <cstdio>

int N,faktorN[1001]={0};
void write(int x){
    if(faktorN[x]==1){
        printf("%d",x);
    }else if(faktorN[x]>1){
        printf("%d^%d",x,faktorN[x]);
    }
}

int main(){
    scanf("%d",&N);
    int M=N,P=0;
    while(N>1){
        bool foundprime=false;
        for(int i=2;i*i<=N;i++){
            if(N%i==0){
                faktorN[i]++;
                N=N/i;
                foundprime = true;
                break;
            }
        }
        if(!foundprime){
            if(faktorN[N]>0){
                faktorN[N]++;
                N=1;
            }else{
                P=N;
                N=1;
            }
        }
    }
    //tulis keluaran
    bool writex=false;
    for(int i=2;i*i<=M;i++){
        if(faktorN[i]>0){
            if(writex){
                printf(" x ");
            }else{
                writex=true;
            }
            write(i);
        }
    }
    if(P!=0){
        if(writex){
            printf(" x ");
        }
        printf("%d",P);
    }
    printf("\n");
}