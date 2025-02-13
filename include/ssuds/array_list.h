#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <stdexcept>

/// <summary>
/// Namespace ssuds contains the ArrayList class.
/// </summary>
namespace ssuds
{
    /// <summary>
	/// A general-purpose dynamic array list implementation.
    /// </summary>
    /// <typeparam name="T"> The type of elements stored in the ArrayList. </typeparam>
    template <class T>
    class ArrayList
    {
    private:
        T* mData;                   //pointer to the array
        unsigned int mCapacity;     //max number of elements that can be stored
		unsigned int mSize;         //number of elements that contain data

        /// <summary>
		/// Resizes the array to double its current capacity.
        /// </summary>
        void grow()
        {
            unsigned int new_capacity;

            if (mCapacity == 0)
            {
				new_capacity = 1;             //set to 1 if capacity is 0
            }
            else
            {
				new_capacity = mCapacity * 2;       //double the capacity
            }

            reserve(new_capacity);
        }

    public:
        /// <summary>
		/// Constructs an ArrayList with an initial capacity.
		/// If no capacity is given, the default is 5.
		/// If the capacity is set to 0, the default is 5.
        /// </summary>
        ArrayList(unsigned int initial_capacity = 5)
        {
            if (initial_capacity == 0)
            {
				initial_capacity = 5;   //set to 5 if capacity is set to 0
			}

            mCapacity = initial_capacity;    
			mData = new T[mCapacity];     //allocate memory for the array
			mSize = 0;                    //initialize the size to 0
        }


		/// <summary>
		/// Destructor that deallocates the memory used by the array.
		/// </summary>
		~ArrayList()                            //destructor
        {
            delete[] mData;
        }

        /// <summary>
		/// Gets the number of elements in the array.
        /// </summary>
        /// <returns> The number of elements in the array. </returns>
        unsigned int size() const
        {
            return mSize;
        }

        /// <summary>
		/// The maximum number of elements that can be stored in the array.
        /// </summary>
        /// <returns> The maximum number of elements that can be stored in the array. </returns>
        unsigned int capacity() const
        {
            return mCapacity;
        }

        /// <summary>
		/// Reserves a new capacity for the array.  
		/// If the new capacity is less than the current size, the size will be set to the new capacity.
        /// </summary>
        /// <param name="new_capacity"> The minimum capacity of the array. </param>
        void reserve(unsigned int new_capacity)
        {
            if (new_capacity == mCapacity)
            { 
                return;           
			}
            if (new_capacity < mSize)
			{
				new_capacity = mSize;       //set new capacity to size if it is less than size
			}

			T* new_data = new T[new_capacity];       //allocate memory for the new array

			for (unsigned int i = 0; i < mSize; i++)
            { 
				new_data[i] = mData[i];               //copy the data from the old array to the new array
			}

			delete[] mData;                        //deallocate memory for the old array
			mData = new_data;                      //set the pointer to the new array
			mCapacity = new_capacity;              //set the capacity to the new capacity
        }

        /// <summary>
		/// Appends an element to the end of the list.
		/// Grows the array if it reaches full capacity.
        /// </summary>
        /// <param name="new_value"> The item to append to the end of the list. </param>
        void append(const T& new_value)
        {
            if (mSize == mCapacity)
            {
                grow();
            }

			mData[mSize] = new_value;          //add the new value to the end of the array
            mSize++;
        }

        /// <summary>
		/// Adds an element to the beginning of the list.
		/// Shifts elements to the right to make room.
		/// Will grow the array if necessary.
        /// </summary>
        /// <param name="new_value"> The item to add to the beginning of the list. </param>
        void prepend(const T& new_value)
        {
            if (mSize == mCapacity)
            { 
                grow();
			}
   
            for (unsigned int i = mSize; i > 0; i--)
            {
				mData[i] = mData[i - 1];		//shift the elements to the right
			}

			mData[0] = new_value;               //add the new value to the beginning of the array
            mSize++;
        }

        /// <summary>
        /// Inserts an item at the index given.
		/// Shifts elements to the right to make room.
		/// Will grow the array if necessary.
        /// </summary>
        /// <param name="new_value"> The item to be inserted. </param>
        /// <param name="index"> The position to insert the item. </param>
        void insert(const T& new_value, unsigned int index)
        {
            if (index > mSize)  
                throw std::out_of_range("Index out of bounds");

            if (mSize == mCapacity)
                grow();

            for (unsigned int i = mSize; i > index; i--)
            {
				mData[i] = mData[i - 1];            //shift the elements to the right
            }

            mData[index] = new_value;
            mSize++;
        }

        /// <summary>
		/// Accesses an element in the list by index.
		/// Returns a reference to the element at the given index.
		/// Throws an exception if the index is out of bounds.
        /// </summary>
        /// <param name="index"> The position of the item to be accessed. </param>
        /// <returns> A reference to the element at the given index. </returns>
        T& at(unsigned int index)
        {
            if (index >= mSize)
                throw std::out_of_range("Index out of bounds");
            return mData[index];
        }

        /// <summary>
		/// Finds the index of the first occurrence of a value, starting at the given index.
        /// </summary>
        /// <param name="value"> The item searched for. </param>
		/// <param name="start_index"> The position to start the search. </param>
        /// <returns> The index of the first occurrence of the item. </returns>
        int find(const T& value, unsigned int start_index = 0) const
        {
            if (start_index >= mSize)
            {
                throw std::out_of_range("Start index out of bounds");
            }

            for (unsigned int i = start_index; i < mSize; i++)
            {
                if (mData[i] == value)
                    return i;
            }
            return -1;              //not found
        }

        /// <summary>
        /// Removes the element at the given index.
		/// Shifts the elements to the left to fill the gap.
		/// Shrinks the array if the size drops below 1/4 of the capacity.
        /// </summary>
        /// <param name="index"> The position of the item to be removed. </param>
        T remove(unsigned int index)
        {
            if (index >= mSize)
            {
                throw std::out_of_range("Index out of bounds");
            }

			T removed_value = mData[index];             //store the value to be removed

            for (unsigned int i = index; i < mSize - 1; i++)
            {
				mData[i] = mData[i + 1];                //shift the elements to the left
            }

            mSize--;

			if (mSize < mCapacity / 4 && mCapacity > 5)      //shrink the array if the size drops below 1/4 of the capacity
            {
                unsigned int new_capacity = mCapacity / 2;
                reserve(new_capacity);
            }

            return removed_value; 
        }


        /// <summary>
		/// Removes all occurrences of a value from the list.
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        unsigned int remove_all(const T& value)
        {
            unsigned int count = 0;

            for (unsigned int i = 0; i < mSize; ) 
            {
                if (mData[i] == value)
                {
					remove(i);          //uses the remove method to remove the element
					count++;            //keep a counter of the number of elements removed
                }
                else
                {
					i++;           //only increment if the element is not removed
                }
            }

            return count;
        }


        /// <summary>
		/// Outputs the elements of the list to the given output stream.
        /// </summary>
        /// <param name="os"> The output stream for ostream. </param>
        void output(std::ostream& os) const
        {
            os << "[";
            if (mSize > 0)
            {
                os << mData[0];
                for (unsigned int i = 1; i < mSize; i++) 
                {
                    os << ", " << mData[i];
                }
            }
            os << "]";
        }
    };
}

#endif