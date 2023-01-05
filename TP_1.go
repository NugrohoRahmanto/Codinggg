package main

import "fmt"

// no.1
type trec struct {
	v1 int
	vx struct {
		v2, v3 int
	}
	v4 int
}

func BanyakNilai(rec *trec) {
	arrayy := []int{rec.v1, rec.vx.v2, rec.vx.v3, rec.v4}

	// a
	for i := 0; i < len(arrayy); i++ {
		if arrayy[i] < rec.v1 {
			rec.v1 = arrayy[i]
		}
	}
	// b
	var jumlah int
	for i := 0; i < len(arrayy); i++ {
		jumlah += arrayy[i]
	}
	rec.vx.v2 = jumlah
	// c
	rec.vx.v3 = rec.vx.v2 / len(arrayy)
	// d
	for i := 0; i < len(arrayy); i++ {
		if arrayy[i] > rec.v4 {
			rec.v4 = arrayy[i]
		}
	}
}

// no.2
func TambahData(tab *[]int, n *int) {
	var masukan int
	fmt.Scan(&masukan)
	for masukan != 9999 {
		*tab = append(*tab, masukan)
		*n++
		fmt.Scan(&masukan)
	}
}

// no.3
func CariSekuensial(tab []int, v int) int {
	loc := -1
	for i := 0; i < len(tab); i++ {
		if v == tab[i] {
			loc = i
		}
	}
	return loc
}

// no.4
func NilaiMinimum(tab []int, n int) int {
	min := tab[0]
	for i := 1; i < n; i++ {
		if tab[i] < min {
			min = tab[i]
		}
	}
	return min
}

// no.5
func NilaiRerata(tab []int, n int) int {
	var jumlah int
	for i := 0; i < n; i++ {
		jumlah += tab[i]
	}
	jumlah = jumlah / n
	return jumlah
}

// no.6
func TerurutA(tab []int, n int) {
	for i := 0; i < n; i++ {
		pass := i
		for j := i + 1; j < n; j++ {
			if tab[i] > tab[j] {
				pass = j
			}
		}
		tab[i], tab[pass] = tab[pass], tab[i]
	}
}

// no.7
func TerurutB(tab []int, n int) {
	for i := 1; i < n; i++ {
		temp := tab[i]
		j := i - 1
		for j >= 0 && temp > tab[j] {
			tab[j+1] = tab[j]
			j--
		}
		tab[j+1] = temp
	}
}

// no.8
func CariTepat(tab []int, n, v int) int {
	TerurutA(tab, n)
	awal := 0
	akhir := n - 1
	tengah := n / 2
	for tab[tengah] != v {
		if v < tab[tengah] {
			akhir = tengah - 1
		} else {
			awal = tengah + 1
		}
		tengah = awal + (akhir-awal)/2
	}
	if tab[tengah] == v {
		return tengah
	} else {
		return -1
	}
}
