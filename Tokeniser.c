//We should move all includes into a header file
#include <stdio.h>
#define FILEBUFF 100;
FILE* openfile(char* PATH)
{
  FILE* fptr = fopen(PATH, "r");

  if (fptr == NULL)
  {
    printf("Error: Tokeniser couldn't access file.\n");
    return NULL;
  }
  return fptr;
} 

int main(int argc, char* argv[])
{
  /*
  printf("\nargc: %d\n", argc);
  for (int i = 0; i<argc; i++){
    printf("%d: %s\n",i, argv[i]);
  } */
  FILE* file = openfile(argv[1]);

  char* data[FILEBUFF]; //should be a malloc Filebuffer * sizeof(char)...

  //END: Finish writing fgets, write to data and tokenise into a malloc of size FILEBUFF
  //Once reach end of allocated mem call realloc and continue for the dynamic arr
  //Dont be silly 

  //printf("Input: %s\n", argv[1]);
  return 0;
}
