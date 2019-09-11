/**
 * Queue data structure like std::queue but additionally
 * supports get_min().
 * 
 * Note: tt doesn't support MoveInsertable objects, i.e.
 * copies of objects are made.
 */
template <typename Comparable>
class queue_mins {
public:
    
    /**
       Add an element to the queue.
     */
    void push(const Comparable &x) {
        //code
    }

    /**
     * Remove element from front of the queue.
     */
    void pop(void) {
        // code
    }

    /**
     * Get element from front of queue.
     */
    Comparable &front(void) {
        // code
    }

    /**
     * Get min of all elements present in the queue.
     */
    Comparable &get_min(void) {
        // code
    }

    /**
     * Check queue is empty.
     */
    bool empty(void) const {
        // code
    }

    /**
     * Get queue size.
     */
    std::size_t size(void) const {
        // code
    }
};
