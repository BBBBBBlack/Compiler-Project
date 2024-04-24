## 问题
### token与语法定义如何匹配

- 如对以下语法进行匹配
   - ParameterDeclaration  → TypeSpecifier Identifier
   - TypeSpecifier   → 'int' | 'char' | 'float' | 'double' | TypedefName
   - Identifier     → letter | Identifier letter | Identifier digit

  - 参考bison
    - 终结符: 对于长字符串的终结符, 必须在`enum Token`中进行声明, 单字符终结符可以直接使用ascii编码
    - 



## 语法分析配置文件

1. 声明 长终结符(string len > 1)
   - 长度为1的终结符: 用`‘’`包围
   - 
2. 声明产生式
   1. 产生式左项
   2. 产生式右项
   3. 规约的action
      - TODO 在action中实现对产生式右项的引用
3. 分析结果输出位置
4. 