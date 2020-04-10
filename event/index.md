# Event

An event is a type used to implement the [observer pattern](https://en.wikipedia.org/wiki/Observer_pattern). It is similar to events in the C# language. Functions can [subscribe]({{site.baseurl}}/event/event-subscribe) to an event. When the event is [triggered]({{site.baseurl}}/event/event-trigger), those functions will be called. 

There is a strongly-typed version that uses macros similar to c++ templates, but there is also a weakly-typed implementation. In order to use the weakly-typed version, in one source file you __must__ define `GENERIC_EVENT_IMPLEMENTATION` before including the `generic_event.h` header.

## Syntax

```c
EVENT_DEFINE_<arg_count>_H(type_name, function_prefix, ...)
EVENT_DEFINE_C(type_name, function_prefix)
```

Here `<arg_count>` should be replaced with the number of arguments that the event will have. This implementation only supports 0-10 arguments.

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the generated functions with. |
| ... | If `arg_count` is greater than zero, the types of the arguments used to trigger the event. |

For example, an event that takes in one string argument would be defined like so:

```c
EVENT_DEFINE_1_H(StringEvent, str_event, char*)
EVENT_DEFINE_C(StringEvent, str_event)
```

## Remarks

All functions that will be subscribed to an event, whether it's strongly-typed or not, should have a `void*` as its first argument. This will be the context used to subscribe the function to the event. This does not count as one of the arguments when counting for `<arg_count>`. For example, a function that would be subscribed to the StringEvent defined above would have the following signature:

```c
void some_function(void* ctx, char* string_value);
```

## Fields

These generally shouldn't be accessed directly, but they're documented just in case they're needed. This data type defines an additional struct and a function typedef. They are `<type_name>Subscription` and `void <type_name>Delegate(void*, ...)` respectively. `<type_name>` will be replaced with the event type name.

__EventSubscription:__

| Name | Type | Description |
| --- | --- | --- |
| data | void* | The context passed to the function when the event is triggered. |
| function | EventDelegate | The function to call when the event is triggered. |

__Event:__

| Name | Type | Description |
| --- | --- | --- |
| subscriptions | EventSubscription* | A list of the functions subscribed to the event. |
| count | unsigned int | The number of subscriptions. |
| capacity | unsigned int | The number of subscriptions that can be added to the event before resizing. |

## Example

```c
#include <generic_event.h>

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