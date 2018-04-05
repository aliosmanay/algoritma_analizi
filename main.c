#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
struct dugum{
    int veri;
    struct dugum* sag;
    struct dugum* sol;

};
typedef struct dugum eleman;

eleman* ekle(eleman* agac, int eklenecek_deger){
    if(agac==NULL){
        eleman* kok =(eleman*)malloc(sizeof(eleman));

        kok->sag=NULL;
        kok->sol=NULL;
        kok->veri=eklenecek_deger;
        return kok;
    }
    if(agac->veri<eklenecek_deger){
        agac->sag=ekle(agac->sag, eklenecek_deger);

    }
    else{
        agac->sol=ekle(agac->sol,eklenecek_deger);
    }
    return agac;
}
void soldanSagaDolas(eleman* agac){
    if(agac==NULL){
        return;
    }
    soldanSagaDolas(agac->sol);
    printf("%d",agac->veri);
    printf("-");
    soldanSagaDolas(agac->sag);

}
int main()
{
    eleman* agac=NULL;
    printf("agac icin eleman sayisi giriniz:");
    int e_sayisi;
    int rastgele;
    scanf("%d",&e_sayisi);
    int i;
    srand(time(NULL));
   for(i=0; i<e_sayisi; i++){

        rastgele=1+rand()%e_sayisi;
        agac=ekle(agac,rastgele);


    }

     soldanSagaDolas(agac);


}
