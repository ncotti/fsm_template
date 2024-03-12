#include "fsm_first.h"

/******************************************************************************
 * Static prototypes for state functions
******************************************************************************/
static fsm_first_state_t st_A_fn(const fsm_first_data_t* data);
static fsm_first_state_t st_B_fn(const fsm_first_data_t* data);
static fsm_first_state_t st_C_fn(const fsm_first_data_t* data);

/******************************************************************************
 * State declarations
******************************************************************************/
static const fsm_first_state_t st_A = {
    .st = ST_A,
    .fn = st_A_fn,
};

static const fsm_first_state_t st_B = {
    .st = ST_B,
    .fn = st_B_fn,
};

static const fsm_first_state_t st_C = {
    .st = ST_C,
    .fn = st_C_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_first_state_t fsm_first(fsm_first_data_t* data) {
    static fsm_first_state_t current_state = st_A;  // Initial state
    fsm_first_state_t new_state = current_state.fn(data);
    fsm_first_transition_t transition = fsm_first_transition_table[current_state.st][new_state.st];

    if (transition) {
        transition(data);
    }

    if (new_state.st != current_state.st) {
        current_state = new_state;
        current_state = fsm_first(data);
    }

    return current_state;
}

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_first_state_t st_A_fn(const fsm_first_data_t* data) {
    if (data->input_char == 'b') {
        return st_B;
    } else if (data->input_char == 'c') {
        return st_C;
    }

    return st_A;
}

static fsm_first_state_t st_B_fn(const fsm_first_data_t* data) {
    if (data->input_char == 'a') {
        return st_A;
    }
    else if (data->input_char == 'c') {
        return st_C;
    }

    return st_B;
}

static fsm_first_state_t st_C_fn(const fsm_first_data_t* data) {
    if (data->input_char == 'a') {
        return st_A;
    } else if (data->input_char == 'b') {
        return st_B;
    }

    return st_C;
}