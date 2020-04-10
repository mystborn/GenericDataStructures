# option_default

Creates an option that does not have a value.

## Syntax

```c
Option option_default(void);
```

**Returns:** An option that holds no value.

## Example

```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

// Strongly Typed:

StringOption option = str_opt_default();
printf("Has Value? %d\n", str_opt_has_value(option));

// Output:
// Has Value? 0

// Generically Typed:
StringOption option = gds_option_default(StringOption);
printf("Has Value? %d\n", gds_option_has_value(option));

// Output:
// Has Value? 0
```