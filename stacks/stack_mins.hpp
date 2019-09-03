#include <functional>
#include <stack>
#include <vector>

// TODO: remove copying overhead

/**
 * Stack data structure like std::stack but additionally
 * supports get_min().
 * 
 * Note: may involve copying to objects.
 */
template <typename Comparable, typename Compare = std::less<Comparable> >
class stack_mins {
private:
    std::vector<Comparable> main_stack;     // actual values
    std::stack<std::size_t> mins_stack;     // index of mins
public:
    
    Compare comp;
    stack_mins() : comp(Compare()) {}
    
    /**
       Add an element to the stack.
     */
    void push(const Comparable &x) {
        if ( mins_stack.empty() || comp(x, main_stack[mins_stack.top()]) )
            mins_stack.push(main_stack.size());
        main_stack.push_back(x);
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
