# s21_containers

 В рамках данного группового проекта реализованы основные стандартные контейнерные классы языка С++: `list` (список), `map` (словарь), `queue` (очередь), `set` (множество), `stack` (стек), `vector` (вектор), `array` (массив), `multiset` (мультимножество).  
 Я писал `vector`, `array`, также совместно с сокомандниками реализовывал `list`, `queue` и `stack`.


## Project build

Сборка проекта осуществляется командой `make` в папке `src`, существуют следующие цели:  
- `test` - запуск общего тестирования,  
- `valgrind` - проверка на утечки утилитой valgrind,  
- `docker_[ос]` - тестирование и проверка на утечки через docker в системе ubuntu,  
- `clean` - очистить проект от временных файлов.

## Реализация

- Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc
- Код программы находится в папке src
- При написании кода соблюдён Google Style
- Используются итераторы
- Классы реализованы с помощью шаблонов
- Классы реализованы внутри пространства имен `s21`
- Подготовлено полное покрытие unit-тестами методов контейнерных классов c помощью библиотеки GTest
- Соблюдена логика работы стандартной библиотеки шаблонов (STL)

## Описание методов контейнеров

### List

<details>
  <summary>Спецификация</summary>
<br />

*List Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | internal class `ListIterator<T>` defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `ListConstIterator<T>` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*List Functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `list()`  | default constructor, creates empty list                                  |
| `list(size_type n)`  | parameterized constructor, creates the list of size n                                 |
| `list(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates list initizialized using std::initializer_list<T>    |
| `list(const list &l)`  | copy constructor  |
| `list(list &&l)`  | move constructor  |
| `~list()`  | destructor  |
| `operator=(list &&l)`      | assignment operator overload for moving object                                |

*List Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*List Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*List Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*List Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts element into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void push_front(const_reference value)`      | adds an element to the head                      |
| `void pop_front()`   | removes the first element        |
| `void swap(list& other)`                   | swaps the contents                                                                     |
| `void merge(list& other)`                   | merges two sorted lists                                                                      |
| `void splice(const_iterator pos, list& other)`                   | transfers elements from list other starting from pos             |
| `void reverse()`                   | reverses the order of the elements              |
| `void unique()`                   | removes consecutive duplicate elements               |
| `void sort()`                   | sorts the elements                |

</details>


### Map

<details>
  <summary>Спецификация</summary>
<br />

*Map Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `mapped_type`           | `T` the second template parameter (T)                                                      |
| `value_type`             | `std::pair<const key_type,mapped_type>` Key-value pair                                                      |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `MapIterator<K, T>` or `BinaryTree::iterator` as internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `MapConstIterator<K, T>` or `BinaryTree::const_iterator` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Map Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `map()`  | default constructor, creates empty map                                 |
| `map(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the map initizialized using std::initializer_list<T>    |
| `map(const map &m)`  | copy constructor  |
| `map(map &&m)`  | move constructor  |
| `~map()`  | destructor  |
| `operator=(map &&m)`      | assignment operator overload for moving object                                |

*Map Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `T& at(const Key& key)`                     | access specified element with bounds checking                                          |
| `T& operator[](const Key& key)`             | access or insert specified element                                                     |

*Map Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |

*Map Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`                  | checks whether the container is empty                                                  |
| `size_type size()`                   | returns the number of elements                                                         |
| `size_type max_size()`               | returns the maximum possible number of elements                                        |

*Map Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `std::pair<iterator, bool> insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place                                        |
| `std::pair<iterator, bool> insert(const Key& key, const T& obj)`                 | inserts value by key and returns iterator to where the element is in the container and bool denoting whether the insertion took place    |
| `std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);`       | inserts an element or assigns to the current element if the key already exists         |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(map& other)`                   | swaps the contents                                                                     |
| `void merge(map& other);`                  | splices nodes from another container                                                   |

