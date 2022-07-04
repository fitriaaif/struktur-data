#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#define max 10
using namespace std;

struct laundry{
	string pelanggan, kategori_cucian, parfum_cucian;
	double berat;
	double total_harga;
} data[max+1];

struct laundry_selesai{
	string pelanggan_sls, kategori_cucian_sls, parfum_cucian_sls;
	double berat_sls;
	double total_harga_sls;
	laundry_selesai *next;
};

laundry_selesai *pertama = NULL;
laundry_selesai *saatini = NULL;

int awal = 0;
int total_antrian = 0;
bool cek_data(), cek_data_sls();
bool cek_full();
void antrian_ke_selesai();
void input_data();
void list_data();
void list_antrian(), list_selesai();
void ambil_antrian(), ambil_cucian();
void fades(), fitria(), rizal(), nahda();
void zitha_sls();

int main(){
	int menu;
	char ulang;
	fades(); rizal(); nahda(); fitria();
	zitha_sls();

	do {
		system("cls");
		cout << "==================================================" << endl;
		cout << "                    MY LAUNDRY                    " << endl;
		cout << "==================================================" << endl;
		cout << " Menu : " << endl;
		cout << " 1. Input data pelanggan" << endl ;
		cout << " 2. List data pelanggan" << endl ;
		cout << " 3. Ambil antrian" << endl;
		cout << " 4. Ambil laundry" << endl;
		cout << " 5. Keluar" << endl;
		cout << " Masukkan pilihan menu : ";
		cin >> menu;
		cout << endl;

	switch (menu){
		case 1 :
			system("cls");	
			input_data();
			break;
		case 2 :
			system("cls");
			list_data();
			break;
		case 3 :
			ambil_antrian();
			break;
		case 4 :
			ambil_cucian();
			break;
		case 5 :
			exit(0);
			break;
		default :
			cout << " Pilihan menu tidak ada" << endl;
			break;
		} 
		cout << "\n Kembali ke menu (y/n)? ";
		cin >> ulang;
	} while (ulang=='y' || ulang=='Y');
}

bool cek_data() { 
	return (total_antrian == 0);
}

bool cek_full() {
	return (total_antrian == max );
}

bool cek_data_sls(){
	return (pertama == NULL);
}

void input_data(){
	if (cek_full()){
		cout << " Mohon maaf, antrian penuh" << endl;
	} else{
		int pilih_kategori_cucian, pilih_parfum;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "                              INPUT DATA                              " << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Masukkan nama    : ";
		cin >> data[total_antrian].pelanggan;
		cout << " Total berat (kg) : ";
		cin >> data[total_antrian].berat;
		cout << endl;
		cout << "                           Kategori Laundry                           " << endl;
		cout << "----------------------------------------------------------------------" << endl;
	do{
		cout << " 1. Reguler (1 hari)  = Rp 5.500/kg" << endl;
		cout << " 2. Express (12 jam)  = Rp 8.000/kg" << endl;
		cout << " 3. Kilat   ( 6 jam)  = Rp 10.000/kg" << endl;
		cout << " Pilih kategori laundry : "; 
		cin >> pilih_kategori_cucian;
		cout << endl;
		
		switch (pilih_kategori_cucian){
		case 1 :
			data[total_antrian].total_harga = data[total_antrian].berat*5500;
			data[total_antrian].kategori_cucian = "Reguler";
			break;
		case 2 :
			data[total_antrian].total_harga = data[total_antrian].berat*8000;
			data[total_antrian].kategori_cucian = "Express";
			break;
		case 3 :
			data[total_antrian].total_harga = data[total_antrian].berat*10000;
			data[total_antrian].kategori_cucian = "Kilat";
			break;
		default :
			cout << " Maaf pilihan kategori tidak ada\n";
			cout << endl;
			}
		}
		while (pilih_kategori_cucian != 1 && pilih_kategori_cucian != 2 && pilih_kategori_cucian != 3);

		cout << "                            Parfum Laundry                            " << endl;
		cout << "----------------------------------------------------------------------" << endl;
	do{
    	cout << " 1. Sweet Paradise " << endl;
    	cout << " 2. Lavender       " << endl;
	    cout << " 3. Aqua Fresh     " << endl;
    	cout << " 4. Vanila         " << endl;
    	cout << " 5. Casablanca Lily" << endl;
    	cout << " Pilih parfum laundry : "; 
		cin >> pilih_parfum;

    	switch (pilih_parfum){
    	case 1 : 
    		data[total_antrian].parfum_cucian = "Sweet Paradise";
    		break;
    	case 2 : 
    		data[total_antrian].parfum_cucian = "Lavender";
    		break;
    	case 3 : 
    		data[total_antrian].parfum_cucian = "Aqua Fresh";
    		break;
    	case 4 : 
    		data[total_antrian].parfum_cucian = "Vanilla";
    		break;
    	case 5 : 
    		data[total_antrian].parfum_cucian = "Casablanca Lily";
    		break;
    	default :
    		cout << "\n Maaf pilihan parfum tidak tersedia\n";
			cout << endl;
			}
		}
		while (pilih_parfum != 1 && pilih_parfum != 2 && pilih_parfum != 3 && pilih_parfum != 4 && pilih_parfum != 5);

		cout << "\n---------------------------------------------------------------------" << endl;
		cout << " Laundry " << data[total_antrian].kategori_cucian << " + parfum " << data[total_antrian].parfum_cucian << " dengan total = Rp " << data[total_antrian].total_harga;
		cout << "\n----------------------------------------------------------------------" << endl;
		total_antrian++;
		cout << endl;
	}
}

