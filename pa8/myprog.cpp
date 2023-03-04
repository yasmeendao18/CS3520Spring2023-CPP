#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_alphabet(char *a) {
  char *p; 
  char current_letter = 'a';
  for (p=a;p<(a+MAX_LETTERS);p++){ //remove ;
    *p = current_letter++;
  }
}  

void reverse_print_alpha(char *b) {
  static int var = 0;
  char *p;
  
  var?(p=NULL):(p=b); //change to p=b
  var *= 1;
  printf("\nReverse alpha...\n");
  initialize_alphabet(p); //change to p
  for (p=(b+MAX_LETTERS-1);p>=b;p--){ //remove ;
    printf("%c ",*p); //change to *p because it used a everytime
    // pointer value wasn't being updated
  }
  printf("\n");
  return ;
}

int main(void) {
  int i = 0; //initiallize i
  while (i++ < 10) { //edit to go to 10
    reverse_print_alpha(alphabet);
  }
}

  

  
