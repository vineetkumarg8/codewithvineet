
# Iteration Types in C++ (Vector, Map, Unordered Map)

This document explains the 3 main ways to iterate through C++ containers such as `vector`, `map`, and `unordered_map`, with examples.

---

## 1. Range-Based For Loop (Modern C++ Style)

This is the cleanest and simplest way to iterate.

### Example (vector)

```cpp
for (int num : nums) {
    cout << num;
}
```

### Example (unordered_map)

```cpp
for (auto &p : mp) {
    cout << p.first << " " << p.second;
}
```

### Value Types

| Syntax | Meaning |
|--------|---------|
| `int num` | value copy |
| `int &num` | reference (modifies original) |
| `const int &num` | read-only reference, avoids copy |

---

## 2. Iterator-Based Loop

Used when you need full control, like deleting elements or manually moving the iterator.

### Example (vector)

```cpp
for (auto it = nums.begin(); it != nums.end(); it++) {
    cout << *it;
}
```

### Example (unordered_map)

```cpp
for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << " " << it->second;
}
```

---

## 3. Index-Based Loop

Works only for containers that support indexing (like `vector`, `string`).

### Example

```cpp
for (int i = 0; i < nums.size(); i++) {
    cout << nums[i];
}
```

❌ Not valid for `map` or `unordered_map`.

---

# Iterating Through `unordered_map`: All 3 Ways

### 1. Range-Based Loop

```cpp
for (auto &entry : mp) {
    cout << entry.first << " " << entry.second;
}
```

### 2. Iterator-Based Loop

```cpp
for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << " " << it->second;
}
```

### 3. Structured Bindings (C++17)

```cpp
for (auto &[key, value] : mp) {
    cout << key << " " << value;
}
```

---

# Summary Table

| Loop Type | Works on Vector | Works on Map | Best Use Case |
|-----------|----------------|--------------|----------------|
| **Range-based** | ✅ | ✅ | Simple, clean iteration |
| **Iterator-based** | ✅ | ✅ | Need control (erase/skip) |
| **Index-based** | ✅ | ❌ | Need index, random access |

