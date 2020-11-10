#include <stdio.h>
#include <stdlib.h>
int combripetute(int pos,int r,int n,int *val,int *disp,int *sol,int *bestsol,int *nummonetemin,int start,int dispmonete,int lungsol,int count);
int promising(int moneta,int *sol,int r,int lungsol);
int main() {

    int i=0;
    int n=0,r=0;
    int *val;
    int *disp;
    int *sol, *bestsol;
    int pos=0,start=0,dispmonete=0,lungsol=0,count=0,nummonetemin=0;


    printf("Inserisci il resto da dare\n");
    scanf("%d",&r);

    printf("Inserisci il numero di monete disponibili\n");
    scanf("%d",&n);

    //allocazione di val e disp
    val=malloc(n* sizeof(int));
    disp=malloc(n* sizeof(int));

    //inserimento dei valori e delle disponibilità
    for(i=0;i<n;i++){
        printf("%d)Inserici la moneta con il suo valore e la sua disponibilita",i);
        scanf("%d %d",&val[i],&disp[i]);
    }

    for(i=0;i<n;i++){
        nummonetemin+=disp[i];
        dispmonete+=disp[i];
    }
    sol=malloc(dispmonete*sizeof(int));
    bestsol=malloc(dispmonete*sizeof(int));

    count=combripetute(pos, r,n, val, disp, sol, bestsol, &nummonetemin, start, dispmonete, lungsol,count);

    //stampo soluzione
    printf("La soluzione: ");
    for(i=0;i<nummonetemin;i++)
    {
        printf("%d ",bestsol[i]);
    }

    //faccio le free delle strutture dinamiche
    free(disp);
    free(val);
    free(sol);
    free(bestsol);

    return 0;
}

int combripetute(int pos,int r,int n,int *val,int *disp,int *sol,int *bestsol,int *nummonetemin,int start,int dispmonete,int lungsol,int count) {
    int sumsol = 0;
    int i = 0;
    for (i = 0; i < lungsol; i++) {
        sumsol += sol[i];
    }

    if (sumsol == r) {
        if (lungsol < *nummonetemin) {
            for (i = 0; i < lungsol; i++) {
                bestsol[i] = sol[i];
            }
            *nummonetemin = lungsol;


            return count + 1;
        }
    }


    for (i = start; i < n; i++) {
        if (disp[i] > 0) {
            if ((promising(val[i], sol, r,lungsol)) == 1) {
                sol[pos] = val[i];
                disp[i]--;
                lungsol++;
                count = combripetute(pos + 1, r,n, val, disp, sol, bestsol, nummonetemin, start, dispmonete, lungsol,count);
                disp[i]++;
                lungsol--;
                start++;

            }
        }

    }
    return count;
}



int promising(int moneta,int *sol,int r,int lungsol){
    int i=0,sumcurr=0;
    for(i=0;i<lungsol;i++){
        sumcurr+=sol[i];
    }

    if((sumcurr+moneta)>r){
        return 0;
    }
    else{return 1;}



}
