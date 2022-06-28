#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int pilih;
    string mhs[50];
    string temp;
    char yn;
    int n, i, j, mins;

    menu:
    system ("cls");
    cout << "\t\tPROGRAM SORTING NAMA MAHASISWA\n\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n\n";
    cout << "Masukkan pilihan Anda (1/2/3) : "; cin >> pilih;
    system ("cls");

    if (pilih == 1)
    {
        cout << "\tPengurutan Nama Menggunakan Bubble Sort\n\n";
        cout << "Masukan jumlah data : ";
        cin >> n;
        cout << endl;

        for(i=1; i<=n; i++)
        {
            cout << "Nama ke-" << i << " : ";
            cin >> mhs[i];
        }
        for(i=n-1; i>=1; i--)
        {
            for(j=1; j<=i; j++)
            {
                if(mhs[j]>mhs[j+1])
                {
                    temp=mhs[j+1];
                    mhs[j+1]=mhs[j];
                    mhs[j]=temp;
                }
            }
        }
        cout << "\n-----------------------------------------------";
        cout << "\nUrutan nama : " << endl;
        cout << endl;
        for (i=1; i<=n; i++)
        {
            cout << mhs[i] << " " << endl;
        }
        cout << "\nUlangi sorting (Y/N)? ";
        cin >> yn;
        cout << endl;
        cout << "\n-----------------------------------------------";
        cout << "\n-----------------------------------------------";
        cout << endl << endl;
        if(yn=='Y'||yn=='y')
        {
            goto menu;
        }
        if(yn=='N'||yn=='n')
        {
            goto akhir;
        }
    }
    else if (pilih == 2)
    {
        cout << "\tPengurutan Nama Menggunakan Selection Sort\n\n";
        cout <<"Masukan jumlah data: ";
        cin >> n;
        cout << endl;

        for (i = 0; i < n; i++)
        {
            cout << "Nama ke-" << i+1 << " : ";
            cin >> mhs[i];
        }
        for(i = 0; i < n; i++)
        {
            mins = i;
            for(j=i+1; j<n; j++)
            {
                if(mhs[mins]>mhs[j])
                    mins=j;
            }
            if(mhs[i] != mhs[mins]) 
            {
                temp = mhs[i];
                mhs[i] = mhs[mins];
                mhs[mins] = temp;
            }
        }
        cout << "\n-----------------------------------------------";
        cout << "\nUrutan nama : " << endl;
        cout << endl;
        for(i = 0; i <n; i++)
        {
            cout << mhs[i] << " " << endl;
        }
        cout << "\nUlangi sorting (Y/N)? ";
        cin >> yn;
        cout << endl;
        cout << "\n-----------------------------------------------";
        cout << "\n-----------------------------------------------";
        cout << endl << endl;
        if(yn=='Y'||yn=='y')
        {
            goto menu;
        }
        if(yn=='N'||yn=='n')
        {
            goto akhir;
        }
    }
    else if (pilih == 3)
    {
        cout << "\tPengurutan Nama Menggunakan Insertion Sort\n\n";
        cout << "Masukan jumlah data : ";
        cin >> n;
        cout << endl;
        for (i = 0; i < n; i++)
        {
            cout << "Nama ke-" << i+1 << " : ";
            cin >> mhs[i];
        }
        for(i=1; i<=n-1; i++)
        {
            temp=mhs[i];
            j=i-1;

            while((temp<mhs[j])&&(j>=0))
            {
                mhs[j+1]=mhs[j];
                j=j-1;
            }

            mhs[j+1]=temp;
        }
        cout << "\n-----------------------------------------------";
        cout << "\nUrutan nama : " << endl;
        cout << endl;
        for(i=0; i<n; i++)
        {
            cout << mhs[i] << " " << endl;
        }
        cout << "\nUlangi sorting (Y/N)? ";
        cin >> yn;
        cout << endl;
        cout << "\n-----------------------------------------------";
        cout << "\n-----------------------------------------------";
        cout << endl << endl;
        if(yn=='Y'||yn=='y')
        {
            goto menu;
        }
        if(yn=='N'||yn=='n')
        {
            goto akhir;
        }
    }
    else
    {
        cout <<"Pilihan salah";
    }
    cout << "\n\nMasukkan data lagi (Y/N)? ";
    cin >> yn;
    cout << endl;
    cout << "\n-----------------------------------------------";
    cout << "\n-----------------------------------------------";
    cout << endl << endl;
    if(yn=='Y'||yn=='y')
    {
        goto menu;
    }
    if(yn=='N'||yn=='n')
    {
        goto akhir;
    }

    akhir:
    return 0;
}