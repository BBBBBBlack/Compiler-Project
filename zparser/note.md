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

### 项目结构

- 架构错误: 错误的将分析表额外存储(为了好看还用了md 太蠢啦)
  - 起因: 对于action, 可能必须硬编码为.cpp, 不能持久化 → 写入parse.cpp, 然后将其编译为可执行文件
  - 结论: 那么这个可执行文件只能分析一类语法, 使用的分析表也是固定的
  - 修改方向: 将table也硬编码到parse.cpp中


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

## 语义分析问题记录

### 回填

1. truelist和falselist
   - 对于true, 没有falselist; 对于false, 没有truelist, 这是正确的, 但是代码中可能要进行处理
2. 对于nextlist的回填, 是在控制语句之外, 对stmts进行回填的, 所以ppt上空缺了

### CST遗留问题

没有查看实验要求&没有学习语义分析, 在实现语法分析时就将cst结构和语法分析(自底向上)过程耦合起来

- 具体为tokenStack中不仅有token, 还有CST的Node的id
  - 实际上这个id应该作为token的属性来存储