void list_data(){
	if (cek_data() && cek_data_sls()){
		cout << " Data masih kosong" << endl;
	} else{
		list_selesai();
		cout << endl;
		list_antrian();
		cout << endl;
		}
}

void list_antrian(){
	if (cek_data()){
		cout << " Belum ada antrian terbaru" << endl;
	} else{
		string kg = "kg", rp = "Rp";
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "                                List Antrian                                " << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		for (int i = awal; i < total_antrian; i++){
			cout << " " << i+1 << ". " << setiosflags(ios::left)<<setw(9) << data[i].pelanggan << data[i].berat << setiosflags(ios::left)<<setw(9) 
			<< kg << setiosflags(ios::left)<<setw(9) << data[i].kategori_cucian << setiosflags(ios::left)<<setw(17) << data[i].parfum_cucian 
			<< rp << setiosflags(ios::left)<<setw(9) << data[i].total_harga << "belum selesai" << endl;
		}
	}		
}

void list_selesai(){
	if (cek_data_sls()){
		cout << " Laundry belum ada yang selesai" << endl;
	} else{
		string kg = "kg", rp = "Rp";
		int i = 1;
		laundry_selesai *awal = pertama;

		cout << " Laundry yang sudah selesai" << endl;
		cout << endl;
		while (awal != NULL){
			cout << " " << i << ". " << setiosflags(ios::left)<<setw(9) << awal->pelanggan_sls << awal->berat_sls << setiosflags(ios::left)<<setw(9) 
			<< kg << rp << setiosflags(ios::left)<<setw(9) << awal->total_harga_sls << "selesai"<< endl;
			awal = awal->next;
			i++;
		}
	}
}

