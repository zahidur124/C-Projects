#include "testing-module.h"
#include "pantry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name
ERROR_I_have_NOT_yet_completed_the_INTEGRITY_statement
// Name:
// login ID:


//  START OF DANGER ZONE!  DO NOT EDIT ANYTHING IN HERE
// ====================================================

// These are all of the message strings printed by the program.

const char MSG_QUIT[] = "Bye!\n";
const char MSG_CREATE[] = "Pantry created.\n";
const char MSG_DESTROY[] = "Pantry destroyed.\n";
const char MSG_COMMAND[] = "Enter Command: ";
const char MSG_UPDATE[] = "Pantry updated.\n";
const char MSG_COUNT[] = "The Pantry contains %d of ingredient '%s'.\n";

// These are all of the error messages printed by the program.

const char ERR_INVALID[] = "Invalid command.\n";
const char ERR_CREATE[] = "Free current Pantry before creating a new one.\n";
const char ERR_NO_PANTRY[] = "You must create a Pantry first.\n";
const char ERR_REMOVE[] = 
           "You cannot remove %d of '%s', the Pantry only contains %d.\n";
const char ERR_TUT[] = "Tut tut, you forgot to free the Pantry!\n";
const char ERR_AMT[] = "All amounts must be positive integers.\n";

// =================================================
// END OF THE DANGER ZONE.  YOU CAN EDIT THINGS AGAIN


void interactive_pantry_test(void) {
  struct Pantry *p = NULL;

  
  
}
