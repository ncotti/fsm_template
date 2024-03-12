#ifndef FSM_FIRST_H_
#define FSM_FIRST_H_

/******************************************************************************
 * Types and definitions
******************************************************************************/
#define FSM_FIRST_STATE_QTY 3  /// Total amount of states

/// @brief All possible states
typedef enum fsm_first_state_t {
    ST_A,
    ST_B,
    ST_C,
} fsm_first_state_t;

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
fsm_first_state_t fsm_first(fsm_first_data_t* data);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_first_transition_t fsm_first_transition_table[FSM_FIRST_STATE_QTY][FSM_FIRST_STATE_QTY];

#endif // FSM_FIRST_H_