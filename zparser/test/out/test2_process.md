## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | x x y $ |  |
| 0 | $ | x x y $ | Shift 1|
| 0 1 | $ x | x y $ | Shift 2|
| 0 1 2 | $ x x | y $ | Shift 3|
| 0 1 2 3 | $ x x y | $ | Reduce T->y |
| 0 1 2 4 | $ x x T | $ | Reduce S->x x T |
| 0 5 | $ S | $ | Accept|
| 0 5 | $ S | $ | Accept|
