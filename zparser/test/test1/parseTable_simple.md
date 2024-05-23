## Parse Table
- Terminal size : 4
- Non-terminal size : 1
- State size : 7

| | ACT |  |  |  | GOTO | 
| --- | --- | --- | --- | --- | --- | 
| | $ | digit | + | * | E | 
| 0 |   | S2 |   |   | G1 | 
| 1 | ACC |   | S4 | S3 |   | 
| 2 | R3 |   | R3 | R3 |   | 
| 3 |   | S2 |   |   | G5 | 
| 4 |   | S2 |   |   | G6 | 
| 5 | R1 |   | S4 | S3 |   | 
| 6 | R2 |   | S4 | S3 |   | 
