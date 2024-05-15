## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | ( digit + digit ) * digit $ |  |
| 0 | $ | ( digit + digit ) * digit $ | Shift 4|
| 0 4 | $ ( | digit + digit ) * digit $ | Shift 5|
| 0 4 5 | $ ( digit | + digit ) * digit $ | Reduce F → ( E ) |
| 3 | F | + digit ) * digit $ | Reduce T → T * F |
