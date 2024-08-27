# multiset

`multiset` 是一个有序容器，允许存储多个相同的元素，并按照元素的值进行排序。`multiset` 的内部通常基于红黑树实现。

# 特性

1. 有序性 
   - `multiset` 中的元素是有序的，即按照元素的值进行升序排序。这使得在 multiset 中的元素可以很方便地进行有序访问。
2. 允许重复元素 
   - 与 `set` 不同，`multiset` 允许存储相同的元素多次。这意味着可以在 multiset 中存储相同值的多个元素，并且它们在排序后会依然保持有序。
3. 基于红黑树实现 
   - `multiset` 的内部通常基于红黑树实现。红黑树是一种自平衡的二叉搜索树，确保了插入、删除和查找等操作的高效性能。

# 性能

1. 插入和删除性能 
   - 由于 `multiset` 内部使用红黑树实现，插入和删除元素的性能通常是很好的，平均情况下时间复杂度为 O(log n)。
2. 查找性能 
   - 红黑树的有序性使得查找操作也具有很好的性能，平均情况下时间复杂度为 O(log n)。
3. 内存开销 
   - `multiset` 的内部实现通常需要额外的内存来存储红黑树的节点，因此在内存开销上相对于一些其他容器可能会更高一些。
4. 应用场景 
   - `multiset` 适用于需要有序存储允许重复元素的场景，例如需要维护一个按照时间戳排序的事件集合。

# 工作原理

在 multiset 中，为了存储重复元素，红黑树的每个节点都包含一个键和一个计数器，用于表示该键在 multiset 中的出现次数。

在插入元素时，如果键已经存在于红黑树中，则将计数器加 1；如果键不存在于红黑树中，则插入一个新的节点，并将计数器初始化为 1。

在删除元素时，如果计数器大于 1，则将计数器减 1；如果计数器等于 1，则从红黑树中删除该节点。

在查找元素时，红黑树的查找操作可以找到包含该键的节点，并返回该节点的计数器值。



# 补充

1. 解释`multiset`和`Set`的区别是什么？ 

   - `multiset`和`Set`都是关联容器，它们可以存储元素，并能够快速检索。它们之间的主要区别在于`multiset`允许存储重复的元素，而`Set`不允许重复元素。这意味着在`multiset`中，可以有多个相同的键值，每个键值都会被计数；而在`Set`中，同一个键值只能出现一次。

2. 在`multiset`中如何统计一个元素的出现次数？ 

   - 在`multiset`中，可以通过`count`成员函数来统计某个元素的出现次数。以下是如何使用`count`函数的示例代码：

   ```cpp
   multiset<int> mymultiset;
   // ... (代码中添加一些元素到mymultiset中) ...
   int count = mymultiset.count(5); // 统计元素5出现的次数
   ```