class interval_iterator
	: public std::iterator <std::forward_iterator_tag, int>
{
private:
	friend class interval;
	const interval* mInterval; // Référence à l'interval.
	int mCurrent; // la valeur courante dont on fait référence.
 
	interval_iterator(const interval& anInterval, int aCurrentValue) : 
		mInterval(&anInterval), mCurrent(aCurrentValue) {}
 
public:
	interval_iterator(const interval_iterator& anotherIterator):
		mInterval(anotherIterator.mInterval),
		mCurrent(anotherIterator.mCurrent) {}
 
	interval_iterator& operator = (interval_iterator& anotherIterator)
	{
		mInterval = anotherIterator.mInterval;
		mCurrent = anotherIterator.mCurrent;
		return *this;
	}
 
	const reference operator*() const;
	const pointer operator->() const;
	interval_iterator& operator++();
	interval_iterator& operator++(int);
	bool operator ==(const interval_iterator&) const;
	bool operator !=(const interval_iterator&) const;
 
};

class interval_iterator
{
};
 
inline interval::iterator interval::begin() const
{
    return iterator(*this, minValue); 
}
 
inline interval::iterator interval::end() const
{
    return iterator(*this, maxValue + 1); 
}