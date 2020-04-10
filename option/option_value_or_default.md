# option_value_or_default

If the option has a value, gets it. Otherwise, gets a default initialized value.
## Syntax

```c
value_type option_value_or_default(Option option);
```

| Name | Type | Description |
| --- | --- | --- |
| option | Option | An optional value. |

**Returns:** If the option holds a value, the value. Otherwise a default initialized value.

## Example

Strongly Typed:

```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption option = str_opt_default();
printf("Value is null? %d\n", str_opt_value_or_default(option) == NULL);

option = str_opt_make("Hello World");
printf("%s\n", str_opt_value_or_default(option));

// Output:
// Value is null? 1
// Hello World
```

Generically Typed:
```c
OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption option = gds_option_default(StringOption);
printf("Value is null? %d\n", gds_option_value_or_default(option) == NULL);

option = gds_option_make(StringOption, "Hello World");
printf("%s\n", gds_option_value_or_default(option));

// Output:
// Value is null? 1
// Hello World
```