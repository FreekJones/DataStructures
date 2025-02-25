#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <stdexcept>

/// <summary>
/// Namespace ssuds contains the ArrayList class and the nested ArrayListIterator class.
/// </summary>
namespace ssuds
{
    /// <summary>
	/// A general-purpose dynamic array list implementation and iterators.
    /// </summary>
    /// <typeparam name="T"> The type of elements stored in the ArrayList. </typeparam>
    template <class T>
    class ArrayList
    {
    private:
        /// <summary>
		/// The dynamic array that stores the elements.
        /// </summary>
        T* mData;

        /// <summary>
		/// The current capacity of the array.
        /// </summary>
        unsigned int mCapacity;

        /// <summary>
		/// The current number of elements in the array.
        /// </summary>
        unsigned int mSize;

        /// <summary>
		/// Resizes the array to double its current capacity.
        /// </summary>
        void grow()
        {
            unsigned int new_capacity;

            if (mCapacity == 0)
            {
                new_capacity = 1;
            }
            else
            {
                new_capacity = mCapacity * 2;
            }

            reserve(new_capacity);
        }

    public:

        /// <summary>
		/// Constructor that initializes the array with a given capacity.
        /// </summary>
        /// <param name="initial_capacity"> The initial capacity of the list. The default is 5. </param>
        ArrayList(unsigned int initial_capacity = 5)
        {
            if (initial_capacity == 0)
            {
                initial_capacity = 5;
            }

            mCapacity = initial_capacity;
            mData = new T[mCapacity];
            mSize = 0;
        }

        /// <summary>
        /// Destructor that deallocates the memory used by the array.
        /// </summary>
        ~ArrayList()
        {
            delete[] mData;
        }

        /// <summary>
        /// Copy constructor that creates a deep copy of the array.
        /// </summary>
        /// <param name="other"> The ArrayList to copy </param>
        ArrayList(const ArrayList& other)
        {
            mCapacity = other.mCapacity;
            mSize = other.mSize;
            mData = new T[mCapacity];

            for (unsigned int i = 0; i < mSize; i++)
            {
                mData[i] = other.mData[i];
            }
        }

        /// <summary>
        /// Assignment operator that creates a deep copy of the array.
        /// </summary>
        /// <param name="other"> The ArrayList to assign from. </param>
        /// <returns> Reference to the assigned ArrayList </returns>
        ArrayList& operator=(const ArrayList& other)
        {
            if (this != &other)
            {
                delete[] mData;
                mCapacity = other.mCapacity;
                mSize = other.mSize;
                mData = new T[mCapacity];

                for (unsigned int i = 0; i < mSize; i++)
                {
                    mData[i] = other.mData[i];
                }
            }
            return *this;
        }

        /// <summary>
        /// Move constructor that transfers the data to the new array.
        /// </summary>
        /// <param name="other"> The ArrayList to move from </param>
        ArrayList(ArrayList&& other) 
        {
            mData = other.mData;
            mCapacity = other.mCapacity;
            mSize = other.mSize;

            other.mData = nullptr;
            other.mCapacity = 0;
            other.mSize = 0;
        }

        /// <summary>
		/// Constructor that initializes the array with an initializer list.
        /// </summary>
        /// <param name="initList"> The list to initialize the array. </param>
        ArrayList(std::initializer_list<T> initList)
        {
            unsigned int initSize = initList.size(); 

            if (initSize == 0)
            {
                mCapacity = 1;  
            }
            else
            {
                mCapacity = initSize;
            }

            mData = new T[mCapacity]; 
            mSize = initSize; 

            unsigned int i = 0;
            for (const T& val : initList)
            {
                mData[i] = val;
                i++;
            }
        }

        /// <summary>
		/// Returns the current number of elements in the array.
        /// </summary>
        /// <returns> The size of the array. </returns>
        unsigned int size() const
        {
            return mSize;
        }

        /// <summary>
		/// Returns the current capacity of the array.
        /// </summary>
        /// <returns> The capacity of the array. </returns>
        unsigned int capacity() const
        {
            return mCapacity;
        }

        /// <summary>
		/// Reserves a new capacity for the array.
        /// </summary>
        /// <param name="new_capacity"> The new capacity to reserve. </param>
        void reserve(unsigned int new_capacity)
        {
            if (new_capacity < mSize)
            {
                new_capacity = mSize;
            }

            T* new_data = new T[new_capacity];

            for (unsigned int i = 0; i < mSize; i++)
            {
                new_data[i] = mData[i];
            }

            delete[] mData;
            mData = new_data;
            mCapacity = new_capacity;
        }

