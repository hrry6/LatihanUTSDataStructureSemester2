#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataMahasiswa
{
    char* nama;
    int semester;
    float ipk;
    struct DataMahasiswa* next;
} DataMahasiswa;

DataMahasiswa* data[100] = {NULL};

int hashData(char* nama)
{

}

void tampilkanData()
{

}

void tambahData(char* nama, int semester, float ipk)
{

}

void editData()
{

}

void hapusData(char* nama)
{

}

void hapusSemuaData()
{

}

void printMenu()
{

}

int main()
{
    int opsiUser;

    tambahData("Harry", 2, 4);
    tambahData("Hesa", 2, 4);
    tambahData("Jensen", 2, 4);
    tambahData("Gabe", 2, 4);
    tambahData("Olav", 2, 4);


    do
    {
        printMenu();
        scanf("%d", &opsiUser);
        getchar();

        system("cls");

        if(opsiUser == 1)
        {
            tampilkanData();
        }
        else if(opsiUser == 2)
        {
            char* nama = (char*) malloc(10 * sizeof(char));
            int semester;
            float ipk;

            printf("Tambah Data :\n");
            printf("Masukkan nama : ");
            scanf("%[^\n]", nama);
            getchar();
            printf("Masukkan semester : ");
            scanf("%d", &semester);
            getchar();
            printf("Masukkan IPK : ");
            scanf("%f",&ipk);
            getchar();

            tambahData(nama, semester, ipk);
            free(nama);
        }
        else if(opsiUser == 3)
        {
            editData();
        }
        else if(opsiUser == 4)
        {
            char* nama = (char*) malloc(10 * sizeof(char));
            printf("Masukkan nama yang ingin dihapus : ");
            scanf("%[^\n]", nama);
            getchar();

            hapusData(nama);
            free(nama);
        }
        else if(opsiUser == 5)
        {
            hapusSemuaData();
            printf("Selesai\n");
            break;
        }

        printf("Tekan tombol untuk melanjutkan\n");
        getchar();

    }while(1);

    return 0;
}