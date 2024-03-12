#include "fsm_first.h"

/******************************************************************************
 * State functions
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

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_first_fn_t fsm_first_fn_list[FSM_FIRST_STATE_QTY] = {
    st_A_fn,
    st_B_fn,
    st_C_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_first_state_t fsm_first(fsm_first_data_t* data) {
    static fsm_first_state_t current_state = ST_A;  // Initial state
    fsm_first_state_t new_state = fsm_first_fn_list[current_state](data);
    fsm_first_transition_t transition = fsm_first_transition_table[current_state][new_state];

    if (transition) {
        transition(data);
    }

    if (new_state != current_state) {
        current_state = new_state;
        current_state = fsm_first(data);
    }

    return current_state;
}