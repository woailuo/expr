
#include <stdio.h>
#include <stdlib.h>

struct database{
    char *name ;
    int *lh;
    char *tt;
};

//int main(){
//    
//    struct database *db = malloc(sizeof(struct database));
//    db->name = "333";
//    db->lh= malloc(sizeof(int));
//    *(db->lh) = 4;
//    db= NULL;
//    if(db)
//    {
//        if(db->tt)
//            printf("close filename");
//        
//        if(db->lh)
//            {free(db->lh); printf("free db->lh done\n");}
//        
//        free(db);
//        
//        printf("free db done\n");
//    }
//    return 1;
//}

int main(){
    
    struct database *db = malloc(sizeof(struct database));
    db->name = "333";
    db->lh= malloc(sizeof(int));
    *(db->lh) = 4;
    db= NULL;
    
    
        if(db->tt)
            printf("close filename");
        
    
        {free(db->lh); printf("free db->lh done\n");}
        
        free(db);
        
        printf("free db done\n");
    
    return 1;
}


