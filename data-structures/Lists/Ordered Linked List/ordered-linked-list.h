typedef int KEY;

typedef struct {

	KEY key;

} RECORD;

typedef struct NEXT {

  RECORD record;

  struct NEXT* next;

} ELEMENT;

typedef ELEMENT* POINTER;

typedef struct {

  POINTER init;

} LIST;

void initialize(LIST* list);

void reset(LIST* lista);

int lenght(LIST* lista);

void show(LIST* lista);

POINTER pop(LIST* lista, KEY key, POINTER* lastElement);

POINTER sequentialSearch(LIST* lista, KEY key);

int insertElement(LIST* lista, RECORD record);

int removeElement(LIST* lista, KEY key);

