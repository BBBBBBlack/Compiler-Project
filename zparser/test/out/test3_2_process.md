## 分析过程
| 状态栈 | 符号栈 | 输入串 | 动作 |
| --- | --- | ---: | --- |
| 0 | $ | a b a b $ |  |
| 0 | $ | a b a b $ | Shift 4|
| 0 4 | $ a | b a b $ | Shift 7|
| 0 4 7 | $ a b | a b $ | Reduce B->b |
| 0 4 6 | $ a B | a b $ | Reduce B->a B |
| 0 3 | $ B | a b $ | Shift 4|
| 0 3 4 | $ B a | b $ | Shift 7|
| 0 3 4 7 | $ B a b | $ | Reduce B->b |
| 0 3 4 6 | $ B a B | $ | Reduce B->a B |
| 0 3 3 | $ B B | $ | Reduce A->ε |
| 0 3 3 5 | $ B B A | $ | Reduce A->B A |
| 0 3 5 | $ B A | $ | Reduce A->B A |
| 0 2 | $ A | $ | Reduce S->A |
| 0 1 | $ S | $ | Accept|
