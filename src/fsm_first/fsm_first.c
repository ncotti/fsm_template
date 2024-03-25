#include "fsm_first.h"
#include <stdio.h>

static fsm_first_state_t current_state = FSM_FIRST_INITIAL_STATE;

/******************************************************************************
 * STATES
******************************************************************************/
static fsm_first_state_t st_A_fn(const fsm_first_data_t* data) {
    if (data->input_char == 'b') {
        return ST_B;
    } else if (data->input_char == 'c') {
        return ST_C;
    }

    return ST_A;
}

static fsm_first_state_t st_B_fn(const fsm_first_data_t* data) {
    if (data->input_char == 'a') {
        return ST_A;
    }
    else if (data->input_char == 'c') {
        return ST_C;
    }

    return ST_B;
}

static fsm_first_state_t st_C_fn(const fsm_first_data_t* data) {
    if (data->input_char == 'a') {
        return ST_A;
    } else if (data->input_char == 'b') {
        return ST_B;
    }

    return ST_C;
}

/// @brief List with all possible states, as function pointers
static const fsm_first_fn_t fsm_first_fn_list[FSM_FIRST_STATE_QTY] = {
    st_A_fn,
    st_B_fn,
    st_C_fn,
};

/******************************************************************************
 * TRANSITIONS
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

/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
static const fsm_first_transition_t fsm_first_transition_table[FSM_FIRST_STATE_QTY][FSM_FIRST_STATE_QTY] = {
                /*ST_A*/        /*ST_B*/        /*ST_C*/
    /*ST_A*/    {NULL,          from_A_to_B,    from_A_to_C,    },
    /*ST_B*/    {from_B_to_A,   NULL,           from_B_to_C,    },
    /*ST_C*/    {from_C_to_A,   from_C_to_B,    NULL,           },
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
void fsm_first(fsm_first_data_t* data) {
    fsm_first_state_t new_state = fsm_first_fn_list[current_state](data);
    fsm_first_transition_t transition = fsm_first_transition_table[current_state][new_state];

    if (transition) {
        transition(data);
    }

    current_state = new_state;
}

fsm_first_state_t fsm_first_get_state(void) {
    return current_state;
}