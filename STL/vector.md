# Vector

`std::vector` 是一个动态数组，它在内存中以连续的块存储元素。与静态数组相比，`std::vector` 允许在运行时动态调整大小，而无需手动管理内存。

# 内存管理

`std::vector` 维护了两个重要的状态信息：容量（capacity）和大小（size）。

- 容量表示当前 vector 分配的内存空间大小
- 大小表示 vector **当前包含**的元素数量。
- 当向 vector 中添加元素时，如果元素数量超过了容量，就需要进行内存重新分配。

## 内存分配和释放

当容量不足以容纳新元素时，`std::vector` 会分配一块新的内存空间，将原有元素复制到新的内存中，然后释放原内存。这个过程确保了元素的连续存储。



## 动态扩容策略

为了提高性能，`std::vector` 采用了一种称为“指数增长（`exponential growth`）”的策略进行动态扩容。

- 当需要进行扩容时，`std::vector` 通常会将容量翻倍，以避免频繁的内存分配操作，从而减少系统开销。

这种指数增长策略确保了平均情况下的插入操作具有**常数时间复杂度**，而不是线性时间复杂度。



## 随机访问和迭代器

`std::vector` 提供了高效的随机访问能力，即通过索引直接访问元素。

- 因为元素在内存中是连续存储的，通过简单的指针运算即可实现 O(1) 时间复杂度的访问。



# 工作原理

`C++`中`vector`的数组内存通常是在堆上分配的。

- 当创建一个`vector`对象时，对象本身（即`vector`的控制结构，包括指向数据的指针、大小和容量等）通常存储在栈上（如果是局部变量）或其他存储区（如全局/静态存储区）
- 但实际的元素数据是在堆上分配的。

这种设计允许`vector`在运行时动态增长和收缩，因为堆是用于动态内存分配的区域，没有固定的大小限制（除了可用内存的物理限制）。当调用`vector`的`push_back`等方法时，`vector`可能会重新分配其底层的动态数组以适应新元素。这通常涉及申请新的更大的内存块，复制现有元素到新内存，添加新元素，然后释放旧的内存块。在`C++`官方实现的`vector`中，这种动态内存管理通常是通过分配器来完成的，`vector`使用一个默认的分配器`std::allocator`，它封装了动态内存分配函数，如`new`和`delete`。开发者也可以为`vector`提供自定义的分配器，以适应特定的内存分配策略。

![img](assets/202404031640461.png)

1. 虚线以上的内存为**栈内存**，虚线以下的内存为**堆内存**
2. 红色区域为`vector`对象控制结构存储的位置
3. **紫色区域**和**灰色区域**为存储元素的数组的位置, 其中**紫色区域**表示已经使用, **灰色区域**表示未使用

# 实现

## 私有成员

1. 指向动态数组的指针
2. 容量
3. 当前大小（数组中元素的个数）

## 成员函数

1. **构造函数**

```cpp
Vector() : elements(nullptr), capacity(0), size(0) {}
```

- 初始化 `Vector` 对象，其中 `elements` 是指向 `T` 类型动态数组的指针，初始时没有分配内存（`nullptr`）；
- `capacity` 表示数组的容量，初始为 0；
- `size` 表示数组中当前元素的数量，初始也为 0。

2. **析构函数**

```cpp
~Vector() {
    delete[] elements;
}
```

- 当 `Vector` 对象被销毁时，析构函数释放 `elements` 指向的动态分配的内存。

3. **拷贝构造函数**

```cpp
Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
    elements = new T[capacity];
    std::copy(other.elements, other.elements + size, elements);
}
```

- 用于创建一个新的 `Vector` 对象，它是另一个 `Vector` 对象的副本；
- 分配与原始 `Vector` 相同的容量；
- 将原始 `Vector` 中的元素复制到新对象中。
- std::copy的用法 是一个标准库算法，通常用于从一个容器复制元素到另一个容器。std::copy需要三个参数：两个指定要复制的元素范围的迭代器（起始迭代器和结束迭代器），以及一个指向目标位置开始的迭代器。 指针也是一种天然的迭代器

4. **拷贝赋值操作符**

```cpp
Vector& operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        std::copy(other.elements, other.elements + size, elements);
    }
    return *this;
}
```

- 允许将一个 `Vector` 对象的值赋给另一个 `Vector` 对象；
- 首先检查自赋值的情况，如果不是自赋值，则释放当前对象的内存；
- 分配新内存，并复制所有元素；
- 返回对当前对象的引用。

5. **`push_back` 函数**

