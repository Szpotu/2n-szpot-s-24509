
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    DIR *ls_direction;
    int id = fork();
    if (id == -1)
    {
        perror("Fork");
    }

    if(id == 0) // Child
    {
        ls_direction = opendir("/usr/bin");
        if(ls_direction == NULL)
        {
            perror("No such a directory or unable to open");
        }
        char *const arguments[] = {"/bin/ls","-a", NULL};
        printf("Child / By execvp");
        execv("/bin/ls",arguments);
        //Fuction "system ls? Why not? //
	//Just like: 
	// int i;
	//i = system("ls"); OR char commandLs[50]; system(commandLs);
        printf("exited, status: %d\n", WEXITSTATUS(id));
        exit(0);
    }
    else // Parent
    {
        printf("Parent / Child executed completely");
    }
    wait(&id);
    printf("Child process passed well");
    return 0;

}
