## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | ( digit + digit ) * digit $ |  |
| 0 | $ | ( digit + digit ) * digit $ | Shift 4|
| 0 4 | $ ( | digit + digit ) * digit $ | Shift 5|
| 0 4 5 | $ ( digit | + digit ) * digit $ | Reduce F → digit |
| 0 4 3 | $ ( F | + digit ) * digit $ | Reduce T → F |
| 0 4 2 | $ ( T | + digit ) * digit $ | Reduce E → T |
| 0 4 8 | $ ( E | + digit ) * digit $ | Shift 6|
| 0 4 8 6 | $ ( E + | digit ) * digit $ | Shift 5|
| 0 4 8 6 5 | $ ( E + digit | ) * digit $ | Reduce F → digit |
| 0 4 8 6 3 | $ ( E + F | ) * digit $ | Reduce T → F |
| 0 4 8 6 9 | $ ( E + T | ) * digit $ | Reduce E → E + T |
| 0 4 8 | $ ( E | ) * digit $ | Shift 11|
| 0 4 8 11 | $ ( E ) | * digit $ | Reduce F → ( E ) |
| 0 3 | $ F | * digit $ | Reduce T → F |
| 0 2 | $ T | * digit $ | Shift 7|
| 0 2 7 | $ T * | digit $ | Shift 5|
| 0 2 7 5 | $ T * digit | $ | Reduce F → digit |
| 0 2 7 10 | $ T * F | $ | Reduce T → T * F |
| 0 2 | $ T | $ | Reduce E → T |
| 0 1 | $ E | $ | Accept|