```cpp
void push_back(const T& value) {
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : 2 * capacity);
    }
    elements[size++] = value;
}
```

- 在 `Vector` 的末尾添加一个新元素；
- 如果当前没有足够的容量来存储新元素，则通过 `reserve` 函数扩展数组的容量；
- 将新元素添加到数组的末尾，并递增 `size`。
- 不能简单的将`capacity`容量翻倍, 需要考虑0的边界情况

6. **`getSize` 和 `getCapacity` 函数**

```cpp
size_t getSize() const {
    return size;
}

size_t getCapacity() const {
    return capacity;
}
```

- `getSize` 返回 `Vector` 中的元素数量；
- `getCapacity` 返回 `Vector` 的容量。

7. **下标操作符**

```cpp
T& operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

const T& operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
```

- 允许通过下标来访问 `Vector` 中的元素；
- 如果指定的下标越界（大于或等于 `size`），则抛出 `std::out_of_range` 异常；
- 分为 `const` 和 `non-const` 版本。

8. **`insert` 函数**

```cpp
void insert(size_t index, const T& value) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    for (size_t i = size; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    ++size;
}
```

- 在 `Vector` 的指定位置 `index` 插入一个元素 `value`；
- 如果 `index` 大于 `size`，则抛出 `std::out_of_range` 异常；
- 如果当前没有足够的容量来存储新元素，则通过 `reserve` 函数扩展数组的容量；
- 将 `index` 之后的所有元素向后移动一个位置，为新元素腾出空间；
- 将新元素放置在 `index` 位置；
- 增加 `Vector` 的 `size`。

9. **`pop_back` 函数**

```cpp
void pop_back() {
    if (size > 0) {
        --size;
    }
}
```

- 删除 `Vector` 末尾的元素；
- 减少 `Vector` 的 `size`；
- 不实际释放内存，这意味着即使调用了 `pop_back`，`capacity` 保持不变

10. **`clear` 函数**

```cpp
void clear() {
    size = 0;
}
```

- 清空 `Vector` 中的所有元素；
- 设置 `size` 为 0；
- 类似 `pop_back`，`clear` 不释放内存，`capacity` 保持不变。

11. **迭代器相关函数 `begin` 和 `end`**

```cpp
T* begin() {
    return elements;
}

T* end() {
    return elements + size;
}

const T* begin() const {
    return elements;
}

const T* end() const {
    return elements + size;
}
```

- `begin` 和 `end` 函数提供了遍历 `Vector` 的能力；
- 非 `const` 版本返回指向 `elements` 的指针，可以用来修改 `Vector` 中的元素；
- `const` 版本返回 `const` 指针，用于只读访问；
- `begin` 返回指向第一个元素的指针；
- `end` 返回指向最后一个元素之后的位置的指针，通常用于表示范围的结束。

12. **`printElements` 函数**

    ```cpp
    void printElements() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
    ```

    - 打印 `Vector` 中的所有元素；
    - 遍历 `Vector`，并使用 `std::cout` 打印每个元素；
    - 这个函数不修改 `Vector` 的内容，所以被声明为 `const`



# 和STL的区别

上面的代码实现了一个简化版的 `MyVector` 类，但在实际应用中存在一些关键区别。以下是其中一些主要区别：

1. 不同的实现复杂度：

   - C++ 标准库中的 `std::vector` 是经过精心设计和优化的，实现考虑了许多细节，以提供高性能和通用性。它使用了更复杂的内存管理和算法，以在各种情况下提供高效的性能。

   - 上面的 `MyVector` 类是一个简单的示例，虽然它模拟了一些 `std::vector` 的基本行为，但它的实现远不及标准库版本的复杂和高效。

2. 不同的功能覆盖范围：

   - C++ 标准库中的 `std::vector` 提供了更多的功能，包括但不限于迭代器范围操作、成员函数和算法。标准库中的 `std::vector` 还具有更多的配置选项，例如分配器、自定义比较函数等。

   - `MyVector` 类只实现了一些基本的功能，例如插入、删除、访问元素等，而没有涵盖 `std::vector` 的所有功能和特性。

3. 内存管理和性能：

   - C++ 标准库中的 `std::vector` 在内存管理和性能方面进行了更复杂的优化。它采用更智能的内存分配策略，通过预留一定的额外容量来减少频繁的内存分配和释放操作。

   - `MyVector` 类的内存管理相对较简单，每次插入元素时都可能触发内存重新分配，可能导致性能瓶颈。

