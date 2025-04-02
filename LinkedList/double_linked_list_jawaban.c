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
DataBarang* tail = NULL;

void printFromHead()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;
    printf("+----+-------------+--------------+---------------+-------------+\n");
    printf("| Id | Nama Barang | Harga Barang | Jumlah Barang | Harga Akhir |\n");
    printf("+----+-------------+--------------+---------------+-------------+\n");
    while(cursor != NULL)
    {
        printf("| %-2d | %-11s | %-12d | %-13d | %-11d |\n",cursor->id, cursor->namaBarang, cursor->hargaBarang, cursor->jumlahBarang, cursor->hargaAkhir);
        cursor = cursor->next;
    }
    printf("+----+-------------+--------------+---------------+-------------+\n");
}

void printFromTail()
{
    if(tail == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = tail;
    printf("+----+-------------+--------------+---------------+-------------+\n");
    printf("| Id | Nama Barang | Harga Barang | Jumlah Barang | Harga Akhir |\n");
    printf("+----+-------------+--------------+---------------+-------------+\n");
    while(cursor != NULL)
    {
        printf("| %-2d | %-11s | %-12d | %-13d | %-11d |\n",cursor->id, cursor->namaBarang, cursor->hargaBarang, cursor->jumlahBarang, cursor->hargaAkhir);
        cursor = cursor->prev;
    }
    printf("+----+-------------+--------------+---------------+-------------+\n");
}

void addDataFromHead(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->id = id;
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = hargaBarang * jumlahBarang;
    newData->next = NULL;
    newData->prev = NULL;

    if(head == NULL)
    {
        head = newData;
        tail = newData;
    }
    else
    {
        newData->next = head;
        head->prev = newData;
        head = newData;
    }

    printf("Data berhasil ditambahkan\n");

}

void addDataFromTail(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->id = id;
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = hargaBarang * jumlahBarang;
    newData->next = NULL;
    newData->prev = NULL;

    if(tail == NULL)
    {
        head = newData;
        tail = newData;
    }
    else
    {
        tail->next = newData;
        newData->prev = tail;
        tail = newData;
    }

    printf("Data berhasil Ditambahkan\n");
}

void addDataFromId(int indexId, int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->id = id;
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = hargaBarang * jumlahBarang;
    newData->next = NULL;
    newData->prev = NULL;

    DataBarang* cursor = head;
    while(cursor != NULL && cursor->id != indexId)
    {
        cursor = cursor->next;
    }

    if(cursor == NULL)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    if(cursor == tail)
    {
        tail = newData;
    }

    cursor->next->prev = newData;
    newData->next = cursor->next;
    newData->prev = cursor;
    cursor->next = newData;
}

void editDataFromId()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

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
        printf("Data todak ditemukan\n");
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

    printf("Data berhasil diupdate");

}

void editDataFromPosition()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;

    int position;
    printf("Posisi : ");
    scanf("%d", &position);
    getchar();

    while(position != 1)
    {
        position--;
        if(cursor->next == NULL)
        {
            printf("Data tidak ditemukan\n");
            return;
        }
        cursor = cursor->next;
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

}

void deleteFromId(int id)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;
    while(cursor != NULL && cursor->id != id)
    {
        cursor = cursor->next;
    }

    if(cursor  == NULL)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    if(cursor == head) head = cursor->next;
    if(cursor == tail) tail = cursor->prev;
    if(cursor->prev != NULL) cursor->prev->next = cursor->next;
    if(cursor->next != NULL) cursor->next->prev = cursor->prev;

    free(cursor->namaBarang);
    free(cursor);

    printf("Data berhasil dihapus\n");
}

void deleteFromPosition(int position)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }
    DataBarang* cursor = head;
    
    while(position != 1)
    {
        if(cursor->next == NULL)
        {
            printf("Data tidak ditemukan\n");
            return;
        }
        cursor = cursor->next;
        position--;
    }

    if(cursor == head) head = cursor->next;
    if(cursor == tail) tail = cursor->prev;
    if(cursor->prev != NULL) cursor->prev->next = cursor->next;
    if(cursor->next != NULL) cursor->next->prev = cursor->prev;

    free(cursor->namaBarang);
    free(cursor);

    printf("Data berhasil dihapus\n");
}

