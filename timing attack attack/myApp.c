#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

bool my_strcmp(char *realPassword,char const* password){
    for(int i=0; *realPassword ; i++){
        if( *realPassword++ != *password++ ){
            return false;
        }
        sleep(1);
    }
    return !*realPassword && !*password;
}


int login(char const* password){
    bool suc = false;
    char realPassword[8] = {0};

    FILE *fp_password; 

   fp_password = fopen("password.txt", "r");
    fscanf(fp_password, "%s", realPassword);
    
    
    if (my_strcmp(realPassword, password))
    {
        sleep(2);
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
    if(argc == 2){
        login(argv[1]);
    }
    return 0;
}