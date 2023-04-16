#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "SpHimpunan.h"
#include <windows.h>

/****** BODY SUB PROGRAM *******/

//pembentukan list superset
void create_super (superset_list *S){
    S->first_super = NULL;
}

//pembentukan list subset-1
void CreateSub1 (subset1_list *H1){
    H1->first_sub1 = NULL;
}

//pembentukan list subset-2
void Createsub2 (subset2_list *H2){
    H2->first_sub2 = NULL;
}

//mengecek apakah superset kosong
bool IsSuperEmpty (superset_list S){
    return (S.first_super == NULL);
}

//mengecek apakah subset-1 kosong
bool IsSubAEmpty (subset1_list H1){
    return (H1.first_sub1 == NULL);
}

//mengecek apakah subset-2 kosong
bool IsSubBEmpty (subset2_list H2){
    return (H2.first_sub2 == NULL);
}

//mengecek apakah proses alokasi berhasil atau gagal karena memori yang kurang
// alamatsuper IsSuperFull (){
//     alamatsuper bantu;

//     bantu = (alamatsuper) malloc (sizeof(elmtsuper));
//     if ( bantu != NULL){
//         printf("Alokasi Memori Berhasil !");
//     } else { printf("Alokasi Memori Gagal !");}
// }

bool IsSuperFull (){
    /*kamus lokal*/
    alamatsuper bantu;

    bantu = (alamatsuper) malloc (sizeof(elmtsuper));
}


//menge