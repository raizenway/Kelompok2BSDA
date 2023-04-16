/* File        : spNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#ifndef spnrsll_H
#define spnrsll_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct subset1 *alamatsub1;
typedef struct subset1{
    char nama_sb1[10];
    char member_sb1[20];
    char id_sb1[10];
    alamatsub1 next_sb1;
}elmtsubset1;

typedef struct subset2 *alamatsub2;
typedef struct subset2{
    char nama_sb2[10];
    char member_sb2[20];
    char id_sb2[10];
    alamatsub2 next_sb2;
}elmtsubset2;

typedef struct superset* alamatsuper;
typedef struct superset{
    char nama_super[7] = "POLBAN";
    char id_member[9];
    alamatsuper next_sp;
    alamatsub1 super_sub1;
    alamatsub2 super_sub2;
    char member_sp[];
}elmtsuper;

typedef struct{
    alamatsuper first_super;
}superset_list;

typedef struct {
    alamatsuper first_sub1;
}subset1_list;

typedef struct {
    alamatsuper first_sub2;
}subset2_list;

// void Seleksi_MemberSuper(superset_list S);

bool isExistSuper(superset_list S, char nama_mhs, char id);

void add_membersuper(superset_list *S, char nama_mhs, char id);

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/



void display_menu();
#endif
