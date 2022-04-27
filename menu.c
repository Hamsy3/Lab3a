#include "menu.h"
int choice_action() {
    int choice_input = 0;
    printf("Please, choose action\n");
    printf ("0. Exit\n");
    printf ("1. Insert element\n");
    printf ("2. Delete element\n");
    printf ("3. Search element\n");
    printf ("4. Print table\n");
    scanf ("%d", &choice_input);
    return choice_input;
}
int menu_action() {
  int choice = 0;
    choice = choice_action();
  if (choice<0 || choice>4) {
      do {
          choice = choice_action();
      } while (choice<0 || choice>4);
  }
  return choice;
}
