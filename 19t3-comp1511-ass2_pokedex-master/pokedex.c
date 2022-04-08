// Assignment 2 19T3 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Joshua Denison Chung Sy (z5259375)
// on 24-11-2019
// 
// Version 2.0.4: Release
// pokedex.c contains the functions for main.c to work. This allows to pokedex 
// to run. There are multiple functions for different commands of pokedex. 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Note you are not allowed to use <string.h> in this assignment
// There are some techniques we would like you to learn to code
// that the string library trivialises.

// ----------------------------------------------
// Add any extra #includes your code needs here.
// ----------------------------------------------

#include "pokedex.h"


// ----------------------------------------------
// Add your own #defines here.
// ----------------------------------------------
# define TRUE 1
# define FALSE 0

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.
struct pokedex {
    struct pokenode *head;
    struct pokenode *curr;
    //For stage 3
    struct pokenode *poketypes;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
//
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.
struct pokenode {
    Pokemon pokemon;
    int found;
    int recently_found;
    struct pokenode *next;
    //For stage 4
    struct pokenode *evolve;
};


// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------




// ----------------------------------------------
// Add prototypes for your own functions here.
// ----------------------------------------------
void print_pokemon_type(int type); 
static int compare_types(int type, Pokedex pokedex);
static int explore_compare_types(int type, Pokedex pokedex);
static void print_ID(int id);
// Creates a new pokenode struct and returns a pointer to it.
static struct pokenode *new_pokenode(Pokemon pokemon);
static int compare_strings(Pokemon pokemon, char *text);


// You need to implement the following functions in their stages.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


// Creates a new Pokedex, and returns a pointer to it.
// Note: you will need to modify this function.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex pokedex = malloc(sizeof(struct pokedex));
    assert(pokedex != NULL);

    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    pokedex->head = NULL;

    // TODO: Add your own code here.

    return pokedex;
}

// Create a new pokenode struct and returns a pointer to it.
//
// This function should allocate memory for a pokenode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct pokenode *new_pokenode(Pokemon pokemon) {
    struct pokenode *new = malloc(sizeof(struct pokenode));
    new->pokemon = pokemon;
    new->found = FALSE;
    new->recently_found = FALSE;
    return new;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    // Note: you should use the new_pokenode function here, and add
    // the newly-created pokenode to the end of the linked list of
    // pokenodes in the Pokedex.
    struct pokenode *id_checker = pokedex->head;
    struct pokenode *new = new_pokenode(pokemon);
    struct pokenode *curr = pokedex->head;
    // Checks if the a Pokemon with the same ID has already been entered
    while (id_checker != NULL) {
        if (pokemon_id(new->pokemon) == pokemon_id(id_checker->pokemon)) {
            fprintf(stderr, "There's already a pokemon with the same ID!\n");
            exit(1);
        }
        id_checker = id_checker->next;
    }    
    // If there are no pokemon in the pokedex, sets the new pokemon to head
    if (curr == NULL) {
        pokedex->head = new;
        pokedex->curr = new;
        curr = pokedex->head;
        curr->next = NULL;
        curr->evolve = NULL;
    }
    // Adds new pokemon to end of linked list 
    else {
        while (curr->next!= NULL) {
            curr= curr->next;
        }
        curr->next = new; 
        curr = curr->next;
        curr->next = NULL;
        curr->evolve = NULL;  
    }
}

// Print out the details of the currently selected Pokemon.
void detail_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *selected_pokemon; 
        selected_pokemon = pokedex->curr;
        // Detail Pokemon for Pokemon that has not been found
        if (selected_pokemon->found == FALSE) {
            printf("ID: ");
            print_ID(pokemon_id(selected_pokemon->pokemon));
            printf("\n");
            printf("Name: ");
            char *name_array = pokemon_name(selected_pokemon->pokemon);
            int i = 0;
            while (name_array[i] != '\0') {
                printf("*");
                i++;
            }
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n"); 
            printf("Type: --\n");  
        }
        // Detail Pokemon for Pokemon that has been found
        else {
            printf("ID: ");
            print_ID(pokemon_id(selected_pokemon->pokemon));
            printf("\n"); 
            printf("Name: %s\n",pokemon_name(selected_pokemon->pokemon));
            printf("Height: %.1lfm\n",pokemon_height(selected_pokemon->pokemon));
            printf("Weight: %.1lfkg\n",pokemon_weight(selected_pokemon->pokemon)); 
            printf("Type: %s ", pokemon_type_to_string(pokemon_first_type
            (selected_pokemon->pokemon)));
            if (pokemon_second_type(selected_pokemon->pokemon) != 0) {
                printf("%s", pokemon_type_to_string(pokemon_second_type
                (selected_pokemon->pokemon)));
            }
            printf("\n");
        }
    }
}


// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        fprintf(stderr, "exiting because there are no pokemon in the pokedex\n");
        exit(1);
    }
    else { 
        return pokedex->curr->pokemon;   
    }
}

// Sets the currently selected Pokemon to be 'found'.
void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *selected_pokemon; 
        selected_pokemon = pokedex->curr;
        selected_pokemon->found = TRUE;
        selected_pokemon->recently_found = TRUE;
    }
}

// Print out all of the Pokemon in the Pokedex.
void print_pokemon(Pokedex pokedex) {
    struct pokenode *curr;
    curr = pokedex->head;
    while (curr != NULL) {
        // Prints arrow if pokemon is selected
        if (curr == pokedex->curr) {
            printf("--> ");
        }
        // Prints space if pokemon is not selected
        else {
            printf("    ");
        }
        // Print Pokemon if Pokemon is found    
        if (curr->found == TRUE) {
            printf("#");
            print_ID(pokemon_id(curr->pokemon));
            printf(": "); 
            printf("%s\n",pokemon_name(curr->pokemon)); 
            curr = curr->next;
        }
        // Print Pokemon if Pokemon is not found    
        else {
            printf("#");
            print_ID(pokemon_id(curr->pokemon));
            printf(": "); 
            char *name_array = pokemon_name(curr->pokemon);
            int i = 0;
            while (name_array[i] != '\0') {
                printf("*");
                i++;
            }
            printf("\n");
            curr = curr->next;
        }
    }
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        if (pokedex->curr->next!=NULL) {
            pokedex->curr = pokedex->curr->next;
        }
    }
}

// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *curr;
        struct pokenode *prev;
        curr = pokedex->head;
        prev = pokedex->head; 
        while (curr != pokedex->curr) {
            if (curr != pokedex->head) {
                prev = curr;
            }
            curr = curr->next;
        }
        pokedex->curr = prev;
    }
}
// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void change_current_pokemon(Pokedex pokedex, int id) {
    if (pokedex->head != NULL) {
        struct pokenode *curr;
        curr = pokedex->head;
        int stop_looping = FALSE;
        while (stop_looping == FALSE) {
            if (curr == NULL) {
                stop_looping = TRUE;
            }
            else if (pokemon_id(curr->pokemon) == id) {
                stop_looping = TRUE;
            }
            if (stop_looping == 0) {
                curr = curr->next;
            }
        }
        if (curr != NULL) {
            pokedex->curr = curr;
        }
    }
}
// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *remove = pokedex->curr;
        struct pokenode *prev = pokedex->head;
        struct pokenode *evolve_checker = pokedex->head;
        while (evolve_checker != NULL) {
            if (evolve_checker->evolve == remove) {
                evolve_checker->evolve = NULL;
            }
            evolve_checker = evolve_checker->next;
        }
        //head is being removed next is NULL i.e one element in linked list
        if (pokedex->curr == pokedex->head) {
            if (pokedex->head->next == NULL) {
                destroy_pokemon(remove->pokemon); 
                free(remove);
                pokedex->head = NULL;
                pokedex->curr = NULL;
            }
            //head is being removed and there are more than one element in linked list 
            else {
                pokedex->head = pokedex->head->next;
                pokedex->curr = pokedex->head;
                destroy_pokemon(remove->pokemon); 
                free(remove);
            }
        } else {
            while (prev->next != remove) {
                prev = prev->next;
            }
            // removing pokenode at the end of the list
            if (remove->next == NULL) {
                prev->next = NULL;
                pokedex->curr = prev;
                destroy_pokemon(remove->pokemon);  
                free(remove);
            }
            // removing pokenode in the middle of the list
            else {
                prev->next = remove->next;
                pokedex->curr = prev->next;
                destroy_pokemon(remove->pokemon); 
                free(remove);
            }
        }
    }
}

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *destroy; 
        pokedex->curr = pokedex->head->next; 
        destroy = pokedex->curr;
        while (pokedex->curr != NULL) {
            pokedex->curr = pokedex->curr->next;
            destroy_pokemon(destroy->pokemon); 
            free(destroy);
            destroy = pokedex->curr;
        }
        destroy_pokemon(pokedex->head->pokemon); 
        free(pokedex->head);
    }
    free(pokedex);
    // Note: there is no fprintf or exit(1) in this function, as the
    // Stage 1 autotests call destroy_pokedex but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1, rather than exit).
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////

