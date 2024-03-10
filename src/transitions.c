#include "transitions.h"

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transitionTable[X][Y]
transitionFn_t transitionTable[STATE_QTY][STATE_QTY] = {
    {fromAToA,      fromAToB,    NULL,      },
    {NULL,          NULL,        fromBToC,  },
    {fromCToA,      NULL,        NULL       },
};

/******************************************************************************
 * Transition Table
******************************************************************************/
void fromAToA(void) {
    printf("Transition from A to A.\n");
}

void fromAToB(void) {
    printf("Transition from A to B.\n");
}

void fromBToC(void) {
    printf("Transition from B to C.\n");
}

void fromCToA(void) {
    printf("Transition from C to A.\n");
}