#include <stdbool.h>
#include "unity.h"
#include "qhsm.h"
#include "mock_test_qhsm_mocks.h"

Qhsm s0 = {.parent = NULL, .handler = Test_Qhsm_Mocks_eventHandler};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_qhsm_machineEnteredOnFirstCall(void)
{
    QhsmEvent event = QHSM_EVENT_ENTRY;
    QhsmTransit transit = {};
    Test_Qhsm_Mocks_eventHandler_ExpectAndReturn(&s0, &event, &transit, QHSM_RESULT_IGNORED);
    QhsmDo(&s0,&event,&transit);
}

