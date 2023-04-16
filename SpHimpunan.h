/*  AUTHOR      : Kelompok 2
    NAMA        : SpHimpunan.h
    DESKRIPSI   : Header untuk struktur data himpunan
    TANGGAL     : 16 APRIL 2023
=======================================================================================================================*/
#ifndef SPHIMPUNAN_H
#define SPHIMPUNAN_H
#include <stdio.h>
#include <stdbool.h>

/*============================ STRUKTUR DATA ============================*/
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
    char nama_super[10];
    char member_sp[20];
    char id_member[10];
    alamatsuper next_sp;
    alamatsub1 super_sub1;
    alamatsub2 super_sub2;
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

/*============================ METHOD ============================*/
bool IsExistSuper(superset_list S, char nama, char id);
void add_membersuper(superset_list *S, char nama, char id);
void Seleksi_MemberSuper(superset_list *S);
void create_super (superset_list *S);
void CreateSub1 (subset1_list *H1);
void Createsub2 (subset2_list *H2);
bool IsSuperEmpty (superset_list S);
bool IsSubAEmpty (subset1_list H1);
bool IsSubBEmpty (subset2_list H2);
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]);
bool IsSuperFull();


#endif /* SPHIMPUNAN_H */