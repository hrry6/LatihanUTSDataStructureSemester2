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
    system("cls");
    if(head == NULL)
    {
        printf("Belum ada data\n");
        printf("Tekan tombol apa saja untuk melanjutkan...");
        getchar();        
        return;
    }

    DataBarang* cursor = head;
    printf("+-----+-------------+--------------+---------------+-------------+\n");
    printf("| Id  | Nama Barang | Harga Barang | Jumlah Barang | Harga Akhir |\n");
    printf("+-----+-------------+--------------+---------------+-------------+\n");

    while(cursor != NULL)
    {
        printf("| %-3d | %-11s | %-12d | %-13d | %-11d |\n", cursor->id, cursor->namaBarang, cursor->hargaBarang,cursor->jumlahBarang, cursor->hargaAkhir);
        cursor = cursor->next;
    }

    printf("+-----+-------------+--------------+---------------+-------------+\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();
}

void addDataFromHead(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->id = id;
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = jumlahBarang * hargaBarang;
    newData->next = NULL;

    if(head == NULL)
    {
        head = newData;
        tail = newData;
        return;
    }

    newData->next = head;
    head = newData;

    printf("Data berhasil ditambahkan\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();
}

void addDataFromTail(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->id = id;
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    strcpy(newData->namaBarang, namaBarang);
    newData->jumlahBarang = jumlahBarang;
    newData->hargaBarang = hargaBarang;
    newData->hargaAkhir = jumlahBarang * hargaBarang;
    newData->next = NULL;

    if(tail == NULL)
    {
        tail = newData;
        head = newData;
        return;
    }

    tail->next = newData;
    tail = newData;

    printf("Data berhasil ditambahkan\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();
}

void addDataFromId(int indexId, int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->id = id;
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    strcpy(newData->namaBarang, namaBarang);
    newData->jumlahBarang = jumlahBarang;
    newData->hargaBarang = hargaBarang;
    newData->hargaAkhir = jumlahBarang * hargaBarang;
    newData->next = NULL;

    DataBarang* cursor = head;
    while(cursor->id != indexId && cursor != NULL)
    {
        cursor = cursor->next;
    }
    
    if(cursor == NULL)
    {
        printf("Data tidak ditemukan\n");
        printf("Tekan tombol apa saja untuk melanjutkan...");
        getchar();
        return;
    }
    newData->next = cursor->next;
    cursor->next = newData;

    printf("Data berhasil ditambahkan\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();
}

void editDataFromId()
{
    DataBarang* cursor = head;
    
    int id;
    printf("Id : ");
    scanf("%d", &id);
    getchar();


    while(cursor->id != id && cursor != NULL)
    {
        cursor = cursor->next;
    }

    if(cursor == NULL)
    {
        system("cls");
        printf("Data tidak ditemukan\n");
        printf("Tekan tombol apa saja untuk melanjutkan...");
        getchar();
        return;
    }

    printf("Nama Barang : %s \n", cursor->namaBarang);
    printf("Harga Barang : %d \n", cursor->hargaBarang);
    printf("Jumlah Barang : %d \n", cursor->jumlahBarang);
    printf("Harga Akhir : %d \n\n", cursor->hargaAkhir);

    printf("Edit data :\n");
    printf("Nama Barang : ");
    scanf("%10s", cursor->namaBarang);
    getchar();
    printf("Harga Barang : ");
    scanf("%d", &cursor->hargaBarang);
    getchar();
    printf("Jumlah Barang : ");
    scanf("%d", &cursor->jumlahBarang);
    getchar();
    cursor->hargaAkhir = cursor->jumlahBarang * cursor->hargaBarang;

    printf("Data berhasil diedit\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();
}

void editDataFromPosition()
{
    DataBarang* cursor = head;
    
    int position;
    printf("Posisi : ");
    scanf("%d", &position);
    getchar();


    while(position != 1)
    {
        cursor = cursor->next;
        if(cursor == NULL)
        {
            system("cls");
            printf("Data tidak ditemukan\n");
            printf("Tekan tombol apa saja untuk melanjutkan...");
            getchar();
            return;         
        }
        position--;
    }

    printf("Nama Barang : %s \n", cursor->namaBarang);
    printf("Harga Barang : %d \n", cursor->hargaBarang);
    printf("Jumlah Barang : %d \n", cursor->jumlahBarang);
    printf("Harga Akhir : %d \n\n", cursor->hargaAkhir);

    printf("Edit data :\n");
    printf("Nama Barang : ");
    scanf("%10s", cursor->namaBarang);
    getchar();
    printf("Harga Barang : ");
    scanf("%d", &cursor->hargaBarang);
    getchar();
    printf("Jumlah Barang : ");
    scanf("%d", &cursor->jumlahBarang);
    getchar();
    cursor->hargaAkhir = cursor->jumlahBarang * cursor->hargaBarang;

    printf("Data berhasil diedit\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();

}

void deleteFromId(int id)
{
    DataBarang* cursor = head;
    DataBarang* temp = NULL;
    while(cursor->id != id && cursor != NULL)
    {
        temp = cursor;
        cursor = cursor->next;
    }

    if(cursor == NULL)
    {
        printf("Data tidak ditemukan\n");
        printf("Tekan tombol apa saja untuk melanjutkan...");
        getchar();
        return;
    }

    if(cursor == head)
    {
        head = cursor->next;
    }
    else
    {
        temp->next = cursor->next;
    }

    if(cursor == tail)
    {
        tail = temp;
    }

    if(head == NULL)
    {
        tail = NULL;
    }

    free(cursor->namaBarang);
    free(cursor);

    printf("Data berhasil dihapus\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();
}

void deleteFromPosition(int position)
{
    DataBarang* cursor = head;
    DataBarang* temp = NULL;
    while(position != 1)
    {
        temp = cursor;
        cursor = cursor->next;
        if(cursor == NULL)
        {
            system("cls");
            printf("Data tidak ditemukan");
            printf("Tekan tombol apa saja untuk melanjutkan...");
            getchar();
            return;
        }
        position--;
    }

    if(cursor == head)
    {
        head = cursor->next;
    }else
    {
        temp->next = cursor->next;
    }

    if(cursor == tail)
    {
        tail = temp;
    }

    if(head == NULL)
    {
        tail = NULL;
    }

    printf("Data berhasil dihapus\n");
    printf("Tekan tombol apa saja untuk melanjutkan...");
    getchar();

    free(cursor->namaBarang);
    free(cursor);
}

void sortData(int sortOption)
{
    if(head == NULL || head->next == NULL)
    {
        return;
    }

    int swapped;
    DataBarang* currentData;
    DataBarang* last = NULL;
    
    do
    {
        swapped = 0;
        currentData = head;

        while(currentData->next != last)
        {
            if((sortOption == 1 && (currentData->id > currentData->next->id)) || (sortOption == 2 && (strcmp(currentData->namaBarang, currentData->next->namaBarang) > 0)) || (sortOption == 3 && (currentData->hargaBarang > currentData->next->hargaBarang)) || (sortOption == 4 && (currentData->jumlahBarang > currentData->next->jumlahBarang)) || (sortOption == 5 && (currentData->hargaAkhir > currentData->next->hargaAkhir)))
            {
                DataBarang* nextData = currentData->next;
                currentData->next = nextData->next;
                nextData->next = currentData;

                if(currentData == head)
                {
                    head = nextData;
                }else
                {
                    DataBarang* prevData = head;
                    while(prevData->next != currentData)
                    {
                        prevData = prevData->next;
                    }
                    prevData->next = nextData;
                }
                currentData = nextData;
                swapped = 1;
            }
            currentData = currentData->next;
        }
        last = currentData;
    }while(swapped);
}

void freeAllLinkedList()
{
    if(head == NULL)
    {
        return;
    }

    DataBarang* cursor = head;
    DataBarang* temp = NULL;
    while(cursor != NULL)
    {
        temp = cursor;
        cursor = cursor->next;
        free(temp->namaBarang);
        free(temp);
    }

    printf("Semua data telah dihapus\n");
}

void printMenu()
{
    system("cls");
    printf("         .__               .__           .__  .__        __              .___ .__  .__          __   \n");
    printf("    _____|__| ____    ____ |  |   ____   |  | |__| ____ |  | __ ____   __| _/ |  | |__| _______/  |_ \n");
    printf("   /  ___/  |/    \\  / ___\\|  | _/ __ \\  |  | |  |/    \\|  |/ // __ \\ / __ |  |  | |  |/  ___/\\   __\\\n");
    printf("   \\___ \\|  |   |  \\/ /_/  >  |_\\  ___/  |  |_|  |   |  \\    <\\  ___// /_/ |  |  |_|  |\\___ \\  |  |  \n");
    printf("  /____  >__|___|  /\\___  /|____/\\___  > |____/__|___|  /__|_ \\___  >____ |  |____/__/____  > |__|  \n");
    printf("       \\/        \\//_____/           \\/               \\/     \\/    \\/     \\/               \\/        \n\n");
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

            system("cls");

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

            system("cls");

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

            system("cls");

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
            system("cls");
            editDataFromId();
        }
        else if(inputUser == 6)
        {
            system("cls");
            editDataFromPosition();
        }
        else if(inputUser == 7)
        {
            int id;
            system("cls");
            printf("Masukkan id : ");
            scanf("%d", &id);
            deleteFromId(id);
        }
        else if(inputUser == 8)
        {
            int position;
            system("cls");
            printf("Masukkan posisi : ");
            scanf("%d", &position);
            deleteFromPosition(position);
        }
        else if(inputUser == 9)
        {
            int sortOption;
            do
            {
                system("cls");
                printf("urutkan data berdasarkaan? \n1. id \n2. nama_barang \n3. harga_barang \n4. jumlah_barang \n5. atau harga_akhir\n >> ");
                scanf("%d", &sortOption);
                getchar();
            }while(sortOption < 1 || sortOption > 5);

            sortData(sortOption);
        }
        else if(inputUser == 10)
        {
            system("cls");
            freeAllLinkedList();
            printf("Selesai\n");
            break;
        }

    }while(1);
    return 0;
}