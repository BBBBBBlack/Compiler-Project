## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | int id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ |  |
| 0 | $ | int id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce A → ε |
| 0 2 | $ A | int id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 6|
| 0 2 6 | $ A int | id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce basic → int |
| 0 2 3 | $ A basic | id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 7|
| 0 2 3 7 | $ A basic id | ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 8|
| 0 2 3 7 8 | $ A basic id ( | ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 9|
| 0 2 3 7 8 9 | $ A basic id ( ) | { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 10|
| 0 2 3 7 8 9 10 | $ A basic id ( ) { | real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 5|
| 0 2 3 7 8 9 10 5 | $ A basic id ( ) { real | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce basic → real |
| 0 2 3 7 8 9 10 14 | $ A basic id ( ) { basic | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 10 14 20 | $ A basic id ( ) { basic B | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 10 14 20 26 | $ A basic id ( ) { basic B array | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 10 15 | $ A basic id ( ) { type | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 21|
| 0 2 3 7 8 9 10 15 21 | $ A basic id ( ) { type id | ; int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 27|
| 0 2 3 7 8 9 10 15 21 27 | $ A basic id ( ) { type id ; | int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 10 12 | $ A basic id ( ) { decl | int id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 6|
| 0 2 3 7 8 9 10 12 6 | $ A basic id ( ) { decl int | id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce basic → int |
| 0 2 3 7 8 9 10 12 14 | $ A basic id ( ) { decl basic | id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 10 12 14 20 | $ A basic id ( ) { decl basic B | id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 10 12 14 20 26 | $ A basic id ( ) { decl basic B array | id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 10 12 15 | $ A basic id ( ) { decl type | id ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 21|
| 0 2 3 7 8 9 10 12 15 21 | $ A basic id ( ) { decl type id | ; int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 27|
| 0 2 3 7 8 9 10 12 15 21 27 | $ A basic id ( ) { decl type id ; | int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 10 12 12 | $ A basic id ( ) { decl decl | int [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 6|
| 0 2 3 7 8 9 10 12 12 6 | $ A basic id ( ) { decl decl int | [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce basic → int |
| 0 2 3 7 8 9 10 12 12 14 | $ A basic id ( ) { decl decl basic | [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 10 12 12 14 20 | $ A basic id ( ) { decl decl basic B | [ num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 25|
| 0 2 3 7 8 9 10 12 12 14 20 25 | $ A basic id ( ) { decl decl basic B [ | num ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 33|
| 0 2 3 7 8 9 10 12 12 14 20 25 33 | $ A basic id ( ) { decl decl basic B [ num | ] id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 41|
| 0 2 3 7 8 9 10 12 12 14 20 25 33 41 | $ A basic id ( ) { decl decl basic B [ num ] | id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 10 12 12 14 20 25 33 41 47 | $ A basic id ( ) { decl decl basic B [ num ] array | id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce array → [ num ] array |
| 0 2 3 7 8 9 10 12 12 14 20 26 | $ A basic id ( ) { decl decl basic B array | id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 10 12 12 15 | $ A basic id ( ) { decl decl type | id ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 21|
| 0 2 3 7 8 9 10 12 12 15 21 | $ A basic id ( ) { decl decl type id | ; real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 27|
| 0 2 3 7 8 9 10 12 12 15 21 27 | $ A basic id ( ) { decl decl type id ; | real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 10 12 12 12 | $ A basic id ( ) { decl decl decl | real [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 5|
| 0 2 3 7 8 9 10 12 12 12 5 | $ A basic id ( ) { decl decl decl real | [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce basic → real |
| 0 2 3 7 8 9 10 12 12 12 14 | $ A basic id ( ) { decl decl decl basic | [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 10 12 12 12 14 20 | $ A basic id ( ) { decl decl decl basic B | [ num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 25|
| 0 2 3 7 8 9 10 12 12 12 14 20 25 | $ A basic id ( ) { decl decl decl basic B [ | num ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 33|
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 | $ A basic id ( ) { decl decl decl basic B [ num | ] [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 41|
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 41 | $ A basic id ( ) { decl decl decl basic B [ num ] | [ num ] id ; id = num ; id = num + id * num ; } $ | Shift 25|
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 41 25 | $ A basic id ( ) { decl decl decl basic B [ num ] [ | num ] id ; id = num ; id = num + id * num ; } $ | Shift 33|
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 41 25 33 | $ A basic id ( ) { decl decl decl basic B [ num ] [ num | ] id ; id = num ; id = num + id * num ; } $ | Shift 41|
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 41 25 33 41 | $ A basic id ( ) { decl decl decl basic B [ num ] [ num ] | id ; id = num ; id = num + id * num ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 41 25 33 41 47 | $ A basic id ( ) { decl decl decl basic B [ num ] [ num ] array | id ; id = num ; id = num + id * num ; } $ | Reduce array → [ num ] array |
| 0 2 3 7 8 9 10 12 12 12 14 20 25 33 41 47 | $ A basic id ( ) { decl decl decl basic B [ num ] array | id ; id = num ; id = num + id * num ; } $ | Reduce array → [ num ] array |
| 0 2 3 7 8 9 10 12 12 12 14 20 26 | $ A basic id ( ) { decl decl decl basic B array | id ; id = num ; id = num + id * num ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 10 12 12 12 15 | $ A basic id ( ) { decl decl decl type | id ; id = num ; id = num + id * num ; } $ | Shift 21|
| 0 2 3 7 8 9 10 12 12 12 15 21 | $ A basic id ( ) { decl decl decl type id | ; id = num ; id = num + id * num ; } $ | Shift 27|
| 0 2 3 7 8 9 10 12 12 12 15 21 27 | $ A basic id ( ) { decl decl decl type id ; | id = num ; id = num + id * num ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 10 12 12 12 12 | $ A basic id ( ) { decl decl decl decl | id = num ; id = num + id * num ; } $ | Reduce decls → ε |
| 0 2 3 7 8 9 10 12 12 12 12 16 | $ A basic id ( ) { decl decl decl decl decls | id = num ; id = num + id * num ; } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 10 12 12 12 16 | $ A basic id ( ) { decl decl decl decls | id = num ; id = num + id * num ; } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 10 12 12 16 | $ A basic id ( ) { decl decl decls | id = num ; id = num + id * num ; } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 10 12 16 | $ A basic id ( ) { decl decls | id = num ; id = num + id * num ; } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 10 13 | $ A basic id ( ) { decls | id = num ; id = num + id * num ; } $ | Shift 18|
| 0 2 3 7 8 9 10 13 18 | $ A basic id ( ) { decls id | = num ; id = num + id * num ; } $ | Shift 23|
| 0 2 3 7 8 9 10 13 18 23 | $ A basic id ( ) { decls id = | num ; id = num + id * num ; } $ | Shift 28|
| 0 2 3 7 8 9 10 13 18 23 28 | $ A basic id ( ) { decls id = num | ; id = num + id * num ; } $ | Reduce expr → num |
| 0 2 3 7 8 9 10 13 18 23 31 | $ A basic id ( ) { decls id = expr | ; id = num + id * num ; } $ | Shift 36|
| 0 2 3 7 8 9 10 13 18 23 31 36 | $ A basic id ( ) { decls id = expr ; | id = num + id * num ; } $ | Reduce stmt → id = expr ; |
| 0 2 3 7 8 9 10 13 17 | $ A basic id ( ) { decls stmt | id = num + id * num ; } $ | Shift 18|
| 0 2 3 7 8 9 10 13 17 18 | $ A basic id ( ) { decls stmt id | = num + id * num ; } $ | Shift 23|
| 0 2 3 7 8 9 10 13 17 18 23 | $ A basic id ( ) { decls stmt id = | num + id * num ; } $ | Shift 28|
| 0 2 3 7 8 9 10 13 17 18 23 28 | $ A basic id ( ) { decls stmt id = num | + id * num ; } $ | Reduce expr → num |
| 0 2 3 7 8 9 10 13 17 18 23 31 | $ A basic id ( ) { decls stmt id = expr | + id * num ; } $ | Shift 40|
| 0 2 3 7 8 9 10 13 17 18 23 31 40 | $ A basic id ( ) { decls stmt id = expr + | id * num ; } $ | Shift 32|
| 0 2 3 7 8 9 10 13 17 18 23 31 40 32 | $ A basic id ( ) { decls stmt id = expr + id | * num ; } $ | Reduce expr → id |
| 0 2 3 7 8 9 10 13 17 18 23 31 40 46 | $ A basic id ( ) { decls stmt id = expr + expr | * num ; } $ | Shift 38|
| 0 2 3 7 8 9 10 13 17 18 23 31 40 46 38 | $ A basic id ( ) { decls stmt id = expr + expr * | num ; } $ | Shift 28|
| 0 2 3 7 8 9 10 13 17 18 23 31 40 46 38 28 | $ A basic id ( ) { decls stmt id = expr + expr * num | ; } $ | Reduce expr → num |
| 0 2 3 7 8 9 10 13 17 18 23 31 40 46 38 44 | $ A basic id ( ) { decls stmt id = expr + expr * expr | ; } $ | Reduce expr → expr * expr |
| 0 2 3 7 8 9 10 13 17 18 23 31 40 46 | $ A basic id ( ) { decls stmt id = expr + expr | ; } $ | Reduce expr → expr + expr |
| 0 2 3 7 8 9 10 13 17 18 23 31 | $ A basic id ( ) { decls stmt id = expr | ; } $ | Shift 36|
| 0 2 3 7 8 9 10 13 17 18 23 31 36 | $ A basic id ( ) { decls stmt id = expr ; | } $ | Reduce stmt → id = expr ; |
| 0 2 3 7 8 9 10 13 17 17 | $ A basic id ( ) { decls stmt stmt | } $ | Reduce stmts → ε |
| 0 2 3 7 8 9 10 13 17 17 22 | $ A basic id ( ) { decls stmt stmt stmts | } $ | Reduce stmts → stmt stmts |
| 0 2 3 7 8 9 10 13 17 22 | $ A basic id ( ) { decls stmt stmts | } $ | Reduce stmts → stmt stmts |
| 0 2 3 7 8 9 10 13 19 | $ A basic id ( ) { decls stmts | } $ | Shift 24|
| 0 2 3 7 8 9 10 13 19 24 | $ A basic id ( ) { decls stmts } | $ | Reduce block → { decls stmts } |
| 0 2 3 7 8 9 11 | $ A basic id ( ) block | $ | Reduce program → A basic id ( ) block |
| 0 1 | $ program | $ | Accept|
