# vararg-macros

C preprocess macros that allow processing of data with variable numbers of
arguments. See include/vararg-macros.h for details, but a quick summary is:

| Macro name | Description |
| --- | --- |
| ARG_COUNT(arg1, arg2, ...) | Counts the number of arguments |
| | supplied |
| | |
| PROCESS_ARGS(macro, arg1, | Invokes the user-defined macro |
| arg2, ...) | for each argument, putting commas between  |
| | the results of each invocation. |
| | |
| PROCESS_SEP_ARGS(macro, | Invokes the user-defined macro for |
| sep, arg1, arg2, ...) | each argument, putting sep between the |
| | results of each invocation. |

