#include <cstddef>

/**
 * Trie data structure with extended features:
 *   - Arbitrary, but contiguous, alphabet.
 *   - Tracking of prefixes as well as ends.
 * 
 * base     first letter of the alphabet
 * size     size of the alphabet
 * prefix   if true, track prefixes
 */
template <char base = 'a', std::size_t size = 26UL, bool prefix = false>
class trie {
private:
    std::size_t is_end[size];
    trie<base, size, prefix> *children[size];

    void insert(const std::string &x, size_t i) {
        // code
    }

    std::size_t search(const std::string &x, size_t i) const {
        // code
    }

public:
    
    trie() {
        // initialize to empty
        for ( std::size_t i = 0; i < size; ++i ) {
            is_end[i] = 0;
            children[i] = nullptr;
        }
    }
    
    ~trie() {}
    
    /**
     * Insert string into trie.
     * 
     * preconditions:
     *   0 < x.size()
     */
    void insert(const std::string &x) {
        insert(x, 0);
    }

    /**
     * Number of times (prefix) x was inserted in trie.
     */
    std::size_t search(const std::string &x) const {
        return search(x, 0);
    }
};
