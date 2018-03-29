#include <stdio.h>
#include <stdlib.h>
struct n{
 int x;
 struct n * next;
};

typedef struct n node;

void bastir( node * r){
 while (r != NULL){
  printf("%d ", r->x);
  r = r -> next;
 }
 printf("\n");
}

void ekle( node * r, int x){
 while( r -> next != NULL){
  r =r -> next;
 }
 r -> next = ( node *) malloc (sizeof (node ) );
 r -> next -> x = x;
 r -> next -> next = NULL;

}
node * sil(node *r, int x){
 node *temp;
 node *iter = r;
 if( r->x == x){
  temp = r;
  r = r->next;
  free (temp);
  return r;
 }

 while ( iter->next != NULL && iter->next->x != x){
  iter = iter->next;
 }
 if ( iter->next == NULL){
  printf( "Sayi bulunamadi!\n" );
  return r;
 }
 temp = iter->next;
 iter->next = iter->next->next;
 free (temp);
 return r;
}

int main()
{
    node* root;
    node* iter;
    iter=root;
    root = (node*)malloc(sizeof(node));
    root->next=NULL;
    root->x=1;

    ekle(root,4);
    ekle(root,11);
    ekle(root,20);
    ekle(root,2);
    bastir(root);
    sil(root,11);
    bastir(root);
    sil(root,99);
    bastir(root);
    root=sil(root,1);
     bastir(root);



    return 0;
}
