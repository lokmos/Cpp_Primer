# set

`std::set` 是 C++ 标准模板库（STL）中提供的有序关联容器之一。它基于红黑树（`Red-Black Tree`）实现，用于存储一组唯一的元素，并按照元素的值进行排序。

以下是一些关键特性和操作：

- 唯一性： `std::set` 中不允许存储重复的元素，每个元素都是唯一的。插入重复元素的操作会被忽略。
- 有序性： `std::set` 中的元素是按照升序进行排序的。这种排序是通过红黑树的自平衡性质实现的，保证了插入、删除等操作的高效性。
- 插入元素： 使用 `insert` 成员函数可以将元素插入到集合中，如果元素已存在，则插入操作会被忽略。

# 内部原理

## 核心数据结构

`std::set` 是一个有序的关联容器，它使用红黑树（Red-Black Tree）实现，为存储唯一元素提供了高效的查找、插入和删除操作。可以说，`std::set`就是红黑树的一层封装

## 节点结构

`std::set` 中的每个元素都映射到红黑树的一个节点。由于红黑树保持了有序性和唯一性, 因此我们不需要对节点进行多余的处理, 只要保证节点数据类型支持比较运算符重载就可以了



# 补充

1. **如何检查 `std::set` 中是否存在某个值？**
   - 答：可以使用 `find` 方法检查 `std::set` 中是否存在某个值。如果找到元素，`find` 将返回一个指向该元素的迭代器，否则返回 `end()`。
2. **`std::set` 的迭代器是什么类型？**
   - 答：`std::set` 的迭代器是双向迭代器（`Bidirectional Iterator`）。可以向前（`++`）和向后（`--`）遍历集合，但不能进行随机访问。
3. **`std::set` 和 `std::unordered_set` 有什么区别？**
   - 答：`std::set` 是基于红黑树的，元素是排序的，而 `std::unordered_set` 是基于哈希表的，元素是无序的。因此，`std::set` 中的操作（如插入、删除和查找）通常具有对数时间复杂度（O(log n)），而 `std::unordered_set` 中的相应操作具有平均常数时间复杂度（O(1)），但在最坏情况下可能会退化到线性时间复杂度（O(n)）。
4. **`std::set`中的迭代器失效的情况有哪些？**
   - 答：在`std::set`中，迭代器的失效主要由元素的删除导致。当删除一个元素时，指向该元素的迭代器将失效。但是，由于红黑树的性质，删除操作不会影响到其他元素的迭代器，所以除了被删除元素的迭代器外，其他迭代器仍然有效。与此相反，插入操作不会导致现有迭代器失效，因为`std::set`的元素是不可变的，插入新元素不会改变已有元素的位置。
     - 树的结构发生变化不会影响已有元素的内存地址，所以迭代器依然有效