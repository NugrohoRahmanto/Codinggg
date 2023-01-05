package main

import "fmt"

type Nasabah struct {
	kodeAsdos string
	nama      string
	bank      string
	noRek     string
}

func main() {
	var tabNasabah []Nasabah
	var kapasitas int = 2022
	for i := 0; i < 10; i++ {
		addNasabah(&tabNasabah, kapasitas)
	}
	var pencarianBank string
	fmt.Scan(&pencarianBank)
	cetak(tabNasabah, kapasitas, pencarianBank)
}
func addNasabah(tabNasabah *[]Nasabah, N int) {
	if len(*tabNasabah) == N {
		fmt.Println("data penuh")
	} else {
		var newNasabah Nasabah
		fmt.Scan(&newNasabah.kodeAsdos, &newNasabah.nama, &newNasabah.bank, &newNasabah.noRek)
		*tabNasabah = append(*tabNasabah, newNasabah)
	}
}
func cetak(tabNasabah []Nasabah, N int, x string) {
	for _, data := range tabNasabah {
		if data.bank == x {
			fmt.Printf("Kode: %s , Nasabah: %s , Bank : %s , Rek : %s \n", data.kodeAsdos, data.nama, data.bank, data.noRek)
		}
	}
}
