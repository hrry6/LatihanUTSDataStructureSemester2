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

void printDataBackward()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }
    
    DataBarang* cursor = head->prev;

    printf("+----+-------------+--------------+---------------+-------------+\n");
    printf("| Id | Nama Barang | Harga Barang | Jumlah Barang | Harga Akhir |\n");
    printf("+----+-------------+--------------+---------------+-------------+\n");
    do
    {
        printf("| %-2d | %-11s | %-12d | %-13d | %-11d |\n",cursor->id, cursor->namaBarang, cursor->hargaBarang, cursor->jumlahBarang, cursor->hargaAkhir);
        cursor = cursor->prev;
    }while(cursor != head->prev);
    printf("+----+-------------+--------------+---------------+-------------+\n");
}

void addDataFromHead(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    newData->id = id;
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = jumlahBarang * hargaBarang;
    newData->next = NULL;
    newData->prev = NULL;

    if(head == NULL)
    {
        newData->next = newData;
        newData->prev = newData;
        head = newData;
    }else
    {
        head->prev->next = newData;
        newData->prev = head->prev;
        newData->next = head;
        head->prev = newData;
        head = newData;
    }

    printf("Data berhasil ditambahkan\n");
}

void addDataFromEnd(int id, char* namaBarang, int hargaBarang, int jumlahBarang)
{
    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    newData->id = id;
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = jumlahBarang * hargaBarang;
    newData->next = NULL;
    newData->prev = NULL;

    if(head == NULL)
    {
        newData->next = newData;
        newData->prev = newData;
        head = newData;
    }else
    {
        head->prev->next = newData;
        newData->prev = head->prev;
        newData->next = head;
        head->prev = newData;
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

    DataBarang* cursor = head;

    do
    {
        cursor = cursor->next;

    }while(cursor != head && cursor->id != indexId);

    if(cursor->id != indexId)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    DataBarang* newData = (DataBarang*) malloc(sizeof(DataBarang));
    newData->namaBarang = (char*) malloc(11 * sizeof(char));
    newData->id = id;
    strcpy(newData->namaBarang, namaBarang);
    newData->hargaBarang = hargaBarang;
    newData->jumlahBarang = jumlahBarang;
    newData->hargaAkhir = jumlahBarang * hargaBarang;
    newData->next = cursor->next;
    newData->prev = cursor;

    cursor->next->prev = newData;
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
    }while(cursor->id != id && cursor != head);

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

    printf("Data berhasil diupdate\n");
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

    printf("Data berhasil diupdate\n");
}

void deleteFromId(int id)
{
    if(head == NULL)
    {
        printf("Data kosong\n");
        return;
    }

    DataBarang* cursor = head;
    do{
        cursor = cursor->next;
    }while(cursor != head && cursor->id != id);

    if(cursor->id != id)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    if(cursor == head)
    {
        if(head == head->next) head = NULL;
        else head = head->next;
    }

    DataBarang* dataBefore = cursor->prev;
    dataBefore->next = cursor->next;
    cursor->next->prev = dataBefore;


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

    if(position <= 0) position = 1;

    while(position > 1)
    {
        cursor = cursor->next;
        position--;
    }

    if(cursor == head)
    {
        if(head == head->next) head = NULL;
        else head = head->next;
    }

    DataBarang* dataBefore = cursor->prev;
    dataBefore->next = cursor->next;
    cursor->next->prev = dataBefore;

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
    DataBarang* nextData = NULL;
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

    addDataFromHead(1,"1",1,1);
    addDataFromHead(2,"2",2,2);
    addDataFromHead(3,"3",3,3);
    addDataFromEnd(4,"4",4,4);
    addDataFromEnd(5,"5",5,5);

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