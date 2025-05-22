ch - 'a' => use to find index from character

ch + 'a' => used to find charcter from index

1. std::vector
- push_back(element):
Appends element to the end of the vector. This operation typically has a time complexity of O(1), but it can be O(n) in the worst case if the vector needs to reallocate memory.<br>
- insert(position, element):
Inserts element at the specified position in the vector. This operation has a time complexity of O(n) because it may require shifting existing elements.
2. std::stack
- push(element): Adds element to the top of the stack. This operation has a time complexity of O(1).
3. std::queue
- push(element): Adds element to the back of the queue. This operation has a time complexity of O(1).
4. std::map
- map[key] = value:
If key exists, its value is updated to value. If key does not exist, a new key-value pair is inserted into the map.
- map.insert({key, value}):
Inserts the key-value pair only if the key does not already exist in the map.
- mp[i]++:
If mp is a std::map with integer keys, this increments the value associated with key i. If i doesn't exist, it creates mp[i] with a default value (usually 0) and then increments it to 1.
5. std::set
- insert(element): Inserts element into the set, maintaining the set's sorted order. If the element already exists, it is not inserted.
