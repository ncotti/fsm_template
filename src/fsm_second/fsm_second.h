#ifndef FSM_SECOND_H_
#define FSM_SECOND_H_

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_second_state_t {
    ST_ODD,
    ST_EVEN,
    ST_NAN,
} fsm_second_state_t;

#define FSM_SECOND_STATE_QTY 3              /// Total amount of states
#define FSM_SECOND_INITIAL_STATE ST_NAN     /// Initial state

/// @brief Contains all the information extracted from external events, and
///     is used by the FSM to determine if a transition is due.
typedef struct fsm_second_data_t {
    int input_char;
} fsm_second_data_t;

/// @brief Function pointer for state functions.
typedef fsm_second_state_t (*fsm_second_fn_t)(const fsm_second_data_t*);

/// @brief Function pointer for transitions.
typedef void (*fsm_second_transition_t)(fsm_second_data_t*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
void fsm_second(fsm_second_data_t* data);

fsm_second_state_t fsm_second_get_state(void);

#endif // FSM_SECOND_H_