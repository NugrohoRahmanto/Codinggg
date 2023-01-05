print("\nCONVERTER SUHU\n")

suhu = input("Masukkan jenis suhu : ")
suhu2 = input("Jenis suhu yg akan dihasilkan : ")
jumlah_suhu = input("Masukkan jumlah suhu : ")


if jumlah_suhu.isdigit():
    angka = int(jumlah_suhu)
    if suhu == "Celcius":
        if suhu2 == "Reamur":
            hasil = angka * 4/5
            print("Suhu Celcius dalam Reamur adalah", hasil)
        elif suhu2 == "Farenhit":
            hasil = (angka * 9/5) + 32
            print("Suhu Celcius dalam Farenhit adalah", hasil)
        elif suhu2 == "Kelvin":
            hasil = angka + 273
            print("Suhu Celcius dalam Kelvin adalah", hasil)
        else:
            print("format yang anda masukkan salah")
    elif suhu == "Reamur":
        if suhu2 == "Celcius":
            hasil = angka * 5/4
            print("Suhu Reamur dalam Celcius adalah", hasil)
        elif suhu2 == "Farenhit":
            hasil = (angka * 9/4) + 32
            print("Suhu Reamur dalam Farenhit adalah", hasil)
        elif suhu2 == "Kelvin":
            hasil = (5/4 * angka) + 273
            print("Suhu Reamur dalam Kelvin adalah", hasil)
        else:
            print("format yang anda masukkan salah")
    elif suhu == "F":
        if suhu2 == "Celcius":
            hasil = 5/9 * (angka - 32)
            print("Suhu Farenhit dalam Celcius adalah", hasil)
        elif suhu2 == "Reamur":
            hasil = 4/9 * (angka - 32)
            print("Suhu Farenhit dalam Reamur adalah", hasil)
        elif suhu == "Kelvin":
            hasil = (5/9 * (angka - 32)) + 273
            print("Suhu Farenhit dalam Kelvin adalah", hasil)
        else:
            print("format yang anda masukkan salah")
    elif suhu == "Kelvin":
        if suhu2 == "Celcius":
            hasil = angka - 273
            print("Suhu Kelvin dalam Celcius adalah", hasil)
        elif suhu2 == "Reamur":
            hasil = 4/5 * (angka - 273)
            print("Suhu Kelvin dalam Reamur adalah", hasil)
        elif suhu2 == "Farenhit":
            hasil = ((angka - 273) * 9/5) + 32
            print("Suhu Kelvin dalam Farenhit adalah", hasil)
        else:
            print("format yang anda masukkan salah")        
    else:
        print("format yang anda masukkan salah")
else :
    print("format yang anda masukkan salah") 