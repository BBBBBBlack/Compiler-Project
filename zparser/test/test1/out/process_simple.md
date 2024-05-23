## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | digit + digit * digit $ |  |
| 0 | $ | digit + digit * digit $ | Shift 2|
| 0 2 | $ digit | + digit * digit $ | Reduce E → digit |
| 0 1 | $ E | + digit * digit $ | Shift 4|
| 0 1 4 | $ E + | digit * digit $ | Shift 2|
| 0 1 4 2 | $ E + digit | * digit $ | Reduce E → digit |
| 0 1 4 6 | $ E + E | * digit $ | Shift 3|
| 0 1 4 6 3 | $ E + E * | digit $ | Shift 2|
| 0 1 4 6 3 2 | $ E + E * digit | $ | Reduce E → digit |
| 0 1 4 6 3 5 | $ E + E * E | $ | Reduce E → E * E |
| 0 1 4 6 | $ E + E | $ | Reduce E → E + E |
| 0 1 | $ E | $ | Accept|
