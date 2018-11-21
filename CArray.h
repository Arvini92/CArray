#pragma once

template <typename TData>
class CArray
{
public:

  CArray();

  CArray(
      const CArray & _array
    );

  ~CArray();

  void push_back(
      const TData & _value
    );

  void insert(
      unsigned int  _index,
      const TData & _value
    );

  void erase(
      unsigned int _index
    );

  void clear();

  unsigned int size() const;

  TData & operator[](
      unsigned int _index
    );

  const TData * const begin()
  {
    return array;
  }

  TData const * const end()
  {
    return pEnd;
  }

protected:
  const unsigned int initialCapacity = 4;
  TData * array = nullptr;
  TData * pEnd = nullptr;
  unsigned int _size = 0;
  unsigned int capacity = initialCapacity;

  void resize();
  void check_capacity();
  void setCapacity();
  void isValid(unsigned int _index);
};

template <typename TData>
CArray<TData>::CArray()
{
  array = new TData[capacity];
  pEnd = array;
}


template <typename TData>
CArray<TData>::CArray(
    const CArray & _array
  )
{
  _size = _array.size();
  array = new TData[_size];
  pEnd = array + _size;

  for (unsigned int i = 0; i < _size; i++)
  {
    array[i] = _array.array[i];
  }
}


template <typename TData>
CArray<TData>::~CArray()
{
  delete [] array;
}


template <typename TData>
void CArray<TData>::push_back(
    const TData & _value
  )
{

  check_capacity();

  *pEnd = _value;
  _size += 1;
  pEnd += 1;

}


template <typename TData>
void CArray<TData>::insert(
    unsigned int  _index,
    const TData & _value
  )
{
  if (_size != 0)
  {
    isValid(_index);
  }

  check_capacity();
  _size += 1;
  pEnd += 1;


  for (unsigned int i = _size - 1; i > _index; i--)
  {
    array[i] = array[i - 1];
  }
  array[_index] = _value;

}


template <typename TData>
void CArray<TData>::erase(
    unsigned int _index
  )
{
  if (_size != 0)
  {
    isValid(_index);
  }

  for (unsigned int i = _index; i < _size; i++)
  {
    array[i] = array[i + 1];
  }
  _size -= 1;
  pEnd -= 1;

}


template <typename TData>
void CArray<TData>::clear()
{
  delete [] array;
  capacity = initialCapacity;
  array = new TData[capacity];
  pEnd = array;
  _size = 0;
}


template <typename TData>
unsigned int CArray<TData>::size() const
{
  return _size;
}


template <typename TData>
TData & CArray<TData>::operator[](
    unsigned int _index
  )
{
  isValid(_index);
  return array[_index];
}


template <typename TData>
void CArray<TData>::check_capacity()
{
  if (capacity <= _size)
  {
    setCapacity();
    resize();
  }
}


template <typename TData>
void CArray<TData>::setCapacity()
{
  unsigned int delta = 0;
  if (capacity > 64)
  {
    delta = capacity / 4;
  }
  else if (capacity > 8)
  {
    delta = 16;
  }
  else
  {
    delta = 4;
  }
  capacity += delta;
}


template <typename TData>
void CArray<TData>::resize()
{
  TData * temp = new TData[capacity];

  for (unsigned int i = 0; i < _size; i++)
  {
    temp[i] = array[i];
  }
  delete [] array;
  array = temp;
  pEnd = array + _size;
}

template <typename TData>
void CArray<TData>::isValid(
    unsigned int _index
  )
{
  if (_index >= _size)
  {
    throw std::out_of_range("CArray out of range");
  }
}