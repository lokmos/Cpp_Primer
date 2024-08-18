# deque

C++ STL中的`deque`（双端队列）是一种在内存中存储元素的数据结构，它支持在两端添加和删除元素。

## 特性

- 双端操作： `deque`支持在前端和后端执行快速的插入和删除操作。

- 随机访问： 与list不同，`deque`允许在常量时间内对元素进行随机访问。这是因为`deque`的内部结构采用分段数组，而不是链表，从而提供了更好的随机访问性能。

  - 在C++中，std::`deque` 允许在常量时间内对元素进行随机访问，这意味着可以通过索引直接访问`deque`中的元素，而不会随`deque`的大小而增加访问时间。下面是一个简单的例子来说明这一点：

    ```CPP
    #include <iostream>
    #include <deque>
    
    int main() {
        // 创建一个包含一些元素的deque
        std::deque<int> myDeque = {1, 2, 3, 4, 5};
    
        // 在常量时间内对元素进行随机访问
        std::cout << "Element at index 2: " << myDeque[2] << std::endl;
        std::cout << "Element at index 4: " << myDeque[4] << std::endl;
    
        return 0;
    }
    ```

    在上面的例子中，`myDeque[2]` 和 `myDeque[4]` 的访问时间是常量的，不受deque的大小的影响。

    这是因为`std::deque` 使用了分段数组的结构，每个分段都是一个固定大小的数组，因此可以直接计算索引的位置，而不需要遍历整个容器。

    请注意，虽然 `std::deque` 允许在常量时间内对元素进行随机访问。

    但与 `std::vector` 相比，`std::deque` 在访问元素时可能涉及更多的间接层次，因此在一些情况下，`std::vector` 的随机访问性能可能略优。

    在选择容器时，需要根据具体的使用情况和需求权衡不同容器的优劣。

- 动态扩展： `deque`的大小可以动态调整，无需事先分配固定大小的内存。这使得`deque`适用于需要动态增长和缩小的情况。

- 保持迭代器有效性： `deque`在进行插入和删除操作时，能够更好地保持迭代器的有效性。这意味着在进行这些操作后，不会导致所有迭代器失效。

- 内存局部性： `deque`的内部结构利用了多个缓冲区，有助于提高内存局部性，从而在某些情况下提供更好的性能。



# 工作原理

`C++ STL中`的 `deque`（双端队列）确实规定了接口和时间复杂度，但没有规定特定的实现细节。`C++` 标准描述了每个容器的行为和性能要求，具体实现留给了实现者。

**采用循环数组来模拟双端队列**

- 数据结构
  - `elements`: 动态数组存储队列元素
  - `capacity`: 数组容量
  - `size`: 数组长度(已使用的容量)
  - `frontIndex` 和 `backIndex` : 分别指向队列的前端和后端元素。注意， 此处的`frontIndex`和`backIndex`类似标准`STL`中的`begin`和`end`, `frontIndex`位置指向的数据是已存在的(除了`deque`为空的情况), 而`backIndex`指向的位置是当前末尾元素的下一个位置, 也就是还没有有效的数据(如果容量满了, 其会指向`frontIndex`的位置)
- **循环数组**：通过模运算来实现数组的循环效果，使得队列可以在数组的任意一端进行插入和删除操作, 因为索引越界后直接取模从另一端开始就可以了。
- **动态调整大小**：当数组达到容量限制时，会自动扩展容量（加倍扩展），并将所有现有元素复制到新的更大的数组中。
- **索引计算**：利用模运算来正确计算新的 `frontIndex` 和 `backIndex`，无论是添加或删除操作。

以下是一个图示说明， 展示了`deque`在两端插入的逻辑:

![img](https://kstar-1253855093.cos.ap-nanjing.myqcloud.com/baguwen1.0/202404031651604.png)

- 无论是`push_front`还是`push_back`, 都需要判断当前数组是否已满, 已满的话将其扩容为原容量的2倍, 将原来的数组元素复制到新的数组中。
- `push_front`需要将`frontIndex`自减后在`frontIndex`位置插入, `frontIndex`自减后需要加上`capacity`后对`capacity`取模, 这使得如果`frontIndex`为负, `frontIndex`将指向从数组末尾
- `push_back`直接在`backIndex`位置插入, 然后将`backIndex`自增, `backIndex`自增后需要对`capacity`取模, 这使得如果`backIndex`越界, `backIndex`将指向从数组开始的位置