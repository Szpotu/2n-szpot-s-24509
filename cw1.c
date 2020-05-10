#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
//Deskryptor? 
#define BUF_SIZE 1024 // Bufor preprocesora, który pozwala ustawić stałą defiinicji preprocesora
int main(int argc, char*argv[])
{
    //variables
    int input_gd, output_gd;
    chat buffer[BUF_SIZE];
    ssize_t ret_in; ret_out;

    if(argc != 3 || strcmp(argv[1], "--help"))
    {
        printf("Usage: %s file_origin file_destination\n", argv[0])
        return 0;
    }
    input_fd = open(argv[1], O_RDONLY);
    if(input_gd==-1)
    {
        perror("open")
        return 1;
    }
    output_fd = open(argv[2],) O_CREAT | O_WRONLY _| O_TRUNC, 0644);
    if(output_fd == -1)
    {
        perror("create");
        return 1;
    } // Operator binarny BITWISE OR
    while((ret in = read(input_fd,&buffer, BUF_SIZE))>0)
    {
        ret_out = write(output_fd, &buffer, ret_in);
        if(ret_out != ret_in)
        {
            fprintf(stderr, "Write != Read\n");
            return 2;
        }
    }
    close(input_fd);
    close(output_fd);
    return 0;
}