void ambil_antrian(){
	if (cek_data()){
		cout << " Belum ada antrian terbaru" << endl;
	} else{	
		string pengambilan, tmp, tmp2, tmp3;
		int mengecek = 0, x = total_antrian - 1;
		double tmp1, tmp4;

		cout << " Atas nama : "; 
		cin >> pengambilan;
		for (int i = awal; i < total_antrian; i++){
			if (data[i].pelanggan == pengambilan){
				tmp = data[awal].pelanggan; data[awal].pelanggan = data[i].pelanggan; data[i].pelanggan = tmp;
				tmp1 = data[awal].berat; data[awal].berat = data[i].berat; data[i].berat = tmp1;
				tmp2 = data[awal].kategori_cucian; data[awal].kategori_cucian = data[i].kategori_cucian; data[i].kategori_cucian = tmp2;
				tmp3 = data[awal].parfum_cucian; data[awal].parfum_cucian = data[i].parfum_cucian; data[i].parfum_cucian = tmp3;
				tmp4 = data[awal].total_harga; data[awal].total_harga = data[i].total_harga; data[i].total_harga = tmp4;
				mengecek = 1;
				break;
				}
			}
		if (mengecek == 1){
			antrian_ke_selesai();
			cout << "\n Laundry atas nama " << data[awal].pelanggan << " telah selesai" << endl; /*<< " Berat : " << data[awal].berat << "Kg" << endl ;
			cout << " Cucian " << data[awal].kategori_cucian << " + parfum " << data[awal].parfum_cucian << endl ;*/
			/* cout << " " << "Total = Rp" << data[awal].total_harga << endl ; */
			for (int i = awal ; i <= x; i++){
				data[i].pelanggan = data[i+1].pelanggan;
				data[i].berat = data[i+1].berat;
				data[i].parfum_cucian = data[i+1].parfum_cucian;
				data[i].kategori_cucian = data[i+1].kategori_cucian;
				data[i].total_harga = data[i+1].total_harga;
				}
			total_antrian--;
			cout << endl;
			} else{
				cout << " Maaf nama tidak terdaftar" << endl;
		}
	}
}

void ambil_cucian(){
	laundry_selesai *data_cek;
	if (cek_data_sls()){
		cout << " Laundry belum ada yang selesai" << endl;
	} else{
		data_cek = pertama;
		int mengecek = 0, mengecek1 = 0;
		string customer;

		cout << " Masukkan nama laundry Anda : "; 
		cin >> customer;
		for (int i = awal; i <= total_antrian; i++){
			if (data[i].pelanggan == customer){
				mengecek = 2;
				break;
			}
		}
		if (mengecek != 2){
		if (pertama->pelanggan_sls != customer && saatini->pelanggan_sls != customer){
			if (data_cek == saatini){
					mengecek = 1;
			} else if (data_cek->next == saatini){
					mengecek = 1;
			} else{
			while (data_cek->next->pelanggan_sls != customer){
				data_cek = data_cek->next;
				if (data_cek->next == saatini){
					mengecek = 1;
					break;
					}
				}
				laundry_selesai *hapus;
				hapus = data_cek->next;
				data_cek->next = data_cek->next->next;
				hapus->next = NULL;
				delete hapus;
			}
		} else if (pertama->pelanggan_sls == customer){
			laundry_selesai *hapus = pertama;
			if (pertama->next != NULL)
				pertama = pertama->next;
			else
				pertama = NULL;
			delete hapus;
		} else{
			if (pertama == saatini){
			pertama = NULL;
			saatini = NULL;
			return;
			}
			laundry_selesai *bantu = pertama;
			laundry_selesai *hapus = saatini;
			while (bantu->next != saatini){
				bantu = bantu->next;
				}
			saatini = bantu;
			saatini->next = NULL;
			delete hapus;
			}
 	}
		if (mengecek == 2){
			cout << "\n Maaf laundry atas nama " << customer << " belum selesai" << endl;
		} else if (mengecek == 1){
			cout << "\n Maaf cucian atas nama " << customer << " tidak terdaftar / belum laundry disini" << endl;		
		} else{
			cout << "\n Terimakasih telah me-laundry bersama kami" << endl;
			}
	}
}

	/*
 	cout << " 1. Sweet Paradise " << endl;
    cout << " 2. Lavender       " << endl;
    cout << " 3. Aqua Fresh     " << endl;
    cout << " 4. Vanila         " << endl;
    cout << " 5. Casablanca Lily" << endl;
    */