void sortData(int sortOption)
{
    if(head == NULL || head->next == NULL)
    {
        printf("Data tidak cukup untuk disortir\n");
        return;
    }

    DataBarang* cursor = head;
    DataBarang* nextData = NULL;
    DataBarang* last = NULL;
    int swapped;

    do
    {
        cursor = head;
        swapped = 0;

        while(cursor->next != last)
        {
            nextData = cursor->next;
            if((sortOption == 1 && (cursor->id > nextData->id)) || (sortOption == 2 && (strcmp(cursor->namaBarang, nextData->namaBarang) > 0)) || (sortOption == 3 && (cursor->hargaBarang > nextData->hargaBarang)) || (sortOption == 4 && (cursor->jumlahBarang > nextData->jumlahBarang)) || (sortOption == 5 && (cursor->hargaAkhir > nextData->hargaAkhir)))
            {
                //temp = a
                DataBarang* temp = (DataBarang*) malloc(sizeof(DataBarang));
                temp->namaBarang = (char*) malloc(11 * sizeof(char));
                temp->id = cursor->id;
                strcpy(temp->namaBarang, cursor->namaBarang);
                temp->hargaBarang = cursor->hargaBarang;
                temp->jumlahBarang = cursor->jumlahBarang;
                temp->hargaAkhir = cursor->hargaAkhir;

                // a = b
                cursor->id = nextData->id;
                strcpy(cursor->namaBarang, nextData->namaBarang);
                cursor->hargaBarang = nextData->hargaBarang;
                cursor->jumlahBarang = nextData->jumlahBarang;
                cursor->hargaAkhir = nextData->hargaAkhir;

                // b = temp
                nextData->id = temp->id;
                strcpy(nextData->namaBarang, temp->namaBarang);
                nextData->hargaBarang = temp->hargaBarang;
                nextData->jumlahBarang = temp->jumlahBarang;
                nextData->hargaAkhir = temp->hargaAkhir;

                free(temp->namaBarang);
                free(temp);

                swapped = 1;
            }
            cursor = nextData;
        }
        last = cursor;
    }while(swapped);
}

void freeAllLinkedList()
{
    DataBarang* cursor = head;
    DataBarang* temp = NULL;
    while(cursor != NULL)
    {
        temp = cursor;
        cursor = cursor->next;
        free(temp->namaBarang);
        free(temp);
    }
}

void printMenu()
{
    system("cls");
    printf("    .___          ___.   .__           .__  .__        __              .___ .__  .__          __   \n");
    printf("  __| _/____  __ _\\_ |__ |  |   ____   |  | |__| ____ |  | __ ____   __| _/ |  | |__| _______/  |_ \n");
    printf(" / __ |/  _ \\|  |  \\ __ \\|  | _/ __ \\  |  | |  |/    \\|  |/ // __ \\ / __ |  |  | |  |/  ___/\\   __\\\n");
    printf("/ /_/ (  <_> )  |  / \\_\\ \\  |_\\  ___/  |  |_|  |   |  \\    <\\  ___// /_/ |  |  |_|  |\\___ \\  |  |  \n");
    printf("\\____ |\\____/|____/|___  /____/\\___  > |____/__|___|  /__|_  \\___  >____ |  |____/__/____  > |__|  \n");
    printf("     \\/                \\/          \\/               \\/     \\/    \\/     \\/               \\/        \n");
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
                printFromHead();
            }
            else if(inputUser == 2)
            {
                printFromTail();
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
    
                addDataFromHead(id, namaBarang, hargaBarang, jumlahBarang);
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
    
                addDataFromTail(id, namaBarang, hargaBarang, jumlahBarang);
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