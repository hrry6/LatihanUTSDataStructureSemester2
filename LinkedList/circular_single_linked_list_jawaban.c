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
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;
    printf("+----+-------------+--------------+---------------+-------------+\n");
    printf("| Id | Nama Barang | Harga Barang | Jumlah Barang | Harga Akhir |\n");
    printf("+----+-------------+--------------+---------------+-------------+\n");
    do
    {
        printf("| %-2d | %-11s | %-12d | %-13d | %-11d |\n",cursor->id, cursor->namaBarang, cursor->hargaBarang, cursor->jumlahBarang, cursor->hargaAkhir);
        cursor = cursor->next;
    }while(cursor != head);
    printf("+----+-------------+--------------+---------------+-------------+\n");
}

void addDataFromHead(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->namaBarang = (char*) malloc(11* sizeof(char));
    newData->id = id;
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = hargaBarang * jumlahBarang;
    newData->next = NULL;

    if(head == NULL)
    {
        newData->next = newData;
        head = newData;
    }else
    {
        DataBarang* last = head;
        
        do{
            last = last->next;    
        }while(last->next != head);
    
        last->next = newData;
        newData->next = head;
        head = newData;
    
    }

    printf("Data berhasil ditambahkan\n");
}

void addDataFromTail(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->namaBarang = (char*) malloc(11* sizeof(char));
    newData->id = id;
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = hargaBarang * jumlahBarang;
    newData->next = NULL;

    if(head == NULL)
    {
        newData->next = newData;
        head = newData;
    }else
    {
        DataBarang* last = head;
        
        do{
            last = last->next;    
        }while(last->next != head);
    
        last->next = newData;
        newData->next = head;    
    }

    printf("Data berhasil ditambahkan\n");
}

void addDataFromId(int indexId, int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->namaBarang = (char*) malloc(11* sizeof(char));
    newData->id = id;
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = hargaBarang * jumlahBarang;
    newData->next = NULL;

    DataBarang* cursor = head;
    do
    {
        cursor = cursor->next;
    }while(cursor != head && cursor->id != indexId);

    if(cursor->id != indexId)
    {
        printf("Data tidak ditemukan");
        return;
    }

    newData->next = cursor->next;
    cursor->next = newData;

    printf("Data berhasil ditambahkan\n");
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

    do
    {
        cursor = cursor->next;
    }while(cursor != head && cursor->id != id);

    if(cursor->id != id)
    {
        printf("Data tidak ditemukan\n");
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

    if(position <= 0) position = 1;

    while(position > 1)
    {
        cursor = cursor->next;
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

    printf("Data berhasil diupdate");
}

void deleteFromId(int id)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;
    DataBarang* dataBefore = NULL;

    do
    {
        dataBefore = cursor;
        cursor = cursor->next;
    }while(cursor != head && cursor->id != id);

    if(cursor->id != id)
    {
        printf("Data tidak ditemukan");
        return;
    }

    if(head == cursor)
    {
        if(head->next == head)
        {
            head = NULL;
        }
        else head = cursor->next;
    }

    dataBefore->next = cursor->next;
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
    DataBarang* dataBefore = head;

    do
    {
        dataBefore = dataBefore->next;
    }while(dataBefore->next != head);

    if(position <= 0) position = 1;

    while(position > 1)
    {
        dataBefore = cursor;
        cursor = cursor->next;
        position--;
    }

    if(cursor == head)
    {
        if(head->next == head)
        {
            head = NULL;
        }
        else head = head->next;
    }

    dataBefore->next = cursor->next;

    free(cursor->namaBarang);
    free(cursor);

    printf("Data berhasil dihapus\n");
}

void sortData(int sortOption)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor;
    DataBarang* last = head;
    int swapped;

    do
    {
        cursor = head;
        swapped = 0;

        while(cursor->next != last)
        {
            DataBarang* nextData = cursor->next;
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

    printf("Data berhasil disortir\n");
}

void freeAllLinkedList()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;
    DataBarang* temp = NULL;

    do
    {
        temp = cursor;
        cursor = cursor->next;
        free(temp->namaBarang);
        free(temp);
    }while(cursor != head);

    head = NULL;

    printf("Data berhasil dihapus\n");
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

    addDataFromHead(1, "1", 1, 1);
    addDataFromHead(2, "2", 2, 2);
    addDataFromHead(3, "3", 3, 3);
    addDataFromTail(4, "4", 4, 4);
    addDataFromTail(5, "5", 5, 5);

    do
    {
        printMenu();
        scanf("%d", &inputUser);
        getchar();

        system("cls");
        if(inputUser > 0 && inputUser <= 10)
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