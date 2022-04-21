template <typename T>
void ConstIterator<T>::_checkIndex(const string hint) const {
    if (_index < _rows * _cols)
        return;
    time_t cur_time = time(NULL);
    auto local_time = localtime(&cur_time);
    throw IndexError(asctime(local_time), __FILE__, __LINE__, hint);
}

template <typename T>
void ConstIterator<T>::_checkValid(const string hint) const {
    if (!isValid()) {
        time_t cur_time = time(NULL);
        auto local_time = localtime(&cur_time);
        throw MemoryError(asctime(local_time), __FILE__, __LINE__, hint);
    }
}

template <typename T>
bool ConstIterator<T>::operator!=(ConstIterator const& other) const {
    return _index != other._index;
}

template <typename T>
bool ConstIterator<T>::operator==(ConstIterator const& other) const {
    return _index == other._index;
}

template <typename T>
const T& ConstIterator<T>::operator*() const {
    _checkValid("Iterator points on nullptr");
    _checkIndex("ConstIterator doens't in data bounds, while executing const operator*");
    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = _data.lock();
    return data_ptr[_index / _cols][_index % _cols];
}

template <typename T>
const T& ConstIterator<T>::value() const {
    return operator*();
}

template <typename T>
const T* ConstIterator<T>::operator->() const {
    _checkValid("Iterator points on nullptr");
    _checkIndex("ConstIterator doens't in data bounds, while executing const operator->");
    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = _data.lock();
    return data_ptr[_index / _cols].getAddr() + (_index % _cols);
}

template <typename T>
const ConstIterator<T>& ConstIterator<T>::operator++() const {
    if (_index < _cols * _rows)
        ++_index;
    return *this;
}

template <typename T>
ConstIterator<T>& ConstIterator<T>::next() const {
    return operator++();
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) const {
    ConstIterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
bool ConstIterator<T>::operator<(ConstIterator const& other) const {
    return _index < other._index;
}

template <typename T>
bool ConstIterator<T>::isEnd() const {
    return _index == _rows * _cols;
}

template <typename T>
ConstIterator<T>::operator bool() const {
    return _data.expired();
}

template <typename T>
bool ConstIterator<T>::isValid() const {
    return !_data.expired();
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator+(const int value) const {
    ConstIterator<T> it(*this);
    if (value < 0 && it._index < static_cast<size_t>(-value))
        it._index = 0;
    else
        it._index += value;

    if (it._index > _rows * _cols)
        it._index = _rows * _cols;

    return it;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator-(const int value) const {
    return operator+(-value);
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator+=(const int value) const {
    _index += value;
    return *this;
}
