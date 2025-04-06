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
    int hash = 0;

    for(int i = 0; i < strlen(nama); i++)
    {
        hash += nama[i];
    }

    return hash %= 100;
}

void tampilkanData()
{
    int id = 0, dataAvailabel = 0;
    printf("+----+--------------+----------+-----+\n");
    printf("| Id | Nama         | Semester | IPK |\n");
    printf("+----+--------------+----------+-----+\n");

    for(int i = 0; i < 100; i++)
    {
        if(data[i] == NULL) continue;
        else
        {
            dataAvailabel = 1;
            DataMahasiswa* cursor = data[i];
            while(cursor != NULL)
            {
                printf("| %-2d | %-12s | %-8d | %-4.2f |\n", ++id, cursor->nama, cursor->semester, cursor->ipk);
                cursor = cursor->next;
            }
        }
    }
    if(dataAvailabel == 0) printf("|            Data Kosong             |\n");

    printf("+----+--------------+----------+-----+\n");
}

void tambahData(char* nama, int semester, float ipk)
{
    DataMahasiswa* newData = (DataMahasiswa*) malloc(sizeof(DataMahasiswa));
    newData->nama = (char*) malloc(10 * sizeof(char));    
    strcpy(newData->nama, nama);
    newData->semester = semester;
    newData->ipk = ipk;
    newData->next = NULL;

    int hash = hashData(nama);

    if(data[hash] == NULL)
    {
        data[hash] = newData;
    }else
    {
        DataMahasiswa* cursor = data[hash];
        while(cursor->next != NULL)
        {
            cursor = cursor->next;
        }
        cursor->next = newData;
    }
}

void editData()
{
    char* nama = (char*) malloc(10 * sizeof(char));
    printf("Masukkan nama : ");
    scanf("%s", nama);
    getchar();
    int hash = hashData(nama);

    if(data[hash] == NULL)
    {    
        printf("Data tidak ditemukan\n");
    }
    else{
        DataMahasiswa* cursor = data[hash];
        while(strcmp(cursor->nama, nama) != 0 && cursor != NULL)
        {
            cursor = cursor->next;
        }
        
        if(cursor == NULL)
        {
            printf("Data tidak ditemukan\n");
        }else
        {
            printf("Nama : %s\n", cursor->nama);
            printf("Semester : %d\n", cursor->semester);
            printf("IPK : %.2f\n\n", cursor->ipk);

            printf("Masukkan data baru :\n");
            printf("Masukkan semester : ");
            scanf("%d", &cursor->semester);
            getchar();
            printf("Masukkan IPK : ");
            scanf("%f",&cursor->ipk);
            getchar();
        }
    }
    free(nama);
}

void hapusData(char* nama)
{
    int hash = hashData(nama);

    if(data[hash] == NULL)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    DataMahasiswa* cursor = data[hash];
    DataMahasiswa* temp = NULL; 
    while(strcmp(cursor->nama, nama) != 0 && cursor != NULL)
    {
        temp = cursor;
        cursor = cursor->next;
    }

    if(cursor == NULL)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    if(cursor == data[hash])
    {
        data[hash] = cursor->next;
    }else
    {
        temp->next = cursor->next;
    }

    free(cursor->nama);
    free(cursor);

    printf("Data berhasil dihapus\n");
}

void hapusSemuaData()
{
    for(int i = 0; i < 100; i++)
    {
        if(data[i] == NULL) continue;
        else
        {
            DataMahasiswa* cursor = data[i];
            DataMahasiswa* temp = NULL;
            while(cursor != NULL)
            {
                temp = cursor;
                cursor = cursor->next;
                free(temp->nama);
                free(temp);
            }
        }
    }

    printf("Data telah dibersihkan\n");
}

void printMenu()
{
    system("cls");
    printf("     ___ ___               .__        _____                 \n");
    printf("    /   |   \\_____    _____|  |__    /     \\ _____  ______  \n");
    printf("   /    ~    \\__  \\  /  ___/  |  \\  /  \\ /  \\\\__  \\ \\____ \\ \n");
    printf("   \\    Y    // __ \\_\\___ \\|   Y  \\/    Y    \\/ __ \\|  |_> >\n");
    printf("    \\___|_  /(____  /____  >___|  /\\____|__  (____  /   __/ \n");
    printf("          \\/      \\/     \\/     \\/         \\/     \\/|__|    \n\n");
    printf("1. Tampilkan Semua Data\n");
    printf("2. Tambah Data\n");
    printf("3. Edit Data\n");
    printf("4. Hapus Data\n");
    printf("5. Selesai\n");
    printf("Opsi >> ");
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