void zitha_sls(){
	laundry_selesai *baru = NULL;
	baru = new laundry_selesai;
	baru->pelanggan_sls = "Zitha";
	baru->kategori_cucian_sls = "Kilat";
	baru->parfum_cucian_sls = "Sweet Paradise";
	baru->berat_sls = 4.5;
	if (baru->kategori_cucian_sls == "Reguler")
		baru->total_harga_sls = baru->berat_sls*5500;
	else if (baru->kategori_cucian_sls == "Express")
		baru->total_harga_sls = baru->berat_sls*8000;
	else if (baru->kategori_cucian_sls == "Kilat")
		baru->total_harga_sls = baru->berat_sls*10000;
	if (cek_data_sls())
		pertama = baru;
	else
		saatini->next = baru;
	saatini = baru;
	saatini->next = NULL;
}

void antrian_ke_selesai(){
	laundry_selesai *baru = NULL;
	baru = new laundry_selesai;
	baru->pelanggan_sls = data[awal].pelanggan;
	baru->kategori_cucian_sls = data[awal].kategori_cucian;
	baru->parfum_cucian_sls = data[awal].parfum_cucian;
	baru->berat_sls = data[awal].berat;
	baru->total_harga_sls = data[awal].total_harga;
	if (cek_data_sls())
		pertama = baru;
	else
		saatini->next = baru;
	saatini = baru;
	saatini->next = NULL;
}
   
void fades(){
	data[total_antrian].pelanggan = "Fades"; data[total_antrian].berat = 2.7; data[total_antrian].kategori_cucian = "Reguler"; 
	data[total_antrian].parfum_cucian = "Casablanca Lily";
	if (data[total_antrian].kategori_cucian == "Reguler")
		data[total_antrian].total_harga = data[total_antrian].berat*5500;
	else if (data[total_antrian].kategori_cucian == "Express")
		data[total_antrian].total_harga = data[total_antrian].berat*8000;
	else if (data[total_antrian].kategori_cucian == "Kilat")
		data[total_antrian].total_harga = data[total_antrian].berat*10000;
	total_antrian++;
}

void nahda(){
	data[total_antrian].pelanggan = "Nahda"; data[total_antrian].berat = 1.5; data[total_antrian].kategori_cucian = "Kilat"; 
	data[total_antrian].parfum_cucian = "Aqua Fresh";
	if (data[total_antrian].kategori_cucian == "Reguler")
		data[total_antrian].total_harga = data[total_antrian].berat*5500;
	else if (data[total_antrian].kategori_cucian == "Express")
		data[total_antrian].total_harga = data[total_antrian].berat*8000;
	else if (data[total_antrian].kategori_cucian == "Kilat")
		data[total_antrian].total_harga = data[total_antrian].berat*10000;
	total_antrian++;
}

void fitria(){
	data[total_antrian].pelanggan = "Fitria"; data[total_antrian].berat = 3.8; data[total_antrian].kategori_cucian = "Express";
	data[total_antrian].parfum_cucian = "Vanila";
	if (data[total_antrian].kategori_cucian == "Reguler")
		data[total_antrian].total_harga = data[total_antrian].berat*5500;
	else if (data[total_antrian].kategori_cucian == "Express")
		data[total_antrian].total_harga = data[total_antrian].berat*8000;
	else if (data[total_antrian].kategori_cucian == "Kilat")
		data[total_antrian].total_harga = data[total_antrian].berat*10000;
	total_antrian++;
}

void rizal(){
	data[total_antrian].pelanggan = "Rizal" ; data[total_antrian].berat = 1.2; data[total_antrian].kategori_cucian = "Reguler"; 
	data[total_antrian].parfum_cucian = "Lavender";
	if (data[total_antrian].kategori_cucian == "Reguler")
		data[total_antrian].total_harga = data[total_antrian].berat*5500;
	else if (data[total_antrian].kategori_cucian == "Express")
		data[total_antrian].total_harga = data[total_antrian].berat*8000;
	else if (data[total_antrian].kategori_cucian == "Kilat")
		data[total_antrian].total_harga = data[total_antrian].berat*10000;
	total_antrian++;
}
