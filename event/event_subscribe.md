# event_subscribe

Subscribes a function and its context to the event.

## Syntax

```c
bool event_subscribe(Event* event, void* context, EventDelegate function);
bool gds_event_subscribe(GdsEvent* event, void* context, void* function);
```

| Name | Type | Description |
| --- | --- | --- |
| event | Event* | A pointer to the event. |
| context | void* | A context to pass to the function when the event is triggered. |
| function | EventDelegate | A function to call when the event is triggered. |

**Returns:** `true` on success, `false` on allocation failure.

## Remarks

When using the generic version, make sure all of the functions subscribed to the event have the same signature. Otherwise, when the event is triggered, there will be undefined behavior that will most likely crash the program.

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

str_event_subscribe(event, NULL, print_string);
str_event_subscribe(event, "Hello ", print_context_and_string);

str_event_trigger(event, "World");

str_event_free(event);

// Output:
// World
// Hello World
```

Generically Typed:
```c
static void print_string(void* ctx, char* str) {
    puts(str);
}

GdsEvent* event = gds_event_create();

gds_event_subscribe(event, NULL, print_string);

GDS_EVENT_TRIGGER(event, GDS_EVENT_SIGNATURE(char*), "Hello World");

gds_event_free(event);

// Output:
// Hello World
```