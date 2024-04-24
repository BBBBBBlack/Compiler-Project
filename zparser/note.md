## 问题
### token与语法定义如何匹配

- 如对以下语法进行匹配
   - ParameterDeclaration  → TypeSpecifier Identifier
   - TypeSpecifier   → 'int' | 'char' | 'float' | 'double' | TypedefName
   - Identifier     → letter | Identifier letter | Identifier digit

  - 参考bison
    - 终结符: 对于长字符串的终结符, 必须在`enum Token`中进行声明, 单字符终结符可以直接使用ascii编码
    - 