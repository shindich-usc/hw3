#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void swap(size_t i1, size_t i2);
  size_t bestChild(size_t parent);
  std::vector<T> contents_;
  size_t m_;
  PComparator c_;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m_(m), c_(c)
{

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

// Swap helper function
template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(size_t i1, size_t i2)
{
  T tempItem = contents_[i1];
  contents_[i1] = contents_[i2];
  contents_[i2] = tempItem;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::bestChild(size_t parent)
{
  size_t best = m_ * parent + 1;
  for (size_t i = 2; i <= m_; i++) {
    if (m_ * parent + i >= size()) {return best;}
    if (!c_(contents_[best], contents_[m_ * parent + i])) {best = m_ * parent + i;}
  }
  return best;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return contents_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return contents_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  contents_.push_back(item);
  // Trickle up
  size_t current = size() - 1;
  size_t parent = (current - 1) / m_;
  while (current != 0 && !c_(contents_[parent], contents_[current])) {
    swap(parent, current);
    current = parent;
    parent = (current - 1) / m_;
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return contents_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");
  }
  // Replace top with last
  contents_[0] = contents_.back();
  contents_.pop_back();
  // Heapify
  size_t current = 0;
  size_t child = 0;
  // Note: current equals child whenever a swap occurs
  while (current == child) {
    child = bestChild(current);
    // Done if no children or if current is better than best child
    if (child >= size() || c_(contents_[current], contents_[child])) {}
    // Swap current with child and repeat otherwise
    else{
      swap(current, child);
      current = child;
    }
  }
}

#endif

