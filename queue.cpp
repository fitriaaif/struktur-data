#include <iostream>
#include <stdlib.h>
#define n 20

using namespace std;

struct mahasiswa{
    string nama;
    int nim;
} Mhs[n];

struct queue{
    int awal, akhir;
} Queue;

void menu();
void inQueue();
void deQueue();
void tampil();

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil direset\n\n";
    menu();
}

bool isFull(){
    if(Queue.akhir == n-1 ){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if(Queue.akhir == -1 ){
        return true;
    } else{
        return false;
    }
}

void menu(){
    int pilih;

    cout << "================================\n";
    cout << "     PROGRAM DATA MAHASISWA     \n";
    cout << "================================\n";
    cout << "1. Input Data\n";
    cout << "2. Hapus Data\n";
    cout << "3. Reset Data\n";
    cout << "4. Tampilkan Data\n";
    cout << "Masukkan nomor menu yang Anda pilih : ";
    cin >> pilih;
    cout << endl;

    switch(pilih){
        case 1:
            inQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            init();
            break;
        case 4:
            tampil();
            break;
        default:
            cout << "Pilihan menu salah" << endl;
            break;
    }
}

void inQueue(){
    if(!isFull()){
        string nama;
        int nim;

        cout << "Masukkan nama : ";
        cin >> nama;
        cout << "Masukkan NIM  : ";
        cin >> nim;
        Mhs[Queue.akhir].nama = nama;
        Mhs[Queue.akhir].nim = nim;
        ++Queue.akhir;
        cout << endl;
        menu();
    } else{
        cout << "Data sudah penuh";
        menu();
    }
}

void deQueue(){
    if(!isEmpty()){
        for(int i=Queue.awal; i<Queue.akhir; i++){
            Mhs[i].nama = Mhs[i+1].nama;
            Mhs[i].nim = Mhs[i+1].nim;
        } Queue.akhir--;
        cout << "Data berhasil dihapus" << endl << endl;
        menu();
    } else{
        cout << "Antrian kosong" << endl;
    }
    
}

void tampil(){
    if(!isEmpty()){
        for(int i=0; i<Queue.akhir; i++){
            cout << "Nama : " << Mhs[i].nama << endl;
            cout << "NIM  : " << Mhs[i].nim << endl << endl;
        }
    } else{
        cout << "Data kosong" << endl << endl;
    }
    menu();
}

int main(){
    menu();

    return 0;
}