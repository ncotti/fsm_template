#include "fsm_second.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_second_state_t st_odd_fn(const fsm_second_data_t* data) {
    if (data->input_char <= '9' && data->input_char >= '0') {
        if ((data->input_char - '0') % 2 == 0) {
            return ST_EVEN;
        } else {
            return ST_ODD;
        }
    }

    return ST_NAN;
}

static fsm_second_state_t st_even_fn(const fsm_second_data_t* data) {
    if (data->input_char <= '9' && data->input_char >= '0') {
        if ((data->input_char - '0') % 2 == 0) {
            return ST_EVEN;
        } else {
            return ST_ODD;
        }
    }

    return ST_NAN;
}

static fsm_second_state_t st_nan_fn(const fsm_second_data_t* data) {
    if (data->input_char <= '9' && data->input_char >= '0') {
        if ((data->input_char - '0') % 2 == 0) {
            return ST_EVEN;
        } else {
            return ST_ODD;
        }
    }

    return ST_NAN;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_second_fn_t fsm_second_fn_list[FSM_SECOND_STATE_QTY] = {
    st_odd_fn,
    st_even_fn,
    st_nan_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_second_state_t fsm_second(fsm_second_data_t* data) {
    static fsm_second_state_t current_state = FSM_SECOND_INITIAL_STATE;
    fsm_second_state_t new_state = fsm_second_fn_list[current_state](data);
    fsm_second_transition_t transition = fsm_second_transition_table[current_state][new_state];

    if (transition) {
        transition(data);
    }

    current_state = new_state;
    return current_state;
}