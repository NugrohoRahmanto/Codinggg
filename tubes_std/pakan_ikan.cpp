#include "pakan_ikan.h"

void createListKolam(listKolam &LK){
    firstKolam(LK) = nil;
};
adrKolam createElemenKolam(int noKolam){
    adrKolam P = new kolam;
    infoKolam(P) = noKolam;
    Jadwal(P) = nil;
    nextKolam(P) = nil;
};
adrJam createElemenJam(int j){
    adrJam P = new jam;
    infoJam(P) = j;
    nextJam(P) = nil;
};
void insertLastKolam(listKolam &LK, adrKolam P){
    if(firstKolam(LK) != nil){
        adrKolam Q = firstKolam(LK);
        while (nextKolam(Q) != nil){
            Q = nextKolam(Q);
        }
        nextKolam(Q) = P;
    }else{
        firstKolam(LK) = P;
    }
};
void insertLastJadwal(adrKolam P, adrJam J){
    if (Jadwal(P) != nil){
        adrJam Q = Jadwal(P);
        while(nextJam(Q) != nil){
            Q = nextJam(Q);
        }
        nextJam(Q) = J;
    }else{
        Jadwal(P) = J;
    }
};

adrKolam searchJam(listKolam LK, int noJam){
    adrKolam P = firstKolam(LK);
    while(P!= nil){
        adrJam Q = Jadwal(P);
        while(Q != nil){
            if (infoJam(Q) == noJam){
                return P;
            }
            Q = nextJam(Q);
        }
        P = nextKolam(P);
    }
    return nil;
};
adrKolam searchKolam(listKolam LK, int noKolam){
    adrKolam P = firstKolam(LK);
    while(P!=nil && infoKolam(P) != noKolam){
        P = nextKolam(P);
    }
    return P;
};
void kasihJadwal(listKolam &LK, int noKolam){
    adrKolam K = searchKolam(LK, noKolam);
    if(Jadwal(K) == nil){
        for(int i =1; i<=24/MAXkolam; i++){
            adrJam P = createElemenJam(noKolam);
            insertLastJadwal(K, P);
            noKolam = noKolam + MAXkolam;
        }
    }else{
        cout << "Jadwal kolam " << noKolam << " sudah ada!"<< endl;
    }
};
void HapusKolam(listKolam &LK, int noKolam){
    HapusJadwal(LK,noKolam);

    adrKolam Q,K,P;
    P = firstKolam(LK);
    while(nextKolam(P) != nil){
        Q = P;
        P = nextKolam(P);
    }
    int kolamterakhir = infoKolam(P);
    if (noKolam ==1){
        K = firstKolam(LK);
        firstKolam(LK) = nextKolam(K);
        nextKolam(K) = nil;
    }else if(noKolam == kolamterakhir){
        nextKolam(Q) = nil;
    }else{
        P = firstKolam(LK);
        while(infoKolam(P) != noKolam){
            Q = P;
            P = nextKolam(P);
        }
        nextKolam(Q) = nextKolam(P);
        nextKolam(P) = nil;
    }

};
void HapusJadwal(listKolam &LK, int noKolam){
    adrKolam K = searchKolam(LK, noKolam);
    Jadwal(K) = nil;
};
void HitungJadwal(listKolam &LK, int noKolam){
    adrKolam K = searchKolam(LK, noKolam);
    adrJam J = Jadwal(K);
    int i = 0;
    while (J!= nil){
        J = nextJam(J);
        i++;
    }
    cout << "jumlah jadwal kolam " << noKolam << " adalah " << i << endl;
};
void ProgramBeriMakan(listKolam &LK){
    int MENU,jam;
    jam = 9;
    menu(jam);
    cin >> MENU;
    while(MENU != 0){
        if(MENU == 1){
            adrKolam K = searchJam(LK, jam);
            if (K == nil){
                cout << "Tidak ada jadwal makan pada jam sekarang!" << endl;
            }else{
                cout << "beri pakan kolam " << infoKolam(K) << endl;
            }
            jam++;
            cout <<endl;
        }else if(MENU == 2){
            int no;
            cout << "Masukkan No Kolam (1-8) :";
            cin >> no;
            kasihJadwal(LK, no);
            cout <<endl;
        }else if(MENU == 3){
            int jam1 = jam;
            for(int i = 1; i<=24;i++){
                cout << "Jam sekarang " << jam1 << ".00 , ";
                adrKolam K = searchJam(LK, jam1);
                if (K == nil){
                    cout << "Tidak ada jadwal makan pada jam sekarang!" << endl;
                }else{
                    cout << "beri pakan kolam " << infoKolam(K) << endl;
                }
                jam1++;
                if (jam1 == 25){
                    jam1 = 1;
                }
            }
            cout <<endl;
        }else if(MENU == 4){
            showALL(LK);
            cout << endl;
        }else if(MENU == 5){
            int no;
            cout << "Masukkan No Kolam (1-8) :";
            cin >> no;
            HapusKolam(LK,no);
            cout << endl;
        }else if(MENU == 6){
            int no;
            cout << "Masukkan No Kolam (1-8) :";
            cin >> no;
            HapusJadwal(LK,no);
            cout << endl;
        }else if(MENU == 7){
            int no;
            cout << "Masukkan No Kolam (1-8) :";
            cin >> no;
            HitungJadwal(LK,no);
            cout << endl;
        }else{
            cout << "Menu salah!, silahkan masukkan kembali!"<<endl << endl;
        }
        if (jam == 25){
            jam = 1;
        }
        menu(jam);
        cin >> MENU;
    }
    cout << "Program Selesai!" << endl;
};

void ShowParents(listKolam LK){
    adrKolam Q = firstKolam(LK);
    while (Q!=nil){
        cout << infoKolam(Q) << " ";
        Q = nextKolam(Q);
    }
};
void showALL(listKolam LK){
    adrKolam Q = firstKolam(LK);
    while (Q!=nil){
        cout << infoKolam(Q) << " -> ";
        adrJam P = Jadwal(Q);
        while(P != nil){
            cout << infoJam(P) << " ";
            P = nextJam(P);
        }
        cout << endl;
        Q = nextKolam(Q);
    }
};
void menu(int jam){
    cout << "Jam sekarang " << jam << ".00" <<endl;
    cout << "1.BeriPakan Ikan, 2.Masukkkan ikan, 3.Beri Pakan 1 Hari, 4.Show All, 5. Hapus Kolam, 6. Hapus Jadwal, 7.Hitung Jadwal 0.Out Program"<<endl;
    cout << "Masukkan Menu :";
};