4. 安全性和健壮性：

   - C++ 标准库中的 `std::vector` 实现了许多安全性和健壮性的机制，例如范围检查、异常处理等。它会在越界访问等错误情况下提供保护。

   - `MyVector` 类并未实现这些安全性检查，因此在特定条件下可能导致未定义行为。

# 补充知识点

### 1. `std::vector`的扩容过程

当向 `std::vector` 添加元素并且当前容量不足以容纳新元素时，`std::vector` 会进行扩容。这通常涉及以下步骤：

1. 分配一个更大的内存块，通常是当前大小的两倍（这个增长因子取决于实现）。
2. 将当前所有元素移到新分配的内存中。
3. 销毁旧元素，并释放旧内存块。
4. 插入新元素。

这个过程中的复制和移动操作可能会导致性能开销，尤其当元素具有复杂的拷贝构造函数或移动构造函数时。

### 2. 解释 `std::vector::push_back` 和 `std::vector::emplace_back` 的区别。

`std::vector::push_back` 和 `std::vector::emplace_back` 都是在 `std::vector` 的末尾添加一个新元素，但它们添加元素的方式不同。

- `push_back` 会对给定的对象进行拷贝或移动构造，以将元素添加到 `vector` 的末尾。
- `emplace_back` 则使用给定的参数直接在 `vector` 的末尾构造一个元素，无需拷贝或移动操作，这通常更高效。

### 3. 什么时候会使用 `std::vector::reserve()`？

`std::vector::reserve()` 用于预分配内存，以避免在添加新元素时重新分配内存。当知道将要存储大量元素，但又不想在每次插入时都可能发生内存重新分配时，使用 `reserve()` 可以提高性能。这样可以减少因扩容导致的不必要的内存分配和元素拷贝。

### 4. 如何减少 `std::vector` 占用的空间？

可以使用 `std::vector::shrink_to_fit` 方法来请求移除未使用的容量，减少 `vector` 的内存使用。这个函数是 C++11 引入的，它会尝试压缩 `std::vector` 的容量，使其等于其大小。但是，这只是一个请求，并不保证容量会减少，因为这依赖于实现。

### 5. 如何检查 `std::vector` 是否为空？

使用 `std::vector::empty()` 方法可以检查 `vector` 是否没有元素。这比使用 `size()` 方法（比较 `size() == 0`）更首选，因为 `empty()` 通常可以保证是常数时间复杂度的操作。

### 6. 什么是迭代器失效? 如何避免?

当 `vector` 进行操作，如增加或删除元素，尤其是在中间插入或删除元素时，迭代器可能会失效。例如：

- 如果 `vector` 进行了重新分配，所有指向元素的迭代器都会失效。
- 如果在 `vector` 中间插入或删除元素，从该点到末尾的所有迭代器都会失效。

解决方案是最好使用标准库提供的算法，如 `std::remove` 和 `std::remove_if` 结合 `vector::erase` 方法来删除元素。这些算法在设计时已经考虑了迭代器失效的问题。

### 7. 如果 `std::vector` 的元素是指针，需要注意什么？

当 `vector` 的元素是指针对 `std::vector` 元素为指针的情况，需要注意以下几点：

1. **内存管理**：如果 `std::vector` 存储的是原始指针，那么仅仅清空 `vector` 或者让 `vector` 被销毁，并不会释放指针所指向的内存。因此，需要确保在 `vector` 被销毁之前，逐个删除所有动态分配的对象。
2. **所有权和生命周期**：需要确保在 `vector` 所包含的指针被使用期间，指向的对象是有效的。同时，需要清楚地定义谁拥有这些对象的所有权，以及在何时何地进行释放。
3. **异常安全**：如果在创建和填充 `vector` 的过程中遇到异常，需要有一个清晰的机制来处理已经分配的内存，以避免内存泄漏。
4. **智能指针**：为了简化内存管理，推荐使用智能指针（如 `std::unique_ptr` 或 `std::shared_ptr`）作为 `vector` 的元素类型。这样，当 `vector` 被清空或销毁时，智能指针会自动释放它们所拥有的资源。
5. **避免悬垂指针**：当指针指向的对象被删除或移动时，需要确保没有悬垂指针指向无效的内存地址。同样，当 `vector` 被重新分配时，如果存储的是指向其他元素的指针，这些指针也会失效。
6. **深拷贝与浅拷贝**：如果需要复制这样的 `vector`，就需要决定是进行深拷贝（复制指针指向的对象）还是浅拷贝（仅复制指针本身）。正确地选择取决于应用需求和所有权策略。
