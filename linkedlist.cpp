#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Data_node{
    char nama[50];
    char nim[10];
};

struct node{
    Data_node data;
    node *next;
};

node *head;
node *tail;
node *curr;
node *entry;
node *del;

void inisialisasi(){
    head = NULL;
    tail = NULL;
}

void input(Data_node dt){
    entry = (node*)malloc(sizeof(node)); 
    entry->data = dt; 
    entry->next = NULL;
    if(head==NULL){
        head = entry;
        tail = head;
    } else{
        tail->next = entry;
        tail = entry;
    }
}

void hapus(){
    node simpan;
    if(head==NULL){
        cout << "Linked list kosong, penghapusan data tidak bisa dilakukan" << endl;
    } else{
        simpan.data  = head->data;
        cout << "Data yang dihapus adalah ";
        cout << simpan.data.nama << "|" << simpan.data.nim << endl;

        del = head;
        head = head->next;
        delete del;
    }
}

void cetak(){
    curr = head;
    if(head == NULL){
        cout << "Tidak ada data dalam linked list" << endl;
    } else{
        cout << "Data yang ada dalam linked list : \n";
        while(curr!=NULL){
            cout << curr->data.nama << "|" << curr->data.nim;
            cout << " -> ";
            curr = curr->next;
        }
            cout << "NULL";
            cout << endl;
    }
}

void menu(){
    char pilih, ulang;
    node tmp; 

    do{
        fflush(stdin); 
        system("cls");
        cout << "================================\n";
        cout << "     PROGRAM DATA MAHASISWA     \n";
        cout << "================================\n";
        cout << "Menu :\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan menu Anda : ";
        cin >> pilih;
        cout << endl;

        switch(pilih){
            case '1' :
                fflush(stdin);
                cout << "Masukkan nama  : ";
                cin >> tmp.data.nama;
                cout << "Masukkan NIM   : ";
                cin >> tmp.data.nim;
                input(tmp.data);
                break;
            case '2' :
                hapus();
                break;
            case '3' :
                cetak();
                break;
            case '4' :
                exit(0);
                break;
            default :
                cout << "Pilihan menu salah" << endl;
      }
      cout << "\nKembali ke menu (y/n)? ";
      cin >> ulang;
   } while(ulang=='y' || ulang=='Y');
}

int main(){
    inisialisasi();
    menu();

    return 0;
}