// Print out all of the different types of Pokemon in the Pokedex.
void show_types(Pokedex pokedex) {
    struct pokenode *curr; 
    curr = pokedex->head;
    pokedex->poketypes = pokedex->head; 
    int first_type = 0;
    int second_type = 0;    
    while (curr != NULL) {
        first_type = pokemon_first_type(curr->pokemon);
        second_type = pokemon_second_type(curr->pokemon);
        if (compare_types(first_type, pokedex) == TRUE) {
            printf("%s\n", pokemon_type_to_string(pokemon_first_type(curr->pokemon)));
        }
        if (compare_types(second_type, pokedex) == TRUE) {
            printf("%s\n", pokemon_type_to_string(pokemon_second_type(curr->pokemon)));
        }
        curr = curr->next;
        pokedex->poketypes = curr;
    }
    pokedex->poketypes = pokedex->head;  
}

// Set the first not-yet-found Pokemon of each type to be found.
void go_exploring(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    pokedex->poketypes = pokedex->head; 
    int first_type = 0;
    int second_type = 0; 
    while (curr != NULL) {
        if (curr->found == FALSE) {
            first_type = pokemon_first_type(curr->pokemon);
            second_type = pokemon_second_type(curr->pokemon);
            if (explore_compare_types(first_type, pokedex) == TRUE) {
                curr->found = 1;
            }
            if (explore_compare_types(second_type, pokedex) == TRUE) {
                curr->found = 1;
            }
        }
        curr = curr->next;
        pokedex->poketypes = curr;
    }
    // Sets all pokemon that are found to be recently found
    pokedex->poketypes = pokedex->head; 
    curr = pokedex->head;
    while (curr != NULL) {
        if (curr->found == TRUE) {
            curr->recently_found = TRUE;
        }
        curr = curr->next;
    }  
}

// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    int pokemon_count = 0;
    struct pokenode *curr;
    curr = pokedex->head;
        
    while (curr != NULL) {
        pokemon_count++;
        curr = curr->next;  
    }
    return pokemon_count;
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int found_count = 0;
    struct pokenode *curr;
    curr = pokedex->head;
        
    while (curr != NULL) {
        if (curr->found == TRUE) {
            found_count++;
        }
        curr = curr->next;
    }
    return found_count;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    if (pokedex->head == NULL) {
        fprintf(stderr, "Invalid Pokemon Evolution!\n");
        exit(1);
    }
    else {
        struct pokenode *before = pokedex->head;
        struct pokenode *after = pokedex->head;
        // Looks for Pokemon with from_id
        int stop_looping = FALSE;
        while (stop_looping == FALSE) {
            if (before == NULL) {
                stop_looping = TRUE;
            } else if (pokemon_id(before->pokemon) == from_id) {
                stop_looping = TRUE;
            }
            if (stop_looping == FALSE) {
                before = before->next;
            }
        }
        // Looks for Pokemon with to_id
        stop_looping = FALSE;
        while (stop_looping == FALSE) {
            if (after == NULL) {
                stop_looping = TRUE;
            } else if (pokemon_id(after->pokemon) == to_id) {
                stop_looping = TRUE;
            }
            if (stop_looping == FALSE) {
                after = after->next;
            }
        }
        // Adds the evolution
        if (before != NULL && after != NULL) {
            before->evolve = after;
        }
        // Else exits the program
        if (before == NULL || after == NULL) {
            fprintf(stderr, "Invalid Pokemon Evolution!\n");
            exit(1);    
        }
    }
}

