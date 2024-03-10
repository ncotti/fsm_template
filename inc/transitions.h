#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_

#include "states.h"
#include <stdio.h>

/******************************************************************************
 * Type definitions and external variables
******************************************************************************/
/// @brief Function pointer for transitions.
typedef void (*transitionFn_t)(void);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern transitionFn_t transitionTable[STATE_QTY][STATE_QTY];

/******************************************************************************
 * Prototypes
******************************************************************************/
/// @brief Actions executed while transitioning from state "A" to state "A"
void fromAToA(void);

/// @brief Actions executed while transitioning from state "A" to state "B"
void fromAToB(void);

/// @brief Actions executed while transitioning from state "B" to state "C"
void fromBToC(void);

/// @brief Actions executed while transitioning from state "C" to state "A"
void fromCToA(void);

#endif // TRANSITIONS_H_