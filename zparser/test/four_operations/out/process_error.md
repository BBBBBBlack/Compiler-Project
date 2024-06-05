## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | digit + ( digit * digit ) / ( digit * ( digit + digit ) $ |  |
| 0 | $ | digit + ( digit * digit ) / ( digit * ( digit + digit ) $ | Shift 3|
| 0 3 | $ digit | + ( digit * digit ) / ( digit * ( digit + digit ) $ | Reduce E → digit |
| 0 1 | $ E | + ( digit * digit ) / ( digit * ( digit + digit ) $ | Shift 4|
| 0 1 4 | $ E + | ( digit * digit ) / ( digit * ( digit + digit ) $ | Shift 2|
| 0 1 4 2 | $ E + ( | digit * digit ) / ( digit * ( digit + digit ) $ | Shift 3|
| 0 1 4 2 3 | $ E + ( digit | * digit ) / ( digit * ( digit + digit ) $ | Reduce E → digit |
| 0 1 4 2 8 | $ E + ( E | * digit ) / ( digit * ( digit + digit ) $ | Shift 5|
| 0 1 4 2 8 5 | $ E + ( E * | digit ) / ( digit * ( digit + digit ) $ | Shift 3|
| 0 1 4 2 8 5 3 | $ E + ( E * digit | ) / ( digit * ( digit + digit ) $ | Reduce E → digit |
| 0 1 4 2 8 5 10 | $ E + ( E * E | ) / ( digit * ( digit + digit ) $ | Reduce E → E * E |
| 0 1 4 2 8 | $ E + ( E | ) / ( digit * ( digit + digit ) $ | Reduce E → ( E |
| 0 1 4 9 | $ E + E | ) / ( digit * ( digit + digit ) $ | Reduce E → E + E |
