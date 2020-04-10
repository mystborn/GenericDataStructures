# event_free

Frees the resources used by the event, then frees the event itself.

## Syntax

```c
void event_free(Event* event);
```

| Name | Type | Description |
| --- | --- | --- |
| event | Event* | A pointer to the event. |

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