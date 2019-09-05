#include <functional>
#include <stack>
#include <vector>

/**
 * Stack data structure like std::stack but additionally
 * supports get_min(). It also supports MoveInsertable objects.
 */
template <typename Comparable, typename Compare = std::less<Comparable> >
class stack_mins {
private:
    std::vector<Comparable> main_stack;     // actual values
    std::stack<std::size_t> mins_stack;     // index of mins
    
    // update current min, if needed, for to-be inserted Comparable object
    void update_min(Comparable &x) {
        if ( mins_stack.empty() || comp(x, main_stack[mins_stack.top()]) )
            mins_stack.push(main_stack.size());
    }

public:
    
    Compare comp;
    stack_mins() : comp(Compare()) {}
    
    /**
       Add an element to the stack.
     */
    void push(const Comparable &x) {
        update_min(x);
        main_stack.push_back(x);
    }

    /**
     * Add an element to the stack. Supports MoveInsertable
     * elements.
     */
    void push(Comparable &&x) {
        update_min(x);
        main_stack.push_back(std::move(x));
    }

    /**
     * Remove element from top of stack.
     */
    void pop(void) {
        if ( main_stack.size() - 1 == mins_stack.top() )
            mins_stack.pop();
        main_stack.pop_back();
    }

    /**
     * Remove element from top of stack. Useful for
     * MoveInsertable elements.
     */
    void pop(Comparable &x) {
        x = std::move(main_stack.back());
        pop();
    }

    /**
     * Get element from top of stack.
     */
    Comparable &top(void) {
        return main_stack.back();
    }

    /**
     * Get min of all elements present in the stack.
     */
    Comparable &get_min(void) {
        return main_stack[mins_stack.top()];
    }

    /**
     * Check stack is empty.
     */
    bool empty(void) const {
        return ( main_stack.empty() );
    }
};
