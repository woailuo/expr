
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct database{
    char *name ;
    int *lh;
    char *tt;
};
int Num = 2;

/* int main(){ */
/*  l:{; } */
/*    struct database *db = malloc(sizeof(struct database)); */
/*    Num = Num -1; */
/*    assert(Num >= 0); */
/*    db->name = "333"; */
/*    db->lh= malloc(sizeof(int)); */
/*    Num = Num -1; */
/*    assert(Num >= 0); */
/*    *(db->lh) = 4; */
/*    db = NULL; */
/*    if(db) */
/*    { */
/*        if(db->tt) */
/*            printf("close filename"); */

/*        if(db->lh) */
/*          {free(db->lh); printf("free db->lh done\n"); Num = Num + 1;} */

/*        free(db); */
/*        Num = Num + 1; */

/*        printf("free db done\n"); */
/*    } */
/*    goto l; */
/*    return 1; */
/* } */

int main(){
 l:{;}
    /* struct database *db = malloc(sizeof(struct database)); */
    /* Num = Num -1; */
    /* assert(Num >= 0); */
    /* db->name = "333"; */
    /* db->lh= malloc(sizeof(int)); */
    /* Num = Num -1; */
    /* assert(Num >=0); */
    /* *(db->lh) = 4; */
    /* db = NULL; */
    /* if(db->tt) */
    /*         printf("close filename"); */

    /* {free(db->lh); Num = Num + 1; printf("free db->lh done\n");} */

    /*     free(db); */
    /*     Num = Num + 1; */

    /*     printf("free db done\n"); */

  int *a = malloc(sizeof(int));
  int  *b = malloc(sizeof(int));
  Num = Num -2;
  assert(Num >= 0);
  int m = 3;
   if(a)
     {
       if(b) { free(b); Num = Num + 1;}

       free(a);
       Num = Num + 1;
     }

        goto l;
    return 1;
}


