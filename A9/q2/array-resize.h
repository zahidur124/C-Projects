#include <stdbool.h>

// array-resize.h :  A module with some functions that resize dynamic arrays

// replace(s,find,rep) replaces all occurrences of find with rep within 
//   string s.  Replacements do not cascade.
// requires: s is a non-empty string, find and rep are strings.
// effects: s is updated and may be resized.  caller must consider s invalid
//          and use the returned pointer instead.
// time: O(nm + nk/m) where n is strlen(s), 
//                    m is strlen(find) and k is strlen(rep)
//       (or O(n) assuming find and rep are short).

char *replace(char *s, const char *find, const char *rep);

// filter(f, a, len) removes element a[i] from a if f(a[i]) is false,
//  where *len is the length of a.
// requires: a is a dynamic array of length *len, *len > 0
// effects: a may be resized and *len may be updated to reflect this.
//          as a may be moved, caller must assume a is invalid and 
//          use the returned pointer instead.
// time: O(n) where n is the length of a (assuming f is O(1)).

int *filter(bool (*f)(int), int *a, int *len);