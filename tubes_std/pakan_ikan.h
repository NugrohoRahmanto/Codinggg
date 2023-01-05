#ifndef PAKAN_IKAN_H_INCLUDED
#define PAKAN_IKAN_H_INCLUDED
#include <iostream>
using namespace std;

#define firstJam(L) L.firstJam
#define firstKolam(L) L.firstKolam
#define infoJam(p) p->infoJam
#define Jadwal(p) p->Jadwal
#define nextJam(p) p->nextJam
#define infoKolam(p) p->infoKolam
#define nextKolam(p) p->nextKolam
#define nil NULL

//pilihan max kolam = 1,2,3,4,6,8,12,24
const int MAXkolam = 8;
typedef struct jam *adrJam;
typedef struct kolam *adrKolam;

struct jam{
    int infoJam;
    adrJam nextJam;
};
struct kolam{
    int infoKolam;
    adrKolam nextKolam;
    adrJam Jadwal;
};

struct listKolam{
    adrKolam firstKolam;
};

void createListKolam(listKolam &LK);
adrKolam createElemenKolam(int noKolam);
adrJam createElemenJam(int J);
void insertLastKolam(listKolam &LK, adrKolam P); //1
void insertLastJadwal(adrKolam P, adrJam J); //5
adrKolam searchJam(listKolam LK, int noJam); //4
adrKolam searchKolam(listKolam LK, int noKolam); //8
void kasihJadwal(listKolam &LK, int noKolam); //6
void ProgramBeriMakan(listKolam &LK);
void ShowParents(listKolam LK); //2
void showALL(listKolam LK); //7
void menu(int jam);
void HapusKolam(listKolam &LK, int noKolam); //3
void HapusJadwal(listKolam &LK, int noKolam); //9
void HitungJadwal(listKolam &LK, int noKolam); //10


#endif // PAKAN_IKAN_H_INCLUDED
