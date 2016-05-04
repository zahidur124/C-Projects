// dyn-arrays.h:  A module with a few functions that create dynmaic arrays

// my_strappend(s1,s2) returns a new dynamically allocated string that 
//   contains the concatenation of s1 and s2.
// requires: s1, s2 are valid strings.
// effects: a new dynamically allocated string is returned, caller must free
// time: O(n) where n is the combined length of s1 and s2

char *my_strappend(const char *s1, const char *s2);


// hex_to_bin(const char *h) returns a new dynamically allocated string
//   that contains the binary representation of the hexadecimal string h.
// requires: h is a valid string representing a hexadecimal number
// effects: a new dynamically allocated string is returned, caller must free
// time: O(n) 

char *hex_to_bin(const char *h);

// hex_to_bin_short(const char *h) returns a new dynamically allocated string
//   that contains the binary representation of the hexadecimal string h.
//   All leading zeroes are removed but the binary string always contains at 
//   least one digit.
// requires: h is a valid string representing a hexadecimal number
// effects: a new dynamically allocated string is returned, caller must free
// time: O(n) 

char *hex_to_bin_short(const char *h);
