#include "fsm_second.h"
#include <stdio.h>

static fsm_second_state_t current_state = FSM_SECOND_INITIAL_STATE;

/******************************************************************************
 * STATES
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

/// @brief List with all possible states, as function pointers
static const fsm_second_fn_t fsm_second_fn_list[FSM_SECOND_STATE_QTY] = {
    st_odd_fn,
    st_even_fn,
    st_nan_fn,
};

/******************************************************************************
 * TRANSITIONS
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

/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
static const fsm_second_transition_t fsm_second_transition_table[FSM_SECOND_STATE_QTY][FSM_SECOND_STATE_QTY] = {
                /*ST_ODD*/          /*ST_EVEN*/         /*ST_NAN*/
    /*ST_ODD*/  {from_odd_to_odd,   from_odd_to_even,   NULL,       },
    /*ST_EVEN*/ {from_even_to_odd,  from_even_to_even,  NULL,       },
    /*ST_NAN*/  {from_nan_to_odd,   from_nan_to_even,   NULL,       },
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
void fsm_second(fsm_second_data_t* data) {
    fsm_second_state_t new_state = fsm_second_fn_list[current_state](data);
    fsm_second_transition_t transition = fsm_second_transition_table[current_state][new_state];

    if (transition) {
        transition(data);
    }

    current_state = new_state;
}

fsm_second_state_t fsm_second_get_state(void) {
    return current_state;
}