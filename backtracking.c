#include <stdio.h>
#include <stdlib.h>
//my first backtracking program :)

int isTrue(int N, int arr_place[N]){
    // printf("\n");
    // for(int i=0; i<N; i++){
    //     printf("%d ", arr_place[i]);
    // }
    // printf("\n");

    for(int i=0; arr_place[i]!=-1 && i<N-1; i++){
        for(int j=i+1; arr_place[j]!=-1 && j<N; j++){
            if(arr_place[i]==arr_place[j]){//momkene ke arr_place[j]=-1 bashe vali mohem nist
                // printf("\ntekrari hast\n");
                return 0;//meaning that is not true
            }

        }
    }


    // printf("\n");
    // for(int i=0; i<N; i++){
    //     printf("%d ", arr_place[i]);
    // }
    // printf("\n");
    
    float shibkhat1;
    for(int i=0; arr_place[i]!=-1 && i<N-1; i++){
        if(arr_place[i+1]!=-1){
            for(int j=i+1; arr_place[j]!=-1&& j<N; j++){
                if(arr_place[j]!=-1){
                    shibkhat1=(float)(arr_place[i]-arr_place[j]);
                    // printf("shibkhat= %d\n", (arr_place[i]-arr_place[j])); 
                    shibkhat1/=(i-j);
                    if(shibkhat1==1||shibkhat1==-1){
                        // printf("arrplace[%d]=%d va arrplace[%d]=%d", i, arr_place[i], j, arr_place[j]);
                        // printf("shibkhat= %f\n", shibkhat1); 
                        return 0;
                    }
                }
            }
        }else{
            break;
        }
    }
    return 1;
}
//in tabe gharare ke bebine ke hameye vazira jashun dorost

void find_solution(int N, int arr_place[N], int which_column, int jelyaagh){
    if(arr_place[which_column]==-1){
        arr_place[which_column]=0;
    }

    if(jelyaagh==0){
        if(arr_place[which_column]<N-1){
            arr_place[which_column]++;
        }else if(which_column>0){
            find_solution(N, arr_place, which_column-1, 0);
        }else{
            printf("There is no answer to this question.\n");
            exit(0);
        }
        
    }

    if(isTrue(N, arr_place)==1){//dashti mirafti jelo
        //ye marhale boro payintar
        if(which_column<N-1){//dar surati bere ye ja baraye vazire badi tuye array peyda kone ke az jadval nazane birun
            find_solution(N, arr_place, which_column+1, 1);
        }else{
            return;//dige javabo peyda karD
        }
    }else{//javabet ghalat bude
        if(arr_place[which_column]<N-1){//shakhehaye dige az hamin level ro bareC kon
            arr_place[which_column]++;
            find_solution(N, arr_place, which_column, 1);
        }else{//bargard ye marhale bala tar
        //ghablesh karaE ke tu in marhale karD ro pak kon
            arr_place[which_column]=-1;
            find_solution(N, arr_place, which_column-1, 0);
        }

    }
}



int main(){
    int n;
    printf("Please enter the number of the rows/columns: ");
    scanf("%d", &n);
    int place_of_queens[n];
    for(int i=0; i<n; i++){
        place_of_queens[i]=-1;
    }
    place_of_queens[0]=0;
    find_solution(n, place_of_queens, 0, 1);
    for(int i=0; i<n; i++){
        printf("%d " , place_of_queens[i]);
    }
    printf("\n");
    int arr[n][n];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[j][i]=0;
        }
    }
    for(int i=0; i<n; i++){
        arr[place_of_queens[i]][i]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                printf("%d ",0);
            }else{
                printf("* ");
            }
        }
        printf("\n");
    }
    return 0;
}