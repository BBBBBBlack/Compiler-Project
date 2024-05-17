## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | ( digit + ) * digit $ |  |
| 0 | $ | ( digit + ) * digit $ | Shift 4|
| 0 4 | $ ( | digit + ) * digit $ | Shift 5|
| 0 4 5 | $ ( digit | + ) * digit $ | Reduce F → digit |
| 0 4 3 | $ ( F | + ) * digit $ | Reduce T → F |
| 0 4 2 | $ ( T | + ) * digit $ | Reduce E → T |
| 0 4 8 | $ ( E | + ) * digit $ | Shift 6|
| 0 4 8 6 | $ ( E + | ) * digit $ | Error|
