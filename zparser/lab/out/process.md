## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | int id ( ) { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ |  |
| 0 | $ | int id ( ) { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Shift 6|
| 0 6 | $ int | id ( ) { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Reduce basics → int |
| 0 1 | $ basics | id ( ) { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Shift 7|
| 0 1 7 | $ basics id | ( ) { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Shift 8|
| 0 1 7 8 | $ basics id ( | ) { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Shift 10|
| 0 1 7 8 10 | $ basics id ( ) | { int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Shift 11|
| 0 1 7 8 10 11 | $ basics id ( ) { | int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Reduce declarations → ε |
| 0 1 7 8 10 11 15 | $ basics id ( ) { declarations | int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Reduce stmts → ε |
| 0 1 7 8 10 11 15 26 | $ basics id ( ) { declarations stmts | int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Reduce block → { declarations stmts |
| 0 1 7 8 10 12 | $ basics id ( ) block | int id ; int id ; int id ; id = num + num * num ; id = num ; id = num ; while ( id ) { id = id + num ; if ( id == id ) break ; else if ( id > id id = id + num ; else id = id - num ; } $ | Error|
