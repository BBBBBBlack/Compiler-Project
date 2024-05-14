## zparser使用流程

> v0.1, 待改进

1. 编写config.json
2. 运行自动机, 生成`parse.cpp`和`parseTab.md`
   - `parse.cpp`: 保存产生式action, main函数调用
   - `parseTab.md`: 保存分析表
   - TODO: 将这个步骤封装成一个可执行文件: `ZTableGenerator`
3. 编译`parse.cpp`为可执行文件`ZParser`
   - TODO: 将这步也封到`ZTableGenerator`
4. 运行`ZParser`

## config使用说明
### config.md
参考test/config.json的结构, 需要配置
- parseTabFile: string, 分析表文件位置
- copy: \[可选项\] string array, 复制到parse.cpp的代码段
- rules: 产生式
  - left: 产生式左部
  - rights: 相同左部下的右部
    - right: string, 产生式右部内容, 终结符用`' '`进行包围
    - action: string array, 产生式action

会生成parse.cpp(可修改)用于保存产生式, 调用Parser
TODO 修改CMakeLists.txt 为生成的.cpp添加可执行文件的编译项 (参考test)

### parse.cpp
Usage: ./GenParseTest
 -i/--input     <token file>
 -t/--table     <table file>
 -o/--output    <output file>
 -p/--process   <process file>

也可以直接查看生成的.cpp 不算复杂

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