        /// <summary>
        /// A nested class that allows for iteration over the ArrayList.
        /// </summary>
        class ArrayListIterator
        {
        public:
            /// <summary>
			/// A pointer to the current element in the iteration.
            /// </summary>
            T* ptr;

            /// <summary>
			/// A bool that indicates if the iteration is in reverse.
            /// </summary>
            bool reverse;

            /// <summary>
			/// The default constructor for the ArrayListIterator.
            /// </summary>
            ArrayListIterator()
            {
                ptr = nullptr;
                reverse = false;
            }

            /// <summary>
			/// Constructs an iterator with a given pointer and direction.
            /// </summary>
            /// <param name="p"> Pointer to the current position in the array. </param>
            /// <param name="rev"> Bool indicating if the iterator is in reverse mode (default: false) </param>
            ArrayListIterator(T* p, bool rev = false)
            {
                ptr = p;
                reverse = rev;
            }

            /// <summary>
            /// Copy constructor for the iterator.
            /// </summary>
            /// <param name="other"> The iterator to copy. </param>
            ArrayListIterator(const ArrayListIterator& other)
            {
                ptr = other.ptr;
                reverse = other.reverse;
            }

            /// <summary>
            /// Assignment operator for the iterator.
            /// </summary>
            /// <param name="other"> The iterator to assign from. </param>
            /// <returns> Reference to the assigned iterator. </returns>
            ArrayListIterator& operator=(const ArrayListIterator& other)
            {
                if (this != &other)
                {
                    ptr = other.ptr;
                    reverse = other.reverse;
                }
                return *this;
            }

            /// <summary>
			/// *(Derefence) operator to access the value at the current iterator position.
            /// </summary>
            /// <returns> A Reference to the current element. </returns>
            T& operator*()
            {
                return *ptr;
            }

            /// <summary>
			/// Pre-increment operator to move to the next element.
            /// </summary>
            /// <returns> Reference to the updated iterator. </returns>
            ArrayListIterator& operator++()
            {
                if (reverse)
                {
                    ptr--;
                }
                else
                {
                    ptr++;
                }

                return *this;
            }

            /// <summary>
            /// Post-increment operator to move to the next element.
            /// </summary>
            /// <returns> A copy of the iterator before incrementing. </returns>
            ArrayListIterator operator++(int)
            {
                ArrayListIterator temp = *this;

                if (reverse)
                {
                    ptr -= 1;
                }
                else
                {
                    ptr += 1;
                }

                return temp;
            }

            /// <summary>
            /// Moves the iterator forward or backward by n positions.
            /// </summary>
            /// <param name="n"> The number of positions to move. </param>
            /// <returns> A new iterator at the updated position. </returns>
            ArrayListIterator operator+(int n) const
            {
                if (reverse)
                {
                    return ArrayListIterator(ptr - n, reverse);
                }
                return ArrayListIterator(ptr + n, reverse);
            }

            /// <summary>
            /// Equality comparison operator.
            /// </summary>
            /// <param name="other"> The iterator to compare with. </param>
            /// <returns> true if both iterators are at the same position, otherwise false. </returns>
            bool operator==(const ArrayListIterator& other) const
            {
                return ptr == other.ptr;
            }

            /// <summary>
            /// Inequality comparison operator.
            /// </summary>
            /// <param name="other"> The iterator to compare with. </param>
            /// <returns> true if both iterators are at different positions, otherwise false. </returns>
            bool operator!=(const ArrayListIterator& other) const
            {
                return ptr != other.ptr;
            }
        };

        /// <summary>
        /// Returns an iterator to the beginning of the list.
        /// </summary>
        /// <returns> ArrayListIterator pointing to the first element. </returns>
        ArrayListIterator begin()
        {
            return ArrayListIterator(mData);
        }

        /// <summary>
        /// Returns an iterator to the end of the list.
        /// </summary>
        /// <returns> ArrayListIterator pointing one past the last element. </returns>
        ArrayListIterator end()
        {
            return ArrayListIterator(mData + mSize);
        }

        /// <summary>
        /// Returns a reverse iterator to the last element of the list.
        /// </summary>
        /// <returns> ArrayListIterator pointing to the last element. </returns>
        ArrayListIterator rbegin()
        {
            return ArrayListIterator(mData + mSize - 1, true);
        }

        /// <summary>
        /// Returns a reverse iterator to one position before the first element.
        /// </summary>
        /// <returns> ArrayListIterator pointing one before the first element. </returns>
        ArrayListIterator rend()
        {
            return ArrayListIterator(mData - 1, true);
        }

