#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataBarang
{
    int id;
    char* namaBarang;
    int hargaBarang;
    int jumlahBarang;
    int hargaAkhir;
    struct DataBarang* next;
} DataBarang;

DataBarang* head = NULL;
DataBarang* tail = NULL;

void printAllData()
{

}

void addDataFromHead(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{

}

void addDataFromTail(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{

}

void addDataFromId(int indexId, int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{

}

void editDataFromId()
{

}

void editDataFromPosition()
{

}

void deleteFromId(int id)
{

}

void deleteFromPosition(int position)
{

}

void sortData(int sortOption)
{

}

void freeAllLinkedList()
{

}

void printMenu()
{
    system("cls");
    printf("         .__                     .__                        .__               .__          \n");
    printf("    ____ |__|______   ____  __ __|  | _____ _______    _____|__| ____    ____ |  |   ____  \n");
    printf("  _/ ___\\|  \\_  __ \\_/ ___\\|  |  \\  | \\__  \\\\_  __ \\  /  ___/  |/    \\  / ___\\|  | _/ __ \\ \n");
    printf("  \\  \\___|  ||  | \\/\\  \\___|  |  /  |__/ __ \\|  | \\/  \\___ \\|  |   |  \\/ /_/  >  |_\\  ___/ \n");
    printf("   \\___  >__||__|    \\___  >____/|____(____  /__|    /____  >__|___|  /\\___  /|____/\\___  >\n");
    printf("       \\/                \\/                \\/             \\/        \\//_____/           \\/ \n");
    printf("1. Tampilkan semua data\n");
    printf("2. Tambah data dari head\n");
    printf("3. Tambah data dari tail\n");
    printf("4. Tambah data setelah id tertentu\n");
    printf("5. Edit data berdasarkan id\n");
    printf("6. Edit data berdasarkan posisi\n");
    printf("7. Hapus data berdasarkan id\n");
    printf("8. Hapus data berdasarkan posisi\n");
    printf("9. Urutkan data\n");
    printf("10. Selesai\n");
    printf("Pilihan anda : ");
}

int main()
{
    int inputUser;
    do
    {
        printMenu();
        scanf("%d", &inputUser);
        getchar();

        system("cls");
        if(inputUser > 0 && inputUser >= 10)
        {
            if(inputUser == 1)
            {
                printAllData();
            }
            else if(inputUser == 2)
            {
                int id;
                char* namaBarang = (char*) malloc(11 * sizeof(char));
                int hargaBarang;
                int jumlahBarang;
        
                printf("Masukkan data :\n");
                printf("Id : ");
                scanf("%d", &id);
                getchar();
                printf("Nama Barang : ");
                scanf("%10s", namaBarang);
                getchar();
                printf("Harga Barang : ");
                scanf("%d", &hargaBarang);
                getchar();
                printf("Jumlah Barang : ");
                scanf("%d", &jumlahBarang);
                getchar();
    
                addDataFromHead(id, namaBarang, hargaBarang, jumlahBarang);
                free(namaBarang);
            }
            else if(inputUser == 3)
            {
                int id;
                char* namaBarang = (char*) malloc(11 * sizeof(char));
                int hargaBarang;
                int jumlahBarang;

                printf("Masukkan data :\n");
                printf("Id : ");
                scanf("%d", &id);
                getchar();
                printf("Nama Barang : ");
                scanf("%10s", namaBarang);
                getchar();
                printf("Harga Barang : ");
                scanf("%d", &hargaBarang);
                getchar();
                printf("Jumlah Barang : ");
                scanf("%d", &jumlahBarang);
                getchar();
    
                addDataFromTail(id, namaBarang, hargaBarang, jumlahBarang);
                free(namaBarang);
            }
            else if(inputUser == 4)
            {
                int indexId;
                int id;
                char* namaBarang = (char*) malloc(11 * sizeof(char));
                int hargaBarang;
                int jumlahBarang;
    
                printf("Masukkan id patokan : ");
                scanf("%d", &indexId);
                getchar();
                printf("Masukkan data :\n");
                printf("Id : ");
                scanf("%d", &id);
                getchar();
                printf("Nama Barang : ");
                scanf("%10s", namaBarang);
                getchar();
                printf("Harga Barang : ");
                scanf("%d", &hargaBarang);
                getchar();
                printf("Jumlah Barang : ");
                scanf("%d", &jumlahBarang);
                getchar();
    
                addDataFromId(indexId, id, namaBarang, hargaBarang, jumlahBarang);
                free(namaBarang);
            }
            else if(inputUser == 5)
            {
                editDataFromId();
            }
            else if(inputUser == 6)
            {
                editDataFromPosition();
            }
            else if(inputUser == 7)
            {
                int id;

                printf("Masukkan id : ");
                scanf("%d", &id);
                deleteFromId(id);
            }
            else if(inputUser == 8)
            {
                int position;

                printf("Masukkan posisi : ");
                scanf("%d", &position);
                deleteFromPosition(position);
            }
            else if(inputUser == 9)
            {
                int sortOption;
                do
                {
                    printf("urutkan data berdasarkaan? \n1. id \n2. nama_barang \n3. harga_barang \n4. jumlah_barang \n5. atau harga_akhir\n >> ");
                    scanf("%d", &sortOption);
                    getchar();
                }while(sortOption < 1 || sortOption > 5);
    
                sortData(sortOption);
            }
            else if(inputUser == 10)
            {
                freeAllLinkedList();
                printf("Selesai\n");
                break;
            }
            printf("Tekan tombol apa saja untuk melanjutkan...");
            getchar();
        }


    }while(1);
    return 0;
}