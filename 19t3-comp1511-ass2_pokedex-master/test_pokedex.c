// Assignment 2 19T3 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Joshua Denison Chung Sy (z5259375)
// on 24/11/2019
//
//Contains functions to test pokedex.c
// Version 1.0.0: Assignment released.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.
#define oR_text "oR"
#define b_text "b"
#define saur_text "saur"

#define NIDORINO_ID 33
#define NIDORINO_NAME "Nidorino"
#define NIDORINO_HEIGHT 0.9
#define NIDORINO_WEIGHT 19.5
#define NIDORINO_FIRST_TYPE POISON_TYPE
#define NIDORINO_SECOND_TYPE NONE_TYPE

#define MEWTWO_ID 150
#define MEWTWO_NAME "Mewtwo"
#define MEWTWO_HEIGHT 2.0
#define MEWTWO_WEIGHT 122.0
#define MEWTWO_FIRST_TYPE PSYCHIC_TYPE
#define MEWTWO_SECOND_TYPE NONE_TYPE

#define VENUSAUR_ID 3
#define VENUSAUR_NAME "Venusaur "
#define VENUSAUR_HEIGHT 2.0
#define VENUSAUR_WEIGHT 100.0
#define VENUSAUR_FIRST_TYPE GRASS_TYPE
#define VENUSAUR_SECOND_TYPE POISON_TYPE

#define CHARMANDER_ID 4
#define CHARMANDER_NAME "Charmander"
#define CHARMANDER_HEIGHT 0.6
#define CHARMANDER_WEIGHT 8.5
#define CHARMANDER_FIRST_TYPE FIRE_TYPE
#define CHARMANDER_SECOND_TYPE NONE_TYPE

#define CHARMELEON_ID 5
#define CHARMELEON_NAME "Charmeleon"
#define CHARMELEON_HEIGHT 1.1
#define CHARMELEON_WEIGHT 19.0
#define CHARMELEON_FIRST_TYPE FIRE_TYPE
#define CHARMELEON_SECOND_TYPE NONE_TYPE

#define CHARIZARD_ID 6
#define CHARIZARD_NAME "Charizard"
#define CHARIZARD_HEIGHT 1.7
#define CHARIZARD_WEIGHT 90.5
#define CHARIZARD_FIRST_TYPE FIRE_TYPE
#define CHARIZARD_SECOND_TYPE FLYING_TYPE

#define SQUIRTLE_ID 7
#define SQUIRTLE_NAME "Squirtle"
#define SQUIRTLE_HEIGHT 0.5
#define SQUIRTLE_WEIGHT 9.0
#define SQUIRTLE_FIRST_TYPE WATER_TYPE
#define SQUIRTLE_SECOND_TYPE NONE_TYPE

#define WARTORTLE_ID 8
#define WARTORTLE_NAME "Wartortle "
#define WARTORTLE_HEIGHT 1.0
#define WARTORTLE_WEIGHT 22.5
#define WARTORTLE_FIRST_TYPE WATER_TYPE
#define WARTORTLE_SECOND_TYPE NONE_TYPE

#define BLASTOISE_ID 9
#define BLASTOISE_NAME "Blastoise"
#define BLASTOISE_HEIGHT 1.6
#define BLASTOISE_WEIGHT 85.5
#define BLASTOISE_FIRST_TYPE WATER_TYPE
#define BLASTOISE_SECOND_TYPE NONE_TYPE

// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE


// Add your own prototypes here.
// Helper functions for creating/comparing Pokemon.
static Pokemon create_venusaur(void);
static Pokemon create_charmander(void);
static Pokemon create_charmeleon(void);
static Pokemon create_charizard(void);
static Pokemon create_squirtle(void);
static Pokemon create_wartortle(void);
static Pokemon create_blastoise(void);
// Stage 1 tests
static void test_add2_pokemon(void);
static void test_detail_pokemon(void);
static void test_print_pokemon(void);
static void test_get_current_pokemon(void);
static void test_stage01_empty(void);


