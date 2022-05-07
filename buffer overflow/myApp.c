#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool thereIsUser(char * fileName,char * realPassword ){
   FILE *fp_userName; 
   fp_userName = fopen(fileName, "r");
    if (!fp_userName)
    {
       return 0;
    }
    fscanf(fp_userName, "%s", realPassword);
    fclose(fp_userName);
    return true;
}

void readPassFromFiles(){
     FILE *fp_noy, *fp_adi; 
    fp_adi = fopen("passwords/adi.txt", "r");
    fp_noy = fopen("passwords/noy.txt", "r");
    char noyPass[20], adiPass[20];
    fscanf(fp_adi, "%s", adiPass);
    fscanf(fp_noy, "%s", noyPass);
    printf("\nAdi user: %s\nNoy user: %s", adiPass,noyPass);
    printf("\n");
    fclose(fp_adi);
    fclose(fp_noy);

}
void showPasswords(){
    printf("~~~~~~~~~~~~~~~~~~~~Users Passwords~~~~~~~~~~~~~~~~~~~~");
    readPassFromFiles();
}
int login(){
    bool suc = false;
    char password[8] = {0};
    char fileName[32] ="passwords/";
    char end[5] = ".txt";
    char userName[8] = {0};

    char realPassword[8] = {0};
    printf("Enter User name:");

    gets(userName);
    strcat(strcat(fileName, userName), end);

    bool final=thereIsUser(fileName,realPassword);
    
    if(!final){
        printf("user not found");
        return false;
    }
    
    printf("Enter password:");
    gets(password);    
    
    if (strcmp(realPassword, password) == 0)
    {
        suc = true;
        printf("success\n");
        return 0;
    }

    if (suc)
    {
        printf("success\n");
        return 0;
    }

    printf("not sucess\n");

}

int main(int argc, char const *argv[])
{
   login();
    return 0;
}
