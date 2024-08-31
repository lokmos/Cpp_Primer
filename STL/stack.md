# stack

在C++ STL（标准模板库）中，栈被实现为一个容器适配器，提供了简化的接口，允许开发人员轻松使用栈数据结构。

# 特性

基于容器 C++ STL 中的 `std::stack` 是一个**容器适配器**，它**不是一个独立的数据结构**，而是构建在其他容器之上的。默认情况下，`std::stack` 使用 `std::deque` 作为其底层容器，但也可以选择使用 `std::vector、std::list` 等其他容器来作为底层支持。

# 性能

`std::stack` 的性能通常取决于其底层容器的性能特征。

- 默认情况下，使用 std::deque 作为底层容器，它在大多数操作的情况下具有很好的性能。
- 使用 std::vector 作为底层容器：具有快速的随机访问性能，但在插入和删除元素时可能效率较低。 
- 使用 std::list 作为底层容器：具有快速的插入和删除性能，但随机访问较慢。 

# 补充

1. **什么是栈溢出（Stack Overflow）？**
   * 栈溢出在两种情况下发生：一是在一个已经满了的栈上执行 `push` 操作；二是在一个空栈上执行 `pop` 操作。在计算机程序中，栈溢出通常指的是程序调用的栈空间超出了系统所分配的内存限制，这可能导致程序崩溃。
2. **如何用栈实现递归函数的非递归版本**
   - 要将递归函数转换为非递归版本，可以使用栈来模拟递归调用的过程。栈用于存储函数调用的状态（如函数参数、局部变量等），当需要“递归”调用时，将当前状态保存到栈中，然后处理下一层调用。