#include "unity.h"
#include "qhsm.h"

//  Qhsm
//      - IMPLICIT: a Qhsm can have a Parent Qhsm. (*Qhsm)parent
//      - IMPLICIT: a Qhsm can have an event handler. (*EventHandler(*Event))event_handler

//  QHsmDoResult QHsmDo(*QHsm,*QHsmEvent)
//      - if library is passed an internal event it will throw an error
//      - if library is passed a null event it will throw an error
//      - if library is passed a null QHsm it will throw an error

//  boolean QhsmStateIsActive(*Qhsm);
//      - if state is an active leaf or parent of an active leaf returns true
//      - else returns false

//  QhsmEventHandler(EventResult(Event))
//      - IMPLICIT: takes events and returns results and transitions (transition through a parameter)
//      - on first event, root/top state becomes active leaf
//      - on event becoming active leaf, event handler gets hit with entry and then init
//      - for entry and exit, result is discarded and treated as ignored.
//          - entry transit ignored even if handler returns consumed
//          - exit transit ignored even if handler returns consumed
//      - for init events, result is discarded and treated as consumed.
//          - init transit is taken even if handler returns ignored
//      - for all other events:
//          - if result is ignored, it will be passed to parent (if exists, and doesn't contain unprocessed orthogonal regions) or leaf-most unprocessed active state in another region (if exists)
//          - if all states ignore event, QhsmDo returns ignored
//          - if result is consumed, transition will be taken (if given) and 
//          - if result is deferred:
//              - event will be passed to remaining orthogonal regions
//              - if event is not consumed it will be saved
//              - saved events are rethrown in FIFO order after next transition

//  QhsmEventResult
//      - OHSM_EVENT_RESULT_IGNORED
//          - will pass event to parent if parent exists
//      - OHSM_EVENT_RESULT_CONSUMED
//          - will stop passing event
//      - OHSM_EVENT_RESULT_DEFERRED
//          - will defer event if it is not consumed in an orthogonal region

//  QHsmTransition
//      - can have a destination QHsm
//      - can have a subtarget
//          - NORMAL will transition to target
//          - SHALLOW will transition to previous active child Qhsm of target
//          - DEEP will transition to previous active leaf Qhsm of target
//          - TERMINATE will transition to target and then exit entire QHsm tree
//      - can have an exit QHsm
//          - if given and in active tree transition will exit down the tree until it has exitted the exit QHsm before transitioning to target

//  QhsmEvent
//   - has an EventId (ENTRY/INIT/EXIT/application)

//  QhsmEventId
//      - QHSM_EVENT_ID_ENTRY
//          - passed when a state first becomes active
//      - QHSM_EVENT_ID_INIT
//          - passed after entry if the state is an active leaf
//      - QHSM_EVENT_ID_EXIT
//          - passed when a state ceases to be active
//      - QHSM_EVENT_ID_FIRST_UNUSED
//          - defines the first usable event id for an application
//

void setUp(void)
{
}

void tearDown(void)
{
}

void test_qhsm_needToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement qhsm");
}

