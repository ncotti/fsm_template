#ifndef FSM_FIRST_H_
#define FSM_FIRST_H_

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_first_state_t {
    ST_A,
    ST_B,
    ST_C,
} fsm_first_state_t;

#define FSM_FIRST_STATE_QTY 3           /// Total amount of states
#define FSM_FIRST_INITIAL_STATE ST_A    /// Initial state

/// @brief Contains all the information extracted from external events, and
///     is used by the FSM to determine if a transition is due.
typedef struct fsm_first_data_t {
    int input_char;
} fsm_first_data_t;

/// @brief Function pointer for state functions.
typedef fsm_first_state_t (*fsm_first_fn_t)(const fsm_first_data_t*);

/// @brief Function pointer for transitions.
typedef void (*fsm_first_transition_t)(fsm_first_data_t*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
void fsm_first(fsm_first_data_t* data);

/// @brief Return the current state of the FSM.
fsm_first_state_t fsm_first_get_state(void);

#endif // FSM_FIRST_H_