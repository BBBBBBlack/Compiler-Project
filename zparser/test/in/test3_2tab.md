## Parse Table
- Terminal size : 3
- Non-terminal size : 3
- State size : 8

|     | ACT |     |     | GOTO |     |     |
| --- | --- | --- | --- | ---- | --- | --- |
|     | `a` | `b` | `$` | `S`  | `A` | `B` |
| 0   | S4  | S7  | R3  | G1   | G2  | G3  |
| 1   |     |     | ACC |      |     |     |
| 2   |     |     | R1  |      |     |     |
| 3   | S4  | S7  | R3  |      | G5  | G3  |
| 4   | S4  | S7  |     |      |     | G6  |
| 5   |     |     | R2  |      |     |     |
| 6   | R4  | R4  | R4  |      |     |     |
| 7   | R5  | R5  | R5  |      |     |     |
