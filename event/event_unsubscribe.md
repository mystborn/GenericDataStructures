# event_unsubscribe

Removes a function and its context from an event.

## Syntax

```c
bool event_unsubscribe(Event* event, void* context, EventDelegate function);
bool gds_event_unsubscribe(GdsEvent* event, void* context, void* function);
```

| Name | Type | Description |
| --- | --- | --- |
| event | Event* | A pointer to the event. |
| context | void* | The context used when originally subscribing the function. |
| function | EventDelegate | The function to remove from the event. |

**Returns:** `true` if the function was removed, `false` if it couldn't be found.

## Remarks

The context used to remove a function has to be an exact match to the one used to originally subscribe it.

## Example

Strongly Typed:

```c
EVENT_DEFINE_1_H(StringEvent, str_event, char*)
EVENT_DEFINE_C(StringEvent, str_event)

static void print_string(void* ctx, char* str) {
    puts(str);
}

static void print_context_and_string(void* ctx, char* str) {
    printf("%s%s\n", (char*)ctx, str);
}

StringEvent* event = str_event_create();

char* context = "Hello ";

str_event_subscribe(event, NULL, print_string);
str_event_subscribe(event, context, print_context_and_string);

str_event_trigger(event, "World");

str_event_unsubscribe(event, context, print_context_and_string);

str_event_trigger(event, "String all alone");

str_event_free(event);

// Output:
// World
// Hello World
// String all alone
```

Generically Typed:
```c
static void print_string(void* ctx, char* str) {
    puts(str);
}

static void print_context_and_string(void* ctx, char* str) {
    printf("%s%s\n", (char*)ctx, str);
}

GdsEvent* event = gds_event_create();

gds_event_subscribe(event, NULL, print_string);
gds_event_subscribe(event, "Hello ", print_context_and_string);

GDS_EVENT_TRIGGER(event, GDS_EVENT_SIGNATURE(char*), "World");

gds_event_unsubscribe(event, "Hello ", print_context_and_string);

GDS_EVENT_TRIGGER(event, GDS_EVENT_SIGNATURE(char*), "String all alone");

gds_event_free(event);

// Output:
// World
// Hello World
// String all alone
```