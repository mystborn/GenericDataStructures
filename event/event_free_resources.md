# event_free_resources

Frees the resources used by the event without freeing the event itself.

## Syntax

```c
void event_free_resources(Event* event);
```

| Name | Type | Description |
| --- | --- | --- |
| event | Event* | A pointer to the event. |

## Example

Strongly Typed:

```c
EVENT_DEFINE_1_H(StringEvent, str_event, char*)
EVENT_DEFINE_C(StringEvent, str_event)

StringEvent event;
str_event_init(&event);

// Use the event...

str_event_free_resources(event);
```

Generically Typed:
```c
GdsEvent event;
gds_event_init(&event);

// Use the event...

gds_event_free_resources(event);
```