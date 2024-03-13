#include "fsm_first.h"
#include <stdio.h>

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_A_to_B(fsm_first_data_t* data) {
    printf("Transition from A to B.\n");
}

static void from_A_to_C(fsm_first_data_t* data) {
    printf("Transition from A to C.\n");
}

static void from_B_to_A(fsm_first_data_t* data) {
    printf("Transition from B to A.\n");
}

static void from_B_to_C(fsm_first_data_t* data) {
    printf("Transition from B to C.\n");
}

static void from_C_to_A(fsm_first_data_t* data) {
    printf("Transition from C to A.\n");
}

static void from_C_to_B(fsm_first_data_t* data) {
    printf("Transition from C to B.\n");
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_first_transition_t fsm_first_transition_table[FSM_FIRST_STATE_QTY][FSM_FIRST_STATE_QTY] = {
                /*ST_A*/        /*ST_B*/        /*ST_C*/
    /*ST_A*/    {NULL,          from_A_to_B,    from_A_to_C,    },
    /*ST_B*/    {from_B_to_A,   NULL,           from_B_to_C,    },
    /*ST_C*/    {from_C_to_A,   from_C_to_B,    NULL,           },
};