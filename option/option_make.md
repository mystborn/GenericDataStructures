# option_make

Creates an option that has a value.

## Syntax

```c
Option option_make(value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| value | value_type | The value held by the option. |

**Returns:** An option that holds the specified value.

## Example

Strongly Typed:

```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption option = str_opt_make("Hello World");

printf("%s\n", str_opt_value(option));

// Output:
// Hello World
```

Generically Typed:
```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption option = gds_option_make(StringOption, "Hello World");

printf("%s\n", gds_option_value(option));

// Output:
// Hello World
```