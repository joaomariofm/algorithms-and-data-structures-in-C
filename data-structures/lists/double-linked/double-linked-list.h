typedef int KEY;

typedef struct
{
	KEY key;
} RECORD;

typedef struct OTHER_ELEMENT
{
  RECORD record;
  struct OTHER_ELEMENT* next;
  struct OTHER_ELEMENT* prev;
} ELEMENT;

typedef ELEMENT* POINTER;

typedef struct
{
  POINTER init;
} LIST;

// Query operations

POINTER search(LIST *list, KEY key);

// POINTER min(LIST *list);

// POINTER max(LIST *list);

POINTER next(LIST *list, POINTER element);

POINTER prev(LIST *list, POINTER element);

// Modifying operations

void init(LIST* list);

void reset(LIST* list);

void insert(LIST *list, POINTER element);

void discard(LIST *list, POINTER element);
