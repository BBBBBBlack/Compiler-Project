## 可能需要的工作

### value处理
重构Token的value, 让value支持多种属性
- Token定义在Token.hpp
- 记得修改config的转换方式

那么词法分析传递的<type, value, lineno, pos>中的value应该如何处理
- 词法分析的value一定是终结符的value!
- 终结符的属性