*Map Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool contains(const Key& key)`                  | checks if there is an element with key equivalent to key in the container                                   |

</details>

### Queue

<details>
  <summary>Спецификация</summary>
<br />

*Queue Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Queue Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `queue()`  | default constructor, creates empty queue                                 |
| `queue(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates queue initizialized using std::initializer_list<T>    |
| `queue(const queue &q)`  | copy constructor  |
| `queue(queue &&q)`  | move constructor  |
| `~queue()`  | destructor  |
| `operator=(queue &&q)`      | assignment operator overload for moving object                                |

*Queue Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Queue Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Queue Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts element at the end                       |
| `void pop()`              | removes the first element                        |
| `void swap(queue& other)`             | swaps the contents                               |

</details>

### Set

<details>
  <summary>Спецификация</summary>
<br />

*Set Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `value_type`             | `Key` value type (the value itself is a key)                                                    |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `SetIterator<T>` or `BinaryTree::iterator` as the internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `SetConstIterator<T>` or `BinaryTree::const_iterator` as the internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Set Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `set()`  | default constructor, creates empty set                                 |
| `set(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `set(const set &s)`  | copy constructor  |
| `set(set &&s)`  | move constructor  |
| `~set()`  | destructor  |
| `operator=(set &&s)`      | assignment operator overload for moving object                                |


*Set Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |


*Set Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Set Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `std::pair<iterator, bool> insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place                                        |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(set& other)`                   | swaps the contents                                                                     |
| `void merge(set& other);`                  | splices nodes from another container                                                   |

*Set Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator find(const Key& key)`                   | finds element with specific key                                                        |
| `bool contains(const Key& key)`               | checks if the container contains element with specific key                             |

</details>

### Stack

<details>
  <summary>Спецификация</summary>
<br />

*Stack Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Stack Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `stack()`  | default constructor, creates empty stack                                 |
| `stack(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates stack initizialized using std::initializer_list<T>    |
| `stack(const stack &s)`  | copy constructor  |
| `stack(stack &&s)`  | move constructor  |
| `~stack()`  | destructor  |
| `operator=(stack &&s)`      | assignment operator overload for moving object                                |

*Stack Element access*   

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access   | Definition                                       |
|------------------|--------------------------------------------------|
| `const_reference top()`              | accesses the top element                         |

*Stack Capacity*   

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Stack Modifiers*        

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts element at the top                       |
| `void pop()`              | removes the top element                        |
| `void swap(stack& other)`             | swaps the contents                               |

</details>

### Vector

<details>
  <summary>Спецификация</summary>
<br />

*Vector Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | `T *` defines the type for iterating through the container                                                 |
| `const_iterator`         | `const T *` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Vector Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `vector()`  | default constructor, creates empty vector                                 |
| `vector(size_type n)`  | parameterized constructor, creates the vector of size n                                 |
| `vector(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates vector initizialized using std::initializer_list<T>    |
| `vector(const vector &v)`  | copy constructor  |
| `vector(vector &&v)`  | move constructor  |
| `~vector()`  | destructor  |
| `operator=(vector &&v)`      | assignment operator overload for moving object                                |

*Vector Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos);`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `T* data()`                   | direct access to the underlying array                                                  |

*Vector Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Vector Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:


| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |
| `void reserve(size_type size)`                | allocate storage of size elements and copies current array elements to a newely allocated array                                     |
| `size_type capacity()`               | returns the number of elements that can be held in currently allocated storage         |
| `void shrink_to_fit()`          | reduces memory usage by freeing unused memory                                          |

*Vector Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts elements into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void swap(vector& other)`                   | swaps the contents                                                                     |

</details>

### Array

<details>
  <summary>Спецификация</summary>
<br />

*Array Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | `T *` defines the type for iterating through the container                                                 |
| `const_iterator`         | `const T *` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Array Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `array()`  | default constructor, creates empty array                                 |
| `array(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates array initizialized using std::initializer_list<T>    |
| `array(const array &a)`  | copy constructor  |
| `array(array &&a)`  | move constructor  |
| `~array()`  | destructor  |
| `operator=(array &&a)`      | assignment operator overload for moving object                                |

*Array Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos)`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `iterator data()`                   | direct access to the underlying array                                                  |

*Array Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Array Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Array Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void swap(array& other)`                   | swaps the contents                                |
| `void fill(const_reference value);`         | assigns the given value value to all elements in the container. |


</details>

### Multiset 

<details>
  <summary>Спецификация</summary>
<br />

*Multiset Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `value_type`             | `Key` value type (the value itself is a key)                                                    |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `MultisetIterator<T>` or `BinaryTree::iterator` as internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `MultisetConstIterator<T>` or `BinaryTree::const_iterator` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Multiset Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `multiset()`  | default constructor, creates empty set                                 |
| `multiset(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `multiset(const multiset &ms)`  | copy constructor  |
| `multiset(multiset &&ms)`  | move constructor  |
| `~multiset()`  | destructor  |
| `operator=(multiset &&ms)`      | assignment operator overload for moving object                                |

*Multiset Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |


*Multiset Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Multiset Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `iterator insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container                                        |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(multiset& other)`                   | swaps the contents                                                                     |
| `void merge(multiset& other)`                  | splices nodes from another container                                                   |

*Multiset Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `size_type count(const Key& key)`                  | returns the number of elements matching specific key                                   |
| `iterator find(const Key& key)`                   | finds element with specific key                                                        |
| `bool contains(const Key& key)`               | checks if the container contains element with specific key                             |
| `std::pair<iterator,iterator> equal_range(const Key& key)`            | returns range of elements matching a specific key                                      |
| `iterator lower_bound(const Key& key)`            | returns an iterator to the first element not less than the given key                   |
| `iterator upper_bound(const Key& key)`            | returns an iterator to the first element greater than the given key                    |

</details>