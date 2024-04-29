## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | a b a b $ |  |
| 0 | $ | a b a b $ | Shift 4|
| 0 4 | $ a | b a b $ | Shift 7|
| 0 4 7 | $ a b | a b $ | Reduce B->b |
| 0 4 -1 | $ a B | a b $ | Error|
