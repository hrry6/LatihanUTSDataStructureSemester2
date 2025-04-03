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
    struct DataBarang* prev;
} DataBarang;

DataBarang* head = NULL;

void printDataForward()
{

}

void printDataBackward()
{

}

void addDataFromStart(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{

}

void addDataFromEnd(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
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
    printf("         .__                     .__                     .___          ___.   .__          \n");
    printf("    ____ |__|______   ____  __ __|  | _____ _______    __| _/____  __ _\\_ |__ |  |   ____  \n");
    printf("  _/ ___\\|  \\_  __ \\_/ ___\\|  |  \\  | \\__  \\\\_  __ \\  / __ |/  _ \\|  |  \\ __ \\|  | _/ __ \\ \n");
    printf("  \\  \\___|  ||  | \\/\\  \\___|  |  /  |__/ __ \\|  | \\/ / /_/ (  <_> )  |  / \\_\\ \\  |_\\  ___/ \n");
    printf("   \\___  >__||__|    \\___  >____/|____(____  /__|    \\____ |\\____/|____/|___  /____/\\___  >\n");
    printf("       \\/                \\/                \\/             \\/                \\/          \\/  \n");
    printf("1. Tampilkan semua data dari depan\n");
    printf("2. Tampilkan semua data dari belakang\n");
    printf("3. Tambah data dari head\n");
    printf("4. Tambah data dari tail\n");
    printf("5. Tambah data setelah id tertentu\n");
    printf("6. Edit data berdasarkan id\n");
    printf("7. Edit data berdasarkan posisi\n");
    printf("8. Hapus data berdasarkan id\n");
    printf("9. Hapus data berdasarkan posisi\n");
    printf("10. Urutkan data\n");
    printf("11. Selesai\n");
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
        if(inputUser > 0 && inputUser <= 11)
        {
            if(inputUser == 1)
            {
                printDataForward();
            }
            else if(inputUser == 2)
            {
                printDataBackward();
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
    
                addDataFromStart(id, namaBarang, hargaBarang, jumlahBarang);
                free(namaBarang);
            }
            else if(inputUser == 4)
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
    
                addDataFromEnd(id, namaBarang, hargaBarang, jumlahBarang);
                free(namaBarang);
            }
            else if(inputUser == 5)
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
            else if(inputUser == 6)
            {
                editDataFromId();
            }
            else if(inputUser == 7)
            {
                editDataFromPosition();
            }
            else if(inputUser == 8)
            {
                int id;

                printf("Masukkan id : ");
                scanf("%d", &id);
                deleteFromId(id);
            }
            else if(inputUser == 9)
            {
                int position;

                printf("Masukkan posisi : ");
                scanf("%d", &position);
                deleteFromPosition(position);
            }
            else if(inputUser == 10)
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
            else if(inputUser == 11)
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