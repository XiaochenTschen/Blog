在 CMake 中，list() 指令用于操作和管理列表类型的数据。CMake 的列表实际上是由分号 (\;) 分隔的一串字符串，list() 命令提供了多种方法来操作这些列表，如添加、移除、查找和连接列表元素等.
下面是一个例子用来说明一些基本的用法。
```cmake
# 创建一个列表
set(my_list "apple" "banana" "cherry")

# 添加元素
list(APPEND my_list "date")

# 插入元素
list(INSERT my_list 1 "blueberry")

# 移除元素
list(REMOVE_ITEM my_list "banana")

# 获取列表长度
list(LENGTH my_list list_length)
message("The list length is ${list_length}")

# 查找元素位置
list(FIND my_list "cherry" cherry_index)
message("Cherry is at index ${cherry_index}")

# 获取元素
list(GET my_list 0 first_item)
message("The first item is ${first_item}")

# 连接元素
list(JOIN my_list ", " joined_string)
message("Joined list: ${joined_string}")
```