// Show the evolutions of the currently selected Pokemon.
void show_evolutions(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *curr = pokedex->curr;
        while (curr != NULL) {
            // For Pokemon that has been found
            if (curr->found == TRUE) {
                if (curr != pokedex->curr) {
                    printf("--> ");
                }
                printf("#");
                print_ID(pokemon_id(curr->pokemon));
                printf("%s ",pokemon_name(curr->pokemon)); 
                printf("[%s", pokemon_type_to_string(pokemon_first_type
                                (curr->pokemon)));
                if (pokemon_second_type(curr->pokemon) != 0) {
                    printf(", %s", pokemon_type_to_string(pokemon_second_type
                                (curr->pokemon)));
                }
                printf("] ");
            }
            // For Pokemon that has not been found
            else {
                if (curr != pokedex->curr) {
                    printf("--> ");
                }
                printf("#");
                print_ID(pokemon_id(curr->pokemon));
                printf(" ???? "); 
                printf("[????] ");
            }
            curr = curr->evolve;
        }
        printf("\n");
    }
}

// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
int get_next_evolution(Pokedex pokedex) {
    struct pokenode *select = pokedex->curr;
    if (pokedex->head == NULL) {
        fprintf(stderr, "The Pokedex is empty\n");
        exit(1);
    } else if (select->evolve == NULL) {
        return DOES_NOT_EVOLVE;
    }
    else { 
        select = pokedex->curr->evolve;
        return pokemon_id(select->pokemon);   
    }
    return DOES_NOT_EVOLVE;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                        //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    struct pokedex *same_type = malloc(sizeof(struct pokedex));
    struct pokenode *original = pokedex->head;
    same_type->head = NULL; 
    while (original != NULL) {
        if (original->found == TRUE) {
            // Checks if the Pokemon has the same type as type being searched
            if (pokemon_first_type(original->pokemon) == type ||
                pokemon_second_type(original->pokemon) == type) {
                add_pokemon(same_type, clone_pokemon(original->pokemon));
                int total_same_type = count_total_pokemon(same_type);
                int i = 0;
                while (i < total_same_type) { 
                    find_current_pokemon(same_type);
                    next_pokemon(same_type);
                    i++;
                }
                same_type->curr = same_type->head;
            }
        }
        original = original->next;
    }
    return same_type;
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    struct pokedex *found_pokedex = malloc(sizeof(struct pokedex));
    struct pokedex *temp_pokedex = malloc(sizeof(struct pokedex));
    struct pokenode *original = pokedex->head; 
    temp_pokedex->head = NULL;
    found_pokedex->head = NULL;
    // Adds the found Pokemon from original pokedex to a temporary Pokedex
    // Temporary Pokedex is unordered
    while (original != NULL) {
        if (original->found == TRUE) {
            add_pokemon(temp_pokedex, clone_pokemon(original->pokemon));
        }
        original = original->next;
        temp_pokedex->curr = temp_pokedex->head;
    }
    // Adds pokemon from temporary Pokedex to found_pokedex
    // Pokemon in found pokedex are ordered
    while (temp_pokedex->head != NULL) {
        struct pokenode *curr_minimum = temp_pokedex->head;
        struct pokenode *temp_curr = temp_pokedex->head;
        while (temp_curr != NULL) {
            if (temp_pokedex->head->next == NULL) {
                curr_minimum = temp_curr;
            }
            else if (pokemon_id(curr_minimum->pokemon) > pokemon_id(temp_curr->pokemon)) {
                curr_minimum = temp_curr;
            }
            temp_curr = temp_curr->next; 
        }
        add_pokemon(found_pokedex, clone_pokemon(curr_minimum->pokemon));
        temp_pokedex->curr = curr_minimum;
        remove_pokemon(temp_pokedex);
    }
    int total_found_pokedex = count_total_pokemon(found_pokedex);
    int i = 0;
    while (i < total_found_pokedex) { 
        find_current_pokemon(found_pokedex);
        next_pokemon(found_pokedex);
        i++;
    }
    destroy_pokedex(temp_pokedex);
    found_pokedex->curr = found_pokedex->head;
    return found_pokedex;
}
// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    struct pokedex *search_pokedex = malloc(sizeof(struct pokedex));
    struct pokenode *original = pokedex->head;
    search_pokedex->head = NULL;
    while (original != NULL) {
        if (original->found == 1) {
            if (compare_strings(original->pokemon, text) == 1) {
                add_pokemon(search_pokedex, clone_pokemon(original->pokemon));
                int search_pokemon_count = count_total_pokemon(search_pokedex);
                int i = 0;
                while (i < search_pokemon_count) { 
                    find_current_pokemon(search_pokedex);
                    next_pokemon(search_pokedex);
                    i++;
                }
                search_pokedex->curr = search_pokedex->head;
            }
        }
        original = original->next;
    }
    if (pokedex->head == NULL) {
        pokedex = search_pokedex;
    }
    return search_pokedex;
}

