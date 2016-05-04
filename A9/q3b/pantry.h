struct Pantry;


// pantry_create() returns a new, empty pantry
// effects: a new pantry is dynamically allocated, called must free 
//          with pantry_destroy
// time: O(1)

struct Pantry *pantry_create(void);


// pantry_destroy(p) frees the dynamically allocated pantry p
// requires: p was created with pantry_create
// effects: p is freed
// time: O(n) where n is the number of ingredients in p

void pantry_destroy(struct Pantry *p);


// pantry_count(p, ing) returns the amount of ingredient ing that remains 
//                      in pantry p
// requires: p is a valid pantry, ing is a string 
// time: O(nm) where n is the number of kinds of ingredients in p 
//             and m is strlen(ing)

int pantry_count(struct Pantry *p, const char *ing);


// pantry_add(p, ing, amt) adds amt of ingredient ing to pantry p
// requires: p is  valid pantry, ing is a string
//           amt > 0
// effects: pantry p is updated
// time: O(nm) where n is the number of kinds of ingredients in p 
//                 and m is strlen(ing)

void pantry_add(struct Pantry *p, const char *ing, int amt);

// pantry_remove(p, ing, amt) removes amt of ingredient ing from pantry p
// requires: p is a valid pantry, ing is a string 
//           there are at least amt of ing in p.
//           amt > 0
// effects: p is updated
// time: O(nm) where n is the number of kinds of ingredients in p 
//             and m is strlen(ing)

void pantry_remove(struct Pantry *p, const char *ing, int amt);
