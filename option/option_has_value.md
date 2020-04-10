# option_has_value

Determines if the option contains a value.

## Syntax

```c
bool option_has_value(Optional option);
```

| Name | Type | Description |
| --- | --- | --- |
| option | Option | An optional value. |

**Returns:** `true` if the option has a value, `false` otherwise.

## Example

Strongly Typed:

```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption option = str_opt_make("Hello");
printf("Has Value? %s\n", str_opt_has_value(option));

option = str_opt_default();
printf("Has Value? %s\n", str_opt_has_value(option));

// Output:
// Has Value? 1
// Has Value? 0
```

Generically Typed:
```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption option = gds_option_make(StringOption, "Hello");
printf("Has Value? %s\n", gds_option_has_value(option));

option = gds_option_default(StringOption);
printf("Has Value? %s\n", gds_option_has_value(option));

// Output:
// Has Value? 1
// Has Value? 0
```