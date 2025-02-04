#include <stdexcept>  // For std::out_of_range
#include <cstddef>    // For size_t and ptrdiff_t
#include <iterator>   // For iterator tags

class interval_iterator;  // Forward declaration

class interval {
private:
    int minValue;
    int maxValue;
 
public:
    friend class interval_iterator;
    typedef int value_type;
    typedef const int& reference;
    typedef const int& const_reference;

    typedef interval_iterator iterator;
    typedef interval_iterator const_iterator;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    inline iterator begin() const;
    inline iterator end() const;

    interval(int theMinValue, int theMaxValue) : minValue(theMinValue), maxValue(theMaxValue) {}
    
    interval(const interval& anotherInterval) : minValue(anotherInterval.minValue), maxValue(anotherInterval.maxValue) {}
    
    interval& operator = (const interval& anotherInterval) {
        minValue = anotherInterval.minValue;
        maxValue = anotherInterval.maxValue;
        return *this;
    }

    size_type size() const {
        return (size_type)(maxValue - minValue + 1);
    }

    int operator[](size_type anIndex) const {
        if (anIndex >= size())  // Corrected index check
            throw std::out_of_range("Index out of range");
        return minValue + (int)anIndex;
    }

    bool operator==(const interval& anotherInterval) const {
        return anotherInterval.maxValue == maxValue && anotherInterval.minValue == minValue;
    }

    bool operator!=(const interval& anotherInterval) const {
        return anotherInterval.maxValue != maxValue || anotherInterval.minValue != minValue;
    }
};

class interval_iterator {
private:
    friend class interval;
    const interval* mInterval; // Reference to the interval.
    int mCurrent;              // Current value in the range.

    interval_iterator(const interval& anInterval, int aCurrentValue) : mInterval(&anInterval), mCurrent(aCurrentValue) {}

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type        = int;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const int*;
    using reference         = const int&;

    interval_iterator(const interval_iterator& anotherIterator) : mInterval(anotherIterator.mInterval), mCurrent(anotherIterator.mCurrent) {}

    interval_iterator& operator=(const interval_iterator& anotherIterator) {
        mInterval = anotherIterator.mInterval;
        mCurrent = anotherIterator.mCurrent;
        return *this;
    }

    reference operator*() const {
        return mCurrent;
    }

    pointer operator->() const {
        return &mCurrent;
    }

    interval_iterator& operator++() {
        if (mCurrent <= mInterval->maxValue)
            mCurrent++;
        return *this;
    }

    interval_iterator operator++(int) {
        interval_iterator it(*this);
        ++(*this);
        return it;
    }

    bool operator==(const interval_iterator& anotherIterator) const {
        return mCurrent == anotherIterator.mCurrent && *mInterval == *anotherIterator.mInterval;
    }

    bool operator!=(const interval_iterator& anotherIterator) const {
        return mCurrent != anotherIterator.mCurrent || *mInterval != *anotherIterator.mInterval;
    }
};

inline interval::iterator interval::begin() const {
    return iterator(*this, minValue);
}

inline interval::iterator interval::end() const {
    return iterator(*this, maxValue + 1);
}
