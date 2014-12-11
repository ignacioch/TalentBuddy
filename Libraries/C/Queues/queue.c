#include "queue.h"

// each node has data and a pointer to the next one
typedef struct queueNodeTag {
  queueElementT element;
  struct queueNodeTag *next;
} queueNodeT;


// front and rear are pointers to queueNodesT
typedef struct queueCDT {
    queueNodeT *front, *rear;
} queueCDT;

queueADT QueueCreate(void)
{
  queueADT queue;

  queue = (queueADT)malloc(sizeof(queueCDT));

  if (queue == NULL) {
    fprintf(stderr, "Insufficient memory for new queue.\n");
    exit(1);  /* Exit program, returning error code. */
  }

  queue->front = queue->rear = NULL;

  return queue;
}

void QueueDestroy(queueADT queue)
{
  /*
   * First remove each element from the queue (each
   * element is in a dynamically-allocated node.)
   */
  while (!QueueIsEmpty(queue))
    QueueDelete(queue);

  /*
   * Reset the front and rear just in case someone
   * tries to use them after the CDT is freed.
   */
  queue->front = queue->rear = NULL;

  /*
   * Now free the structure that holds information
   * about the queue.
   */
  free(queue);
}

void QueueEnter(queueADT queue, queueElementT element)
{
  queueNodeT *newNodeP;

  /* Get a new node with the information stored in it. */

  newNodeP = NewNode(element);

  /*
   * Link the element into the right place in
   * the linked list.
   */

  if (queue->front == NULL) {  /* Queue is empty */
    queue->front = queue->rear = newNodeP;
  } else {
    queue->rear->next = newNodeP;
    queue->rear = newNodeP;
  }
}

int QueueIsEmpty(queueADT queue){}
  return ((queue->front == NULL) && (queue->rear == NULL));
}

queueElementT QueueDelete(queueADT queue) {

  if (QueueIsEmpty(queue)) {
    fprintf(stderr, "Deleting an empty queue causes error.\n");
    exit(1);  /* Exit program, returning error code. */
  }

  /*
   * First remove front element from the queue (each
   * element is in a dynamically-allocated node.)
   */
  queueNodeT* oldNode;
  oldNode = queue -> front;
  queue ->front = queue ->front -> next;
  queueElementT element = oldNode->element;
  free(oldNode);

  return element;
  

}


/************* Helper function prototypes ************/

/*
 * Function: NewNode
 * Usage: p = NewNode(element)
 * -----------------------------------
 * Returns a pointer to new node with the
 * specified element filled in.
 */
static queueNodeT *NewNode(queueElementT element);

/**************** Function definitions ***************/

static queueNodeT *NewNode(queueElementT element)
{
  queueNodeT *newNodeP;

  /* Allocate space for a node in the linked list. */

  newNodeP = (queueNodeT *)malloc(sizeof(queueNodeT));

  if (newNodeP == NULL) {
    fprintf(stderr, "Insufficient memory for new node.\n");
    exit(1);  /* Exit program, returning error code. */
  }

  /* Place information in the node */

  newNodeP->element = element;
  newNodeP->next = NULL;

  return newNodeP;
}
    