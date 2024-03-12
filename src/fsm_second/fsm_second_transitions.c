#include "fsm_second.h"
#include <stdio.h>

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_odd_to_odd(fsm_second_data_t* data) {
    printf("Two odds in a row! Keep it up!\n");
}

static void from_odd_to_even(fsm_second_data_t* data) {
    printf("Previous number was odd, this number is even.\n");
}

static void from_even_to_even(fsm_second_data_t* data) {
    printf("Two evens in a row! Keep it up!\n");
}

static void from_even_to_odd(fsm_second_data_t* data) {
    printf("Previous number was even, this number is odd.\n");
}

static void from_nan_to_odd(fsm_second_data_t* data) {
    printf("An odd number, what a sight!\n");
}

static void from_nan_to_even(fsm_second_data_t* data) {
    printf("An even number, balance is key!\n");
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_second_transition_t fsm_second_transition_table[FSM_SECOND_STATE_QTY][FSM_SECOND_STATE_QTY] = {
                /*ST_ODD*/          /*ST_EVEN*/         /*ST_NAN*/
    /*ST_ODD*/  {from_odd_to_odd,   from_odd_to_even,   NULL,       },
    /*ST_EVEN*/ {from_even_to_odd,  from_even_to_even,  NULL,       },
    /*ST_NAN*/  {from_nan_to_odd,   from_nan_to_even,   NULL,       },
};

