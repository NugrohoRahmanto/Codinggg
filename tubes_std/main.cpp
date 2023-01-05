#include "pakan_ikan.h"

int main() //11
{
    listKolam LK;

    createListKolam(LK);

    //inisialisai membuat list dengan jumlah kolam 8
    for (int i = 1 ; i <= MAXkolam; i++ ){
        adrKolam P = createElemenKolam(i);
        insertLastKolam(LK, P);
    }
    cout << "jumlah kolam = " << MAXkolam <<", ";
    ShowParents(LK);
    cout << endl;
    ProgramBeriMakan(LK);

    return 0;
}