// Add definitions for your own functions here.
// Make them static to limit their scope to this file.

// Compares the type of the Pokemon for show_types and returns TRUE
// if Pokemon type has not been seen before
static int compare_types(int type, Pokedex pokedex) {
    if (type == 0) {
        return FALSE;
    }
    struct pokenode *curr;
    curr = pokedex->head;
    struct pokenode *selected;
    selected = pokedex->poketypes;
    int checker = TRUE;   
    while (curr != selected) {
        if (pokemon_first_type(curr->pokemon) == type) {
            checker = FALSE;
        }
        if (pokemon_second_type(curr->pokemon) == type) {
            checker = FALSE;
        }
        curr = curr->next;
    }
    return checker; 
}
// Compares the type of the Pokemon for show_types and returns TRUE
// if Pokemon type has not been seen before
static int explore_compare_types(int type, Pokedex pokedex) {
    if (type == 0) {
        return FALSE;
    }
    struct pokenode *curr;
    curr = pokedex->head;
    int checker = TRUE;   
    while (curr != pokedex->poketypes) {
        if (pokemon_first_type(curr->pokemon) == type && curr->recently_found 
        == FALSE) {
            checker = FALSE;
        }
        if (pokemon_second_type(curr->pokemon) == type && 
                                   curr->recently_found == FALSE) {
            checker = FALSE;
        }
        curr = curr->next;
    }
    return checker; 
}

// Prints the ID of the Pokemon
static void print_ID(int id) {
    if (id > 9 && id < 100 ) {
        printf("0%d", id);
    } else if (id >= 100) {
        printf("%d", id);
    } else {
        printf("00%d", id);
    } 
}

// Compares the name of the Pokemon and text for search_pokemon
static int compare_strings(Pokemon pokemon, char *text) {
    // A new array stores Pokemon name and text
    char *name_pointer = pokemon_name(pokemon);
    int i = 0;
    int name_length = 0;
    while (name_pointer[i] != '\0') {
        name_length++;
        i++;
    }
    char name_array[name_length]; 
    i = 0;
    while (name_pointer[i] != '\0') {
        name_array[i] = name_pointer[i]; 
        i++;
    }
    i = 0;
    int text_length = 0;
    while (text[i] != '\0') {
        text_length++;
        i++;
    }
    i = 0;
    char text_array[text_length];
    while (text[i] != '\0') {
        text_array[i] = text[i]; 
        i++;
    }
    // Changes the letters of the Pokemon name and text to lowercase
    i = 0;
    while (i < text_length) {
        if (text_array[i] >= 'A' && text_array[i] <= 'Z') {
            int alphabetPosition = text_array[i] - 'A';
            text_array[i] = 'a' + alphabetPosition;
        }
        i++;
    }
    i = 0;
    while (i < name_length) {
        if (name_array[i] >= 'A' && name_array[i] <= 'Z') {
            int alphabetPosition = name_array[i] - 'A';
            name_array[i] = 'a' + alphabetPosition;
        }
        i++;
    }
    // Checks for similarities between Pokemon name and text
    i = 0;
    int j = 0;
    int checker = FALSE; 
    while (i < name_length) {
        j = 0;
        if (name_array[i] == text_array[j]) {
            int k = i;
            int keep_checking = TRUE;
            while (j < text_length && k < name_length && keep_checking == 1) {
                if (name_array[k] == text_array[j]) {
                    k++;
                    j++;
                }
                else {
                    keep_checking = FALSE;
                }
                if (j == text_length) {
                    checker = TRUE;
                    return checker;
                }
            }
        }
        i++;
    }
    return checker; 
}
