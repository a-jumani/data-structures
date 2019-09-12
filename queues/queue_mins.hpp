#include <deque>
#include <queue>

/**
 * Queue data structure like std::queue but additionally
 * supports get_min().
 * 
 * Note: tt doesn't support MoveInsertable objects, i.e.
 * copies of objects are made.
 */
template <typename Comparable>
class queue_mins {
private:
    std::queue<Comparable> main_queue;      // actual values
    std::deque<Comparable> mins_deque;      // mins

public:
    
    /**
       Add an element to the queue.
     */
    void push(const Comparable &x) {

        // add to queue
        main_queue.push(x);

        // update mins
        while ( !mins_deque.empty() && x < mins_deque.back() )
            mins_deque.pop_back();
        mins_deque.push_back(x);
    }

    /**
     * Remove element from front of the queue.
     */
    void pop(void) {
        if ( mins_deque.front() == main_queue.front() )
            mins_deque.pop_front();
        main_queue.pop();
    }

    /**
     * Get element from front of queue.
     */
    Comparable &front(void) {
        return main_queue.front();
    }

    /**
     * Get min of all elements present in the queue.
     */
    Comparable &get_min(void) {
        return mins_deque.front();
    }

    /**
     * Check queue is empty.
     */
    bool empty(void) const {
        return ( main_queue.empty() );
    }

    /**
     * Get queue size.
     */
    std::size_t size(void) const {
        return main_queue.size();
    }
};