        /// <summary>
		/// Overloaded output stream operator to print the list.
        /// </summary>
        /// <param name="os"> The output stream. </param>
        /// <param name="arr"> The ArrayList to print. </param>
        /// <returns> The output stream. </returns>
        friend std::ostream& operator<<(std::ostream& os, const ArrayList& arr)
        {
            os << "[";
            if (arr.mSize > 0)
            {
                os << arr.mData[0];
                for (unsigned int i = 1; i < arr.mSize; i++)
                {
                    os << ", " << arr.mData[i];
                }
            }
            os << "]";
            return os;
        }

        /// <summary>
		/// Overloaded [] operator to access elements in the list without bounds checking.
        /// </summary>
        /// <param name="index"> The index of the element to access. </param>
        /// <returns> Reference to the element at the given index. </returns>
        T& operator[](unsigned int index)
        {
            return mData[index];
        }

        /// <summary>
        /// Appends an element to the end of the list.
        /// </summary>
        /// <param name="new_value"> The value to append. </param>
        void append(const T& new_value)
        {
            if (mSize == mCapacity)
            {
                grow();
            }

            mData[mSize] = new_value;
            mSize++;
        }

        /// <summary>
        /// Inserts an element at the beginning of the list.
        /// </summary>
        /// <param name="new_value"> The value to prepend. </param>
        void prepend(const T& new_value)
        {
            if (mSize == mCapacity)
            {
                grow();
            }

            for (unsigned int i = mSize; i > 0; i--)
            {
                mData[i] = mData[i - 1];		
            }

            mData[0] = new_value;               
            mSize++;
        }

        /// <summary>
        /// Finds an element in the list.
        /// </summary>
        /// <param name="value"> The value to find in the list. </param>
        /// <returns> An iterator pointing to the found element or end() if not found. </returns>
        ArrayListIterator find(const T& value)
        {
            for (ArrayListIterator it = begin(); it != end(); ++it)
            {
                if (*it == value)
                {
                    return it;
                }
            }
            return end();
        }

        /// <summary>
		/// Removes an element at the given iterator position. Shrinks the array if necessary.
        /// </summary>
        /// <param name="pos"> The iterator pointing to the element to remove. </param>
        /// <returns> An iterator pointing to the next valid element after removal. </returns>
        ArrayListIterator remove(ArrayListIterator pos)
        {
            if (pos == end())
            {
                return pos;
            }

            T* target = pos.ptr;

            for (T* it = target; it < mData + mSize - 1; ++it)
            {
                *it = *(it + 1);
            }

            mSize--;

            if (mSize <= mCapacity / 4 && mCapacity > 5)
            {
                unsigned int new_capacity = mCapacity / 2;
                if (new_capacity < 5)
                {
                    new_capacity = 5;
                }
                reserve(new_capacity);
            }

            return ArrayListIterator(target);
        }

        /// <summary>
        /// Accesses an element at the given index.
        /// </summary>
        /// <param name="index"> The element to access. </param>
        /// <returns> Reference to the element at the given index. </returns>
        T& at(unsigned int index)
        {
            if (index >= mSize)
            {
                throw std::out_of_range("Index out of bounds");
            }
            return mData[index];
        }

        /// <summary>
        /// Inserts an element at a specified position.
        /// </summary>
        /// <param name="new_value"> The value to insert </param>
        /// <param name="index"> The position to insert the element at. </param>
        void insert(const T& new_value, unsigned int index)
        {
            if (index > mSize)
            {
                throw std::out_of_range("Index out of bounds");
            }

            if (mSize == mCapacity)
            {
                grow();
            }

            for (unsigned int i = mSize; i > index; i--)
            {
                mData[i] = mData[i - 1];
            }

            mData[index] = new_value;
            mSize++;
        }

        /// <summary>
        /// Removes all occurrences of a specified value from the list.
        /// </summary>
        /// <param name="value"> The value to remove. </param>
        /// <returns> The number of elements removed. </returns>
        unsigned int remove_all(const T& value)
        {
            unsigned int count = 0;
            auto it = begin();

            while (it != end())
            {
                if (*it == value)
                {
                    it = remove(it);
                    count++;  
                }
                else
                {
                    ++it;
                }
            }

            if (mSize <= mCapacity / 4 && mCapacity > 5)
            {
                unsigned int new_capacity = mCapacity / 2;
                if (new_capacity < 5)
                {
                    new_capacity = 5;
                }
                reserve(new_capacity);
            }

            return count;
        }
    };
}

#endif