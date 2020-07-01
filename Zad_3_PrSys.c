  #include <stdio.h>
  #include <string.h>

  int main(int argc, char *argv[])
  {
      if(argc == 2)
      {
          int read,i;
          FILE *stream;
          FILE *newFile;
          char * fileName = argv[1];
          stream = fopen(fileName,"r+");
          newFile = fopen(strcat(fileName,".red"),"w+");
          if(!stream)
          {
              perror("Bug");
          }
          else
          {   fseek(stream, 0L,SEEK_END); // Ustaw pozycje pliku na koncu strumienia
              long int sizeOfFile = ftell(stream);// Podaj dane o wielkosci pliku
              rewind(stream);
              for(int i = 0; i < sizeOfFile; i++){
              read = getc(stream);
              if(i % 3 == 0)
              {
                putc(read, newFile);
                printf("%c",(char)read);
              }
          }
          printf("%lu",sizeof(stream));
          fclose(stream);
          fclose(newFile);


    }
    return 0;

  }
  else
    {
    printf("Bug - ain't no such a file");

  }
  }
