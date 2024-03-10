#include "states.h"

/******************************************************************************
 * State declarations
******************************************************************************/
const state_t stA = {
    .st = STATE_A,
    .stFn = stateAFn,
};

const state_t stB = {
    .st = STATE_B,
    .stFn = stateBFn,
};

const state_t stC = {
    .st = STATE_C,
    .stFn = stateCFn,
};

/******************************************************************************
 * State functions
******************************************************************************/
state_t stateAFn(const instanceData_t* data) {
    printf("Doing work on state A\n");
    if (data->inputCharacter == 'b') {
        return stB;
    }

    return stA;
}

state_t stateBFn(const instanceData_t* data) {
    printf("Doing work on state B\n");
    if (data->inputCharacter == 'c') {
        return stC;
    }

    return stB;
}

state_t stateCFn(const instanceData_t* data) {
    printf("Doing work on state C\n");
    if (data->inputCharacter == 'a') {
        return stA;
    }

    return stC;
}