// Stage 2 tests
static void test_next_pokemon_spam(void);
static void test_next_pokemon_empty(void);
static void test_prev_pokemon(void);
static void test_prev_pokemon_spam(void);
static void test_prev_pokemon_empty(void);
static void test_change_current_pokemon_empty(void);
static void test_change_current_pokemon(void);
static void test_change_current_pokemon_invalid(void);
static void test_remove_pokemon_empty(void);
static void test_remove_pokemon_remove_head(void);
static void test_remove_pokemon_remove_tail(void);
static void test_remove_pokemon_remove_middle(void);

// Stage 3 tests
static void test_count_total_pokemon_empty(void);
static void test_count_total_pokemon(void);
static void test_count_total_pokemon_with_remove(void);
static void test_count_found_pokemon_empty(void);
static void test_count_found_pokemon(void);
static void test_go_exploring_empty(void);
static void test_go_exploring(void);
static void test_show_types_empty(void);
static void test_show_types(void);

// Stage 4 tests
static void test_add_pokemon_evolution_empty(void);
static void test_add_pokemon_evolution_itself(void);
static void test_show_evolutions_empty(void);
static void test_get_next_evolution_empty(void);
static void test_stage04_functions(void);
static void test_stage04_functions_remove(void);

//Stage 5 tests
static void test_get_pokemon_of_type_wrong_type(void);
static void test_get_pokemon_of_type_empty(void);
static void test_get_pokemon_of_type_invalid(void);
static void test_get_pokemon_of_type(void);
static void test_get_pokemon_of_type_unfound(void);
static void test_search_pokemon_empty(void);
static void test_search_pokemon_b(void);
static void test_search_pokemon_b_invalid(void);
static void test_search_pokemon_oR(void);
static void test_search_pokemon_unfound(void);

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_get_found_pokemon(void);
static void test_next_pokemon(void);

// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    //If tests are commented out, then it is because those tests exit the program not allowing other tests to run
    
    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_get_found_pokemon();
    
    //Test for stage 1
    test_add2_pokemon();
    test_detail_pokemon();
    test_print_pokemon();
    test_get_current_pokemon();
    test_stage01_empty();

    
    // Test for stage 2
    test_next_pokemon_spam();
    test_next_pokemon_empty();
    test_prev_pokemon();
    test_prev_pokemon_spam();
    test_prev_pokemon_empty();
    test_change_current_pokemon_empty();
    test_change_current_pokemon();
    test_change_current_pokemon_invalid();
    test_remove_pokemon_empty();
    test_remove_pokemon_remove_head();
    test_remove_pokemon_remove_tail();
    test_remove_pokemon_remove_middle();

    // Tests for stage 3
    test_count_total_pokemon_empty();
    test_count_total_pokemon(); 
    test_count_total_pokemon_with_remove(); 
    test_count_found_pokemon_empty(); 
    test_count_found_pokemon();
    test_go_exploring_empty();
    test_go_exploring(); 
    test_show_types_empty();
    test_show_types();
    
    // Tests for Stage 4
    //test_add_pokemon_evolution_empty(); {
    //test_add_pokemon_evolution_itself();
    test_show_evolutions_empty();
    //test_get_next_evolution_empty();
    test_stage04_functions();
    test_stage04_functions_remove();
    
    // Tests for Stage 5
    test_get_pokemon_of_type_wrong_type();
    test_get_pokemon_of_type_empty();
    test_get_pokemon_of_type_invalid();
    test_get_pokemon_of_type();
    test_get_pokemon_of_type_unfound();
    test_search_pokemon_empty();
    test_search_pokemon_b();
    test_search_pokemon_b_invalid();
    test_search_pokemon_oR();
    test_search_pokemon_unfound();


    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Write your own Pokedex tests here!


