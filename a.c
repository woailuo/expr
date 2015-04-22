#include <stdio.h>
#include <stdlib.h>

struct database{
  char *name ;
  int *lh;
  char *filename;
};

  int main(){

    struct database *db = malloc(sizeof(struct database));
    db->name = "333";
    /* db->lh= malloc(sizeof(int)); */
    /* *(db->lh) = 4; */
    if(db)
      {
        if(db->filename) printf("close filename");

        if(db->lh) {free(db->lh); printf("free db->lh done\n");}

        free(db);

        printf("free db done\n");
      }
        return 1;
  }
