## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | real id ; int id ; int [ num ] id ; $ |  |
| 0 | $ | real id ; int id ; int [ num ] id ; $ | Reduce M → ε |
| 0 2 | $ M | real id ; int id ; int [ num ] id ; $ | Shift 4|
| 0 2 4 | $ M real | id ; int id ; int [ num ] id ; $ | Reduce B → real |
| 0 2 6 | $ M B | id ; int id ; int [ num ] id ; $ | Reduce E → ε |
| 0 2 6 8 | $ M B E | id ; int id ; int [ num ] id ; $ | Reduce C → ε |
| 0 2 6 8 11 | $ M B E C | id ; int id ; int [ num ] id ; $ | Reduce T → B E C |
| 0 2 7 | $ M T | id ; int id ; int [ num ] id ; $ | Shift 9|
| 0 2 7 9 | $ M T id | ; int id ; int [ num ] id ; $ | Shift 12|
| 0 2 7 9 12 | $ M T id ; | int id ; int [ num ] id ; $ | Reduce A → ε |
| 0 2 7 9 12 14 | $ M T id ; A | int id ; int [ num ] id ; $ | Shift 5|
| 0 2 7 9 12 14 5 | $ M T id ; A int | id ; int [ num ] id ; $ | Reduce B → int |
| 0 2 7 9 12 14 6 | $ M T id ; A B | id ; int [ num ] id ; $ | Reduce E → ε |
| 0 2 7 9 12 14 6 8 | $ M T id ; A B E | id ; int [ num ] id ; $ | Reduce C → ε |
| 0 2 7 9 12 14 6 8 11 | $ M T id ; A B E C | id ; int [ num ] id ; $ | Reduce T → B E C |
| 0 2 7 9 12 14 7 | $ M T id ; A T | id ; int [ num ] id ; $ | Shift 9|
| 0 2 7 9 12 14 7 9 | $ M T id ; A T id | ; int [ num ] id ; $ | Shift 12|
| 0 2 7 9 12 14 7 9 12 | $ M T id ; A T id ; | int [ num ] id ; $ | Reduce A → ε |
| 0 2 7 9 12 14 7 9 12 14 | $ M T id ; A T id ; A | int [ num ] id ; $ | Shift 5|
| 0 2 7 9 12 14 7 9 12 14 5 | $ M T id ; A T id ; A int | [ num ] id ; $ | Reduce B → int |
| 0 2 7 9 12 14 7 9 12 14 6 | $ M T id ; A T id ; A B | [ num ] id ; $ | Reduce E → ε |
| 0 2 7 9 12 14 7 9 12 14 6 8 | $ M T id ; A T id ; A B E | [ num ] id ; $ | Shift 10|
| 0 2 7 9 12 14 7 9 12 14 6 8 10 | $ M T id ; A T id ; A B E [ | num ] id ; $ | Shift 13|
| 0 2 7 9 12 14 7 9 12 14 6 8 10 13 | $ M T id ; A T id ; A B E [ num | ] id ; $ | Shift 15|
| 0 2 7 9 12 14 7 9 12 14 6 8 10 13 15 | $ M T id ; A T id ; A B E [ num ] | id ; $ | Reduce C → ε |
| 0 2 7 9 12 14 7 9 12 14 6 8 10 13 15 17 | $ M T id ; A T id ; A B E [ num ] C | id ; $ | Reduce C → [ num ] C |
| 0 2 7 9 12 14 7 9 12 14 6 8 11 | $ M T id ; A T id ; A B E C | id ; $ | Reduce T → B E C |
| 0 2 7 9 12 14 7 9 12 14 7 | $ M T id ; A T id ; A T | id ; $ | Shift 9|
| 0 2 7 9 12 14 7 9 12 14 7 9 | $ M T id ; A T id ; A T id | ; $ | Shift 12|
| 0 2 7 9 12 14 7 9 12 14 7 9 12 | $ M T id ; A T id ; A T id ; | $ | Reduce A → ε |
| 0 2 7 9 12 14 7 9 12 14 7 9 12 14 | $ M T id ; A T id ; A T id ; A | $ | Reduce D → ε |
| 0 2 7 9 12 14 7 9 12 14 7 9 12 14 16 | $ M T id ; A T id ; A T id ; A D | $ | Reduce D → T id ; A D |
| 0 2 7 9 12 14 7 9 12 14 16 | $ M T id ; A T id ; A D | $ | Reduce D → T id ; A D |
| 0 2 7 9 12 14 16 | $ M T id ; A D | $ | Reduce D → T id ; A D |
| 0 2 3 | $ M D | $ | Reduce P → M D |
| 0 1 | $ P | $ | Accept|
