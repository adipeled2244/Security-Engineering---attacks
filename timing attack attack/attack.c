#include <stdio.h>
#include <time.h>
#include <sys/types.h> 
#include <unistd.h> //execl   
#include <sys/wait.h> 
#include <stdlib.h>

#define chars  "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ0123456789"

int main(int argc, char const *argv[])
{
    int curIndexPass,currIndexChars = 0;
    time_t lastTimeAttempt = 0;    

    char password[10] = {0};
    
    for (curIndexPass; curIndexPass < 10 && currIndexChars <  sizeof(chars);)
    {     
        pid_t pid = fork();
        if (pid == 0)
        {   /* child  */
            printf("Hacker> %s\n", password);
            execl("myApp.exe", "myApp.exe", password); 
            exit(1);                                   
        }
        else
        {   /* parent  */

            // calculate time start and end 
            time_t startOfMeasurment = time(0);
            waitpid(pid, 0, 0);
            time_t endOfMeasurment = time(0);

            
            if ( lastTimeAttempt > (endOfMeasurment - startOfMeasurment)){
                password[curIndexPass] = 0;
                break;
            }
            else if (lastTimeAttempt == (endOfMeasurment - startOfMeasurment)){
                password[curIndexPass] = chars[currIndexChars++];
            }
            else{
                lastTimeAttempt = endOfMeasurment - startOfMeasurment;
                currIndexChars = 0;
                password[++curIndexPass] = chars[currIndexChars++];
            }
        }
    }

    printf("\nI know your password ^_^ ~~~~~~~~~~~~~~~> %s\n", password);
    return 0;
}