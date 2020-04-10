# option_value

If the option has a value, gets it.

## Syntax

```c
value_type option_value(Option option);
```

| Name | Type | Description |
| --- | --- | --- |
| option | Option | An optional value. |

**Returns:** The value if the option has one.

## Remarks

This function uses assert to check if the option has a value. When using a release build, this function is equivalent to [option_value_or_default]({{site.baseurl}}/option/option_value_or_default).

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