#include<stdio.h>
#include<string.h>
#define MAX_CONTACTS 100
struct Contact{
    char name[50];
    char phone[15];
};

struct Contact contactList[MAX_CONTACTS];
int contactCount = 0;
void displayMenu(){
    printf("************ MENU ****************\n");
    printf("1. Toan bo danh sach lien he\n");
    printf("2. bo sung lien he moi\n");
    printf("3. cap nhat thong tin lien he\n");
    printf("4. Xoa lien he\n");
    printf("5. sap xep danh sach lien he\n");
    printf("6. Tim kiem theo ten lien he\n");
    printf("7. tim kiem theo trang thai\n");
    printf("0. Thoat chuong trinh\n");
    printf("*********************************\n");
}

void displayAllContacts(){
    printf("Danh sach lien he:\n");
    for(int i = 0; i < contactCount; i++){
        printf("Ten lien he la:%s\nSo dien thoai la:%s\n", contactList[i].name, contactList[i].phone);
    }
}

void addNewContact(){
    struct Contact newContact;
    printf("Nhap ten lien he: ");
    scanf("%s", newContact.name);
    printf("Nhap so dien thoai: ");
    scanf("%s", newContact.phone);
    contactList[contactCount++] = newContact;
    printf("Lien he da duoc them.\n");
}

void updateContact(){
    char searchName[50];
    printf("Nhap ten lien he muon chinh sua: ");
    scanf("%s", searchName);
    int foundIndex = -1;
    for(int i = 0; i < contactCount; i++){
        if(strcmp(contactList[i].name, searchName) == 0){
            foundIndex = i;
            break;
        }
    }
    if(foundIndex != -1){
        printf("Nhap thong tin moi cho lien he:\n");
        printf("Nhap ten lien he: ");
        scanf("%s", contactList[foundIndex].name);
        printf("Nhap so dien thoai: ");
        scanf("%s", contactList[foundIndex].phone);
        printf("Thong tin lien he duoc cap nhap.\n");
    } else{
        printf("khong tim thay lien he.\n");
    }
}

void deleteContact(){
    char deleteName[50];
    printf("Nhap ten lien he muon xoa: ");
    scanf("%s", deleteName);
    int foundIndex = -1;
    for(int i = 0; i < contactCount; i++){
        if(strcmp(contactList[i].name, deleteName) == 0){
            foundIndex = i;
            break;
        }
    }
    if(foundIndex != -1){
        for(int i = foundIndex; i < contactCount - 1; i++){
            contactList[i] = contactList[i + 1];
        }
        contactCount--;
        printf("Lien he da duoc xoa.\n");
    } else{
        printf("Khong tim thay lien he.\n");
    }
}

void bubbleSortContacts(){
    for(int i = 0; i < contactCount - 1; i++){
        for(int j = 0; j < contactCount - i - 1; j++){
            if(strcmp(contactList[j].name, contactList[j + 1].name) > 0){
                struct Contact temp = contactList[j];
                contactList[j] = contactList[j + 1];
                contactList[j + 1] = temp;
            }
        }
    }
    printf("danh sach lien he duoc sap xep.\n");
}

int main(){
    int choice;
    do {
        displayMenu();
        printf("lua chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                displayAllContacts();
                break;
            case 2:
                addNewContact();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                bubbleSortContacts();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("lua chon khong hop ly, vui long chon lai.\n");
        }
    } while (choice != 0);
    return 0;
}

