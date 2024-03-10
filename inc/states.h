#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"

/******************************************************************************
 * Type definitions and defines
******************************************************************************/
/// Total amount of states
#define STATE_QTY 3

/// @brief All possible states
typedef enum stateEnum_t {
    STATE_A,
    STATE_B,
    STATE_C,
} stateEnum_t;

/// @brief Contains all the information extracted from external events, and
///     is used by the FSM to determine if a transition is due.
typedef struct instanceData_t {
    int inputCharacter;
} instanceData_t;

/// @brief Represents a state, composed of the state's value and function.
typedef struct state_t {
    stateEnum_t st;
    struct state_t (*stFn)(const instanceData_t*);
} state_t;

/******************************************************************************
 * Extern state variables
******************************************************************************/
extern const state_t stA;
extern const state_t stB;
extern const state_t stC;

/******************************************************************************
 * Prototypes
******************************************************************************/
/// @brief While inside state "A", check if any event was triggered that
///     demands a state change.
/// @param data Pointer to the data from the events that could trigger a
///     state transition.
/// @return Next state.
state_t stateAFn(const instanceData_t* data);

/// @brief While inside state "B", check if any event was triggered that
///     demands a state change.
/// @param data Pointer to the data from the events that could trigger a
///     state transition.
/// @return Next state.
state_t stateBFn(const instanceData_t* data);

/// @brief While inside state "C", check if any event was triggered that
///     demands a state change.
/// @param data Pointer to the data from the events that could trigger a
///     state transition.
/// @return Next state.
state_t stateCFn(const instanceData_t* data);

#endif // STATE_H_