#ifndef _QHSM_H
#define _QHSM_H

typedef struct Qhsm Qhsm;
typedef struct QhsmTransit QhsmTransit;

typedef enum QhsmResult {
    QHSM_RESULT_IGNORED,
    QHSM_RESULT_CONSUMED,
    QHSM_RESULT_DEFERRED,
} QhsmResult;

typedef enum QhsmEvent {
    QHSM_EVENT_ENTRY,
    QHSM_EVENT_INIT,
    QHSM_EVENT_EXIT,
    QHSM_EVENT_FIRST_AVAILABLE,
} QhsmEvent;

typedef enum QhsmTransitType {
    QHSM_TRANSIT_TYPE_NORMAL,
} QhsmTransitType;

typedef enum QhsmTransitResult {
    QHSM_TRANSIT_RESULT_NONE,
} QhsmTransitResult;

typedef QhsmTransitResult (*QhsmTransitHandler)(Qhsm *source, QhsmTransit *transit);

struct QhsmTransit {
    Qhsm *target;
    Qhsm *exit;
    QhsmTransitType type;
    QhsmTransitHandler handler;
};

typedef QhsmResult (*QhsmEventHandler)(Qhsm *self, QhsmEvent *event, QhsmTransit *transit);

struct Qhsm {
    Qhsm *parent;
    QhsmEventHandler handler;
};

void QhsmDo(Qhsm *machine, QhsmEvent *event, QhsmTransit *transit);

#endif // _QHSM_H
