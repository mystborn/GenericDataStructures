# event_trigger

Causes an event to call all of the functions subscribed to it.

## Syntax

```c
void event_trigger(Event* event, ...);
void GDS_EVENT_TRIGGER(GdsEvent* event, event_signature, ...)
```

| Name | Type | Description |
| --- | --- | --- |
| event | Event* | A pointer to the event. |
| event_signature | function_signature | The signature of the functions called by the event. |
| ... | ... | The arguments to pass to the functions. |

## Remarks

The arguments passed to this function will be strongly typed if the event was created using one of the `EVENT_DEFINE_#_H` macros.

When triggering a generic event, the function signature is needed as well. There are two helper macros to make this easier:

* GDS_EVENT_DEFAULT for functions that only receive the context pointer
* GDS_EVENT_SIGNATURE(...) for functions that have additional arguments.

You can, however, always just write the function signature manually.

The following lines are equivalent to each other:

```c
void (*)(void*, char*)
GDS_EVENT_SIGNATURE(char*)
```

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