## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | int id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ |  |
| 0 | $ | int id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce A → ε |
| 0 2 | $ A | int id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 4|
| 0 2 4 | $ A int | id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce basic → int |
| 0 2 3 | $ A basic | id ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 7|
| 0 2 3 7 | $ A basic id | ( ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 8|
| 0 2 3 7 8 | $ A basic id ( | ) { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 9|
| 0 2 3 7 8 9 | $ A basic id ( ) | { real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 11|
| 0 2 3 7 8 9 11 | $ A basic id ( ) { | real id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 5|
| 0 2 3 7 8 9 11 5 | $ A basic id ( ) { real | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce basic → real |
| 0 2 3 7 8 9 11 12 | $ A basic id ( ) { basic | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 11 12 16 | $ A basic id ( ) { basic B | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 11 12 16 20 | $ A basic id ( ) { basic B array | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 11 13 | $ A basic id ( ) { type | id ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 17|
| 0 2 3 7 8 9 11 13 17 | $ A basic id ( ) { type id | ; int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 22|
| 0 2 3 7 8 9 11 13 17 22 | $ A basic id ( ) { type id ; | int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 11 15 | $ A basic id ( ) { decl | int id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 4|
| 0 2 3 7 8 9 11 15 4 | $ A basic id ( ) { decl int | id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce basic → int |
| 0 2 3 7 8 9 11 15 12 | $ A basic id ( ) { decl basic | id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 11 15 12 16 | $ A basic id ( ) { decl basic B | id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 11 15 12 16 20 | $ A basic id ( ) { decl basic B array | id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 11 15 13 | $ A basic id ( ) { decl type | id ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 17|
| 0 2 3 7 8 9 11 15 13 17 | $ A basic id ( ) { decl type id | ; int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 22|
| 0 2 3 7 8 9 11 15 13 17 22 | $ A basic id ( ) { decl type id ; | int [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 11 15 15 | $ A basic id ( ) { decl decl | int [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 4|
| 0 2 3 7 8 9 11 15 15 4 | $ A basic id ( ) { decl decl int | [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce basic → int |
| 0 2 3 7 8 9 11 15 15 12 | $ A basic id ( ) { decl decl basic | [ num ] id ; real [ num ] [ num ] id ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 11 15 15 12 16 | $ A basic id ( ) { decl decl basic B | [ num ] id ; real [ num ] [ num ] id ; } $ | Shift 21|
| 0 2 3 7 8 9 11 15 15 12 16 21 | $ A basic id ( ) { decl decl basic B [ | num ] id ; real [ num ] [ num ] id ; } $ | Shift 24|
| 0 2 3 7 8 9 11 15 15 12 16 21 24 | $ A basic id ( ) { decl decl basic B [ num | ] id ; real [ num ] [ num ] id ; } $ | Shift 25|
| 0 2 3 7 8 9 11 15 15 12 16 21 24 25 | $ A basic id ( ) { decl decl basic B [ num ] | id ; real [ num ] [ num ] id ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 11 15 15 12 16 21 24 25 26 | $ A basic id ( ) { decl decl basic B [ num ] array | id ; real [ num ] [ num ] id ; } $ | Reduce array → [ num ] array |
| 0 2 3 7 8 9 11 15 15 12 16 20 | $ A basic id ( ) { decl decl basic B array | id ; real [ num ] [ num ] id ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 11 15 15 13 | $ A basic id ( ) { decl decl type | id ; real [ num ] [ num ] id ; } $ | Shift 17|
| 0 2 3 7 8 9 11 15 15 13 17 | $ A basic id ( ) { decl decl type id | ; real [ num ] [ num ] id ; } $ | Shift 22|
| 0 2 3 7 8 9 11 15 15 13 17 22 | $ A basic id ( ) { decl decl type id ; | real [ num ] [ num ] id ; } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 11 15 15 15 | $ A basic id ( ) { decl decl decl | real [ num ] [ num ] id ; } $ | Shift 5|
| 0 2 3 7 8 9 11 15 15 15 5 | $ A basic id ( ) { decl decl decl real | [ num ] [ num ] id ; } $ | Reduce basic → real |
| 0 2 3 7 8 9 11 15 15 15 12 | $ A basic id ( ) { decl decl decl basic | [ num ] [ num ] id ; } $ | Reduce B → ε |
| 0 2 3 7 8 9 11 15 15 15 12 16 | $ A basic id ( ) { decl decl decl basic B | [ num ] [ num ] id ; } $ | Shift 21|
| 0 2 3 7 8 9 11 15 15 15 12 16 21 | $ A basic id ( ) { decl decl decl basic B [ | num ] [ num ] id ; } $ | Shift 24|
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 | $ A basic id ( ) { decl decl decl basic B [ num | ] [ num ] id ; } $ | Shift 25|
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 25 | $ A basic id ( ) { decl decl decl basic B [ num ] | [ num ] id ; } $ | Shift 21|
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 25 21 | $ A basic id ( ) { decl decl decl basic B [ num ] [ | num ] id ; } $ | Shift 24|
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 25 21 24 | $ A basic id ( ) { decl decl decl basic B [ num ] [ num | ] id ; } $ | Shift 25|
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 25 21 24 25 | $ A basic id ( ) { decl decl decl basic B [ num ] [ num ] | id ; } $ | Reduce array → ε |
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 25 21 24 25 26 | $ A basic id ( ) { decl decl decl basic B [ num ] [ num ] array | id ; } $ | Reduce array → [ num ] array |
| 0 2 3 7 8 9 11 15 15 15 12 16 21 24 25 26 | $ A basic id ( ) { decl decl decl basic B [ num ] array | id ; } $ | Reduce array → [ num ] array |
| 0 2 3 7 8 9 11 15 15 15 12 16 20 | $ A basic id ( ) { decl decl decl basic B array | id ; } $ | Reduce type → basic B array |
| 0 2 3 7 8 9 11 15 15 15 13 | $ A basic id ( ) { decl decl decl type | id ; } $ | Shift 17|
| 0 2 3 7 8 9 11 15 15 15 13 17 | $ A basic id ( ) { decl decl decl type id | ; } $ | Shift 22|
| 0 2 3 7 8 9 11 15 15 15 13 17 22 | $ A basic id ( ) { decl decl decl type id ; | } $ | Reduce decl → type id ; |
| 0 2 3 7 8 9 11 15 15 15 15 | $ A basic id ( ) { decl decl decl decl | } $ | Reduce decls → ε |
| 0 2 3 7 8 9 11 15 15 15 15 19 | $ A basic id ( ) { decl decl decl decl decls | } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 11 15 15 15 19 | $ A basic id ( ) { decl decl decl decls | } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 11 15 15 19 | $ A basic id ( ) { decl decl decls | } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 11 15 19 | $ A basic id ( ) { decl decls | } $ | Reduce decls → decl decls |
| 0 2 3 7 8 9 11 14 | $ A basic id ( ) { decls | } $ | Reduce stmts → ε |
| 0 2 3 7 8 9 11 14 18 | $ A basic id ( ) { decls stmts | } $ | Shift 23|
| 0 2 3 7 8 9 11 14 18 23 | $ A basic id ( ) { decls stmts } | $ | Reduce block → { decls stmts } |
| 0 2 3 7 8 9 10 | $ A basic id ( ) block | $ | Reduce program → A basic id ( ) block |
| 0 1 | $ program | $ | Accept|
