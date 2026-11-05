//We should move all includes into a header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILEBUFF 100
//Preprocessor statments

//in: path to file, out: file ptr
FILE* openfile(char* PATH)
{
  //opens file in read mode
  FILE* fptr = fopen(PATH, "r");

  if (fptr == NULL)
  {
    //Cannot access file.
    printf("Error: Tokeniser couldn't access file.\n");
    return NULL;
  }
  return fptr;
} 

//in: arr of tokens && arr size, out: prints each token 
void tokenDisp(char** tokens, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%s\n", tokens[i]);
  }
}

//in: arr of tokens && token to be added, out: adds token to arr
void addToken(char*** tokens, char* token, int* size)
{
  if (*size >= FILEBUFF)
  {
    //reallocs mem if run out of space in tokens arr
    //we stan natural language processing
    *tokens = realloc(*tokens, sizeof(char*) * (*size + FILEBUFF));
    if (*tokens == NULL)
    {
      //Ran out of mem T.T
      printf("Error: realloc could not allocate more memory.\n");
      return;
    }
  }

  (*tokens)[*size] = token;
  (*size)++;
}

int main(int argc, char* argv[])
{
  /*
  printf("\nargc: %d\n", argc);
  for (int i = 0; i<argc; i++){
    printf("%d: %s\n",i, argv[i]);
  } */
  FILE* file = openfile(argv[1]);

  char* line = malloc(sizeof(char) * FILEBUFF);
  fgets(line, FILEBUFF, file);
  char** tokens = malloc(sizeof(char*) * FILEBUFF);
  int size = 0;


  while (fgets(line, FILEBUFF, file) != NULL)
  {
    char* token = strtok(line, " ");
    while (token != NULL)
    {
      addToken(&tokens, token, &size);
      token = strtok(NULL, " ");
    }
    tokenDisp(tokens, size);
  }
  //tokenDisp(tokens, size);

  //Save my poor memory
  fclose(file);
  free(line);

  // END: tokens arr is double counting some tokens and concatinating others aswell
  //double check size and realloc as it may be upon ptr switch.

  //printf("Input: %s\n", argv[1]);
  return 0;
}