////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}
// My helper functions for creating different Pokemon for testing purposes
static Pokemon create_venusaur(void) {
    Pokemon pokemon = new_pokemon(
            VENUSAUR_ID, VENUSAUR_NAME,
            VENUSAUR_HEIGHT, VENUSAUR_WEIGHT,
            VENUSAUR_FIRST_TYPE,
            VENUSAUR_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_charmander(void) {
    Pokemon pokemon = new_pokemon(
            CHARMANDER_ID, CHARMANDER_NAME,
            CHARMANDER_HEIGHT, CHARMANDER_WEIGHT,
            CHARMANDER_FIRST_TYPE,
            CHARMANDER_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_charmeleon(void) {
    Pokemon pokemon = new_pokemon(
            CHARMELEON_ID, CHARMELEON_NAME,
            CHARMELEON_HEIGHT, CHARMELEON_WEIGHT,
            CHARMELEON_FIRST_TYPE,
            CHARMELEON_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_charizard(void) {
    Pokemon pokemon = new_pokemon(
            CHARIZARD_ID, CHARIZARD_NAME,
            CHARIZARD_HEIGHT, CHARIZARD_WEIGHT,
            CHARIZARD_FIRST_TYPE,
            CHARIZARD_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_squirtle(void) {
    Pokemon pokemon = new_pokemon(
            SQUIRTLE_ID, SQUIRTLE_NAME,
            SQUIRTLE_HEIGHT, SQUIRTLE_WEIGHT,
            SQUIRTLE_FIRST_TYPE,
            SQUIRTLE_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_wartortle(void) {
    Pokemon pokemon = new_pokemon(
            WARTORTLE_ID, WARTORTLE_NAME,
            WARTORTLE_HEIGHT, WARTORTLE_WEIGHT,
            WARTORTLE_FIRST_TYPE,
            WARTORTLE_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_blastoise(void) {
    Pokemon pokemon = new_pokemon(
            BLASTOISE_ID, BLASTOISE_NAME,
            BLASTOISE_HEIGHT, BLASTOISE_WEIGHT,
            BLASTOISE_FIRST_TYPE,
            BLASTOISE_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_nidorino(void) {
    Pokemon pokemon = new_pokemon(
            NIDORINO_ID, NIDORINO_NAME,
            NIDORINO_HEIGHT, NIDORINO_WEIGHT,
            NIDORINO_FIRST_TYPE,
            NIDORINO_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_mewtwo(void) {
    Pokemon pokemon = new_pokemon(
            MEWTWO_ID, MEWTWO_NAME,
            MEWTWO_HEIGHT, MEWTWO_WEIGHT,
            MEWTWO_FIRST_TYPE,
            MEWTWO_SECOND_TYPE
    );
    return pokemon;
}


// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!

//Stage 1 tests
static void test_add2_pokemon(void) {
    printf("\n>> Testing add2_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that there are two pokemon in the pokedex\n");
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add2_pokemon tests!\n");
}
static void test_detail_pokemon(void) {
    printf("\n>> Testing detail_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Using detail command on unfound Bulbasaur\n");
    detail_pokemon(pokedex);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Using detail command on found Bulbasaur\n");
    detail_pokemon(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed detail_pokemon tests!\n");
}
static void test_print_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       ... Printing unfound Bulbasaur and unfound Ivysaur\n");
    print_pokemon(pokedex);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("       ... Printing found Bulbasaur and unfound Ivysaur\n");
    print_pokemon(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed print_pokemon tests!\n");
}
static void test_stage01_empty(void) {
    printf("\n>> Testing stage01 detail and find_current_pokemon with empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Using detail_pokemon on empty pokedex\n");
    detail_pokemon(pokedex);
    
    printf("    ... Using find_current_pokemon on empty pokedex\n");
    find_current_pokemon(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed stage01_empty tests!\n");
}
static void test_get_current_pokemon(void) {
    printf("\n>> Testing get_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_current_pokemon tests!\n");
}    
// Stage 2 test
static void test_next_pokemon_spam(void) {
    printf("\n>> Testing next_pokemon and spamming next\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests_spam!\n");
}
static void test_next_pokemon_empty(void) {
    printf("\n>> Testing next_pokemon with empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests_spam!\n");
}
static void test_prev_pokemon(void) {
    printf("\n>> Testing prev_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed prev_pokemon tests!\n");
}
static void test_prev_pokemon_spam(void) {
    printf("\n>> Testing prev_pokemon and spamming prev_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed prev_pokemon tests_spam!\n");
}
static void test_prev_pokemon_empty(void) {
    printf("\n>> Testing prev_pokemon with empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed prev_pokemon tests_spam!\n");
}
static void test_change_current_pokemon_empty(void) {
    printf("\n>> Testing change_current_pokemon_pokemon with empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling change current pokemon to ID with 1 which is Bulbasaur\n");
    change_current_pokemon(pokedex, BULBASAUR_ID);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed change_current_pokemon_pokemon with empty pokedex!\n");
}
static void test_change_current_pokemon(void) {
    printf("\n>> Testing change_current_pokemon_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    
    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Calling change current pokemon to ID with 3 which is Venusaur\n");
    change_current_pokemon(pokedex, VENUSAUR_ID);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed change_current_pokemon_pokemon!\n");
}
static void test_change_current_pokemon_invalid(void) {
    printf("\n>> Testing change_current_pokemon with invalid ID change\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle and Wartortle\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    
    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle and Wartortle to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Calling change current pokemon to ID with 3 which is Venusaur\n");
    change_current_pokemon(pokedex, BLASTOISE_ID);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur i.e current Pokemon is still Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed change_current_pokemon with invalid ID change!\n");
}
static void test_remove_pokemon_empty(void) {
    printf("\n>> Testing remove_pokemon with empty Pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Removing a Pokemon in empty Pokedex (should do nothing, checking that program does not crash)\n");
    remove_pokemon(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon with empty Pokedex!\n");
}
static void test_remove_pokemon_remove_head(void) {
    printf("\n>> Testing remove_pokemon when removing head\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Removing the selected Pokemon in Pokedex\n");
    remove_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon when removing head!\n");
}
static void test_remove_pokemon_remove_tail(void) {
    printf("\n>> Testing remove_pokemon when removing tail\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Calling change current pokemon to select Blastoise which is the last Pokemon in the list\n");
    change_current_pokemon(pokedex, BLASTOISE_ID);
    
    printf("       --> Checking that the current Pokemon is Blastoise\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), blastoise));

    printf("    ... Removing the selected Pokemon in Pokedex\n");
    remove_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Wartortle (i.e pokemon before Blastoise)\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), wartortle));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon when removing tail!\n");
}
static void test_remove_pokemon_remove_middle(void) {
    printf("\n>> Testing remove_pokemon when removing pokemon in the middle of the list\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Calling change current pokemon to ID with 3 which is Venusaur\n");
    change_current_pokemon(pokedex, VENUSAUR_ID);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));

    printf("    ... Removing the selected Pokemon in Pokedex\n");
    remove_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Charmander (i.e pokemon after Venusaur)\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmander));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon when removing pokemon in the middle of the list!\n");
}
// Stage 3 Tests 
static void test_count_total_pokemon_empty(void) {
    printf("\n>> Testing count_total_pokemon in empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling count_total_pokemon\n");
    count_total_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 0\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_total_pokemon in empty pokedex!\n");
}
static void test_count_total_pokemon(void) {
    printf("\n>> Testing count_total_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);

    printf("    ... Calling count_total_pokemon\n");
    count_total_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 9\n");
    assert(count_total_pokemon(pokedex) == 9);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_total_pokemon!\n");
}
static void test_count_total_pokemon_with_remove(void) {
    printf("\n>> Testing count_total_pokemon and removing one Pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);

    printf("    ... Calling count_total_pokemon\n");
    count_total_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 9\n");
    assert(count_total_pokemon(pokedex) == 9);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Removing the selected Pokemon in Pokedex which is Bulbasaur\n");
    remove_pokemon(pokedex);

    printf("    ... Calling count_total_pokemon\n");
    count_total_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 8\n");
    assert(count_total_pokemon(pokedex) == 8);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_total_pokemon and removing one Pokemon!\n");
}
static void test_count_found_pokemon_empty(void) {
    printf("\n>> Testing count_found_pokemon in empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling count_found_pokemon\n");
    count_found_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 0\n");
    assert(count_found_pokemon(pokedex) == 0);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_total_pokemon in empty pokedex!\n");
}
static void test_count_found_pokemon(void) {
    printf("\n>> Testing count_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();

    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Setting Ivysaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Calling count_total_pokemon\n");
    count_total_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 2\n");
    assert(count_found_pokemon(pokedex) == 2);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Removing the selected Pokemon in Pokedex which is Ivysaur\n");
    remove_pokemon(pokedex);

    printf("    ... Calling count_found_pokemon\n");
    count_found_pokemon(pokedex);
    
    printf("    --> Checking that count_found_pokemon returned 1\n");
    assert(count_found_pokemon(pokedex) == 1);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_found_pokemon test!\n");
}
static void test_go_exploring_empty(void) {
    printf("\n>> Testing go_exploring in empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling go_exploring\n");
    go_exploring(pokedex);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed go_exploring in empty pokedex!\n");
}
static void test_go_exploring(void) {
    printf("\n>> Testing go_exploring\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("    ... Calling go_exploring\n");
    go_exploring(pokedex);
    
    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 4);
    assert(count_found_pokemon(found_pokedex) == 4);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), charmander));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), charizard));
    
        printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), squirtle));
    
    printf("    ... Destroying Found Pokedex\n");
    destroy_pokedex(found_pokedex);
    
    printf("    ... Calling go_exploring\n");
    go_exploring(pokedex);
    
    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex02 = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex02) == 7);
    assert(count_found_pokemon(found_pokedex02) == 7);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), bulbasaur));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex02);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), ivysaur));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex02);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), charmander));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex02);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), charmeleon));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex02);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), charizard));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex02);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), squirtle));
    
    printf("    ... Moving to the next pokemon in found pokedex and checking if next pokemon was copied correctly\n");
    next_pokemon(found_pokedex02);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex02), wartortle));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex02);

    printf(">> Passed go_exploring!\n");
}
static void test_show_types_empty(void) {
    printf("\n>> Testing show_types in empty pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling show_types\n");
    show_types(pokedex);
    
    printf("    --> User checks that it prints nothing\n");
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed show_types in empty pokedex!\n");
}
static void test_show_types(void) {
    printf("\n>> Testing show_types \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard =  create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();

    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle and Blastoise to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("    --> When show_type is called, user checks that it prints:\n");
    printf("Poison\n");
    printf("Grass\n");
    printf("Fire\n");
    printf("Flying\n");
    printf("Water\n");
    
    printf("    ... Calling show_types\n");
    show_types(pokedex);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed show_types test!\n");
}
// Stage 04 Tests
static void test_add_pokemon_evolution_empty(void) {
    printf("\n>> Testing add_pokemon_evolution with empty Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling add_Pokemon_evolution for id 1 to id 2\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, IVYSAUR_ID);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon_evolution with empty Pokedex test!\n");
}
static void test_add_pokemon_evolution_itself(void) {
    printf("\n>> Testing add_pokemon_evolution setting evolution to itself\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
        Pokemon bulbasaur = create_bulbasaur();
        Pokemon ivysaur = create_ivysaur();
        
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
        add_pokemon(pokedex, bulbasaur);
        add_pokemon(pokedex, ivysaur);

    printf("    ... Calling add_Pokemon_evolution for Bulbasaur to Bulbasaur\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, BULBASAUR_ID);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon_evolution setting evolution to itself test!\n");
}
static void test_show_evolutions_empty(void) {
    printf("\n>> Testing show_evolutions with empty Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("   --> User checks that it prints nothing\n");

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed show_evolutions with empty Pokedex test!\n");
}
static void test_get_next_evolution_empty(void) {
    printf("\n>> Testing get_next_evolution with empty Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling get_next_evolution\n");
    get_next_evolution(pokedex);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_next_evolution with empty Pokedex test!\n");
}
static void test_stage04_functions(void) {
    printf("\n>> Testing stage04 functions\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Ivysaur, Venusaur and Charmander\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();


    printf("    ... Adding Bulbasaur, Ivysaur, Venusaur and Charmander to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    
    printf("    ... Calling add_Pokemon_evolution to set Bulbasaur to evolve into Ivysaur\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, IVYSAUR_ID);

    printf("    ... Calling add_Pokemon_evolution to set Ivysaur to evolve into Venusaur\n");
    add_pokemon_evolution(pokedex, IVYSAUR_ID, VENUSAUR_ID);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Calling get_next_evolution\n");
    get_next_evolution(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("ID: 002\n");
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Calling get_next_evolution\n");
    get_next_evolution(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("ID: 003\n");
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));

    printf("    ... Calling get_next_evolution\n");
    get_next_evolution(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("DOES_NOT_EVOLVE\n");
    
    printf("    ... Calling change current pokemon to ID with 1 which is Bulbasaur\n");
    change_current_pokemon(pokedex, BULBASAUR_ID);
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("#001 ???? [????] --> #002 ???? [????] --> #003 ???? [????]\n");
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("#002 ???? [????] --> #003 ???? [????]\n");
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("#003 ???? [????]\n");
    
    printf("    ... Calling change current pokemon to ID with 1 which is Bulbasaur\n");
    change_current_pokemon(pokedex, BULBASAUR_ID);
    
    printf("    ... Calling go_exploring twice to set Bulbasaur and Ivysaur to found\n");
    go_exploring(pokedex);
    go_exploring(pokedex);
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("#001 Bulbasaur [Poison Grass] --> #002 Ivysaur [Poison Grass] --> #003 ???? [????]\n");
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed test_stage04_functions test!\n");
}
static void test_stage04_functions_remove(void) {
    printf("\n>> Testing stage04 functions and when Pokemon is removed\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Calling add_Pokemon_evolution to set Bulbasaur to evolve into Ivysaur\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, IVYSAUR_ID);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Calling get_next_evolution\n");
    get_next_evolution(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("ID: 002\n");
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("#001 ???? [????] --> #002 ???? [????]\n");
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Removing the selected Pokemon in Pokedex\n");
    remove_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Calling get_next_evolution\n");
    get_next_evolution(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("DOES_NOT_EVOLVE\n");
    
    printf("    ... Calling show_evolution\n");
    show_evolutions(pokedex);
    
    printf("    --> User checks that it prints the following\n");
    printf("#001 ???? [????]\n");

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed stage04 functions and when Pokemon is removed!\n");
}
// Stage 5 test functions
static void test_get_pokemon_of_type_wrong_type(void) {
    printf("\n>> Testing get_pokemon_of_type with empty Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Getting all Pokemon with type Poison\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, BULBASAUR_FIRST_TYPE);

    printf("       ... Printing Pokemon for Type Pokedex (i.e should print nothing)\n");
    print_pokemon(type_pokedex);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_pokemon_of_type with empty Pokedex test!\n");
}
static void test_get_pokemon_of_type_empty(void) {
    printf("\n>> Testing get_pokemon_of_type with searhced type not corresponding to any of the Pokemon in the Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Calling go_exploring to set Bulbasaur and Ivysaur to found\n");
    go_exploring(pokedex);
    go_exploring(pokedex);

    printf("       --> Checking that there are two found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 2);

    printf("    ... Getting all Pokemon with type Water\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, SQUIRTLE_FIRST_TYPE);

    printf("       ... Printing Pokemon for Type Pokedex (i.e should print nothing)\n");
    print_pokemon(type_pokedex);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_pokemon_of_type with searhced type not corresponding to any of the Pokemon in the Pokedex!\n");
}
static void test_get_pokemon_of_type_invalid(void) {
    printf("\n>> Testing get_pokemon_of_type with searhced type being invalid \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Calling go_exploring to set Bulbasaur and Ivysaur to found\n");
    go_exploring(pokedex);
    go_exploring(pokedex);

    printf("       --> Checking that there are two found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 2);

    printf("    ... Getting all Pokemon with type None\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, SQUIRTLE_SECOND_TYPE);

    printf("       ... Printing Pokemon for Type Pokedex (i.e should print nothing)\n");
    print_pokemon(type_pokedex);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_pokemon_of_type with searhced type being invalid !\n");
}
static void test_get_pokemon_of_type(void) {
    printf("\n>> Testing get_pokemon_of_type with searhced type being valid \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Calling go_exploring to set Bulbasaur and Ivysaur to found\n");
    go_exploring(pokedex);
    go_exploring(pokedex);

    printf("       --> Checking that there are two found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 2);

    printf("    ... Getting all Pokemon with type Poison\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, BULBASAUR_FIRST_TYPE);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(type_pokedex) == 2);
    assert(count_found_pokemon(type_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(type_pokedex), bulbasaur));
    next_pokemon(type_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(type_pokedex), ivysaur));

    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_pokemon_of_type with searhced type being valid !\n");
}
static void test_get_pokemon_of_type_unfound(void) {
    printf("\n>> Testing get_pokemon_of_type with unfound pokemon \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that there are zero found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 0);

    printf("    ... Getting all Pokemon with type Poison\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, BULBASAUR_FIRST_TYPE);

    printf("       ... Printing Pokemon for Type Pokedex (i.e should print nothing)\n");
    print_pokemon(type_pokedex);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_pokemon_of_type with unfound pokemon!\n");
}
static void test_search_pokemon_empty(void) {
    printf("\n>> Testing search_pokemon with empty Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Getting all Pokemon with letter b in name\n");
    Pokedex search_pokedex = search_pokemon(pokedex, b_text);

    printf("       ... Printing Pokemon for Search Pokedex (i.e should print nothing)\n");
    print_pokemon(search_pokedex);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed search_pokemon with empty Pokedex test!\n");
}
static void test_search_pokemon_b(void) {
    printf("\n>> Testing search_pokemon with letter b in name \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Calling go_exploring to set Bulbasaur and Ivysaur to found\n");
    go_exploring(pokedex);
    go_exploring(pokedex);

    printf("       --> Checking that there are two found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 2);

    printf("    ... Getting all Pokemon with letter b in name\n");
    Pokedex search_pokedex = search_pokemon(pokedex, b_text);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 1);
    assert(count_found_pokemon(search_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), bulbasaur));
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed search_pokemon with letter b in name!\n");
}
static void test_search_pokemon_b_invalid(void) {
    printf("\n>> Testing search_pokemon with letter b in name but no pokemon with b name \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Calling go_exploring to set Ivysaur to found\n");
    go_exploring(pokedex);

    printf("       --> Checking that there is one found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 1);

    printf("    ... Getting all Pokemon with letter b in name\n");
    Pokedex search_pokedex = search_pokemon(pokedex, b_text);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 0);
    assert(count_found_pokemon(search_pokedex) == 0);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed search_pokemon with letter b in name but no pokemon with b name test!\n");
}
static void test_search_pokemon_oR(void) {
    printf("\n>> Testing search_pokemon with letter oR in name\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Ivysaur and Nidorino\n");
    Pokemon ivysaur = create_ivysaur();
    Pokemon nidorino= create_nidorino();
    
    printf("    ... Adding Ivysaur and Nidorino to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, nidorino);

    printf("    ... Calling go_exploring to set Ivysaur and Nidorino to found\n");
    go_exploring(pokedex);
    go_exploring(pokedex);

    printf("       --> Checking that there is one found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 2);

    printf("    ... Getting all Pokemon with letter oR in name\n");
    Pokedex search_pokedex = search_pokemon(pokedex, oR_text);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 1);
    assert(count_found_pokemon(search_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), nidorino));
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed search_pokemon with letter oR in name!\n");
}
static void test_search_pokemon_unfound(void) {
    printf("\n>> Testing search_pokemon with unfound Pokemon in Pokedex \n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that there are zero found pokemon using count_found_pokemon\n");
    assert(count_found_pokemon(pokedex) == 0);

    printf("    ... Getting all Pokemon with letters saur in name\n");
    Pokedex search_pokedex = search_pokemon(pokedex, saur_text);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 0);
    assert(count_found_pokemon(search_pokedex) == 0);
    
    printf("    ... Destroying both Pokedex\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed search_pokemon with unfound Pokemon in Pokedex!\n");
}
