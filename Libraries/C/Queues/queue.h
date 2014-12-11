#include <stdio.h>
#include <stdlib.h>

/*
 * Type: queueElementT
 * -------------------
 * This is the type of objects held in the queue.
 */

typedef char queueElementT	;

/*
 * Type: queueADT
 * --------------
 * The actual implementation of a queue is completely
 * hidden.  Client will work with queueADT which is a
 * pointer to underlying queueCDT.
 */
typedef struct queueCDT	 *queueADT;

/*
 * Function: QueueCreate
 * Usage: queue = QueueCreate();
 * -------------------------
 * A new empty queue is created and returned.
 */

queueADT QueueCreate(void);

/* Function: QueueDestroy
 * Usage: QueueDestroy(queue);
 * -----------------------
 * This function frees all memory associated with
 * the queue.  "queue" may not be used again unless
 * queue = QueueCreate() is called first.
 */

void QueueDestroy(queueADT queue);

/*
 * Functions: QueueEnter, QueueDelete
 * Usage: QueueEnter(queue, element);
 *        element = QueueDelete(queue);
 * --------------------------------------------
 * These are the fundamental queue operations that enter
 * elements in and delete elements from the queue.  A call
 * to QueueDelete() on an empty queue or to QueueEnter()
 * on a full queue is an error.  Make use of QueueIsFull()
 * and QueueIsEmpty() (see below) to avoid these errors.
 */

void QueueEnter(queueADT queue, queueElementT element);
queueElementT QueueDelete(queueADT queue);


/*
 * Functions: QueueIsEmpty
 * Usage: if (QueueIsEmpty(queue)) ...
 * -----------------------------------
 * These return a true/false value based on whether
 * the queue is empty.
 */

int QueueIsEmpty(queueADT queue);

    