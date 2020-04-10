# event_create

Allocates and initializes a new event.

## Syntax

```c
Event* event_create(void);
```

**Returns:** A newly created event on success, `NULL` on failure.

## Example

Strongly Typed:

```c
EVENT_DEFINE_1_H(StringEvent, str_event, char*)
EVENT_DEFINE_C(StringEvent, str_event)

StringEvent* event = str_event_create();

// Use the event...

str_event_free(event);
```

Generically Typed:
```c
GdsEvent* event = gds_event_create();

// Use the event...

gds_event_free(event);
```